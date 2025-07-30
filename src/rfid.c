#include <stddef.h>
#include "rfid.h"
#include "uart.h"
#include "utils.h"
//#include "fw.h"

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

// Corresponds to FUN_00003cc0 in fw.lst
rfid_result_t rfid_get_reader_info(rfid_reader_info_t *info)
{
    if (info == NULL)
    {
        return RFID_RESULT_INVALID_PARAM;
    }

    // Reverse engineered from FUN_00003cc0
    uint32_t *ptr = (uint32_t *)0x790003A0;
    info->device_id = ptr[0];
    info->device_version = ptr[1];

    return RFID_RESULT_OK;
}

// Corresponds to FUN_00003d44 in fw.lst
void rfid_get_freq_hopping(void)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  rfid_send_command((uint8_t *)0x9204, 2, 4, 0);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  if ((bVar2 == 0x55) && (bVar1 == 0x41)) {
    //FUN_00004264();
  }
  return;
}

// Corresponds to FUN_000049e8 in fw.lst
void rfid_set_freq_hopping(byte *param_1)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  uVar3 = 0;
  bVar2 = *param_1;
  if (*param_1 < 0x3a) {
    bVar1 = *param_1 - 0x30;
  }
  else if (*param_1 < 0x61) {
    bVar1 = *param_1 - 0x37;
  }
  bVar2 = bVar1 * 0x10;
  bVar1 = param_1[1];
  if (bVar1 < 0x3a) {
    bVar1 = bVar1 - 0x30;
  }
  else if (bVar1 < 0x61) {
    bVar1 = bVar1 - 0x37;
  }
  rfid_send_command((uint8_t*)0x9204, 2, 6, bVar2 + bVar1);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  return;
}

// Corresponds to FUN_00003cc0 in fw.lst
void rfid_get_antenna_power(void)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  rfid_send_command((uint8_t *)0x9206, 2, 4, 0);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  if ((bVar2 == 0x55) && (bVar1 == 0x41)) {
    //FUN_00004264();
  }
  return;
}

// Corresponds to FUN_00004928 in fw.lst
void rfid_set_antenna_power(byte param_1)
{
  byte bVar1;
  uint32_t uVar2;

  bVar1 = 0;
  uVar2 = 0;
  if (param_1 < 0x3a) {
    bVar1 = param_1 - 0x30;
  }
  else if (param_1 < 0x61) {
    bVar1 = param_1 - 0x37;
  }
  rfid_send_command((uint8_t*)0x9206, 2, 6, bVar1);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar2,0x24);
  return;
}

// Corresponds to FUN_0000350c in fw.lst
void rfid_set_gpio(byte *param_1)
{
  rfid_send_command((uint8_t *)0x91, 2, param_1[0], param_1[1]);
  rfid_delay(100);
  // ... read response ...
}

// Corresponds to FUN_00003e00 in fw.lst
void rfid_get_firmware_version(void)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  rfid_send_command((uint8_t *)0xa1, 2, 0, 0);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x1c);
  if ((bVar2 == 0x55) && (bVar1 == 0)) {
    //FUN_00004e64();
  }
  return;
}

// Corresponds to FUN_00003fa0 in fw.lst
void rfid_inventory(byte param_1, byte param_2, byte param_3)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  if (param_1 < 0x3a) {
    bVar1 = param_1 - 0x30;
  }
  else if (param_1 < 0x61) {
    bVar1 = param_1 - 0x37;
  }
  bVar2 = bVar1 * 0x10;
  if (param_2 < 0x3a) {
    bVar1 = param_2 - 0x30;
  }
  else if (param_2 < 0x61) {
    bVar1 = param_2 - 0x37;
  }
  bVar2 = bVar2 + bVar1;
  if (param_3 < 0x3a) {
    bVar1 = param_3 - 0x30;
  }
  else if (param_3 < 0x61) {
    bVar1 = param_3 - 0x37;
  }
  rfid_send_command((uint8_t *)0x4152, 2, bVar2,bVar1);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  return;
}

