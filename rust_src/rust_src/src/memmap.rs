#![allow(dead_code)]

/* Data Memory */
pub const DAT_20000000: *mut u8 = 0x20000000 as *mut u8;
pub const DAT_20000026: *mut u8 = 0x20000026 as *mut u8;
pub const DAT_20000027: *mut u8 = 0x20000027 as *mut u8;
pub const DAT_2000002F: *mut u8 = 0x2000002F as *mut u8;
pub const DAT_20000030: *mut u16 = 0x20000030 as *mut u16;
pub const DAT_200000A5: *mut u8 = 0x200000A5 as *mut u8;
pub const DAT_20000190: *mut u16 = 0x20000190 as *mut u16;
pub const DAT_20000194: *mut u8 = 0x20000194 as *mut u8;
pub const DAT_20000196: *mut u16 = 0x20000196 as *mut u16;
pub const DAT_20000198: *mut u8 = 0x20000198 as *mut u8;
pub const DAT_200001AA: *mut u16 = 0x200001AA as *mut u16;
pub const DAT_200001AC: *mut u8 = 0x200001AC as *mut u8;
pub const DAT_200001AD: *mut u8 = 0x200001AD as *mut u8;
pub const DAT_200001AE: *mut u8 = 0x200001AE as *mut u8;
pub const DAT_200001AF: *mut u8 = 0x200001AF as *mut u8;
pub const DAT_200001B0: *mut u8 = 0x200001B0 as *mut u8;
pub const DAT_200001B1: *mut u8 = 0x200001B1 as *mut u8;
pub const DAT_200001B2: *mut u8 = 0x200001B2 as *mut u8;
pub const DAT_200001B3: *mut u8 = 0x200001B3 as *mut u8;
pub const DAT_200001B4: *mut u8 = 0x200001B4 as *mut u8;
pub const DAT_200001B5: *mut u8 = 0x200001B5 as *mut u8;
pub const DAT_200001B6: *mut u8 = 0x200001B6 as *mut u8;
pub const DAT_200001B7: *mut u8 = 0x200001B7 as *mut u8;
pub const DAT_200001B8: *mut u8 = 0x200001B8 as *mut u8;
pub const DAT_200001B9: *mut u8 = 0x200001B9 as *mut u8;
pub const DAT_200001BC: *mut u8 = 0x200001BC as *mut u8;
pub const DAT_200001BD: *mut u8 = 0x200001BD as *mut u8;
pub const DAT_200001BE: *mut u8 = 0x200001BE as *mut u8;
pub const DAT_200001BF: *mut u8 = 0x200001BF as *mut u8;
pub const DAT_200001C0: *mut u8 = 0x200001C0 as *mut u8;
pub const DAT_200001C1: *mut u8 = 0x200001C1 as *mut u8;
pub const DAT_200001C2: *mut u8 = 0x200001C2 as *mut u8;
pub const DAT_200001C3: *mut u8 = 0x200001C3 as *mut u8;
pub const DAT_200001C4: *mut u8 = 0x200001C4 as *mut u8;
pub const DAT_200001C5: *mut u8 = 0x200001C5 as *mut u8;
pub const DAT_200001C6: *mut u8 = 0x200001C6 as *mut u8;
pub const DAT_200001C7: *mut u8 = 0x200001C7 as *mut u8;
pub const DAT_200001C8: *mut u8 = 0x200001C8 as *mut u8;
pub const DAT_200001C9: *mut u8 = 0x200001C9 as *mut u8;
pub const DAT_200001CA: *mut u16 = 0x200001CA as *mut u16;
pub const DAT_200001CC: *mut u8 = 0x200001CC as *mut u8;
pub const DAT_2000029C: *mut u8 = 0x2000029C as *mut u8;
pub const DAT_2000042D: *mut u8 = 0x2000042D as *mut u8;

/* Flash Data */
pub const DAT_08009308: *mut u32 = 0x08009308 as *mut u32;
pub const DAT_08003090: *mut u32 = 0x08003090 as *mut u32;
pub const DAT_2000016C: *mut u8 = 0x2000016C as *mut u8;
pub const DAT_20000162: *mut u8 = 0x20000162 as *mut u8;
pub const DAT_2000017E: *mut u16 = 0x2000017E as *mut u16;
pub const DAT_2000017C: *mut u16 = 0x2000017C as *mut u16;


/* Peripherals */
pub const ADDR_40013800: *mut () = 0x40013800 as *mut ();
pub const ADDR_40010800: *mut () = 0x40010800 as *mut ();
pub const ADDR_40005C00: *mut u32 = 0x40005C00 as *mut u32;
pub const ADDR_42218180: *mut u8 = 0x42218180 as *mut u8;
pub const ADDR_42218000: *mut u32 = 0x42218000 as *mut u32;
pub const ADDR_42218190: *mut u32 = 0x42218190 as *mut u32;
pub const ADDR_42218194: *mut u8 = 0x42218194 as *mut u8;
pub const ADDR_42218198: *mut u8 = 0x42218198 as *mut u8;

// These are structs that will be defined in other modules.
// For now, we can use a void pointer as a placeholder.
pub const IWDG: *mut () = 0x40003000 as *mut ();
pub const NVIC: *mut () = 0xE000E100 as *mut ();
pub const SCB: *mut () = 0xE000ED00 as *mut ();
pub const SysTick: *mut () = 0xE000E010 as *mut ();
