#ifndef RFID_H
#define RFID_H

#include "main.h"

void rfid_delay(uint16_t milliseconds);
uint8_t rfid_get_response(uint8_t command);
void rfid_send_command(uint8_t *command, uint16_t length);
void watchdog_reset(void);
void rfid_process_command(byte *param_1);

#endif // RFID_H
