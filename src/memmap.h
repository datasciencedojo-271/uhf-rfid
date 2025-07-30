#ifndef MEMMAP_H
#define MEMMAP_H

#include <stdint.h>
#include "iwdg_types.h"
#include "nvic_types.h"
#include "system_types.h"
#include "systick_types.h"

/* These are volatile as they can be changed by hardware or other threads. */

/* Data Memory */
#define DAT_20000000 ((volatile uint8_t *)0x20000000)
#define DAT_20000026 (*(volatile uint8_t *)0x20000026)
#define DAT_20000027 ((volatile uint8_t *)0x20000027)
#define DAT_2000002F (*(volatile uint8_t *)0x2000002F)
#define DAT_20000030 (*(volatile uint16_t *)0x20000030)
#define DAT_200000A5 (*(volatile uint8_t *)0x200000A5)
#define DAT_20000190 (*(volatile uint16_t *)0x20000190)
#define DAT_20000194 (*(volatile uint8_t *)0x20000194)
#define DAT_20000196 (*(volatile uint16_t *)0x20000196)
#define DAT_20000198 (*(volatile uint8_t *)0x20000198)
#define DAT_200001AA (*(volatile uint16_t *)0x200001AA)
#define DAT_200001AC (*(volatile uint8_t *)0x200001AC)
#define DAT_200001AD (*(volatile uint8_t *)0x200001AD)
#define DAT_200001AE (*(volatile uint8_t *)0x200001AE)
#define DAT_200001AF (*(volatile uint8_t *)0x200001AF)
#define DAT_200001B0 (*(volatile uint8_t *)0x200001B0)
#define DAT_200001B1 (*(volatile uint8_t *)0x200001B1)
#define DAT_200001B2 (*(volatile uint8_t *)0x200001B2)
#define DAT_200001B3 (*(volatile uint8_t *)0x200001B3)
#define DAT_200001B4 (*(volatile uint8_t *)0x200001B4)
#define DAT_200001B5 (*(volatile uint8_t *)0x200001B5)
#define DAT_200001B6 (*(volatile uint8_t *)0x200001B6)
#define DAT_200001B7 (*(volatile uint8_t *)0x200001B7)
#define DAT_200001B8 (*(volatile uint8_t *)0x200001B8)
#define DAT_200001B9 (*(volatile uint8_t *)0x200001B9)
#define DAT_200001BC (*(volatile uint8_t *)0x200001BC)
#define DAT_200001BD (*(volatile uint8_t *)0x200001BD)
#define DAT_200001BE (*(volatile uint8_t *)0x200001BE)
#define DAT_200001BF (*(volatile uint8_t *)0x200001BF)
#define DAT_200001C0 (*(volatile uint8_t *)0x200001C0)
#define DAT_200001C1 (*(volatile uint8_t *)0x200001C1)
#define DAT_200001C2 (*(volatile uint8_t *)0x200001C2)
#define DAT_200001C3 (*(volatile uint8_t *)0x200001C3)
#define DAT_200001C4 (*(volatile uint8_t *)0x200001C4)
#define DAT_200001C5 (*(volatile uint8_t *)0x200001C5)
#define DAT_200001C6 (*(volatile uint8_t *)0x200001C6)
#define DAT_200001C7 (*(volatile uint8_t *)0x200001C7)
#define DAT_200001C8 (*(volatile uint8_t *)0x200001C8)
#define DAT_200001C9 (*(volatile uint8_t *)0x200001C9)
#define DAT_200001CA (*(volatile uint16_t *)0x200001CA)
#define DAT_200001CC ((volatile uint8_t *)0x200001CC)
#define DAT_2000029C ((volatile uint8_t *)0x2000029C)
#define DAT_2000042D ((volatile uint8_t *)0x2000042D)

/* Flash Data */
#define DAT_08009308 ((volatile uint32_t *)0x08009308)
#define DAT_08003090 ((volatile uint32_t *)0x08003090)
#define DAT_2000016C ((volatile uint8_t *)0x2000016C)
#define DAT_20000162 (*(volatile uint8_t *)0x20000162)
#define DAT_2000017E (*(volatile uint16_t *)0x2000017E)
#define DAT_2000017C (*(volatile uint16_t *)0x2000017C)


/* Peripherals */
#define ADDR_40013800 ((volatile void *)0x40013800)
#define ADDR_40010800 ((volatile void *)0x40010800)
#define ADDR_40005C00 ((volatile uint32_t*)0x40005C00)
#define ADDR_42218180 (*(volatile uint8_t*)0x42218180)
#define ADDR_42218000 ((volatile uint32_t*)0x42218000)
#define ADDR_42218190 (*(volatile uint32_t*)0x42218190)
#define ADDR_42218194 (*(volatile uint8_t*)0x42218194)
#define ADDR_42218198 (*(volatile uint8_t*)0x42218198)

#define IWDG ((volatile IWDG_TypeDef *)0x40003000)
#define NVIC ((volatile NVIC_Type *)0xE000E100)
#define SCB ((volatile SCB_Type *)0xE000ED00)
#define SysTick ((volatile SysTick_Type *)0xE000E010)

#endif // MEMMAP_H
