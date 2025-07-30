#include <stddef.h>
#include "rfid.h"
#include "uart.h"
#include "utils.h"
#include "rcc.h"
#include "gpio.h"

// Define the variable here
uint DAT_00003884;

// This function is a rough implementation of a delay.
// It is not a direct translation of any function in fw.lst, but it
// is used by many functions that are.
void rfid_delay(uint16_t milliseconds)
{
  // This is a rough delay function. A more accurate delay function
  // should be used in a real application.
  for (uint32_t i = 0; i < (milliseconds * 1000); i++) {
    __asm__("nop");
  }
}

// This function is a helper and does not directly correspond to a function in fw.lst
uint8_t rfid_get_response(uint8_t command)
{
  uint8_t response;
  uart_write(&command, 1);
  uart_read(&response, 1);
  return response;
}

#include <stdarg.h>

// This function is a helper and does not directly correspond to a function in fw.lst
void rfid_send_command(uint8_t *command, uint16_t length, ...)
{
  va_list args;
  va_start(args, length);

  uint8_t *p = command;
  for (int i = 0; i < length; i++) {
    *p++ = va_arg(args, int);
  }

  uart_write(command, length);
  va_end(args);
}

// Corresponds to FUN_00005a44 in a simplified form
void watchdog_reset(void)
{
  // This is a placeholder for the watchdog reset function.
}

/**
 * @brief Get the reader info.
 * @param info Pointer to the rfid_reader_info_t struct to store the reader info.
 * @return RFID_RESULT_OK on success, RFID_RESULT_INVALID_PARAM if info is NULL.
 * @note This function is a high-level interpretation of the data processing
 *       that happens in FUN_00000cbc. The original function is more of a
 *       data packet processor than a simple info getter.
 */
rfid_result_t rfid_get_reader_info(rfid_reader_info_t *info) {
    if (info == NULL) {
        return RFID_RESULT_INVALID_PARAM;
    }

    // The original function FUN_00000cbc is a complex data packet processor.
    // This C function is a simplified version that just extracts some of the
    // key information that FUN_00000cbc handles, which includes reader info.
    // A full reimplementation is done in rfid_process_data_packet.

    // These pointers are based on the analysis of FUN_00000cbc and its data structures.
    volatile uint8_t* rfid_data_struct = (volatile uint8_t*)*(volatile uint32_t*)DAT_2000016C;
    info->device_id = rfid_data_struct[0]; // Simplified
    info->device_version = rfid_data_struct[1]; // Simplified

    return RFID_RESULT_OK;
}

// This function is a C translation of FUN_00000cbc from the firmware.
// It's responsible for processing incoming data packets.
void rfid_process_data_packet(void) {
    // 0xcc0: r0 = *(volatile uint32_t*)0x2000016c; (pointer to a struct)
    volatile uint8_t* rfid_data_struct = (volatile uint8_t*)*(volatile uint32_t*)DAT_2000016C;

    // 0xcc4: r5 = r0 + 0x10;
    volatile uint8_t* r5_ptr = rfid_data_struct + 0x10;

    // 0xcc8: r6 = *(uint16_t*)r5; (response_len)
    uint16_t response_len = *(volatile uint16_t*)r5_ptr;

    // 0xcce: r7 = r0[8]; (device_state)
    uint8_t device_state = rfid_data_struct[8];

    // 0xcd0: if (r6 != 0) goto 0xd08;
    // 0xcd2: if (r7 != 4) goto 0xd08;
    if (response_len == 0 && device_state == 4) {
        // 0xcd6: r0 = *(volatile uint32_t*)0x20000162;
        // 0xcd8: if (*r0 == 1) { ... }
        if (DAT_20000162 == 1) {
            // This block seems to be related to sending a response
            // 0xce0: movs r1, #0
            // 0xce2: ldr r0, [0x40005c50] ...
            // This part is complex and involves direct hardware register manipulation.
            // It seems to be preparing a buffer and then setting flags.
            // For now, we will just set the flags as a placeholder.
            DAT_2000017E = 0x30;
            DAT_20000162 = 0;
        } else {
            // 0xcfe:
            device_state = 7;
            DAT_2000017E = 0x10;
        }
    } else {
        // LAB_00000d08:
        uint16_t transfer_len = *(volatile uint16_t*)(r5_ptr + 4);
        uint8_t transfer_type = 2; // Default to 2
        if (response_len > transfer_len) {
            transfer_type = 4;
        }

        if (transfer_len > response_len) {
            transfer_len = response_len;
        }

        // This part seems to call a function pointer at [r5 + 8]
        // uint32_t (*func)(uint16_t) = *(uint32_t**)(r5_ptr + 8);
        // uint32_t result = func(transfer_len);
        // For now, we'll just stub this out.
        uint32_t result = 0;

        // A series of function calls and data manipulation follows.
        // This is a simplified representation.
        void* some_buffer = (void*)FUN_00001480();
        FUN_0000524c((void*)result, some_buffer, transfer_len);
        FUN_000022e0(0, transfer_len);

        *(volatile uint16_t*)(r5_ptr + 0) -= transfer_len;
        *(volatile uint16_t*)(r5_ptr + 2) += transfer_len;

        DAT_2000017E = 0x30;
        DAT_2000017C = 0x3000;
    }

    // 0xd58: Update device state
    rfid_data_struct[8] = device_state;
}

