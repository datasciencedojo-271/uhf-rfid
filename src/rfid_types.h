#ifndef RFID_TYPES_H
#define RFID_TYPES_H

#include "main.h"

typedef enum {
    RFID_RESULT_OK,
    RFID_RESULT_INVALID_PARAM,
    RFID_RESULT_ERROR
} rfid_result_t;

typedef struct {
    uint32_t device_id;
    uint32_t device_version;
} rfid_reader_info_t;

typedef struct {
    uint8_t state;
    uint8_t flags;
    uint16_t response_len;
    uint8_t response_buf[256];
    // ... other fields based on analysis
} rfid_data_t;

#endif // RFID_TYPES_H
