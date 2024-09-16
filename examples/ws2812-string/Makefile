#
SOURCES_EXTRA = main.c
CFLAGS_EXTRA += -I$(BMV_DIR)/$(BMV_CHIP)/include/

# set defaults
BMV_ESPTOOL ?= esptool
BMV_CHIP    ?= esp32c3
BMV_PORT    ?= /dev/ttyACM0
BMV_CC      ?= riscv64-unknown-elf-gcc
BMV_OBJCOPY ?= riscv64-unknown-elf-objcopy
BMV_OBJDUMP ?= riscv64-unknown-elf-objdump
BMV_READELF ?= riscv64-unknown-elf-readelf

ifndef BMV_DIR
BMV_DIR := $(abspath $(CURDIR)/../..)
$(info BMV_DIR was NOT set - setting default: $(BMV_DIR))
endif

ifeq ($(wildcard $(BMV_DIR)/$(BMV_CHIP)/Makefile),)
$(error Please verify BMV_DIR is exported / set to the root directory of this project.)
endif

include $(BMV_DIR)/$(BMV_CHIP)/Makefile