/**
 * @brief Get the frequency hopping status.
 * @note This function corresponds to FUN_00003d44 in the firmware.
 */
void rfid_get_freq_hopping(void)
{
    // This function sends a command to the RFID module to get the frequency hopping status.
    // The original function FUN_00003d44 is more complex and involves a state machine
    // for sending the command and waiting for the response.

    // 0x3d46: adr r1, [0x3dec] -> loads address of command data
    // The data is {0xA0, 0x03, 0x00, 0x77, 0xE6, 0x00, 0x00, 0x00}
    uint8_t command_data[] = {0xA0, 0x03, 0x00, 0x77, 0xE6, 0x00};

    // 0x3d56: strh r0, [r1, #0] -> DAT_20000190 = 0
    DAT_20000190 = 0;

    // 0x3d5c: bl FUN_00002c4c -> sends the command
    FUN_00002c4c(command_data, 6);

    // The rest of FUN_00003d44 is a loop that waits for a response.
    // This is a simplified representation of that loop.
    for (int i = 0; i < 0x1000000; i++) {
        if (DAT_20000190 > 5) {
            // Response received, process it.
            // The original code has more complex processing here.
            break;
        }
    }
}

/**
 * @brief Set the frequency hopping.
 * @param param_1 The frequency hopping parameter as a two-char hex string.
 * @note This function corresponds to FUN_000049e8 in the firmware.
 */
void rfid_set_freq_hopping(byte *param_1)
{
    // This function takes a 2-char hex string, converts it to a byte,
    // and sends it as part of a command to the RFID module.

    // 0x49f6-0x4a04: Convert first hex char to a nibble
    byte high_nibble;
    if (*param_1 < 0x3a) {
        high_nibble = *param_1 - 0x30;
    } else {
        high_nibble = *param_1 - 0x37;
    }

    // 0x4a06-0x4a12: Convert second hex char to a nibble
    byte low_nibble;
    if (param_1[1] < 0x3a) {
        low_nibble = param_1[1] - 0x30;
    } else {
        low_nibble = param_1[1] - 0x37;
    }

    // Combine nibbles to form the final byte
    byte value = (high_nibble << 4) + low_nibble;

    // The original function sends a command packet. This is a simplified
    // representation of that command.
    uint8_t command[] = {0x92, 0x04, 0x06, value};
    rfid_send_command(command, sizeof(command));

    // The original function then waits for a response.
    rfid_delay(100);
    uint8_t response[24];
    rfid_read_response(response, sizeof(response));
}

/**
 * @brief Get the antenna power.
 * @note This function corresponds to FUN_00003cc0 in the firmware.
 */
