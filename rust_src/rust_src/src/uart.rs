use stm32f1xx_hal::{
    pac,
    prelude::*,
    serial::{Config, Serial, Tx, Rx},
};

pub struct Uart {
    tx: Tx<pac::USART1>,
    rx: Rx<pac::USART1>,
}

impl Uart {
    pub fn new(
        usart1: pac::USART1,
        tx_pin: gpio::PA9,
        rx_pin: gpio::PA10,
        rcc: &mut rcc::Rcc,
    ) -> Self {
        let mut afio = usart1.afio.constrain(rcc);
        let tx = tx_pin.into_alternate_push_pull(&mut gpioa.crh);
        let rx = rx_pin.into_floating_input(&mut gpioa.crh);
        let serial = Serial::usart1(
            usart1,
            (tx, rx),
            &mut afio.mapr,
            Config::default().baudrate(115200.bps()),
            &clocks,
        );
        let (tx, rx) = serial.split();
        Self { tx, rx }
    }

    pub fn write(&mut self, data: &[u8]) {
        for &byte in data {
            nb::block!(self.tx.write(byte)).unwrap();
        }
    }

    pub fn read(&mut self) -> Result<u8, nb::Error<()>> {
        self.rx.read()
    }
}
