cmake_minimum_required(VERSION 3.16)

# ARM toolchain setup
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR ARM)
set(CMAKE_CROSSCOMPILING TRUE)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_SIZE arm-none-eabi-size)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

project(uhf-rfid C)

# MCU settings
set(MCU cortex-m3)

# Compiler flags
set(CMAKE_C_FLAGS "-mcpu=${MCU} -mthumb -Os -g -Wall -Wextra -std=c99 -ffunction-sections -fdata-sections -nostdlib -ffreestanding")
set(CMAKE_EXE_LINKER_FLAGS "-mcpu=${MCU} -mthumb -Wl,--gc-sections -nostdlib")

# Source files
file(GLOB SOURCES "src/*.c")

# Executable
add_executable(${PROJECT_NAME}.elf ${SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME}.elf PRIVATE src)

# Custom targets for binary and hex files
add_custom_target(${PROJECT_NAME}.bin ALL
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${PROJECT_NAME}.elf> ${PROJECT_NAME}.bin
    DEPENDS ${PROJECT_NAME}.elf)

add_custom_target(${PROJECT_NAME}.hex ALL
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${PROJECT_NAME}.hex
    DEPENDS ${PROJECT_NAME}.elf)

# Print size information
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_SIZE} ${PROJECT_NAME}.elf)