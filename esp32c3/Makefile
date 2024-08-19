# BM_
BMV_ESPTOOL ?= esptool
BMV_CHIP    ?= esp32c3
BMV_PORT    ?= /dev/ttyACM0
BMV_CC      ?= riscv64-unknown-elf-gcc
BMV_OJBCOPY ?= riscv64-unknown-elf-objcopy
BMV_OBJDUMP ?= riscv64-unknown-elf-objdump
BMV_READELF ?= riscv64-unknown-elf-readelf

CC = $(BMV_CC)
OBJCOPY = $(BMV_OBJCOPY)
OBJDUMP = $(BMV_OBJDUMP)
READELF = $(BMV_READELF)

# compiler flags, linker flags
# clang                                       - requires '--target=riscv32', '_zicsr' is unsupported
# riscv64-unknown-elf-gcc, riscv-none-elf-gcc - requires '_zicsr' for csr instructions - requires '-ffreestanding' to use <stdint.h>
# ifeq ($(findstring clang, $(CC)), clang)
ifeq ($(CC),clang)
	CFLAGS  += -Wall -Wextra --target=riscv32 -march=rv32imc -mabi=ilp32 -nostdlib -g -O
else
	CFLAGS  += -Wall -Wextra -march=rv32imc_zicsr -mabi=ilp32 -nostdlib -g -O
endif
LDFLAGS = -Wl,-T$(DIR_CHIP)/linker/esp32c3.ld

# dirs
DIR_CHIP  = $(BMV_DIR)/$(BMV_CHIP)
DIR_SRC   = $(BMV_DIR)/$(BMV_CHIP)/src
DIR_BUILD = ./build/

# source
SOURCES   = $(DIR_SRC)/startup.S $(DIR_SRC)/clock.S $(DIR_SRC)/gpio.S $(DIR_SRC)/usb.S \
			$(DIR_SRC)/wdt.S $(DIR_SRC)/interrupts.S $(DIR_SRC)/ivectors.S
SOURCES  += $(SOURCES_EXTRA)

# output file names
FILE_ELF = $(DIR_BUILD)main.elf
FILE_BIN = $(DIR_BUILD)main.bin
FILE_E2I = $(DIR_BUILD)main.e2i

all: $(FILE_ELF) $(FILE_BIN) $(FILE_E2I)
	@echo "Running target" $@

$(FILE_ELF): $(SOURCES)
	@echo "Running target" $@
	$(CC) $(CFLAGS) $(CFLAGS_EXTRA) $(LDFLAGS) $(SOURCES) -o $@

$(FILE_BIN): $(FILE_ELF)
	@echo "Running target" $@
#	$(OBJCOPY) -O binary $(FILE_ELF) $(FILE_BIN)

$(FILE_E2I): $(FILE_ELF)
	@echo "Running target" $@
	$(BMV_ESPTOOL) --chip $(BMV_CHIP) elf2image --flash_mode dio --flash_freq 80m --flash_size 4MB $(FILE_ELF) -o $(FILE_E2I)
	$(BMV_ESPTOOL) image_info --version 2 $(FILE_E2I)

flash: all
	@echo "Running target" $@
	$(BMV_ESPTOOL) --chip $(BMV_CHIP) --port $(BMV_PORT) write_flash --flash_mode keep --flash_freq keep --flash_size keep 0x0 $(FILE_E2I)

#flash_directboot: all
#	@echo "Running target" $@
#	$(BMV_ESPTOOL) --chip $(BMV_CHIP) --port $(BMV_PORT) write_flash 0x0 $(FILE_BIN)

flash_partboot: all
	@echo "Running target" $@
	$(BMV_ESPTOOL) --chip $(BMV_CHIP) --port $(BMV_PORT) write_flash --flash_mode keep --flash_freq keep --flash_size keep 0x0 $(DIR_CHIP)/bootloader/bootloader.bin 0x8000 $(DIR_CHIP)/partition/partitions.bin 0x10000 $(FILE_E2I)

load_ram: all
	@echo "Running target" $@
	$(BMV_ESPTOOL) --chip $(BMV_CHIP) --port $(BMV_PORT) --no-stub load_ram $(FILE_E2I)

image_info: all
	@echo "Running target" $@
	$(BMV_ESPTOOL) image_info --version 2 $(FILE_E2I)

dump:
	@echo "Running target" $@
	$(OBJDUMP) --all-headers $(FILE_ELF)

readelf:
	$(READELF) -a $(FILE_ELF)

chip_id:
	@echo "Running target" $@
	$(BMV_ESPTOOL) --port $(BMV_PORT) --no-stub chip_id

reset:
	@echo "Running target" $@
	$(BMV_ESPTOOL) --chip $(BMV_CHIP) --port $(BMV_PORT) --no-stub read_mem 0

clean:
	@echo "Running target" $@
	rm -f $(FILE_ELF) $(FILE_BIN) $(FILE_E2I) $(OBJECTS)

show_vars:
	@echo "Running target" $@
	@echo "BMV_ESPTOOL   = " $(BMV_ESPTOOL)
	@echo "BMV_CHIP      = " $(BMV_CHIP)
	@echo "BMV_PORT      = " $(BMV_PORT)
	@echo "CC            = " $(CC)
	@echo "OBJCOPY       = " $(OBJCOPY)
	@echo "OBJDUMP       = " $(OBJDUMP)
	@echo "READELF       = " $(READELF)
	@echo "CFLAGS        = " $(CFLAGS)
	@echo "CFLAGS_EXTRA  = " $(CFLAGS_EXTRA)
	@echo "LDFLAGS       = " $(LDFLAGS)
	@echo "DIR_SRC       = " $(DIR_SRC)
	@echo "DIR_BUILD     = " $(DIR_BUILD)
	@echo "SOURCES       = " $(SOURCES)
	@echo "OBJECTS       = " $(OBJECTS)
	@echo "FILE_ELF      = " $(FILE_ELF)
	@echo "FILE_BIN      = " $(FILE_BIN)
	@echo "FILE_E2I      = " $(FILE_E2I)
	@echo "MAKEFILE_DIR0 = " $(CURDIR)
	@echo "MAKEFILE_DIR1 = " $(lastword $(dir $(MAKEFILE_LIST)))

help:
	@echo "Running target" $@
	@echo "make                  (compile)"
	@echo "make flash            (compile, write_flash - address: 0)"
#	@echo "make flash_directboot (compile, objcopy, write_flash - directboot)"
	@echo "make flash_partboot   (compile, objcopy, write_flash - bootloader, partitions)"
	@echo "make load_ram         (compile, elf2image, load_ram)"
	@echo "make image_info       (image_info)"
	@echo "make dump             ($(OBJDUMP))"
	@echo "make readelf          ($(READELF))"
	@echo "make chip_id          (chip_id)"
	@echo "make reset            (reset/reboot $(BMV_CHIP))"
	@echo "make clean            (clean)"
	@echo "make show_vars        (show defined variables)"


.PHONY: all load_ram flash flash_partboot reset chip_id image_info clean dump readelf show_vars help
