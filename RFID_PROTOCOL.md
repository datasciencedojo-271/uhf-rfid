# RFID Protocol

This document describes the RFID protocol used by the firmware.

## Packet Format

All communication between the host and the reader is done through packets. The general format of a packet is as follows:

*   `[0]`: Start of frame (0xA0)
*   `[1]`: Length of the packet (including the start and end of frame)
*   `[2]`: Reader ID
*   `[3]`: Command
*   `[4]`: Status
*   `[5-n]`: Data
*   `[n+1]`: Checksum
*   `[n+2]`: End of frame (0xC0)

The checksum is calculated as the sum of all bytes from the length to the data, modulo 256. A status code of `0x00` indicates success. Any other value indicates an error.

## Commands

### 1. Get Firmware Version (0x01)

This command retrieves the firmware version.

**Request**

*   **Command:** `0x01`
*   **Parameters:** None

**Response**

*   **Data:**
    *   `[0-1]`: Firmware version (2 bytes)

### 2. Get Reader ID (0x02)

This command retrieves the reader's unique ID.

**Request**

*   **Command:** `0x02`
*   **Parameters:** None

**Response**

*   **Data:**
    *   `[0-3]`: Reader ID (4 bytes)

### 3. Reset (0x03)

This command resets the RFID reader.

**Request**

*   **Command:** `0x03`
*   **Parameters:** None

**Response**

*   **Data:** None

### 4. Set Reader ID (0x04)

This command sets the reader's unique ID.

**Request**

*   **Command:** `0x04`
*   **Parameters:**
    *   `[0-3]`: New Reader ID (4 bytes)

**Response**

*   **Data:** None

### 5. Set Baud Rate (0x06)

This command sets the serial communication baud rate.

**Request**

*   **Command:** `0x06`
*   **Parameters:**
    *   `[0]`: Baud rate (1 byte)
        *   `0x00`: 9600
        *   `0x01`: 19200
        *   `0x02`: 38400
        *   `0x03`: 57600
        *   `0x04`: 115200

**Response**

*   **Data:** None

### 6. Get Work Mode (0x08)

This command retrieves the current work mode of the reader.

**Request**

*   **Command:** `0x08`
*   **Parameters:** None

**Response**

*   **Data:**
    *   `[0]`: Work mode (1 byte)
        *   `0x00`: Normal Mode
        *   `0x01`: Read-Only Mode

### 7. Set Work Mode (0x09)

This command sets the work mode of the reader.

**Request**

*   **Command:** `0x09`
*   **Parameters:**
    *   `[0]`: Work mode (1 byte)
        *   `0x00`: Normal Mode
        *   `0x01`: Read-Only Mode

**Response**

*   **Data:** None

### 8. Read (0x80)

This command reads data from the specified memory area of the tag.

**Request**

*   **Command:** `0x80`
*   **Parameters:**
    *   `[0]`: Memory area (1 byte)
        *   `0x01`: User
        *   `0x02`: EPC
        *   `0x03`: TID
    *   `[1]`: Address (1 byte)

**Response**

*   **Data:**
    *   `[0-3]`: Data (4 bytes)

### 9. Write (0x81)

This command writes data to the specified memory area of the tag.

**Request**

*   **Command:** `0x81`
*   **Parameters:**
    *   `[0]`: Memory area (1 byte)
        *   `0x01`: User
        *   `0x02`: EPC
    *   `[1]`: Address (1 byte)
    *   `[2-5]`: Data (4 bytes)

**Response**

*   **Data:** None

### 10. Lock (0x82)

This command locks or unlocks the specified memory area of the tag.

**Request**

*   **Command:** `0x82`
*   **Parameters:**
    *   `[0]`: Memory area (1 byte)
        *   `0x01`: User
        *   `0x02`: EPC
        *   `0x03`: TID
        *   `0x04`: Access Password
        *   `0x05`: Kill Password
    *   `[1]`: Lock type (1 byte)
        *   `0x00`: Unlock
        *   `0x01`: Lock
        *   `0x02`: Perma-Unlock
        *   `0x03`: Perma-Lock

**Response**

*   **Data:** None

### 11. Kill (0x83)

This command permanently deactivates the tag.

**Request**

*   **Command:** `0x83`
*   **Parameters:**
    *   `[0-3]`: Kill password (4 bytes)

**Response**

*   **Data:** None

### 12. Inventory (0x91)

This command performs an inventory of tags in the reader's field.

**Request**

*   **Command:** `0x91`
*   **Parameters:**
    *   `[0]`: Inventory mode (1 byte)
        *   `0x00`: Single poll
        *   `0x01`: Continuous poll

**Response**

*   **Data:**
    *   `[0-11]`: EPC of the first tag found (12 bytes)
