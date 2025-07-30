#ifndef RCC_H
#define RCC_H

#include "stdint.h"

#define RCC_BASE 0x40021000
#define RCC_APB2ENR (*(volatile uint32_t *)(RCC_BASE + 0x18))
#define RCC_APB1ENR (*(volatile uint32_t *)(RCC_BASE + 0x1C))
#define RCC_AHBENR (*(volatile uint32_t *)(RCC_BASE + 0x14))

#define RCC_PERIPH_USART1 0x40013800
#define RCC_PERIPH_GPIOA 0x40010800
#define RCC_PERIPH_GPIOC 0x40011000

void rcc_periph_clock_cmd(uint32_t periph_base, bool enable);

#endif // RCC_H
