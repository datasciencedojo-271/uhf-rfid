#include "system.h"
#include "memmap.h"

void WFI(void);

void sys_enter_standby_mode(void) {
    // Implementation of FUN_00002996
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    WFI();
}
