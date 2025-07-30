#ifndef IWDG_H
#define IWDG_H

#include <stdint.h>

#define IWDG_PRESCALER_4    0x0
#define IWDG_PRESCALER_8    0x1
#define IWDG_PRESCALER_16   0x2
#define IWDG_PRESCALER_32   0x3
#define IWDG_PRESCALER_64   0x4
#define IWDG_PRESCALER_128  0x5
#define IWDG_PRESCALER_256  0x6

void iwdg_set_prescaler(uint8_t prescaler);
void iwdg_set_reload(uint16_t reload);
void iwdg_reload_counter(void);
void iwdg_enable(void);
void iwdg_init(void);
void iwdg_disable_write_protection(void);
void iwdg_enable_write_protection(void);

#endif // IWDG_H
