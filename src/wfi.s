.global WFI
.type WFI, %function
WFI:
  .word 0xbf30
  .word 0x4770
.size WFI, .-WFI
