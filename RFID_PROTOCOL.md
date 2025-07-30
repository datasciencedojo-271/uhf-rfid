# RFID Protocol

This document describes the communication protocol for the RFID module.

## Packet Format

### Command Packet

The command packet has the following format:

| Field           | Length (bytes) | Description                                       |
|-----------------|----------------|---------------------------------------------------|
| Start of Packet | 2              | `0xAA` `0xBB`                                     |
| Command         | 1 or 2         | The command ID.                                   |
| Length          | 1              | The length of the data payload.                   |
| Data            | `Length`       | The command parameters.                           |
| Checksum        | 1              | The sum of all previous bytes.                    |

### Response Packet

The response packet format is not fully understood, but it is assumed to be similar to the command packet format. It likely contains a header, a status code, a length, data, and a checksum.

## Commands

The following is a list of the commands supported by the RFID module.

| Command ID | Function                  | Description                                | Parameters                               |
|------------|---------------------------|--------------------------------------------|------------------------------------------|
| `0x5580`   | `rfid_get_reader_info`    | Get information about the RFID reader.     | None                                     |
| `0x414E`   | `rfid_get_freq_hopping`   | Get the frequency hopping status.          | `0x30`                                   |
| `0x414E`   | `rfid_set_freq_hopping`   | Set the frequency hopping.                 | `0x31` and a 2-char hex string           |
| `0x9206`   | `rfid_get_antenna_power`  | Get the antenna power.                     | `0x04`, `0x00`                           |
| `0x9206`   | `rfid_set_antenna_power`  | Set the antenna power.                     | `0x06` and a single hex char             |
| `0x91`     | `rfid_set_gpio`           | Set the GPIO status.                       | A 2-byte array with GPIO parameters      |
| `0xA1`     | `rfid_get_firmware_version` | Get the firmware version.                  | `0x00`, `0x00`                           |
| `0x4152`   | `rfid_inventory`          | Perform an inventory of the tags.          | Three parameters for the inventory.      |
| `0x4157`   | `rfid_read_tag`           | Read a tag.                                | Four parameters for reading a tag.       |
| `0x9208`   | `rfid_get_work_mode`      | Get the work mode.                         | `0x04`, `0x06`                           |
| `0x9208`   | `rfid_set_work_mode`      | Set the work mode.                         | A hex string.                            |
| `0x9208`   | `rfid_get_buzzer_status`  | Get the buzzer status.                     | `0x02`                                   |
| `0x9208`   | `rfid_set_buzzer_status`  | Set the buzzer status.                     | A hex string.                            |
| `0x5591`   | `rfid_stop_inventory`     | Stop the inventory process.                | None                                     |
| `0x9200`   | `rfid_get_q_value`        | Get the Q value for the inventory.         | `0x04`, `0x00`                           |
| `0x9200`   | `rfid_set_q_value`        | Set the Q value.                           | A hex string.                            |
| `0x9202`   | `rfid_get_session_target` | Get the session target for the inventory. | `0x04`, `0x00`                           |
| `0x9202`   | `rfid_set_session_target` | Set the session target.                    | A hex string.                            |
| `0x920E`   | `rfid_get_antenna_config` | Get the antenna configuration.             | `0x04`, `0x00`                           |
| `0x920E`   | `rfid_set_antenna_config` | Set the antenna configuration.             | A hex string.                            |
| `0x9215`   | `rfid_get_baud_rate`      | Get the UART baud rate.                    | `0x04`, `0x00`                           |
| `0x9215`   | `rfid_set_baud_rate`      | Set the UART baud rate.                    | A hex string.                            |
| `0xA4`     | `rfid_get_inventory_mode` | Get the inventory mode.                    | `0x02`, `0x00`                           |
| `0xA4`     | `rfid_set_inventory_mode` | Set the inventory mode.                    | A hex string.                            |
