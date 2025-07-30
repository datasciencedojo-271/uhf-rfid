#ifndef MAIN_H
#define MAIN_H

#include "stdint.h"

typedef uint8_t byte;
typedef uint16_t ushort;
typedef uint32_t uint;
// typedef uint8_t undefined1;
// typedef uint16_t undefined2;
// typedef uint32_t undefined4;
// typedef uint64_t undefined8;
// typedef uint8_t undefined;

// This is a buffer for storing commands received from the host.
extern uint8_t command_buffer[256];

// This is the main loop of the application.
void main_loop(void);

#endif // MAIN_H
