#ifndef GPIO_H
#define GPIO_H

#include "stdint.h"

#define GPIOA_BASE 0x40010800
#define GPIOC_BASE 0x40011000

#define GPIOA_CRH (*(volatile uint32_t *)(GPIOA_BASE + 0x04))
#define GPIOC_CRH (*(volatile uint32_t *)(GPIOC_BASE + 0x04))

typedef struct {
    uint16_t pin;
    uint8_t mode;
    uint8_t speed;
} gpio_config_t;

void gpio_init(uint32_t gpio_base, const gpio_config_t *config);

#endif // GPIO_H
