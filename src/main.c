#include "main.h"
#include "uart.h"
#include "rfid.h"
#include "utils.h"
#include <stdio.h>

// Command buffer
uint8_t command_buffer[256];

// Response buffer
uint8_t response_buffer[256];

// Function prototypes
void handle_host_command(void);
void handle_rfid_response(void);
void process_rfid_data(void);
void send_response_to_host(void);

// Main loop
void main_loop(void)
{
    if (uart_has_data()) {
        handle_host_command();
    }

    if (rfid_has_data()) {
        handle_rfid_response();
    }

    process_rfid_data();

    send_response_to_host();
}

// Main function
int main(void)
{
    uart_init();
    rfid_init();

    while (1) {
        main_loop();
    }
}

void handle_host_command(void)
{
    uint8_t command_length;

    // Read the command from the host
    command_length = uart_read(command_buffer, sizeof(command_buffer));

    // If a command was received, process it
    if (command_length > 0) {
        rfid_process_command(command_buffer);
    }
}

void handle_rfid_response(void)
{
    uint8_t response_length;

    // Read the response from the RFID module
    response_length = rfid_read_response(response_buffer, sizeof(response_buffer));

    // If a response was received, process it
    if (response_length > 0) {
        // This will be implemented in a future step
    }
}

void process_rfid_data(void)
{
    // This function will be implemented in a future step.
    // For now, we'll just print the data to the console.
    if (response_buffer[0] != 0) {
        printf("RFID data: %s\n", response_buffer);
    }
}

void send_response_to_host(void)
{
    // This function will be implemented in a future step.
    // For now, we'll just clear the response buffer.
    if (response_buffer[0] != 0) {
        utils_memset(response_buffer, 0, sizeof(response_buffer));
    }
}
