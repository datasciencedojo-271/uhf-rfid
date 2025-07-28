#include "utils.h"

uint8_t utils_checksum(uint8_t *data, uint16_t length)
{
  uint8_t checksum = 0;
  for (uint16_t i = 0; i < length; i++) {
    checksum += data[i];
  }
  return ~checksum + 1;
}

void utils_memcpy(void *dst, const void *src, uint16_t length)
{
  uint8_t *d = (uint8_t *)dst;
  const uint8_t *s = (const uint8_t *)src;
  for (uint16_t i = 0; i < length; i++) {
    d[i] = s[i];
  }
}

void utils_memset(void *dst, uint8_t value, uint16_t length)
{
  uint8_t *d = (uint8_t *)dst;
  for (uint16_t i = 0; i < length; i++) {
    d[i] = value;
  }
}

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
