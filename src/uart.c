#include "uart.h"
#include "usart_regs.h"

/**
 * @brief Initialize the UART.
 * @note This function corresponds to the UART initialization part of FUN_00005a44.
 */
void uart_init(void)
{
    // This function configures the USART1 peripheral. The values are based on the
    // disassembly of FUN_00005a44.

    // 0x5a8c: str r4, [sp, #local_1c] (r4 holds config data)
    // The values 0x200c and 0x45 are written to the USART registers.

    USART1->CR1 = USART_CR1_UE | USART_CR1_TE | USART_CR1_RE; // 0x200C - Enable UART, TX, RX
    USART1->CR2 = 0x0000;
    USART1->CR3 = 0x0000;

    // A baud rate of 115200 is a common default. 0x45 for BRR with a 8MHz clock gives 115200.
    USART1->BRR = 0x45;
}

/**
 * @brief Write data to the UART.
 * @param data The data to write.
 * @param length The length of the data.
 * @note This function corresponds to the polling-based UART write logic
 *       seen in functions like FUN_00002c4c.
 */
void uart_write(uint8_t *data, uint16_t length)
{
  for (uint16_t i = 0; i < length; i++) {
    // Wait for the transmit buffer to be empty
    while ((USART1->SR & USART_SR_TXE) == 0);
    USART1->DR = data[i];
  }
  // Wait for the transmission to complete
  while ((USART1->SR & USART_SR_TC) == 0);
}

/**
 * @brief Read data from the UART.
 * @param data The buffer to store the data.
 * @param length The maximum length to read.
 * @return The number of bytes read.
 * @note This function is a helper based on the logic of checking the RXNE bit.
 */
uint16_t uart_read(uint8_t *data, uint16_t length)
{
  uint16_t i = 0;
  // This is a blocking read. A timeout could be added for robustness.
  while (i < length) {
    if ((USART1->SR & USART_SR_RXNE) != 0) {
      data[i] = (uint8_t)(USART1->DR & 0xFF);
      i++;
    }
  }
  return i;
}

/**
 * @brief Check if the UART has data available for reading.
 * @return True if the UART has data, false otherwise.
 * @note This function is a helper based on the logic of checking the RXNE bit.
 */
bool uart_has_data(void)
{
    return (USART1->SR & USART_SR_RXNE) != 0;
}
