#ifndef SYSTICK_H
#define SYSTICK_H

#include "stdint.h"

void systick_init(void);
void systick_delay(uint32_t ms);
void systick_delay_us(uint16_t us);

#endif // SYSTICK_H
