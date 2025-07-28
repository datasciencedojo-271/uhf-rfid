#include "uart.h"

#define USART1_BASE 0x40013800
#define USART1_SR (*(volatile uint32_t *)(USART1_BASE + 0x00))
#define USART1_DR (*(volatile uint32_t *)(USART1_BASE + 0x04))
#define USART1_BRR (*(volatile uint32_t *)(USART1_BASE + 0x08))
#define USART1_CR1 (*(volatile uint32_t *)(USART1_BASE + 0x0C))
#define USART1_CR2 (*(volatile uint32_t *)(USART1_BASE + 0x10))
#define USART1_CR3 (*(volatile uint32_t *)(USART1_BASE + 0x14))

void uart_init(void)
{
  // This is a placeholder for the UART initialization function.
  // In a real application, this function would configure the UART
  // peripheral with the correct baud rate, parity, etc.
}

void uart_write(uint8_t *data, uint16_t length)
{
  for (uint16_t i = 0; i < length; i++) {
    while ((USART1_SR & 0x80) == 0);
    USART1_DR = data[i];
  }
  while ((USART1_SR & 0x40) == 0);
}

uint16_t uart_read(uint8_t *data, uint16_t length)
{
  uint16_t i = 0;
  while (i < length) {
    if ((USART1_SR & 0x20) != 0) {
      data[i] = USART1_DR;
      i++;
    }
  }
  return i;
}
