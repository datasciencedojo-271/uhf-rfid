#![allow(dead_code)]

use core::ptr::{read_volatile, write_volatile};

const RCC_BASE: u32 = 0x40021000;
const RCC_APB2ENR_OFFSET: u32 = 0x18;
const RCC_APB1ENR_OFFSET: u32 = 0x1C;
const RCC_AHBENR_OFFSET: u32 = 0x14;

const RCC_APB2ENR: *mut u32 = (RCC_BASE + RCC_APB2ENR_OFFSET) as *mut u32;
const RCC_APB1ENR: *mut u32 = (RCC_BASE + RCC_APB1ENR_OFFSET) as *mut u32;
const RCC_AHBENR: *mut u32 = (RCC_BASE + RCC_AHBENR_OFFSET) as *mut u32;

pub const RCC_PERIPH_USART1: u32 = 0x40013800;
pub const RCC_PERIPH_GPIOA: u32 = 0x40010800;
pub const RCC_PERIPH_GPIOC: u32 = 0x40011000;

pub const RCC_APB2ENR_AFIOEN: u32 = 1 << 0;
pub const RCC_APB2ENR_IOPAEN: u32 = 1 << 2;
pub const RCC_APB2ENR_IOPEN: u32 = 1 << 4;

// Corresponds to FUN_00001da4
fn rcc_apb1_periph_clock_cmd(periph: u32, enable: bool) {
    unsafe {
        let mut reg = read_volatile(RCC_APB1ENR);
        if enable {
            reg |= periph;
        } else {
            reg &= !periph;
        }
        write_volatile(RCC_APB1ENR, reg);
    }
}

// Corresponds to FUN_00001d64
fn rcc_ahb_periph_clock_cmd(periph: u32, enable: bool) {
    unsafe {
        let mut reg = read_volatile(RCC_AHBENR);
        if enable {
            reg |= periph;
        } else {
            reg &= !periph;
        }
        write_volatile(RCC_AHBENR, reg);
    }
}

/// Enables or disables the APB2 peripheral clock.
/// This function corresponds to FUN_00001d84 in the firmware.
pub fn rcc_apb2_periph_clock_cmd(periph: u32, enable: bool) {
    unsafe {
        let mut reg = read_volatile(RCC_APB2ENR);
        if enable {
            reg |= periph;
        } else {
            reg &= !periph;
        }
        write_volatile(RCC_APB2ENR, reg);
    }
}

/// Enables or disables the peripheral clock.
/// This function corresponds to FUN_00004d10 in the firmware.
pub fn rcc_periph_clock_cmd(periph_base: u32, enable: bool) {
    match periph_base {
        RCC_PERIPH_USART1 => rcc_apb2_periph_clock_cmd(1 << 14, enable),
        0x40004400 => rcc_apb1_periph_clock_cmd(1 << 1, enable), // TIM3
        0x40004800 => rcc_apb1_periph_clock_cmd(1 << 2, enable), // TIM4
        0x40004C00 => rcc_apb1_periph_clock_cmd(1 << 3, enable), // TIM5
        0x40005000 => rcc_apb1_periph_clock_cmd(1 << 4, enable), // TIM6
        0x40005400 => rcc_apb1_periph_clock_cmd(1 << 5, enable), // TIM7
        _ => (),
    }
}
