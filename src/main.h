#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#include <stdbool.h>

// This is a buffer for storing commands received from the host.
extern uint8_t command_buffer[256];

// This is the main loop of the application.
void main_loop(void);

#endif // MAIN_H
