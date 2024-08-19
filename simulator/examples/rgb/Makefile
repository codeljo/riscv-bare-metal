CC = clang
CFLAGS  = -Wall -Wextra --target=riscv32 -march=rv32i -mabi=ilp32 -nostdlib -O
LDFLAGS = -Wl,--Ttext=0x200,--entry=_start

OBJDUMP = llvm-objdump
READELF = readelf

DIR_SRC   = ./src/
DIR_BUILD = ./build/

SOURCES = $(DIR_SRC)/rgb.S
OBJECTS = $(DIR_BUILD)/rgb.o

FILE_ELF = $(DIR_BUILD)/rgb.elf

all: $(FILE_ELF)

$(FILE_ELF): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(DIR_BUILD)%.o : $(DIR_SRC)%.S
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(FILE_ELF)

readelf:
	$(READELF) -a $(FILE_ELF)

dump:
	@echo "Running target" $@
	$(OBJDUMP) --all-headers $(FILE_ELF)

.PHONY: all clean readelf dump help
