use stm32f1xx_hal::{
    iwdg::IndependentWatchdog,
    pac::IWDG,
};

pub struct Iwdg {
    watchdog: IndependentWatchdog,
}

impl Iwdg {
    pub fn new(iwdg: IWDG) -> Self {
        let watchdog = IndependentWatchdog::new(iwdg);
        Self { watchdog }
    }

    pub fn feed(&mut self) {
        self.watchdog.feed();
    }
}
