#ifndef SYSTICK_TYPES_H
#define SYSTICK_TYPES_H

#include "stdint.h"

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile uint32_t CALIB;
} SysTick_Type;

#endif // SYSTICK_TYPES_H
