#![allow(dead_code)]

use core::ptr::{read_volatile, write_volatile};

const USART1_BASE: u32 = 0x40013800;

#[repr(C)]
struct UsartTypeDef {
    pub sr: u16,
    _reserved0: u16,
    pub dr: u16,
    _reserved1: u16,
    pub brr: u16,
    _reserved2: u16,
    pub cr1: u16,
    _reserved3: u16,
    pub cr2: u16,
    _reserved4: u16,
    pub cr3: u16,
    _reserved5: u16,
    pub gtpr: u16,
    _reserved6: u16,
}

// Bit definitions for USART_CR1
const USART_CR1_UE: u16 = 1 << 13;
const USART_CR1_TE: u16 = 1 << 3;
const USART_CR1_RE: u16 = 1 << 2;

// Bit definitions for USART_SR
const USART_SR_TXE: u16 = 1 << 7;
const USART_SR_TC: u16 = 1 << 6;
const USART_SR_RXNE: u16 = 1 << 5;

/// Initialize the UART.
/// This function corresponds to the UART initialization part of FUN_00005a44.
pub fn uart_init() {
    let usart1 = USART1_BASE as *mut UsartTypeDef;
    unsafe {
        // Enable UART, TX, RX
        write_volatile(&mut (*usart1).cr1, USART_CR1_UE | USART_CR1_TE | USART_CR1_RE);
        write_volatile(&mut (*usart1).cr2, 0x0000);
        write_volatile(&mut (*usart1).cr3, 0x0000);
        // Set baud rate to 115200 (assuming 8MHz clock)
        write_volatile(&mut (*usart1).brr, 0x45);
    }
}

/// Write data to the UART.
/// This function corresponds to the polling-based UART write logic
/// seen in functions like FUN_00002c4c.
pub fn uart_write(data: &[u8]) {
    let usart1 = USART1_BASE as *mut UsartTypeDef;
    for &byte in data {
        unsafe {
            // Wait for the transmit buffer to be empty
            while (read_volatile(&(*usart1).sr) & USART_SR_TXE) == 0 {}
            write_volatile(&mut (*usart1).dr, byte as u16);
        }
    }
    unsafe {
        // Wait for the transmission to complete
        while (read_volatile(&(*usart1).sr) & USART_SR_TC) == 0 {}
    }
}

/// Read data from the UART.
/// This function is a helper based on the logic of checking the RXNE bit.
pub fn uart_read(buffer: &mut [u8]) -> usize {
    let usart1 = USART1_BASE as *mut UsartTypeDef;
    let mut i = 0;
    while i < buffer.len() {
        unsafe {
            if (read_volatile(&(*usart1).sr) & USART_SR_RXNE) != 0 {
                buffer[i] = (read_volatile(&(*usart1).dr) & 0xFF) as u8;
                i += 1;
            }
        }
    }
    i
}

/// Check if the UART has data available for reading.
/// This function is a helper based on the logic of checking the RXNE bit.
pub fn uart_has_data() -> bool {
    let usart1 = USART1_BASE as *mut UsartTypeDef;
    unsafe { (read_volatile(&(*usart1).sr) & USART_SR_RXNE) != 0 }
}
