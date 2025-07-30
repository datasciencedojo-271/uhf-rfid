#![allow(dead_code)]

use crate::systick;

pub fn memset(s: &mut [u8], c: u8, n: usize) {
    for i in 0..n {
        s[i] = c;
    }
}

pub fn delay_ms(ms: u32) {
    systick::systick_delay(ms);
}
