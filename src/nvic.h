#ifndef NVIC_H
#define NVIC_H

#include <stdint.h>

void nvic_set_priority(uint8_t irqn, uint8_t priority);
uint32_t nvic_check_pending(uint8_t irqn);

#endif // NVIC_H
