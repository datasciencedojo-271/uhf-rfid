#ifndef UTILS_H
#define UTILS_H

#include "main.h"

uint8_t utils_checksum(uint8_t *data, uint16_t length);
void utils_memcpy(void *dst, const void *src, uint16_t length);
void utils_memset(void *dst, uint8_t value, uint16_t length);
int utils_memcmp(const void *s1, const void *s2, uint16_t length);

#endif // UTILS_H