// Corresponds to FUN_00004af0 in fw.lst
void rfid_read_tag(byte param_1, byte param_2, byte param_3, byte *param_4)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;

  if (param_1 < 0x3a) {
    bVar1 = param_1 - 0x30;
  }
  else if (param_1 < 0x61) {
    bVar1 = param_1 - 0x37;
  }
  bVar2 = bVar1 * 0x10;
  if (param_2 < 0x3a) {
    bVar1 = param_2 - 0x30;
  }
  else if (param_2 < 0x61) {
    bVar1 = param_2 - 0x37;
  }
  bVar2 = bVar2 + bVar1;
  if (param_3 < 0x3a) {
    bVar1 = param_3 - 0x30;
  }
  else if (param_3 < 0x61) {
    bVar1 = param_3 - 0x37;
  }

  rfid_send_command((uint8_t *)0x4157, 4, bVar2, bVar1, param_4, 10);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  return;
}

// Corresponds to FUN_00003888 in fw.lst
void rfid_get_work_mode(void)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  rfid_send_command((uint8_t *)0x9208, 2, 4, 6);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  if ((bVar2 == 0x55) && (bVar1 == 0x41)) {
    //FUN_00004264();
  }
  return;
}

// Corresponds to FUN_00004264 in fw.lst
void rfid_set_work_mode(byte *param_1)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  if (*param_1 < 0x3a) {
    bVar1 = *param_1 - 0x30;
  }
  else if (*param_1 < 0x61) {
    bVar1 = *param_1 - 0x37;
  }
  bVar2 = bVar1 * 0x10;
  if (param_1[1] < 0x3a) {
    bVar1 = param_1[1] - 0x30;
  }
  else if (param_1[1] < 0x61) {
    bVar1 = param_1[1] - 0x37;
  }
  bVar2 = bVar2 + bVar1;
  if (param_1[2] < 0x3a) {
    bVar1 = param_1[2] - 0x30;
  }
  else if (param_1[2] < 0x61) {
    bVar1 = param_1[2] - 0x37;
  }
  bVar2 = bVar2 + bVar1;
  if (param_1[3] < 0x3a) {
    bVar1 = param_1[3] - 0x30;
  }
  else if (param_1[3] < 0x61) {
    bVar1 = param_1[3] - 0x37;
  }
  bVar2 = bVar2 + bVar1;
  if (param_1[4] < 0x3a) {
    bVar1 = param_1[4] - 0x30;
  }
  else if (param_1[4] < 0x61) {
    bVar1 = param_1[4] - 0x37;
  }

  rfid_send_command((uint8_t *)0x9208, 3, 10, bVar2, bVar1);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  return;
}

// Corresponds to FUN_00003b00 in fw.lst
void rfid_get_buzzer_status(void)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  rfid_send_command((uint8_t *)0x9208, 2, 4, 2);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  if ((bVar2 == 0x55) && (bVar1 == 0x41)) {
    //FUN_00004264();
  }
  return;
}

// Corresponds to FUN_00004828 in fw.lst
void rfid_set_buzzer_status(byte *param_1)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  if (*param_1 < 0x3a) {
    bVar1 = *param_1 - 0x30;
  }
  else if (*param_1 < 0x61) {
    bVar1 = *param_1 - 0x37;
  }
  bVar2 = bVar1 * 0x10;
  if (param_1[1] < 0x3a) {
    bVar1 = param_1[1] - 0x30;
  }
  else if (param_1[1] < 0x61) {
    bVar1 = param_1[1] - 0x37;
  }
  bVar2 = bVar2 + bVar1;

  rfid_send_command((byte *)0x9208, 2, 6, bVar2);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  return;
}

// Corresponds to FUN_00003a6c in fw.lst
void rfid_stop_inventory(void)
{
  rfid_send_command((byte *)0x5591, 2, 0, 0);
  rfid_delay(100);
  return;
}

// Corresponds to FUN_00003b50 in fw.lst
void rfid_get_q_value(void)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  rfid_send_command((byte *)0x9200, 2, 4, 0);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  if ((bVar2 == 0x55) && (bVar1 == 0x41)) {
    //FUN_00004264();
  }
  return;
}

// Corresponds to FUN_000043d0 in fw.lst
void rfid_set_q_value(byte *param_1)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  if (*param_1 < 0x3a) {
    bVar1 = *param_1 - 0x30;
  }
  else if (*param_1 < 0x61) {
    bVar1 = *param_1 - 0x37;
  }
  bVar2 = bVar1 * 0x10;
  if (param_1[1] < 0x3a) {
    bVar1 = param_1[1] - 0x30;
  }
  else if (param_1[1] < 0x61) {
    bVar1 = param_1[1] - 0x37;
  }
  bVar2 = bVar2 + bVar1;

  rfid_send_command((byte *)0x9200, 2, 6, bVar2);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  return;
}

