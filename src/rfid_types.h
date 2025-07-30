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

#endif // RFID_TYPES_H
