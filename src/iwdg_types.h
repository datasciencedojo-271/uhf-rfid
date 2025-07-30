#ifndef IWDG_TYPES_H
#define IWDG_TYPES_H

#include <stdint.h>

typedef struct {
    volatile uint32_t KR;
    volatile uint32_t PR;
    volatile uint32_t RLR;
    volatile uint32_t SR;
} IWDG_TypeDef;

#endif // IWDG_TYPES_H
