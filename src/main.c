#include "main.h"
#include "uart.h"
#include "rfid.h"
#include "utils.h"

// Command buffer
uint8_t command_buffer[256];

// Response buffer
uint8_t response_buffer[256];

// Function prototypes
void handle_host_command(void);
void handle_rfid_response(void);
void process_rfid_data(void);
void send_response_to_host(void);

/**
 * @brief Main loop.
 * @note This function corresponds to the main loop in FUN_00002c8c in the firmware (lines 9424-10650).
 */
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

/**
 * @brief Main function.
 * @note This function corresponds to the Entry Point in the firmware.
 */
int main(void)
{
    uart_init();
    rfid_init();

    while (1) {
        main_loop();
    }
}

/**
 * @brief Handle a command from the host.
 * @note This function is a part of the main loop in FUN_00002c8c in the firmware.
 */
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

/**
 * @brief Handle a response from the RFID module.
 * @note This function is a part of the main loop in FUN_00002c8c in the firmware.
 */
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

/**
 * @brief Process data from the RFID module.
 * @note This function is a part of the main loop in FUN_00002c8c in the firmware.
 */
void process_rfid_data(void)
{
    // This function will be implemented in a future step.
    // For now, we'll just print the data to the console.
    if (response_buffer[0] != 0) {
        // RFID data processing (printf removed for embedded)
    }
}

/**
 * @brief Send a response to the host.
 * @note This function is a part of the main loop in FUN_00002c8c in the firmware.
 */
void send_response_to_host(void)
{
    // This function will be implemented in a future step.
    // For now, we'll just clear the response buffer.
    if (response_buffer[0] != 0) {
        utils_memset(response_buffer, 0, sizeof(response_buffer));
    }
}
