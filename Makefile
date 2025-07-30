#
# Makefile for the RFID reader project
#

#
# Toolchain
#
CC = $(shell which arm-none-eabi-gcc 2>/dev/null || echo gcc)
LD = arm-none-eabi-ld
AR = arm-none-eabi-ar
AS = arm-none-eabi-as
CP = arm-none-eabi-objcopy
OD = arm-none-eabi-objdump

#
# C flags
#
CFLAGS = -Wall -O2 -g -I.

#
# Source files
#
SRCS = src/main.c \
       src/rfid.c \
       src/uart.c \
       src/utils.c \
       src/stubs.c \
       src/string.c \
       src/iwdg.c \
       src/nvic.c \
       src/system.c \
       src/systick.c \
       src/rcc.c \
       src/gpio.c \
       src/wfi.s

#
# Build directory
#
BUILD_DIR = build

#
# Object files
#
OBJS = $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(SRCS))

#
# Executable file
#
EXE = $(BUILD_DIR)/rfid_reader.elf

#
# Default target
#
all: $(BUILD_DIR) $(EXE)

#
# Create build directory
#
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

#
# Link the executable
#
$(EXE): $(OBJS)
	$(CC) -nostdlib -nostartfiles -nodefaultlibs -o $@ $(OBJS)

#
# Compile the source files
#
$(BUILD_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: src/%.s
	$(AS) -o $@ $<

#
# Clean the project
#
clean:
	rm -rf $(BUILD_DIR)
