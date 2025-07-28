#ifndef UART_H
#define UART_H

#include "main.h"

void uart_init(void);
void uart_write(uint8_t *data, uint16_t length);
uint16_t uart_read(uint8_t *data, uint16_t length);

#endif // UART_H
