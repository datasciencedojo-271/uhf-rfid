#include "iwdg.h"
#include "memmap.h"

void iwdg_set_prescaler(uint8_t prescaler) {
    IWDG->KR = 0x5555;
    IWDG->PR = prescaler;
}

void iwdg_set_reload(uint16_t reload) {
    IWDG->KR = 0x5555;
    IWDG->RLR = reload;
}

void iwdg_reload_counter(void) {
    IWDG->KR = 0xAAAA;
}

void iwdg_enable(void) {
    IWDG->KR = 0xCCCC;
}

void iwdg_init(void) {
    iwdg_enable();
    iwdg_set_prescaler(IWDG_PRESCALER_4);
    iwdg_set_reload(0xFFF);
    iwdg_reload_counter();
}

void iwdg_disable_write_protection(void) {
    IWDG->KR = 0x5555;
}

void iwdg_enable_write_protection(void) {
    // This is a guess, the function is empty in the firmware
}
