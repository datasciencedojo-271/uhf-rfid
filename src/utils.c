#include "utils.h"

/**
 * @brief Calculate the checksum of a byte array.
 * @param data The data to calculate the checksum of.
 * @param length The length of the data.
 * @return The checksum.
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
 */
void utils_memset(void *dst, uint8_t value, uint16_t length)
{
  uint8_t *d = (uint8_t *)dst;
  for (uint16_t i = 0; i < length; i++) {
    d[i] = value;
  }
}

/**
 * @brief Compare two memory regions.
 * @param s1 The first memory region.
 * @param s2 The second memory region.
 * @param length The length to compare.
 * @return 0 if the memory regions are equal, -1 if s1 < s2, 1 if s1 > s2.
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
