#ifndef RFID_H
#define RFID_H

#include "main.h"
#include "rfid_types.h"

extern uint DAT_00003884;
extern uint DAT_00004208;
extern uint DAT_00003e50;

void rfid_delay(uint16_t milliseconds);
uint8_t rfid_get_response(uint8_t command);
void rfid_send_command(uint8_t *command, uint16_t length, ...);
void watchdog_reset(void);
void rfid_process_command(byte *param_1);
rfid_result_t rfid_get_reader_info(rfid_reader_info_t *info);
void rfid_get_freq_hopping(void);
void rfid_set_freq_hopping(byte *param_1);
void rfid_get_antenna_power(void);
void rfid_set_antenna_power(byte param_1);
void rfid_set_gpio(byte *param_1);
void rfid_get_firmware_version(void);
void rfid_inventory(byte param_1, byte param_2, byte param_3);
void rfid_read_tag(byte param_1, byte param_2, byte param_3, byte *param_4);
void rfid_get_work_mode(void);
void rfid_set_work_mode(byte *param_1);
void rfid_get_buzzer_status(void);
void rfid_set_buzzer_status(byte *param_1);
void rfid_stop_inventory(void);
void rfid_get_q_value(void);
void rfid_set_q_value(byte *param_1);
void rfid_get_session_target(void);
void rfid_set_session_target(byte *param_1);
void rfid_get_antenna_config(void);
void rfid_set_antenna_config(byte *param_1);
void rfid_get_baud_rate(void);
void rfid_set_baud_rate(byte *param_1);
void rfid_get_inventory_mode(void);
void rfid_set_inventory_mode(byte *param_1);
uint16_t rfid_read_response(uint8_t *buffer, uint16_t length);
bool rfid_has_data(void);
void rfid_init(void);

void FUN_00003d44(void);
void FUN_000053ec(uint);
void FUN_00005460(uint);
void FUN_00003e00(void);
void FUN_00001d84(uint, int);
void FUN_00004d10(uint);
void FUN_000012b6(uint, byte*);


#endif // RFID_H
