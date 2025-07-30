#![allow(dead_code)]

use core::ptr::{read_volatile, write_volatile};

pub const GPIOA_BASE: u32 = 0x40010800;
pub const GPIOC_BASE: u32 = 0x40011000;

pub struct GpioConfig {
    pub pin: u16,
    pub mode: u8,
    pub speed: u8,
}

/// Initialize the GPIO pins.
/// This function corresponds to FUN_000012b6 in the firmware.
pub fn gpio_init(gpio_base: u32, config: &GpioConfig) {
    for i in 0..16 {
        if (config.pin & (1 << i)) != 0 {
            let pin_pos = (i % 8) * 4;
            let cr_offset = if i < 8 { 0x00 } else { 0x04 };
            let cr_addr = (gpio_base + cr_offset) as *mut u32;

            unsafe {
                let mut cr = read_volatile(cr_addr);
                cr &= !(0xF << pin_pos);
                cr |= ((config.speed as u32 | config.mode as u32) << pin_pos);
                write_volatile(cr_addr, cr);
            }
        }
    }
}
