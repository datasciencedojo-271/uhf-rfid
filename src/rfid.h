#ifndef RFID_H
#define RFID_H

#include "main.h"
#include "rfid_types.h"

// Corresponds to DAT_00003884 in fw.lst
extern uint DAT_00003884;
// Corresponds to DAT_00004208 in fw.lst
extern uint DAT_00004208;
// Corresponds to DAT_00003e50 in fw.lst
extern uint DAT_00003e50;

// Corresponds to FUN_000004f8 in a simplified form
void rfid_delay(uint16_t milliseconds);
// This function is a helper and does not directly correspond to a function in fw.lst
uint8_t rfid_get_response(uint8_t command);
// This function is a helper and does not directly correspond to a function in fw.lst
void rfid_send_command(uint8_t *command, uint16_t length, ...);
// Corresponds to FUN_00005a44 in a simplified form
void watchdog_reset(void);
// Corresponds to FUN_00003614 in fw.lst
void rfid_process_command(byte *param_1);
// Corresponds to FUN_00003cc0 in fw.lst
rfid_result_t rfid_get_reader_info(rfid_reader_info_t *info);
// Corresponds to FUN_00003d44 in fw.lst
void rfid_get_freq_hopping(void);
// Corresponds to FUN_000049e8 in fw.lst
void rfid_set_freq_hopping(byte *param_1);
// Corresponds to FUN_00003cc0 in fw.lst
void rfid_get_antenna_power(void);
// Corresponds to FUN_00004928 in fw.lst
void rfid_set_antenna_power(byte param_1);
// Corresponds to FUN_0000350c in fw.lst
void rfid_set_gpio(byte *param_1);
// Corresponds to FUN_00003e00 in fw.lst
void rfid_get_firmware_version(void);
// Corresponds to FUN_00003fa0 in fw.lst
void rfid_inventory(byte param_1, byte param_2, byte param_3);
// Corresponds to FUN_00004af0 in fw.lst
void rfid_read_tag(byte param_1, byte param_2, byte param_3, byte *param_4);
// Corresponds to FUN_00003888 in fw.lst
void rfid_get_work_mode(void);
// Corresponds to FUN_00004264 in fw.lst
void rfid_set_work_mode(byte *param_1);
// Corresponds to FUN_00003b00 in fw.lst
void rfid_get_buzzer_status(void);
// Corresponds to FUN_00004828 in fw.lst
void rfid_set_buzzer_status(byte *param_1);
// Corresponds to FUN_00003a6c in fw.lst
void rfid_stop_inventory(void);
// Corresponds to FUN_00003b50 in fw.lst
void rfid_get_q_value(void);
// Corresponds to FUN_000043d0 in fw.lst
void rfid_set_q_value(byte *param_1);
// Corresponds to FUN_00003984 in fw.lst
void rfid_get_session_target(void);
// Corresponds to FUN_0000448c in fw.lst
void rfid_set_session_target(byte *param_1);
// Corresponds to FUN_000039e4 in fw.lst
void rfid_get_antenna_config(void);
// Corresponds to FUN_00004504 in fw.lst
void rfid_set_antenna_config(byte *param_1);
// Corresponds to FUN_00003a24 in fw.lst
void rfid_get_baud_rate(void);
// Corresponds to FUN_000047c0 in fw.lst
void rfid_set_baud_rate(byte *param_1);
// Corresponds to FUN_00003be0 in fw.lst
void rfid_get_inventory_mode(void);
// Corresponds to FUN_000046a4 in fw.lst
void rfid_set_inventory_mode(byte *param_1);
// This function is a helper and does not directly correspond to a function in fw.lst
uint16_t rfid_read_response(uint8_t *buffer, uint16_t length);
// This function is a helper and does not directly correspond to a function in fw.lst
bool rfid_has_data(void);
// Corresponds to FUN_00005a44 in fw.lst
void rfid_init(void);

// Corresponds to FUN_00003d44 in fw.lst
void FUN_00003d44(void);
// Corresponds to FUN_000053ec in fw.lst
void FUN_000053ec(uint);
// Corresponds to FUN_00005460 in fw.lst
void FUN_00005460(uint);
// Corresponds to FUN_00003e00 in fw.lst
void FUN_00003e00(void);
// Corresponds to FUN_00001d84 in fw.lst
void FUN_00001d84(uint, int);
// Corresponds to FUN_00004d10 in fw.lst
void FUN_00004d10(uint);
// Corresponds to FUN_000012b6 in fw.lst
void FUN_000012b6(uint, byte*);


#endif // RFID_H