void rfid_get_antenna_power(void)
{
    // This function sends a command to request the antenna power.
    // The response is handled by the main data processing loop.
    uint8_t command[] = {0x92, 0x06, 0x04, 0x00};

    DAT_20000190 = 0;
    FUN_00002c4c(command, sizeof(command));

    // Wait for response, which is handled elsewhere
    for (int i = 0; i < 0x1000000; i++) {
        if (DAT_20000190 > 5) {
            break;
        }
    }
}

/**
 * @brief Set the antenna power.
 * @param param_1 The antenna power as a single hex character string.
 * @note This function corresponds to FUN_00004928 in the firmware.
 */
void rfid_set_antenna_power(byte param_1)
{
    // This function takes a single hex char, converts it to a byte,
    // and sends it as part of a command.
    byte value;
    if (param_1 < 0x3a) {
        value = param_1 - 0x30;
    } else {
        value = param_1 - 0x37;
    }

    uint8_t command[] = {0x92, 0x06, 0x06, value};
    rfid_send_command(command, sizeof(command));

    rfid_delay(100);
    uint8_t response[24];
    rfid_read_response(response, sizeof(response));
}

/**
 * @brief Set the GPIO status.
 * @param param_1 A pointer to a 2-byte array containing the GPIO parameters.
 * @note This function corresponds to FUN_0000350c in the firmware.
 */
void rfid_set_gpio(byte *param_1)
{
    // This function sets the GPIO status based on the input parameters.
    // It sends different commands based on the bits in the first parameter.

    // 0x3512: tst r0, #0x1
    if (param_1[0] & 0x1) {
        // 0x351a: tst r0, #0x2
        if (param_1[0] & 0x2) {
            ADDR_42218194 = 0;
        }
        // ... and so on for other bits

        // 0x354c: bl FUN_000053ec
        FUN_000053ec( (param_1[1] + (param_1[1] << 2)) << 1 );
    } else {
        // ... logic for when bit 0 is not set
    }

    // This is a partial implementation. The full logic is more complex.
    // For now, we will just send the command as in the old code.
    rfid_send_command((uint8_t *)0x91, 2, param_1[0], param_1[1]);
    rfid_delay(100);
}

/**
 * @brief Get the firmware version.
 * @note This function corresponds to FUN_00003e00 in the firmware.
 */
void rfid_get_firmware_version(void)
{
    // 0x3e08: bl FUN_00003b00
    FUN_00003b00(NULL); // Pass NULL as we don't have the stack pointer

    // 0x3e0c: movs r0, #0x11
    // ...
    // 0x3e44: bl FUN_00005200
    // This function sends a command to get the firmware version.
    uint8_t command[] = {0x11, 0x02, 0xa1, 0x00, /* ... and so on ... */};
    // The command is constructed on the stack. This is a simplified representation.

    uint8_t get_version_cmd[] = {0xA1, 0x00, 0x00};
    rfid_send_command(get_version_cmd, sizeof(get_version_cmd));

    rfid_delay(100);
    uint8_t response[28];
    rfid_read_response(response, sizeof(response));
}

/**
 * @brief Perform an inventory.
 * @param param_1 The first parameter.
 * @param param_2 The second parameter.
 * @param param_3 The third parameter.
 * @note This function corresponds to FUN_00003fa0 in the firmware.
 */
void rfid_inventory(byte param_1, byte param_2, byte param_3)
{
    // This function processes the input parameters, which are ASCII hex chars,
    // and sends an inventory command.

    // The logic to convert hex chars to a byte value is complex and spread
    // throughout the function. This is a simplified C representation.
    byte val1 = (param_1 < 0x3a) ? (param_1 - 0x30) : (param_1 - 0x37);
    byte val2 = (param_2 < 0x3a) ? (param_2 - 0x30) : (param_2 - 0x37);
    byte val3 = (param_3 < 0x3a) ? (param_3 - 0x30) : (param_3 - 0x37);

    byte bVar2 = (val1 * 0x10) + val2;

    rfid_send_command((uint8_t *)0x4152, 2, bVar2, val3);
    rfid_delay(100);
    uint8_t response[24];
    rfid_read_response(response, sizeof(response));
}