// Corresponds to FUN_00003984 in fw.lst
void rfid_get_session_target(void)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  rfid_send_command((byte *)0x9202, 2, 4, 0);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  if ((bVar2 == 0x55) && (bVar1 == 0x41)) {
    //FUN_00004264();
  }
  return;
}

// Corresponds to FUN_0000448c in fw.lst
void rfid_set_session_target(byte *param_1)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  if (*param_1 < 0x3a) {
    bVar1 = *param_1 - 0x30;
  }
  else if (*param_1 < 0x61) {
    bVar1 = *param_1 - 0x37;
  }
  bVar2 = bVar1 * 0x10;
  if (param_1[1] < 0x3a) {
    bVar1 = param_1[1] - 0x30;
  }
  else if (param_1[1] < 0x61) {
    bVar1 = param_1[1] - 0x37;
  }
  bVar2 = bVar2 + bVar1;

  rfid_send_command((byte *)0x9202, 2, 8, bVar2);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  return;
}

// Corresponds to FUN_000039e4 in fw.lst
void rfid_get_antenna_config(void)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  rfid_send_command((byte *)0x920e, 2, 4, 0);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  if ((bVar2 == 0x55) && (bVar1 == 0x41)) {
    //FUN_00004264();
  }
  return;
}

// Corresponds to FUN_00004504 in fw.lst
void rfid_set_antenna_config(byte *param_1)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  if (*param_1 < 0x3a) {
    bVar1 = *param_1 - 0x30;
  }
  else if (*param_1 < 0x61) {
    bVar1 = *param_1 - 0x37;
  }
  bVar2 = bVar1 * 0x10;
  if (param_1[1] < 0x3a) {
    bVar1 = param_1[1] - 0x30;
  }
  else if (param_1[1] < 0x61) {
    bVar1 = param_1[1] - 0x37;
  }
  bVar2 = bVar2 + bVar1;

  rfid_send_command((byte *)0x920e, 2, 8, bVar2);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  return;
}

// Corresponds to FUN_00003a24 in fw.lst
void rfid_get_baud_rate(void)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  rfid_send_command((byte *)0x9215, 2, 4, 0);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  if ((bVar2 == 0x55) && (bVar1 == 0x41)) {
    //FUN_00004264();
  }
  return;
}

// Corresponds to FUN_000047c0 in fw.lst
void rfid_set_baud_rate(byte *param_1)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  if (*param_1 < 0x3a) {
    bVar1 = *param_1 - 0x30;
  }
  else if (*param_1 < 0x61) {
    bVar1 = *param_1 - 0x37;
  }
  bVar2 = bVar1 * 0x10;
  if (param_1[1] < 0x3a) {
    bVar1 = param_1[1] - 0x30;
  }
  else if (param_1[1] < 0x61) {
    bVar1 = param_1[1] - 0x37;
  }
  bVar2 = bVar2 + bVar1;

  rfid_send_command((byte *)0x9215, 2, 7, bVar2);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  return;
}

// Corresponds to FUN_00003be0 in fw.lst
void rfid_get_inventory_mode(void)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  rfid_send_command((byte *)0xa4, 2, 2, 0);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
  if ((bVar2 == 0x55) && (bVar1 == 0x41)) {
    //FUN_00004264();
  }
  return;
}

// Corresponds to FUN_000046a4 in fw.lst
void rfid_set_inventory_mode(byte *param_1)
{
  byte bVar1;
  byte bVar2;
  uint32_t uVar3;

  bVar1 = 0;
  bVar2 = 0;
  uVar3 = 0;
  if (*param_1 < 0x3a) {
    bVar1 = *param_1 - 0x30;
  }
  else if (*param_1 < 0x61) {
    bVar1 = *param_1 - 0x37;
  }
  bVar2 = bVar1 * 0x10;
  if (param_1[1] < 0x3a) {
    bVar1 = param_1[1] - 0x30;
  }
  else if (param_1[1] < 0x61) {
    bVar1 = param_1[1] - 0x37;
  }
  bVar2 = bVar2 + bVar1;

  rfid_send_command((byte *)0xa4, 2, 0x13, bVar2);
  rfid_delay(100);
  rfid_read_response((byte *)&uVar3,0x24);
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

// Corresponds to FUN_00005a44 in fw.lst
void rfid_init(void)
{
  uart_init();
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
