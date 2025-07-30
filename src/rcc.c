#include "rcc.h"

// Corresponds to FUN_00001da4
static void rcc_apb1_periph_clock_cmd(uint32_t periph, bool enable)
{
    if (enable) {
        RCC_APB1ENR |= periph;
    } else {
        RCC_APB1ENR &= ~periph;
    }
}

// Corresponds to FUN_00001d64
static void rcc_ahb_periph_clock_cmd(uint32_t periph, bool enable)
{
    if (enable) {
        RCC_AHBENR |= periph;
    } else {
        RCC_AHBENR &= ~periph;
    }
}

/**
 * @brief Enables or disables the APB2 peripheral clock.
 * @param periph: The peripheral to enable or disable.
 * @param enable: True to enable, false to disable.
 * @note This function corresponds to FUN_00001d84 in the firmware (lines 5000-5020).
 */
void rcc_apb2_periph_clock_cmd(uint32_t periph, bool enable)
{
    if (enable) {
        RCC_APB2ENR |= periph;
    } else {
        RCC_APB2ENR &= ~periph;
    }
}

/**
 * @brief Enables or disables the peripheral clock.
 * @param periph_base: The base address of the peripheral.
 * @param enable: True to enable, false to disable.
 * @note This function corresponds to FUN_00004d10 in the firmware (lines 15760-15892).
 */
void rcc_periph_clock_cmd(uint32_t periph_base, bool enable)
{
    if (periph_base == RCC_PERIPH_USART1) {
        rcc_apb2_periph_clock_cmd(1 << 14, enable);
    } else if (periph_base == 0x40004400) { // TIM3
        rcc_apb1_periph_clock_cmd(1 << 1, enable);
    } else if (periph_base == 0x40004800) { // TIM4
        rcc_apb1_periph_clock_cmd(1 << 2, enable);
    } else if (periph_base == 0x40004C00) { // TIM5
        rcc_apb1_periph_clock_cmd(1 << 3, enable);
    } else if (periph_base == 0x40005000) { // TIM6
        rcc_apb1_periph_clock_cmd(1 << 4, enable);
    } else if (periph_base == 0x40005400) { // TIM7
        rcc_apb1_periph_clock_cmd(1 << 5, enable);
    }
}