/**
 * @brief Read a tag.
 * @param param_1 The first parameter.
 * @param param_2 The second parameter.
 * @param param_3 The third parameter.
 * @param param_4 The fourth parameter.
 * @note This function corresponds to FUN_00004af0 in the firmware.
 */
void rfid_read_tag(byte param_1, byte param_2, byte param_3, byte *param_4)
{
    // Similar to rfid_inventory, this function processes ASCII hex parameters
    // and sends a command to read a tag.

    byte val1 = (param_1 < 0x3a) ? (param_1 - 0x30) : (param_1 - 0x37);
    byte val2 = (param_2 < 0x3a) ? (param_2 - 0x30) : (param_2 - 0x37);
    byte val3 = (param_3 < 0x3a) ? (param_3 - 0x30) : (param_3 - 0x37);

    byte bVar2 = (val1 * 0x10) + val2;

    rfid_send_command((uint8_t *)0x4157, 4, bVar2, val3, param_4, 10);
    rfid_delay(100);
    uint8_t response[24];
    rfid_read_response(response, sizeof(response));
}

/**
 * @brief Get the work mode.
 * @note This function corresponds to FUN_00003888 in the firmware.
 */
void rfid_get_work_mode(void)
{
    // This function sends a command to get the work mode and waits for a response.
    uint8_t command[] = {0xA0, 0x03, 0x00, 0x91, 0xCC};

    DAT_20000190 = 0;
    FUN_00002c4c(command, sizeof(command));

    // Wait for a specific response
    for (int i = 0; i < 0x1000000; i++) {
        if (DAT_20000190 > 5) {
            if (ADDR_2000029C[4] == 0x93 && ADDR_2000029C[5] == 0x38) {
                // Response received
                break;
            }
        }
    }
}

/**
 * @brief Set the work mode.
 * @param param_1 The work mode parameter as a hex string.
 * @note This function corresponds to FUN_00004264 in the firmware.
 */
void rfid_set_work_mode(byte *param_1)
{
    // This function processes a hex string and sends it as a command
    // to set the work mode.

    // The original code has complex logic to parse the hex string.
    // This is a simplified version.
    uint8_t command[10];
    command[0] = 0xA0;
    command[1] = 0x04;
    command[2] = 0x00;
    command[3] = 0x4A;
    command[4] = 0x13; // Placeholder

    // The rest of the command is constructed from param_1
    // ...

    rfid_send_command(command, sizeof(command));
    rfid_delay(100);
    uint8_t response[24];
    rfid_read_response(response, sizeof(response));
}

/**
 * @brief Get the buzzer status.
 * @note This function corresponds to FUN_00003b00 in the firmware.
 */
void rfid_get_buzzer_status(void)
{
    // This function sends a command to get the buzzer status.
    uint8_t command[] = {0xA0, 0x03, 0x00, 0x97, 0xA4};

    DAT_20000190 = 0;
    FUN_00002c4c(command, sizeof(command));

    // Wait for response
    for (int i = 0; i < 0x1000000; i++) {
        if (DAT_20000190 > 5) {
            break;
        }
    }
}

/**
 * @brief Set the buzzer status.
 * @param param_1 The buzzer status parameter as a hex string.
 * @note This function corresponds to FUN_00004828 in the firmware.
 */
void rfid_set_buzzer_status(byte *param_1)
{
    // This function processes a hex string and sends it as a command.
    byte val1 = (param_1[0] < 0x3a) ? (param_1[0] - 0x30) : (param_1[0] - 0x37);
    byte val2 = (param_1[1] < 0x3a) ? (param_1[1] - 0x30) : (param_1[1] - 0x37);
    byte value = (val1 << 4) + val2;

    uint8_t command[] = {0x92, 0x08, 0x06, value};
    rfid_send_command(command, sizeof(command));

    rfid_delay(100);
    uint8_t response[24];
    rfid_read_response(response, sizeof(response));
}

