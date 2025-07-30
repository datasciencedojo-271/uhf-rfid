#![allow(dead_code)]

use core::ptr::{read_volatile, write_volatile};
use crate::memmap::SysTick;

#[repr(C)]
pub struct SysTick_Type {
    pub ctrl: u32,
    pub load: u32,
    pub val: u32,
    pub calib: u32,
}

pub fn systick_init() {
    let systick = SysTick as *mut SysTick_Type;
    unsafe {
        write_volatile(&mut (*systick).ctrl, 0);
        write_volatile(&mut (*systick).load, 0xFFFFFF);
        write_volatile(&mut (*systick).val, 0);
        write_volatile(&mut (*systick).ctrl, 5);
    }
}

pub fn systick_delay(ms: u32) {
    for _ in 0..ms {
        systick_delay_us(1000);
    }
}

pub fn systick_delay_us(us: u16) {
    for _ in 0..us {
        // This is a rough approximation
        unsafe {
            core::arch::asm!("nop");
            core::arch::asm!("nop");
            core::arch::asm!("nop");
            core::arch::asm!("nop");
            core::arch::asm!("nop");
            core::arch::asm!("nop");
            core::arch::asm!("nop");
            core::arch::asm!("nop");
            core::arch::asm!("nop");
            core::arch::asm!("nop");
        }
    }
}
