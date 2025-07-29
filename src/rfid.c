#include "rfid.h"
#include "uart.h"
#include "utils.h"
#include "fw.h"

void rfid_delay(uint16_t milliseconds)
{
  // This is a rough delay function. A more accurate delay function
  // should be used in a real application.
  for (uint32_t i = 0; i < (milliseconds * 1000); i++) {
    __asm__("nop");
  }
}

uint8_t rfid_get_response(uint8_t command)
{
  uint8_t response;
  uart_write(&command, 1);
  uart_read(&response, 1);
  return response;
}

void rfid_send_command(uint8_t *command, uint16_t length)
{
  uart_write(command, length);
}

void watchdog_reset(void)
{
  // This is a placeholder for the watchdog reset function.
}

void rfid_get_reader_info(void)
{
    // This function is a placeholder for the refactored code.
}

void rfid_get_freq_hopping(void)
{
    // This function is a placeholder for the refactored code.
}

void rfid_set_freq_hopping(byte *param_1)
{
    // This function is a placeholder for the refactored code.
}

void rfid_get_antenna_power(void)
{
    // This function is a placeholder for the refactored code.
}

void rfid_set_antenna_power(byte param_1)
{
    // This function is a placeholder for the refactored code.
}

void rfid_set_gpio(byte *param_1)
{
    // This function is a placeholder for the refactored code.
}

void rfid_get_firmware_version(void)
{
    // This function is a placeholder for the refactored code.
}

void rfid_inventory(byte param_1, byte param_2, byte param_3)
{
    // This function is a placeholder for the refactored code.
}

void rfid_read_tag(byte param_1, byte param_2, byte param_3, byte *param_4)
{
    // This function is a placeholder for the refactored code.
}

void rfid_get_work_mode(void)
{
    // This function is a placeholder for the refactored code.
}

void rfid_set_work_mode(byte *param_1)
{
    // This function is a placeholder for the refactored code.
}

void rfid_get_buzzer_status(void)
{
    // This function is a placeholder for the refactored code.
}

void rfid_set_buzzer_status(byte *param_1)
{
    // This function is a placeholder for the refactored code.
}

void rfid_stop_inventory(void)
{
    // This function is a placeholder for the refactored code.
}

void rfid_get_q_value(void)
{
    // This function is a placeholder for the refactored code.
}

void rfid_set_q_value(byte *param_1)
{
    // This function is a placeholder for the refactored code.
}

void rfid_get_session_target(void)
{
    // This function is a placeholder for the refactored code.
}

void rfid_set_session_target(byte *param_1)
{
    // This function is a placeholder for the refactored code.
}

void rfid_get_antenna_config(void)
{
    // This function is a placeholder for the refactored code.
}

void rfid_set_antenna_config(byte *param_1)
{
    // This function is a placeholder for the refactored code.
}

void rfid_get_baud_rate(void)
{
    // This function is a placeholder for the refactored code.
}

void rfid_set_baud_rate(byte *param_1)
{
    // This function is a placeholder for the refactored code.
}

void rfid_get_inventory_mode(void)
{
    // This function is a placeholder for the refactored code.
}

void rfid_set_inventory_mode(byte *param_1)
{
    // This function is a placeholder for the refactored code.
}

uint16_t rfid_read_response(uint8_t *buffer, uint16_t length)
{
    // This is a placeholder for the real implementation.
    return 0;
}

bool rfid_has_data(void)
{
    // This is a placeholder for the real implementation.
    return false;
}

void rfid_init(void)
{
    // This is a placeholder for the real implementation.
}

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
    rfid_get_reader_info();
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