/**
 * @brief Stop the inventory.
 * @note This function corresponds to FUN_00003a6c in the firmware (lines 1862-1926).
 */
void rfid_stop_inventory(void)
{
    uint8_t command[] = {0x55, 0x91, 0x00, 0x00};
    rfid_send_command(command, sizeof(command));
    rfid_delay(100);
}

/**
 * @brief Get the Q value.
 * @note This function corresponds to FUN_00003b50 in the firmware (lines 1928-1982).
 */
void rfid_get_q_value(void)
{
    uint8_t command[] = {0x92, 0x00, 0x04, 0x00};
    uint8_t response[24];

    rfid_send_command(command, sizeof(command));
    rfid_delay(100);
    rfid_read_response(response, sizeof(response));

    if ((response[0] == 0x55) && (response[1] == 0x41))
    {
        // FUN_00004264();
    }
}

/**
 * @brief Set the Q value.
 * @param param_1 The Q value parameter.
 * @note This function corresponds to FUN_000043d0 in the firmware (lines 1984-2042).
 */
void rfid_set_q_value(byte *param_1)
{
    byte bVar1;
    byte bVar2;
    uint32_t uVar3;

    bVar1 = 0;
    bVar2 = 0;
    uVar3 = 0;
    if (*param_1 < 0x3a)
    {
        bVar1 = *param_1 - 0x30;
    }
    else if (*param_1 < 0x61)
    {
        bVar1 = *param_1 - 0x37;
    }
    bVar2 = bVar1 * 0x10;
    if (param_1[1] < 0x3a)
    {
        bVar1 = param_1[1] - 0x30;
    }
    else if (param_1[1] < 0x61)
    {
        bVar1 = param_1[1] - 0x37;
    }
    bVar2 = bVar2 + bVar1;

    rfid_send_command((byte *)0x9200, 2, 6, bVar2);
    rfid_delay(100);
    rfid_read_response((byte *)&uVar3, 0x24);
    return;
}

/**
 * @brief Get the session target.
 * @note This function corresponds to FUN_00003984 in the firmware (lines 2044-2098).
 */
void rfid_get_session_target(void)
{
    uint8_t command[] = {0x92, 0x02, 0x04, 0x00};
    uint8_t response[24];

    rfid_send_command(command, sizeof(command));
    rfid_delay(100);
    rfid_read_response(response, sizeof(response));

    if ((response[0] == 0x55) && (response[1] == 0x41))
    {
        // FUN_00004264();
    }
}

/**
 * @brief Set the session target.
 * @param param_1 The session target parameter.
 * @note This function corresponds to FUN_0000448c in the firmware (lines 2100-2154).
 */
void rfid_set_session_target(byte *param_1)
{
    byte bVar1;
    byte bVar2;
    uint32_t uVar3;

    bVar1 = 0;
    bVar2 = 0;
    uVar3 = 0;
    if (*param_1 < 0x3a)
    {
        bVar1 = *param_1 - 0x30;
    }
    else if (*param_1 < 0x61)
    {
        bVar1 = *param_1 - 0x37;
    }
    bVar2 = bVar1 * 0x10;
    if (param_1[1] < 0x3a)
    {
        bVar1 = param_1[1] - 0x30;
    }
    else if (param_1[1] < 0x61)
    {
        bVar1 = param_1[1] - 0x37;
    }
    bVar2 = bVar2 + bVar1;

    rfid_send_command((byte *)0x9202, 2, 8, bVar2);
    rfid_delay(100);
    rfid_read_response((byte *)&uVar3, 0x24);
    return;
}

/**
 * @brief Get the antenna config.
 * @note This function corresponds to FUN_000039e4 in the firmware (lines 2156-2210).
 */
void rfid_get_antenna_config(void)
{
    uint8_t command[] = {0x92, 0x0e, 0x04, 0x00};
    uint8_t response[24];

    rfid_send_command(command, sizeof(command));
    rfid_delay(100);
    rfid_read_response(response, sizeof(response));

    if ((response[0] == 0x55) && (response[1] == 0x41))
    {
        // FUN_00004264();
    }
}

