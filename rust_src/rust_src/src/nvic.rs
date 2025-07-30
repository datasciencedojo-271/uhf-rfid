#![allow(dead_code)]

use core::ptr::{read_volatile, write_volatile};
use crate::memmap::NVIC;

#[repr(C)]
pub struct NvicType {
    pub iser: [u32; 8],
    _reserved0: [u32; 24],
    pub icer: [u32; 8],
    _reserved1: [u32; 24],
    pub ispr: [u32; 8],
    _reserved2: [u32; 24],
    pub icpr: [u32; 8],
    _reserved3: [u32; 24],
    pub iabr: [u32; 8],
    _reserved4: [u32; 56],
    pub ip: [u8; 240],
    _reserved5: [u32; 644],
    pub stir: u32,
}

pub fn nvic_set_priority(irqn: u8, priority: u8) {
    let nvic = NVIC as *mut NvicType;
    unsafe {
        write_volatile(&mut (*nvic).ip[irqn as usize], priority);
    }
}

pub fn nvic_check_pending(irqn: u8) -> u32 {
    let nvic = NVIC as *mut NvicType;
    unsafe {
        read_volatile(&(*nvic).ispr[(irqn / 32) as usize]) & (1 << (irqn % 32))
    }
}
