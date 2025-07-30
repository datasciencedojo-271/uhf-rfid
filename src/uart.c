#include "uart.h"

#define USART1_BASE 0x40013800
#define USART1_SR (*(volatile uint32_t *)(USART1_BASE + 0x00))
#define USART1_DR (*(volatile uint32_t *)(USART1_BASE + 0x04))
#define USART1_BRR (*(volatile uint32_t *)(USART1_BASE + 0x08))
#define USART1_CR1 (*(volatile uint32_t *)(USART1_BASE + 0x0C))
#define USART1_CR2 (*(volatile uint32_t *)(USART1_BASE + 0x10))
#define USART1_CR3 (*(volatile uint32_t *)(USART1_BASE + 0x14))

/**
 * @brief Initialize the UART.
 * @note This function corresponds to the UART initialization part of FUN_00005a44 in the firmware (lines 17164-17228).
 */
void uart_init(void)
{
    // This is a simplified version of the logic in FUN_00005a44.
    // The original function is much more complex and involves a state machine.
    // For now, we will just configure the UART with a default baud rate.
    USART1_CR1 = 0x200c;
    USART1_CR2 = 0x0;
    USART1_CR3 = 0x0;
    USART1_BRR = 0x45;
}

/**
 * @brief Write data to the UART.
 * @param data The data to write.
 * @param length The length of the data.
 * @note This function corresponds to FUN_00002c4c in the firmware (lines 9390-9420).
 */
void uart_write(uint8_t *data, uint16_t length)
{
  for (uint16_t i = 0; i < length; i++) {
    while ((USART1_SR & 0x80) == 0);
    USART1_DR = data[i];
  }
  while ((USART1_SR & 0x40) == 0);
}

/**
 * @brief Read data from the UART.
 * @param data The buffer to store the data.
 * @param length The maximum length to read.
 * @return The number of bytes read.
 * @note This function is a helper and does not directly correspond to a function in fw.lst.
 * It is based on the logic of checking the RXNE bit in the USART_SR register.
 */
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

/**
 * @brief Check if the UART has data.
 * @return True if the UART has data, false otherwise.
 * @note This function is a helper and does not directly correspond to a function in fw.lst.
 * It is based on the logic of checking the RXNE bit in the USART_SR register.
 */
bool uart_has_data(void)
{
    return (USART1_SR & 0x20) != 0;
}
