#
# Makefile for the RFID reader project
#

#
# Toolchain
#
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
AR = arm-none-eabi-ar
AS = arm-none-eabi-as
CP = arm-none-eabi-objcopy
OD = arm-none-eabi-objdump

#
# C flags
#
CFLAGS = -Wall -O2 -g -mcpu=cortex-m3 -mthumb -I.

#
# Source files
#
SRCS = src/main.c \
       src/rfid.c \
       src/uart.c \
       src/utils.c \
       fw.c \
       syscalls.c

#
# Object files
#
OBJS = $(SRCS:.c=.o)

#
# Executable file
#
EXE = rfid_reader.elf

#
# Default target
#
all: $(EXE)

#
# Link the executable
#
$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -T stm32f103.ld -o $@ $(OBJS)

#
# Compile the source files
#
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

#
# Clean the project
#
clean:
	rm -f $(OBJS) $(EXE)
