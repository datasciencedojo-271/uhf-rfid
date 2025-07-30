#include "nvic.h"
#include "memmap.h"

void nvic_set_priority(uint8_t irqn, uint8_t priority) {
    NVIC->IP[irqn] = priority;
}

uint32_t nvic_check_pending(uint8_t irqn) {
    return NVIC->ISPR[irqn / 32] & (1 << (irqn % 32));
}
