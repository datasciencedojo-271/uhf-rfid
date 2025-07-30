#include "systick.h"
#include "memmap.h"

void systick_init(void) {
    // Implementation of FUN_00005424
    SysTick->CTRL = 0;
    SysTick->LOAD = 0xFFFFFF;
    SysTick->VAL = 0;
    SysTick->CTRL = 5;
}

void systick_delay(uint32_t ms) {
    // Implementation of FUN_00005460
    uint32_t i;
    for (i = 0; i < ms; i++) {
        systick_delay_us(1000);
    }
}

void systick_delay_us(uint16_t us) {
    // Implementation of FUN_000054ac
    uint32_t i;
    for (i = 0; i < us; i++) {
        // This is a rough approximation
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
    }
}
