#![no_std]
#![no_main]

use cortex_m_rt::entry;
use panic_halt as _;
use stm32f1xx_hal::{pac, prelude::*};

mod iwdg;
mod rfid;
mod uart;

#[entry]
fn main() -> ! {
    // Get access to the core peripherals from the cortex-m crate
    let cp = cortex_m::peripheral::Peripherals::take().unwrap();
    // Get access to the device specific peripherals from the peripheral access crate
    let dp = pac::Peripherals::take().unwrap();

    // Take ownership over the raw flash and rcc devices and convert them into the corresponding HAL structs
    let mut flash = dp.FLASH.constrain();
    let rcc = dp.RCC.constrain();

    // Freeze the configuration of all the clocks in the system and store the frozen frequencies in
    // `clocks`
    let clocks = rcc.cfgr.freeze(&mut flash.acr);

    // Acquire the GPIOA peripheral
    let mut gpioa = dp.GPIOA.split();

    // Configure the systick timer for a 1ms interrupt and obtain the delay provider
    let mut delay = cp.SYST.delay(&clocks);

    // Configure the UART
    let tx = gpioa.pa9.into_alternate_push_pull(&mut gpioa.crh);
    let rx = gpioa.pa10;
    let mut uart = uart::Uart::new(dp.USART1, tx, rx, &mut dp.AFIO.constrain(), &clocks);

    // Configure the independent watchdog
    let mut iwdg = iwdg::Iwdg::new(dp.IWDG);

    // Create an RFID instance
    let mut rfid = rfid::Rfid::new(&mut uart, &mut delay);

    loop {
        main_loop_body(&mut rfid, &mut iwdg);
    }
}

fn main_loop_body(rfid: &mut rfid::Rfid, iwdg: &mut iwdg::Iwdg) {
    iwdg.feed();

    // The rest of this function would be implemented here, using the safe rfid object.
}
