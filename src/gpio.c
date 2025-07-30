#include "gpio.h"
#include "stdint.h"

/**
 * @brief Initialize the GPIO pins.
 * @note This function corresponds to FUN_000012b6 in the firmware (lines 4886-4960).
 */
void gpio_init(uint32_t gpio_base, const gpio_config_t *config)
{
    uint32_t *cr;
    uint32_t pin_pos;

    for (int i = 0; i < 16; i++) {
        if (config->pin & (1 << i)) {
            pin_pos = (i % 8) * 4;
            if (i < 8) {
                cr = (uint32_t *)(uintptr_t)(gpio_base + 0x00);
            } else {
                cr = (uint32_t *)(uintptr_t)(gpio_base + 0x04);
            }
            *cr &= ~((uint32_t)0xF << pin_pos);
            *cr |= ((uint32_t)(config->speed | config->mode) << pin_pos);
        }
    }
}
