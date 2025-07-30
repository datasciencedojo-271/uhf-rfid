#include "stubs.h"
#include "string.h"

void FUN_00005a40(void) {}
void FUN_00005510(uint8_t a) {}
void* FUN_00001480(void) { return NULL; }
void FUN_0000524c(void *dest, void *src, int size) {}
void FUN_000022e0(uint8_t a, uint16_t b) {}
void FUN_00002c4c(void *buf, int size) {}
void FUN_00005200(void* a, uint8_t b) {}
void FUN_00003b00(void* a) {}
void FUN_000053ec(uint32_t count) {}
void FUN_00005460(uint32_t delay) {}
void rfid_delay(uint16_t milliseconds) {}
void __stack_chk_fail(void) { while(1); }
void FUN_00005a44(void) {}

// #include <string.h> // for memset

// // This function is a stand-in for the firmware's bzero-like function
// void FUN_000003ba(void *dest, int size) {
//     memset(dest, 0, size);
// }

// // Stubs for other functions called from the main loop
// void FUN_00001758(void) {}
// void FUN_00002c4c(void *buf, int size) {}
// void FUN_00000288(void *dest, const void *src, int size) { memcpy(dest, src, size); }
// void FUN_00005460(int delay) {}
// int FUN_00000230(const void* buf1, const void* buf2, int size) { return memcmp(buf1, buf2, size); }
// void FUN_000053ec(int count) {}
// void FUN_0000529c(uint8_t a, uint8_t b, uint8_t c) {}
// void FUN_00005224(uint8_t a, uint8_t b) {}
// void FUN_00005200(void* a, uint8_t b) {}
// void FUN_00004dac(void* a, uint16_t b) {}
// void FUN_00004f46(void* a, uint8_t b) {}
// void FUN_00004a90(void) {}
// void FUN_00003e60(void) {}
// void FUN_00003a6c(void) {}
// void FUN_00003888(void) {}
// void FUN_0000350c(void* a) {}
// void FUN_00001cac(void) {}
// void FUN_00005510(uint8_t a) {}
// void FUN_000054ac(uint16_t a) {}
// void FUN_0000531c(uint8_t a, uint8_t b, void* c) {}
// void FUN_00004e1a(void* a, uint16_t b, uint8_t c) {}
// void FUN_00004d10(void* a) {}
// void FUN_00004cf6(void* a, uint8_t b) {}
// void FUN_000049e8(void* a) {}
// void FUN_00004928(uint8_t a) {}
// void FUN_000047c0(void* a) {}
// void FUN_000046a4(void* a) {}
// void FUN_00004504(void* a) {}
// void FUN_000043d0(void* a) {}
// void FUN_000042b8(void* a) {}
// void FUN_00004264(void) {}
// void FUN_00003d44(void) {}
// void FUN_00003cc0(void) {}
// void FUN_00003be0(void) {}
// void FUN_00003b50(void) {}
// void FUN_00003b00(void* a) {}
// void FUN_0000232c(uint8_t a) {}
// void FUN_000022e0(uint8_t a, uint16_t b) {}
// void FUN_00002220(uint8_t a, uint8_t b) {}
// void FUN_000021bc(uint8_t a) {}
// void FUN_00002174(void) {}
// void FUN_00002148(void) {}
// void FUN_0000056c(void) {}
// void FUN_00001d84(uint32_t a, uint32_t b) {}
// void FUN_000012b6(void* a, void* b) {}
// void FUN_00001a54(void* a) {}
// void FUN_000014a0(void) {}
// void FUN_00005a44(void) {}
// void FUN_0000524c(void *dest, void *src, int size) {}
// void FUN_00001480(void) {}
