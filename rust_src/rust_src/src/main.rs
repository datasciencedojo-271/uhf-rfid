#![no_std]
#![no_main]

use core::panic::PanicInfo;

mod gpio;
mod iwdg;
mod memmap;
mod nvic;
mod rcc;
mod rfid;
mod systick;
mod uart;
mod utils;

#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}

fn main_loop_body() {
    // These buffers are located on the stack in the original firmware.
    // They are used for temporary storage during command processing.
    let mut local_buf_bc: [u8; 52] = [0; 52];
    let mut local_buf_88: [u8; 52] = [0; 52];
    let mut local_buf_54: [u8; 52] = [0; 52];
    let mut local_buf_20: [u8; 52] = [0; 52];

    let mut local_stack_vars_1: [u32; 4] = [0; 4];
    let mut local_stack_vars_2: [u32; 4] = [0; 4];

    iwdg::iwdg_reload_counter();

    // Zero out local stack buffers
    local_buf_bc.iter_mut().for_each(|m| *m = 0);
    local_buf_88.iter_mut().for_each(|m| *m = 0);
    local_buf_54.iter_mut().for_each(|m| *m = 0);
    local_buf_20.iter_mut().for_each(|m| *m = 0);

    // Load data from flash into stack variables.
    // These are likely configuration constants or tables.
    unsafe {
        core::ptr::copy_nonoverlapping(
            memmap::DAT_08009308 as *const u32,
            local_stack_vars_1.as_mut_ptr(),
            4,
        );
        core::ptr::copy_nonoverlapping(
            memmap::DAT_08003090 as *const u32,
            local_stack_vars_2.as_mut_ptr(),
            4,
        );
    }

    // Initialize a buffer at DAT_20000027 with 8 zeros
    for i in 0..8 {
        unsafe {
            core::ptr::write_volatile(memmap::DAT_20000027.add(i), 0);
        }
    }

    // -- Main Loop Logic --
    // Check if there are any commands to process. If not, exit.
    unsafe {
        if core::ptr::read_volatile(memmap::DAT_200001B9) == 0
            && core::ptr::read_volatile(memmap::DAT_200001C0) == 0
        {
            return;
        }

        // Main state machine based on the value of DAT_200001B9
        if core::ptr::read_volatile(memmap::DAT_200001B9) != 0 {
            // State machine for when DAT_200001B9 is non-zero.
            // This is a complex set of nested conditions and function calls.

            // This is a simplified representation of the logic.
            // A full translation would require a more detailed analysis of each branch.
            if core::ptr::read_volatile(memmap::DAT_20000190) > 0x17 {
                // ...
            } else if core::ptr::read_volatile(memmap::DAT_20000190) > 0x23 {
                // ...
            }
        } else if core::ptr::read_volatile(memmap::DAT_200001C0) != 0 {
            // This block corresponds to logic starting at 0x2e94
            if core::ptr::read_volatile(memmap::DAT_200001C0) == 0 {
                // This path is not taken if DAT_200001C0 is zero.
            } else {
                // 0x2ea8
                if core::ptr::read_volatile(memmap::DAT_200001C3) == 0 {
                    if core::ptr::read_volatile(memmap::DAT_200001AE) != 0 {
                        // ...
                    }
                } else {
                    // ...
                }
            }
        }
    }
}

#[no_mangle]
pub extern "C" fn main() -> ! {
    rfid::rfid_init();

    loop {
        main_loop_body();
    }
}