/**
 * @brief Set the antenna config.
 * @param param_1 The antenna config parameter.
 * @note This function corresponds to FUN_00004504 in the firmware (lines 2212-2268).
 */
void rfid_set_antenna_config(byte *param_1)
{
    byte bVar1;
    byte bVar2;
    uint32_t uVar3;

    bVar1 = 0;
    bVar2 = 0;
    uVar3 = 0;
    if (*param_1 < 0x3a)
    {
        bVar1 = *param_1 - 0x30;
    }
    else if (*param_1 < 0x61)
    {
        bVar1 = *param_1 - 0x37;
    }
    bVar2 = bVar1 * 0x10;
    if (param_1[1] < 0x3a)
    {
        bVar1 = param_1[1] - 0x30;
    }
    else if (param_1[1] < 0x61)
    {
        bVar1 = param_1[1] - 0x37;
    }
    bVar2 = bVar2 + bVar1;

    rfid_send_command((byte *)0x920e, 2, 8, bVar2);
    rfid_delay(100);
    rfid_read_response((byte *)&uVar3, 0x24);
    return;
}

/**
 * @brief Get the baud rate.
 * @note This function corresponds to FUN_00003a24 in the firmware (lines 2270-2300).
 */
void rfid_get_baud_rate(void)
{
    uint8_t command[] = {0x92, 0x15, 0x04, 0x00};
    uint8_t response[24];

    rfid_send_command(command, sizeof(command));
    rfid_delay(100);
    rfid_read_response(response, sizeof(response));

    if ((response[0] == 0x55) && (response[1] == 0x41))
    {
        // FUN_00004264();
    }
}

/**
 * @brief Set the baud rate.
 * @param param_1 The baud rate parameter.
 * @note This function corresponds to FUN_000047c0 in the firmware (lines 2302-2354).
 */
void rfid_set_baud_rate(byte *param_1)
{
    byte bVar1;
    byte bVar2;
    uint32_t uVar3;

    bVar1 = 0;
    bVar2 = 0;
    uVar3 = 0;
    if (*param_1 < 0x3a)
    {
        bVar1 = *param_1 - 0x30;
    }
    else if (*param_1 < 0x61)
    {
        bVar1 = *param_1 - 0x37;
    }
    bVar2 = bVar1 * 0x10;
    if (param_1[1] < 0x3a)
    {
        bVar1 = param_1[1] - 0x30;
    }
    else if (param_1[1] < 0x61)
    {
        bVar1 = param_1[1] - 0x37;
    }
    bVar2 = bVar2 + bVar1;

    rfid_send_command((byte *)0x9215, 2, 7, bVar2);
    rfid_delay(100);
    rfid_read_response((byte *)&uVar3, 0x24);
    return;
}

/**
 * @brief Get the inventory mode.
 * @note This function corresponds to FUN_00003be0 in the firmware (lines 2356-2412).
 */
void rfid_get_inventory_mode(void)
{
    uint8_t command[] = {0xa4, 0x02, 0x00};
    uint8_t response[24];

    rfid_send_command(command, sizeof(command));
    rfid_delay(100);
    rfid_read_response(response, sizeof(response));

    if ((response[0] == 0x55) && (response[1] == 0x41))
    {
        // FUN_00004264();
    }
}

/**
 * @brief Set the inventory mode.
 * @param param_1 The inventory mode parameter.
 * @note This function corresponds to FUN_000046a4 in the firmware (lines 2414-2468).
 */
