#ifndef NVIC_TYPES_H
#define NVIC_TYPES_H

#include "stdint.h"

typedef struct {
    volatile uint32_t ISER[8];
    uint32_t RESERVED0[24];
    volatile uint32_t ICER[8];
    uint32_t RESERVED1[24];
    volatile uint32_t ISPR[8];
    uint32_t RESERVED2[24];
    volatile uint32_t ICPR[8];
    uint32_t RESERVED3[24];
    volatile uint32_t IABR[8];
    uint32_t RESERVED4[56];
    volatile uint8_t IP[240];
    uint32_t RESERVED5[644];
    volatile uint32_t STIR;
} NVIC_Type;

#endif // NVIC_TYPES_H
