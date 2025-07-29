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
CFLAGS = -Wall -O2 -g -mcpu=cortex-m3 -mthumb -I. -nostdlib -ffreestanding

#
# Source files
#
SRCS = src/main.c \
       src/rfid.c \
       src/uart.c \
       src/utils.c

#
# Build directory
#
BUILD_DIR = build

#
# Object files
#
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/rfid.o $(BUILD_DIR)/uart.o $(BUILD_DIR)/utils.o

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
	$(CC) $(CFLAGS) -o $@ $(OBJS)

#
# Compile the source files
#
$(BUILD_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

#
# Clean the project
#
clean:
	rm -rf $(BUILD_DIR)