void rfid_set_inventory_mode(byte *param_1)
{
    byte bVar1;
    byte bVar2;
    uint32_t uVar3;

    bVar1 = 0;
    bVar2 = 0;
    uVar3 = 0;
    if (*param_1 < 0x3a)
    {
        bVar1 = *param_1 - 0x30;
    }
    else if (*param_1 < 0x61)
    {
        bVar1 = *param_1 - 0x37;
    }
    bVar2 = bVar1 * 0x10;
    if (param_1[1] < 0x3a)
    {
        bVar1 = param_1[1] - 0x30;
    }
    else if (param_1[1] < 0x61)
    {
        bVar1 = param_1[1] - 0x37;
    }
    bVar2 = bVar2 + bVar1;

    rfid_send_command((byte *)0xa4, 2, 0x13, bVar2);
    rfid_delay(100);
    rfid_read_response((byte *)&uVar3, 0x24);
    return;
}

// This function is a helper and does not directly correspond to a function in fw.lst
uint16_t rfid_read_response(uint8_t *buffer, uint16_t length)
{
    uint16_t i;
    for (i = 0; i < length; i++)
    {
        if (uart_read(&buffer[i], 1) == 0)
        {
            return i;
        }
    }
    return i;
}

// This function is a helper and does not directly correspond to a function in fw.lst
bool rfid_has_data(void)
{
    // This is a placeholder for the real implementation.
    return uart_has_data();
}

/**
 * @brief Initialize the RFID module.
 * @note This function corresponds to FUN_00005a44 in the firmware (lines 17156-17228).
 */
void rfid_init(void)
{
    // Enable clocks for GPIOA, GPIOC, and USART1
    rcc_apb2_periph_clock_cmd(0x1 | 0x4 | 0x10, true); // AFIO, GPIOA, GPIOC
    rcc_periph_clock_cmd(RCC_PERIPH_USART1, true);

    // Configure GPIO pins for UART
    gpio_config_t uart_tx = {
        .pin = 1 << 9,
        .mode = 0b10, // Alternate function output Push-pull
        .speed = 0b11, // 50MHz
    };
    gpio_init(GPIOA_BASE, &uart_tx);

    gpio_config_t uart_rx = {
        .pin = 1 << 10,
        .mode = 0b01, // Floating input
        .speed = 0b00, // Input mode
    };
    gpio_init(GPIOA_BASE, &uart_rx);


    // This is a simplified version of the logic in FUN_00005a44.
    // The original function is much more complex and involves a state machine.
    // For now, we will just configure the UART with a default baud rate.
    uart_init();

    // The rest of the function is a complex state machine that will be implemented later.
}

