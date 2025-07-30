#![allow(dead_code)]

use core::ptr::write_volatile;
use crate::memmap::IWDG;

#[repr(C)]
pub struct IwdgTypeDef {
    pub kr: u32,
    pub pr: u32,
    pub rlr: u32,
    pub sr: u32,
}

pub const IWDG_PRESCALER_4: u8 = 0x0;
pub const IWDG_PRESCALER_8: u8 = 0x1;
pub const IWDG_PRESCALER_16: u8 = 0x2;
pub const IWDG_PRESCALER_32: u8 = 0x3;
pub const IWDG_PRESCALER_64: u8 = 0x4;
pub const IWDG_PRESCALER_128: u8 = 0x5;
pub const IWDG_PRESCALER_256: u8 = 0x6;

pub fn iwdg_set_prescaler(prescaler: u8) {
    let iwdg = IWDG as *mut IwdgTypeDef;
    unsafe {
        write_volatile(&mut (*iwdg).kr, 0x5555);
        write_volatile(&mut (*iwdg).pr, prescaler as u32);
    }
}

pub fn iwdg_set_reload(reload: u16) {
    let iwdg = IWDG as *mut IwdgTypeDef;
    unsafe {
        write_volatile(&mut (*iwdg).kr, 0x5555);
        write_volatile(&mut (*iwdg).rlr, reload as u32);
    }
}

pub fn iwdg_reload_counter() {
    let iwdg = IWDG as *mut IwdgTypeDef;
    unsafe {
        write_volatile(&mut (*iwdg).kr, 0xAAAA);
    }
}

pub fn iwdg_enable() {
    let iwdg = IWDG as *mut IwdgTypeDef;
    unsafe {
        write_volatile(&mut (*iwdg).kr, 0xCCCC);
    }
}

pub fn iwdg_init() {
    iwdg_enable();
    iwdg_set_prescaler(IWDG_PRESCALER_4);
    iwdg_set_reload(0xFFF);
    iwdg_reload_counter();
}

pub fn iwdg_disable_write_protection() {
    let iwdg = IWDG as *mut IwdgTypeDef;
    unsafe {
        write_volatile(&mut (*iwdg).kr, 0x5555);
    }
}

pub fn iwdg_enable_write_protection() {
    // This is a guess, the function is empty in the firmware
}
