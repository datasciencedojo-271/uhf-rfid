/*
 * Linker script for the STM32F103 microcontroller
 */

MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 128K
  RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
  .text :
  {
    . = ALIGN(4);
    _sidata = .;
    *(.isr_vector)
    *(.text*)
    . = ALIGN(4);
    _sdata = .;
    *(.data*)
    . = ALIGN(4);
    _edata = .;
  } >FLASH

  .bss :
  {
    . = ALIGN(4);
    __bss_start__ = .;
    _sbss = .;
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;
    __bss_end__ = .;
  } >RAM
}
