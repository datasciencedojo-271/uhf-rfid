#include "utils.h"

typedef unsigned long size_t;

/**
 * @brief Calculate the checksum of a byte array.
 * @param data The data to calculate the checksum of.
 * @param length The length of the data.
 * @return The checksum.
 * @note This function corresponds to FUN_000008c0 in the firmware (lines 923-941).
 */
uint8_t utils_checksum(uint8_t *data, uint16_t length)
{
  uint8_t checksum = 0;
  for (uint16_t i = 0; i < length; i++) {
    checksum += data[i];
  }
  return ~checksum + 1;
}

/**
 * @brief Copy memory.
 * @param dst The destination.
 * @param src The source.
 * @param length The length to copy.
 * @note This function corresponds to FUN_00000288 in the firmware (lines 288-374).
 */
void utils_memcpy(void *dst, const void *src, uint16_t length)
{
  uint8_t *d = (uint8_t *)dst;
  const uint8_t *s = (const uint8_t *)src;
  for (uint16_t i = 0; i < length; i++) {
    d[i] = s[i];
  }
}

/**
 * @brief Fill memory with a value.
 * @param dst The destination.
 * @param value The value to fill with.
 * @param length The length to fill.
 * @note This function corresponds to FUN_00000376 in the firmware (lines 376-476).
 */
void utils_memset(void *dst, uint8_t value, uint16_t length)
{
  uint8_t *d = (uint8_t *)dst;
  for (uint16_t i = 0; i < length; i++) {
    d[i] = value;
  }
}

// Provide memset for compiler
void *memset(void *s, int c, size_t n) {
  utils_memset(s, (uint8_t)c, (uint16_t)n);
  return s;
}

/**
 * @brief Compare two memory regions.
 * @param s1 The first memory region.
 * @param s2 The second memory region.
 * @param length The length to compare.
 * @return 0 if the memory regions are equal, -1 if s1 < s2, 1 if s1 > s2.
 * @note This function corresponds to FUN_00000230 in the firmware (lines 230-286).
 */
int utils_memcmp(const void *s1, const void *s2, uint16_t length)
{
  const uint8_t *p1 = (const uint8_t *)s1;
  const uint8_t *p2 = (const uint8_t *)s2;
  for (uint16_t i = 0; i < length; i++) {
    if (p1[i] != p2[i]) {
      return p1[i] < p2[i] ? -1 : 1;
    }
  }
  return 0;
}

/**
 * @brief A simple busy-wait delay function.
 * @param ms The delay in milliseconds.
 */
void utils_delay_ms(uint32_t ms)
{
    // This is a rough delay function. A more accurate delay function
    // should be used in a real application, preferably using a hardware timer.
    // The constant 1000 is a placeholder and should be calibrated for the target hardware.
    for (volatile uint32_t i = 0; i < ms * 1000; i++) {
        __asm__("nop");
    }
}