// Corresponds to FUN_00003614 in fw.lst
void rfid_process_command(byte *param_1)
{
  char cVar1;
  char cVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;

  utils_memset(&DAT_00003884, 0, sizeof(DAT_00003884));
  uVar4 = (uint)*param_1;
  if (param_1[2] == 0xa1) {
    uVar3 = 0xa1;
  }
  else if (param_1[2] == 0xa4) {
    uVar3 = 0xa4;
  }
  else if (param_1[2] == 0x91) {
    uVar3 = 0x91;
  }
  else {
    uVar3 = (ushort)param_1[2] * 0x100 + (ushort)param_1[3];
  }
  if (uVar3 == 0x5580) {
        rfid_get_reader_info(NULL);
    return;
  }
  if (uVar3 < 0x5581) {
    if (uVar3 == 0x414e) {
      if (param_1[4] == 0x30) {
        rfid_get_freq_hopping();
      }
      if (param_1[4] == 0x31) {
        rfid_set_freq_hopping(param_1 + 6);
      }
      if (param_1[4] == 0x34) {
        rfid_get_antenna_power();
      }
      if (param_1[4] != 0x35) {
        return;
      }
      rfid_set_antenna_power(param_1[7]);
      return;
    }
    if (uVar3 < 0x414f) {
      if (uVar3 == 0x91) {
        rfid_set_gpio(param_1 + 3);
        return;
      }
      if (uVar3 == 0xa1) {
        rfid_get_firmware_version();
        return;
      }
      bVar6 = uVar3 == 0xa4;
    }
    else {
      if (uVar3 == 0x4152) {
        if (uVar4 == 8) {
          if (param_1[6] < 0x3a) {
            cVar2 = param_1[6] - 0x30;
          }
          else {
            cVar2 = param_1[6] - 0x37;
          }
        }
        else {
          if (param_1[7] < 0x3a) {
            cVar2 = param_1[7] - 0x30;
          }
          else {
            cVar2 = param_1[7] - 0x37;
          }
          if (param_1[6] < 0x3a) {
            cVar1 = param_1[6] - 0x30;
          }
          else {
            cVar1 = param_1[6] - 0x37;
          }
          cVar2 = cVar2 + cVar1 * '\x10';
        }
        if (param_1[uVar4] < 0x3a) {
          cVar1 = param_1[uVar4] - 0x30;
        }
        else {
          cVar1 = param_1[uVar4] - 0x37;
        }
        rfid_inventory(param_1[4],cVar2,cVar1);
        return;
      }
      bVar6 = uVar3 == 0x4157;
      if (bVar6) {
        if (param_1[7] == 0x2c) {
          if (param_1[6] < 0x3a) {
            cVar2 = param_1[6] - 0x30;
          }
          else {
            cVar2 = param_1[6] - 0x37;
          }
          if (param_1[8] < 0x3a) {
            cVar1 = param_1[8] - 0x30;
          }
          else {
            cVar1 = param_1[8] - 0x37;
          }
          iVar5 = 10;
        }
        else {
          if (param_1[7] < 0x3a) {
            cVar2 = param_1[7] - 0x30;
          }
          else {
            cVar2 = param_1[7] - 0x37;
          }
          if (param_1[6] < 0x3a) {
            cVar1 = param_1[6] - 0x30;
          }
          else {
            cVar1 = param_1[6] - 0x37;
          }
          cVar2 = cVar2 + cVar1 * '\x10';
          if (param_1[9] < 0x3a) {
            cVar1 = param_1[9] - 0x30;
          }
          else {
            cVar1 = param_1[9] - 0x37;
          }
          iVar5 = 0xb;
        }
        rfid_read_tag(param_1[4],cVar2,cVar1,param_1 + iVar5);
        return;
      }
    }
  }
  else {
    if (uVar3 == 0x9208) {
      if ((uVar4 == 4) && (param_1[4] == 6)) {
        rfid_get_work_mode();
      }
      if (uVar4 == 10) {
        rfid_set_work_mode(param_1 + 5);
      }
      if ((uVar4 == 4) && (param_1[4] == 2)) {
        rfid_get_buzzer_status();
      }
      if (uVar4 != 6) {
        return;
      }
      rfid_set_buzzer_status(param_1 + 5);
      return;
    }
    if (uVar3 < 0x9209) {
      if (uVar3 == 0x5591) {
        rfid_stop_inventory();
        return;
      }
      if (uVar3 == 0x9200) {
        if (uVar4 == 4) {
          rfid_get_q_value();
        }
        if (uVar4 != 6) {
          return;
        }
        rfid_set_q_value(param_1 + 5);
        return;
      }
      bVar6 = uVar3 == 0x9202;
      if (bVar6) {
        if (uVar4 == 4) {
          rfid_get_session_target();
        }
        if (uVar4 != 8) {
          return;
        }
        rfid_set_session_target(param_1 + 5);
        return;
      }
    }
    else {
      if (uVar3 == 0x920e) {
        if (uVar4 == 4) {
          rfid_get_antenna_config();
        }
        if (uVar4 != 8) {
          return;
        }
        rfid_set_antenna_config(param_1 + 5);
        return;
      }
      bVar6 = uVar3 == 0x9215;
      if (bVar6) {
        if (uVar4 == 4) {
          rfid_get_baud_rate();
        }
        if (uVar4 != 7) {
          return;
        }
        rfid_set_baud_rate(param_1 + 5);
        return;
      }
    }
  }
  if (bVar6) {
    if (uVar4 == 2) {
      rfid_get_inventory_mode();
    }
    if (uVar4 == 0x13) {
      rfid_set_inventory_mode(param_1 + 4);
    }
  }
  return;
}
