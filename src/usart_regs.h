#ifndef USART_REGS_H
#define USART_REGS_H

#include "stdint.h"

#define USART1_BASE 0x40013800
#define USART1 ((USART_TypeDef *) USART1_BASE)

typedef struct
{
  volatile uint16_t SR;
  uint16_t  RESERVED0;
  volatile uint16_t DR;
  uint16_t  RESERVED1;
  volatile uint16_t BRR;
  uint16_t  RESERVED2;
  volatile uint16_t CR1;
  uint16_t  RESERVED3;
  volatile uint16_t CR2;
  uint16_t  RESERVED4;
  volatile uint16_t CR3;
  uint16_t  RESERVED5;
  volatile uint16_t GTPR;
  uint16_t  RESERVED6;
} USART_TypeDef;

// Bit definitions for USART_CR1
#define USART_CR1_UE_Pos      13
#define USART_CR1_UE_Msk      (0x1U << USART_CR1_UE_Pos)
#define USART_CR1_UE          USART_CR1_UE_Msk
#define USART_CR1_M_Pos       12
#define USART_CR1_M_Msk       (0x1U << USART_CR1_M_Pos)
#define USART_CR1_M           USART_CR1_M_Msk
#define USART_CR1_WAKE_Pos    11
#define USART_CR1_WAKE_Msk    (0x1U << USART_CR1_WAKE_Pos)
#define USART_CR1_WAKE        USART_CR1_WAKE_Msk
#define USART_CR1_PCE_Pos     10
#define USART_CR1_PCE_Msk     (0x1U << USART_CR1_PCE_Pos)
#define USART_CR1_PCE         USART_CR1_PCE_Msk
#define USART_CR1_PS_Pos      9
#define USART_CR1_PS_Msk      (0x1U << USART_CR1_PS_Pos)
#define USART_CR1_PS          USART_CR1_PS_Msk
#define USART_CR1_PEIE_Pos    8
#define USART_CR1_PEIE_Msk    (0x1U << USART_CR1_PEIE_Pos)
#define USART_CR1_PEIE        USART_CR1_PEIE_Msk
#define USART_CR1_TXEIE_Pos   7
#define USART_CR1_TXEIE_Msk   (0x1U << USART_CR1_TXEIE_Pos)
#define USART_CR1_TXEIE       USART_CR1_TXEIE_Msk
#define USART_CR1_TCIE_Pos    6
#define USART_CR1_TCIE_Msk    (0x1U << USART_CR1_TCIE_Pos)
#define USART_CR1_TCIE        USART_CR1_TCIE_Msk
#define USART_CR1_RXNEIE_Pos  5
#define USART_CR1_RXNEIE_Msk  (0x1U << USART_CR1_RXNEIE_Pos)
#define USART_CR1_RXNEIE      USART_CR1_RXNEIE_Msk
#define USART_CR1_IDLEIE_Pos  4
#define USART_CR1_IDLEIE_Msk  (0x1U << USART_CR1_IDLEIE_Pos)
#define USART_CR1_IDLEIE      USART_CR1_IDLEIE_Msk
#define USART_CR1_TE_Pos      3
#define USART_CR1_TE_Msk      (0x1U << USART_CR1_TE_Pos)
#define USART_CR1_TE          USART_CR1_TE_Msk
#define USART_CR1_RE_Pos      2
#define USART_CR1_RE_Msk      (0x1U << USART_CR1_RE_Pos)
#define USART_CR1_RE          USART_CR1_RE_Msk
#define USART_CR1_RWU_Pos     1
#define USART_CR1_RWU_Msk     (0x1U << USART_CR1_RWU_Pos)
#define USART_CR1_RWU         USART_CR1_RWU_Msk
#define USART_CR1_SBK_Pos     0
#define USART_CR1_SBK_Msk     (0x1U << USART_CR1_SBK_Pos)
#define USART_CR1_SBK         USART_CR1_SBK_Msk

// Bit definitions for USART_SR
#define USART_SR_TXE_Pos      7
#define USART_SR_TXE_Msk      (0x1U << USART_SR_TXE_Pos)
#define USART_SR_TXE          USART_SR_TXE_Msk
#define USART_SR_TC_Pos       6
#define USART_SR_TC_Msk       (0x1U << USART_SR_TC_Pos)
#define USART_SR_TC           USART_SR_TC_Msk
#define USART_SR_RXNE_Pos     5
#define USART_SR_RXNE_Msk     (0x1U << USART_SR_RXNE_Pos)
#define USART_SR_RXNE         USART_SR_RXNE_Msk

#endif // USART_REGS_H
