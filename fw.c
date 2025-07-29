#include "fw.h"

// This file is a direct translation of the assembly code from fw.lst
// It is not intended to be readable or maintainable, but rather to
// demonstrate an understanding of the assembly code.

// Global variables
uint32_t MasterStackPointer;

// Interrupt Service Routines
void Reset_Handler(void);
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVCall_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void IRQ_Handler(void);

// Function prototypes
int FUN_00000230(char *param_1, char *param_2, int param_3);
void FUN_00000288(void);
void FUN_00000312(void);
void FUN_00000376(void);
void FUN_000003ba(void);
void FUN_0000047e(void);
void FUN_000004a0(void);
void FUN_000004f8(void);
void FUN_0000051c(void);
void FUN_0000056c(void);
void FUN_000008c0(void);
void FUN_00000cbc(void);
void FUN_00000d7c(void);
void FUN_00000e64(void);
void FUN_000012b6(void);
void FUN_000013c8(void);
void FUN_00001458(void);
void FUN_0000145c(void);
void FUN_00001460(void);
void FUN_00001480(void);
void FUN_000014a0(void);
void FUN_000014f4(void);
void FUN_00001590(void);
void FUN_000015cc(void);
void FUN_00001628(void);
void FUN_00001684(void);
void FUN_000016c0(void);
void FUN_000016f8(void);
void FUN_00001748(void);
void FUN_00001758(void);
void FUN_00001760(void);
void FUN_00001784(void);
void FUN_00001794(void);
void FUN_000017a0(void);
void FUN_000017ac(void);
void FUN_000017b8(void);
void FUN_00001a54(void);
void FUN_00001cac(void);
void FUN_00001c6c(void);
void FUN_00001d64(void);
void FUN_00001d84(void);
void FUN_00001da4(void);
void FUN_00001e10(void);
void FUN_00001ee4(void);
void FUN_00002052(void);
void FUN_00002148(void);
void FUN_00002174(void);
void FUN_000021bc(void);
void FUN_00002220(void);
void FUN_0000226c(void);
void FUN_000022e0(void);
void FUN_0000232c(void);
void FUN_00002996(void);
void FUN_00002b5c(void);
void FUN_00002b74(void);
void FUN_00002c4c(void);
void FUN_00002c8c(void);
void FUN_0000350c(void);
void FUN_00003614(void);
void FUN_00003888(void);
void FUN_000038fc(void);
void FUN_00003984(void);
void FUN_000039e4(void);
void FUN_00003a24(void);
void FUN_00003a6c(void);
void FUN_00003b00(void);
void FUN_00003b50(void);
void FUN_00003be0(void);
void FUN_00003c40(void);
void FUN_00003cc0(void);
void FUN_00003d44(void);
void FUN_00003e00(void);
void FUN_00003e60(void);
void FUN_00003fa0(void);
void FUN_00004264(void);
void FUN_000042b8(void);
void FUN_000043d0(void);
void FUN_0000448c(void);
void FUN_00004504(void);
void FUN_000046a4(void);
void FUN_000047c0(void);
void FUN_00004828(void);
void FUN_00004928(void);
void FUN_000049e8(void);
void FUN_00004a90(void);
void FUN_00004af0(void);
void FUN_00004d10(void);
void FUN_00004dac(void);
void FUN_00004cf6(void);
void FUN_00004e1a(void);
void FUN_00004e64(void);
void FUN_00004f46(void);
void FUN_00004f50(void);
void FUN_00005200(void);
void FUN_00005224(void);
void FUN_0000524c(void);
void FUN_00005286(void);
void FUN_0000529c(void);
void FUN_0000531c(void);
void FUN_0000539c(void);
void FUN_000053ec(void);
void FUN_00005424(void);
void FUN_00005460(void);
void FUN_000054ac(void);
void FUN_00005a40(void);
void FUN_00005a44(void);

// This is a placeholder for the memory map.
// In a real application, this would be defined in a linker script.
uint32_t DAT_7d0b1476;
uint32_t DAT_08005251;
uint32_t DAT_08004ce9;
uint32_t DAT_0800524d;
uint32_t DAT_08003da1;
uint32_t DAT_08008a47;
uint32_t DAT_080059a9;
uint32_t DAT_080049b9;
uint32_t DAT_080054ab;
uint32_t DAT_08006195;
uint32_t DAT_08008a85;
uint32_t DAT_40010C00;
uint32_t DAT_42218180;

// Vector table
const uint32_t __vector_table[] __attribute__((section(".isr_vector"))) = {
    (uint32_t)&MasterStackPointer,
    (uint32_t)Reset_Handler,
    (uint32_t)NMI_Handler,
    (uint32_t)HardFault_Handler,
    (uint32_t)MemManage_Handler,
    (uint32_t)BusFault_Handler,
    (uint32_t)UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uint32_t)SVCall_Handler,
    (uint32_t)PendSV_Handler,
    0,
    (uint32_t)SysTick_Handler,
    (uint32_t)IRQ_Handler,
};

void Reset_Handler(void) {
    // This is a placeholder for the reset handler.
    // In a real application, this would initialize the hardware.
    while (1);
}

void NMI_Handler(void) {
    while (1);
}

void HardFault_Handler(void) {
    while (1);
}

void MemManage_Handler(void) {
    while (1);
}

void BusFault_Handler(void) {
    while (1);
}

void UsageFault_Handler(void) {
    while (1);
}

void SVCall_Handler(void) {
    while (1);
}

void PendSV_Handler(void) {
    while (1);
}

void SysTick_Handler(void) {
    while (1);
}

void IRQ_Handler(void) {
    while (1);
}

int FUN_00000230(uint *param_1,uint *param_2,uint param_3) {
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;

  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    while (3 < param_3) {
      uVar5 = *param_1;
      param_1 = param_1 + 1;
      uVar3 = *param_2;
      param_2 = param_2 + 1;
      param_3 = param_3 - 4;
      if (uVar5 != uVar3) {
        if ((uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
            uVar5 >> 0x18) <=
            (uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
            uVar3 >> 0x18)) {
          return -1;
        }
        return 1;
      }
    }
  }
  if (param_3 != 0) {
    if ((param_3 & 1) == 0) goto LAB_00000268;
    param_3 = param_3 + 1;
    puVar1 = param_1;
    puVar2 = param_2;
    while( true ) {
      param_1 = (uint *)((int)puVar1 + 1);
      param_2 = (uint *)((int)puVar2 + 1);
      iVar4 = (uint)(byte)*puVar1 - (uint)(byte)*puVar2;
      if (iVar4 != 0) {
        return iVar4;
      }
      param_3 = param_3 - 2;
      if (param_3 == 0) break;
LAB_00000268:
      puVar1 = (uint *)((int)param_1 + 1);
      puVar2 = (uint *)((int)param_2 + 1);
      iVar4 = (uint)(byte)*param_1 - (uint)(byte)*param_2;
      if (iVar4 != 0) {
        return iVar4;
      }
    }
    return 0;
  }
  return 0;
}

undefined8 FUN_00000288(uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  byte *pbVar5;
  byte bVar6;
  undefined2 uVar7;
  byte in_r12;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;

  puVar4 = param_2;
  if (3 < param_3) {
    uVar8 = (uint)param_1 & 3;
    puVar2 = param_1;
    uVar9 = uVar8;
    if (uVar8 != 0) {
      bVar6 = (byte)*param_2;
      puVar4 = (uint *)((int)param_2 + 1);
      if (uVar8 < 3) {
        puVar4 = (uint *)((int)param_2 + 2);
        uVar9 = (uint)*(byte *)((int)param_2 + 1);
      }
      *(byte *)param_1 = bVar6;
      param_2 = puVar4;
      if (uVar8 < 2) {
        param_2 = (uint *)((int)puVar4 + 1);
        bVar6 = (byte)*puVar4;
      }
      param_3 = (param_3 + uVar8) - 4;
      puVar4 = (uint *)((int)param_1 + 1);
      if (uVar8 < 3) {
        puVar4 = (uint *)((int)param_1 + 2);
        *(byte *)((int)param_1 + 1) = (byte)uVar9;
      }
      puVar2 = puVar4;
      if (uVar8 < 2) {
        puVar2 = (uint *)((int)puVar4 + 1);
        *(byte *)puVar4 = bVar6;
      }
    }
    param_4 = (uint)param_2 & 3;
    if (param_4 == 0) {
      uVar9 = 0;
      while (uVar8 = param_3 - 0x20, 0x1f < param_3) {
        uVar9 = param_2[1];
        uVar10 = param_2[2];
        uVar11 = param_2[3];
        *puVar2 = *param_2;
        puVar2[1] = uVar9;
        puVar2[2] = uVar10;
        puVar2[3] = uVar11;
        uVar9 = param_2[4];
        uVar10 = param_2[5];
        uVar11 = param_2[6];
        uVar12 = param_2[7];
        param_2 = param_2 + 8;
        puVar2[4] = uVar9;
        puVar2[5] = uVar10;
        puVar2[6] = uVar11;
        puVar2[7] = uVar12;
        puVar2 = puVar2 + 8;
        param_3 = uVar8;
      }
      if ((uVar8 & 0x10) != 0) {
        uVar9 = *param_2;
        uVar10 = param_2[1];
        uVar11 = param_2[2];
        uVar12 = param_2[3];
        param_2 = param_2 + 4;
        *puVar2 = uVar9;
        puVar2[1] = uVar10;
        puVar2[2] = uVar11;
        puVar2[3] = uVar12;
        puVar2 = puVar2 + 4;
      }
      if ((int)(param_3 << 0x1c) < 0) {
        uVar9 = *param_2;
        uVar10 = param_2[1];
        param_2 = param_2 + 2;
        *puVar2 = uVar9;
        puVar2[1] = uVar10;
        puVar2 = puVar2 + 2;
      }
      puVar3 = puVar2;
      puVar4 = param_2;
      if ((uVar8 & 4) != 0) {
        puVar4 = param_2 + 1;
        uVar9 = *param_2;
        puVar3 = puVar2 + 1;
        *puVar2 = uVar9;
      }
      uVar7 = (undefined2)uVar9;
      if ((uVar8 & 3) != 0) {
        bVar1 = (uVar8 & 2) != 0;
        param_3 = param_3 << 0x1f;
        bVar13 = (int)param_3 < 0;
        puVar2 = puVar4;
        if (bVar1) {
          puVar2 = (uint *)((int)puVar4 + 2);
          uVar7 = (undefined2)*puVar4;
        }
        puVar4 = puVar2;
        if (bVar13) {
          puVar4 = (uint *)((int)puVar2 + 1);
          param_3 = (uint)(byte)*puVar2;
        }
        puVar2 = puVar3;
        if (bVar1) {
          puVar2 = (uint *)((int)puVar3 + 2);
          *(undefined2 *)puVar3 = uVar7;
        }
        puVar3 = puVar2;
        if (bVar13) {
          puVar3 = (uint *)((int)puVar2 + 1);
          *(byte *)puVar2 = (byte)param_3;
        }
        return CONCAT44(puVar4,puVar3);
      }
      return CONCAT44(puVar4,puVar3);
    }
    while( true ) {
      in_r12 = (byte)uVar9;
      if (param_3 < 8) break;
      puVar4 = param_2 + 1;
      param_4 = *param_2;
      param_2 = param_2 + 2;
      uVar9 = *puVar4;
      *puVar2 = param_4;
      puVar2[1] = uVar9;
      puVar2 = puVar2 + 2;
      param_3 = param_3 - 8;
    }
    param_3 = param_3 - 4;
    param_1 = puVar2;
    puVar4 = param_2;
    if (-1 < (int)param_3) {
      puVar4 = param_2 + 1;
      param_4 = *param_2;
      param_1 = puVar2 + 1;
      *puVar2 = param_4;
    }
  }
  bVar6 = (byte)param_4;
  bVar1 = (param_3 & 2) != 0;
  param_3 = param_3 << 0x1f;
  bVar13 = (int)param_3 < 0;
  if (bVar1) {
    pbVar5 = (byte *)((int)puVar4 + 1);
    bVar6 = (byte)*puVar4;
    puVar4 = (uint *)((int)puVar4 + 2);
    in_r12 = *pbVar5;
  }
  puVar2 = puVar4;
  if (bVar13) {
    puVar2 = (uint *)((int)puVar4 + 1);
    param_3 = (uint)(byte)*puVar4;
  }
  if (bVar1) {
    pbVar5 = (byte *)((int)param_1 + 1);
    *(byte *)param_1 = bVar6;
    param_1 = (uint *)((int)param_1 + 2);
    *pbVar5 = in_r12;
  }
  puVar4 = param_1;
  if (bVar13) {
    puVar4 = (uint *)((int)param_1 + 1);
    *(byte *)param_1 = (byte)param_3;
  }
  return CONCAT44(puVar2,puVar4);
}

void FUN_0000051c(int param_1, uint param_2) {
    FUN_00001684();
    FUN_00001628((uint)(byte)(param_1 >> 8) * 2 + 0xa0);
    FUN_000016f8();
    FUN_00001628((uint)(byte)param_1);
    FUN_000016f8();
    FUN_00001628(param_2);
    FUN_000016f8();
    FUN_000016c0();
    FUN_00005460(10);
    return;
}

void FUN_0000056c(void) {
    FUN_00001d84(8, 1);
    *(uint16_t *)0x20000000 = 1;
    *(uint8_t *)0x20000002 = 0x10;
    *(uint8_t *)0x20000003 = 3;
    FUN_000012b6(DAT_40010C00, 0x20000000);
    *(uint32_t *)DAT_42218180 = 0;
    return;
}

byte FUN_000008c0(byte *param_1, int param_2) {
    byte bVar1;
    int iVar2;

    bVar1 = 0;
    if (param_2 != 0) {
        iVar2 = 0;
        do {
            bVar1 = bVar1 + param_1[iVar2];
            iVar2 = iVar2 + 1;
        } while (iVar2 < param_2);
    }
    return (byte) - bVar1;
}

void FUN_00000cbc(void) {
    uint uVar1;
    int iVar2;
    undefined *puVar3;
    uint uVar4;

    puVar3 = *(undefined **)PTR_DAT_2000016c;
    if ((*(short *)(puVar3 + 0x10) == 0) && (puVar3[8] == 4)) {
        if (*(char *)PTR_DAT_20000162 == '\x01') {
            iVar2 = *(int *)(*(int *)PTR_DAT_40005c50 + 2);
            *(uint *)(*(int *)PTR_DAT_40006000 + iVar2 * 2) = 0;
            *(undefined2 *)PTR_DAT_2000017e = 0x30;
            *(undefined *)PTR_DAT_20000162 = 0;
        } else {
            puVar3[8] = 7;
            *(undefined2 *)PTR_DAT_2000017e = 0x10;
        }
    } else {
        uVar4 = (uint) * (ushort *)(puVar3 + 0x14);
        uVar1 = (uint) * (ushort *)(puVar3 + 0x10);
        if (uVar1 < uVar4) {
            uVar4 = uVar1;
        }
        iVar2 = FUN_00000288(*(undefined4 *)(puVar3 + 0x18), uVar4);
        uVar4 = FUN_00001480(0);
        FUN_0000524c(iVar2, uVar4, uVar1);
        FUN_000022e0(0, uVar1);
        *(short *)(puVar3 + 0x10) = *(short *)(puVar3 + 0x10) - (short)uVar1;
        *(short *)(puVar3 + 0x12) = *(short *)(puVar3 + 0x12) + (short)uVar1;
        *(undefined2 *)PTR_DAT_2000017e = 0x30;
        *(undefined2 *)PTR_DAT_2000017c = 0x3000;
        if (uVar4 < uVar1) {
            puVar3[8] = 2;
        } else {
            puVar3[8] = 4;
        }
    }
    return;
}

void FUN_00000d7c(void) {
    ushort uVar1;
    uint uVar2;
    undefined *puVar3;
    uint uVar4;
    uint uVar5;

    puVar3 = *(undefined **)PTR_DAT_2000016c;
    if ((puVar3[1] == 9) && (puVar3[0] == 0x21)) {
        uVar2 = FUN_00001460(0);
        FUN_00001c6c(local_bc, uVar2, 8);
    }
    if (*(code **)(puVar3 + 0x18) != (code *)0x0) {
        uVar1 = *(ushort *)(puVar3 + 0x10);
        if (uVar1 != 0) {
            uVar4 = (uint) * (ushort *)(puVar3 + 0x14);
            if ((int)uVar1 < (int)uVar4) {
                uVar4 = (uint)uVar1;
            }
            uVar5 = (**(code **)(puVar3 + 0x18))(*(undefined4 *)(puVar3 + 0x18), uVar4);
            *(ushort *)(puVar3 + 0x10) = uVar1 - (ushort)uVar4;
            *(ushort *)(puVar3 + 0x12) = *(ushort *)(puVar3 + 0x12) + (ushort)uVar4;
            uVar2 = FUN_00001460(0);
            FUN_00001c6c(uVar5, uVar2, uVar4);
        }
    }
    if (*(ushort *)(puVar3 + 0x10) == 0) {
        puVar3[8] = 6;
        iVar2 = *(int *)(*(int *)PTR_DAT_40005c50 + 2);
        *(uint *)(*(int *)PTR_DAT_40006000 + iVar2 * 2) = 0;
        *(undefined2 *)PTR_DAT_2000017e = 0x30;
    } else {
        *(undefined2 *)PTR_DAT_2000017c = 0x3000;
        FUN_000022e0(0, 0);
        *(undefined2 *)PTR_DAT_2000017e = 0x30;
        if ((ushort) * (ushort *)(puVar3 + 0x10) <= * (ushort *)(puVar3 + 0x14)) {
            puVar3[8] = 3;
        } else {
            puVar3[8] = 5;
        }
    }
    return;
}

void FUN_00001458(undefined4 param_1, undefined4 param_2) {
    *(undefined4 *)(param_1 + 0x14) = param_2;
    return;
}

void FUN_0000145c(void) {
    undefined *puVar1;
    undefined *puVar2;
    uint uVar3;
    int iVar4;
    uint uVar5;
    uint uVar6;
    undefined4 uVar7;
    uint uVar8;

    puVar1 = *(undefined **)PTR_DAT_2000016c;
    uVar7 = 0;
    if (puVar1[1] == 6) {
        if ((puVar1[0] & 0x7f) == 0) {
            puVar2 = *(undefined **)PTR_DAT_20000170;
            if (puVar1[2] == 1) {
                uVar7 = *(undefined4 *)(puVar2 + 0x1c);
            } else if (puVar1[2] == 2) {
                uVar7 = *(undefined4 *)(puVar2 + 0x20);
            } else if (puVar1[2] == 3) {
                uVar7 = *(undefined4 *)(puVar2 + 0x24);
            }
        }
    } else if (puVar1[1] < 7) {
        if (puVar1[1] == 0) {
            if (((*(ushort *)(puVar1 + 2) == 0) && (*(ushort *)(puVar1 + 6) == 2)) &&
                ((puVar1[4] == 0 && ((puVar1[0] & 0x7fU) == 0)))) {
                if (*(ushort *)(puVar1 + 4) == 0) {
                    uVar7 = DAT_08005e75;
                }
            } else {
                uVar3 = (uint)puVar1[0] & 0x7f;
                if (uVar3 == 1) {
                    iVar4 = (**(code **)(*(int *)PTR_DAT_20000170 + 0x18))
                        (puVar1[5]);
                    if ((iVar4 != 0) || (puVar1[10] != 0)) {
                        uVar7 = DAT_08005e75;
                    }
                } else if (uVar3 == 2) {
                    uVar3 = (uint)puVar1[5] & 0xf;
                    uVar8 = (uint)puVar1[5] & 0x70;
                    if ((puVar1[5] & 0x80) == 0) {
                        uVar5 = *(uint *)(*(int *)PTR_DAT_40005c00 + uVar3 * 4);
                        uVar6 = uVar5 & 0x3000;
                    } else {
                        uVar5 = *(uint *)(*(int *)PTR_DAT_40005c00 + uVar3 * 4);
                        uVar6 = uVar5 & 0x30;
                    }
                    if (((uVar3 < (uint) * (byte *)PTR_DAT_200000a5) && (uVar8 == 0)) && (uVar6 != 0)) {
                        uVar7 = DAT_08005e75;
                    }
                }
            }
        }
    } else if (puVar1[1] == 8) {
        if ((puVar1[0] & 0x7f) == 0) {
            uVar7 = DAT_08005df9;
        }
    } else if (puVar1[1] == 10) {
        if ((((puVar1[0] & 0x7f) == 1) && (puVar1[10] != 0)) &&
            (((*(ushort *)(puVar1 + 2) == 0 && (puVar1[4] == 0)) && (*(ushort *)(puVar1 + 6) == 1)))) {
            iVar4 = (**(code **)(*(int *)PTR_DAT_20000170 + 0x18))(puVar1[5]);
            if (iVar4 == 0) {
                uVar7 = DAT_08005e49;
            }
        }
    } else if ((puVar1[1] == 9) && ((puVar1[0] & 0x7f) == 0x21)) {
        puVar3[8] = 3;
        *(undefined2 *)PTR_DAT_2000017c = 0x3000;
    }
    if (uVar7 != 0) {
        *(undefined2 *)(puVar1 + 0x12) = 0;
        *(undefined4 *)(puVar1 + 0x18) = uVar7;
        (*(code *)uVar7)();
    }
    return;
}

void FUN_000012b6(int param_1, ushort *param_2) {
    uint uVar1;
    uint uVar2;
    uint uVar3;
    uint uVar4;
    int iVar5;
    uint uVar6;
    uint uVar7;

    uVar7 = 0;
    uVar6 = 0;
    uVar4 = 0;
    uVar3 = 0;
    uVar2 = (uint) * (byte *)((int)param_2 + 3);
    uVar1 = uVar2 & 0xf;
    if ((uVar2 & 0x10) != 0) {
        uVar1 = uVar1 | (uint) * (byte *)((int)param_2 + 2);
    }
    if (*param_2 != 0) {
        iVar5 = *(int *)param_1;
        uVar2 = 0;
        do {
            uVar7 = 1 << (uVar2 & 0xff);
            if ((*param_2 & uVar7) != 0) {
                uVar6 = 0xf << (uVar2 & 0xff) * 4;
                iVar5 = iVar5 & ~uVar6 | (uVar1 << (uVar2 & 0xff) * 4) & uVar6;
                if (*(char *)((int)param_2 + 3) == 0x28) {
                    *(uint *)(param_1 + 0x14) = uVar7;
                } else if (*(char *)((int)param_2 + 3) == 0x48) {
                    *(uint *)(param_1 + 0x10) = uVar7;
                }
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < 8);
        *(int *)param_1 = iVar5;
    }
    if (0xff < *param_2) {
        iVar5 = *(int *)(param_1 + 4);
        uVar2 = 0;
        do {
            uVar4 = 1 << (uVar2 & 0xff) + 8;
            if ((*param_2 & uVar4) != 0) {
                uVar6 = 0xf << (uVar2 & 0xff) * 4;
                iVar5 = iVar5 & ~uVar6 | (uVar1 << (uVar2 & 0xff) * 4) & uVar6;
                if (*(char *)((int)param_2 + 3) == 0x28) {
                    *(uint *)(param_1 + 0x14) = uVar4;
                } else if (*(char *)((int)param_2 + 3) == 0x48) {
                    *(uint *)(param_1 + 0x10) = uVar4;
                }
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < 8);
        *(int *)(param_1 + 4) = iVar5;
    }
    return;
}

void FUN_000013c8(uint param_1, undefined4 param_2) {
    uint uVar1;
    uint uVar2;

    if ((param_1 & 0x80000000) == 0) {
        uVar2 = *(uint *)(DAT_40010000 + 4);
        uVar1 = *(uint *)(DAT_40010000 + 0x1c);
    } else {
        uVar2 = *(uint *)(DAT_40010000 + 0x1c);
        uVar1 = *(uint *)(DAT_40010000 + 4);
    }
    if ((param_1 & 0x600000) == 0x600000) {
        uVar1 = uVar1 & 0xf0ffffff;
        uVar2 = uVar2 & 0xf0ffffff;
    } else if ((param_1 & 0x200000) == 0x200000) {
        uVar1 = (uVar1 & ~(3 << ((uint)((byte)(param_1 >> 0x10) & 3) * 4))) | 0xf0000000;
    } else {
        uVar1 = (uVar1 & ~((uint)param_2 << ((param_1 >> 0x15) * 0x10 & 0xff))) | 0xf0000000;
    }
    if (param_2 != 0) {
        uVar1 = uVar1 | (uint)param_2 << ((param_1 >> 0x15) * 0x10 & 0xff);
    }
    if ((param_1 & 0x80000000) == 0) {
        *(uint *)(DAT_40010000 + 4) = uVar1;
        return;
    }
    *(uint *)(DAT_40010000 + 0x1c) = uVar1;
    return;
}

void FUN_000014a0(void) {
    uint uVar1;
    uint uVar2;
    uint uVar3;
    uint *puVar4;
    undefined *puVar5;

    puVar4 = (uint *)0x1ffff7e8;
    uVar1 = *puVar4;
    uVar2 = puVar4[1];
    uVar3 = puVar4[2];
    if (uVar1 != 0) {
        puVar5 = (undefined *)PTR_DAT_20000048;
        *(undefined *)(puVar5 + 2) = (char)uVar1;
        *(undefined *)(puVar5 + 4) = (char)(uVar1 >> 8);
        *(undefined *)(puVar5 + 6) = (char)(uVar1 >> 0x10);
        *(undefined *)(puVar5 + 8) = (char)(uVar1 >> 0x18);
        *(undefined *)(puVar5 + 10) = (char)uVar2;
        *(undefined *)(puVar5 + 0xc) = (char)(uVar2 >> 8);
        *(undefined *)(puVar5 + 0xe) = (char)(uVar2 >> 0x10);
        *(undefined *)(puVar5 + 0x10) = (char)(uVar2 >> 0x18);
        *(undefined *)(puVar5 + 0x12) = (char)uVar3;
        *(undefined *)(puVar5 + 0x14) = (char)(uVar3 >> 8);
        *(undefined *)(puVar5 + 0x16) = (char)(uVar3 >> 0x10);
        *(undefined *)(puVar5 + 0x18) = (char)(uVar3 >> 0x18);
    }
    return;
}

void FUN_000014f4(void) {
    *(undefined4 *)PTR_DAT_422181a8 = 0;
    FUN_00002174();
    *(undefined4 *)((int)PTR_DAT_42218000 + 0x1ac) = 0;
    FUN_000054ac(2);
    *(undefined4 *)PTR_DAT_422181a8 = 1;
    FUN_000054ac(2);
    *(undefined4 *)((int)PTR_DAT_42218000 + 0x1a8) = 0;
    return;
}

void FUN_00001590(void) {
    *(undefined4 *)PTR_DAT_422181a8 = 0;
    FUN_00002174();
    *(undefined4 *)((int)PTR_DAT_42218000 + 0x1ac) = 1;
    FUN_000054ac(2);
    *(undefined4 *)PTR_DAT_422181a8 = 1;
    FUN_000054ac(2);
    *(undefined4 *)((int)PTR_DAT_42218000 + 0x1a8) = 0;
    return;
}

undefined FUN_000015cc(uint param_1) {
    byte bVar1;
    int iVar2;

    bVar1 = 0;
    FUN_00002148();
    iVar2 = 0;
    do {
        *(undefined4 *)PTR_DAT_422181a8 = 0;
        FUN_000054ac(2);
        *(undefined4 *)((int)PTR_DAT_42218000 + 0x1a8) = 1;
        bVar1 = (byte)((uint)bVar1 << 1);
        if (*(int *)PTR_DAT_4221812c != 0) {
            bVar1 = bVar1 | 1;
        }
        FUN_000054ac(1);
        iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    if ((param_1 & 1) == 0) {
        FUN_00001590();
    } else {
        FUN_000014f4();
    }
    return bVar1;
}

void FUN_00001628(byte param_1) {
    int iVar1;

    FUN_00002174();
    *(undefined4 *)PTR_DAT_422181a8 = 0;
    iVar1 = 0;
    do {
        *(undefined4 *)((int)PTR_DAT_42218000 + 0x1ac) = (uint)(param_1 >> 7);
        param_1 = param_1 << 1;
        FUN_000054ac(2);
        *(undefined4 *)((int)PTR_DAT_42218000 + 0x1a8) = 1;
        FUN_000054ac(2);
        *(undefined4 *)PTR_DAT_422181a8 = 0;
        FUN_000054ac(2);
        iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
    return;
}

void FUN_00001684(void) {
    FUN_00002174();
    *(undefined4 *)PTR_DAT_422181ac = 1;
    *(undefined4 *)((int)PTR_DAT_42218000 + 0x1a8) = 1;
    FUN_000054ac(4);
    *(undefined4 *)PTR_DAT_422181ac = 0;
    FUN_000054ac(4);
    *(undefined4 *)((int)PTR_DAT_42218000 + 0x1a8) = 0;
    return;
}

void FUN_000012b6(int param_1, ushort *param_2) {
    uint uVar1;
    uint uVar2;
    uint uVar3;
    uint uVar4;
    int iVar5;
    uint uVar6;
    uint uVar7;

    uVar7 = 0;
    uVar6 = 0;
    uVar4 = 0;
    uVar3 = 0;
    uVar2 = (uint) * (byte *)((int)param_2 + 3);
    uVar1 = uVar2 & 0xf;
    if ((uVar2 & 0x10) != 0) {
        uVar1 = uVar1 | (uint) * (byte *)((int)param_2 + 2);
    }
    if (*param_2 != 0) {
        iVar5 = *(int *)param_1;
        uVar2 = 0;
        do {
            uVar7 = 1 << (uVar2 & 0xff);
            if ((*param_2 & uVar7) != 0) {
                uVar6 = 0xf << (uVar2 & 0xff) * 4;
                iVar5 = iVar5 & ~uVar6 | (uVar1 << (uVar2 & 0xff) * 4) & uVar6;
                if (*(char *)((int)param_2 + 3) == 0x28) {
                    *(uint *)(param_1 + 0x14) = uVar7;
                } else if (*(char *)((int)param_2 + 3) == 0x48) {
                    *(uint *)(param_1 + 0x10) = uVar7;
                }
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < 8);
        *(int *)param_1 = iVar5;
    }
    if (0xff < *param_2) {
        iVar5 = *(int *)(param_1 + 4);
        uVar2 = 0;
        do {
            uVar4 = 1 << (uVar2 & 0xff) + 8;
            if ((*param_2 & uVar4) != 0) {
                uVar6 = 0xf << (uVar2 & 0xff) * 4;
                iVar5 = iVar5 & ~uVar6 | (uVar1 << (uVar2 & 0xff) * 4) & uVar6;
                if (*(char *)((int)param_2 + 3) == 0x28) {
                    *(uint *)(param_1 + 0x14) = uVar4;
                } else if (*(char *)((int)param_2 + 3) == 0x48) {
                    *(uint *)(param_1 + 0x10) = uVar4;
                }
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < 8);
        *(int *)(param_1 + 4) = iVar5;
    }
    return;
}

void FUN_000016f8(void) {
    int iVar1;
    undefined uVar2;

    uVar2 = 0;
    FUN_00002148();
    *(undefined4 *)PTR_DAT_422181ac = 1;
    FUN_000054ac();
    *(undefined4 *)((int)PTR_DAT_42218000 + 0x1a8) = 1;
    FUN_000054ac();
    iVar1 = 0xff;
    do {
        if (*(int *)PTR_DAT_4221812c == 0) {
            *(undefined4 *)PTR_DAT_422181a8 = 0;
            return uVar2;
        }
        iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    FUN_000016c0();
    return 1;
}

void FUN_00001458(undefined4 param_1, undefined4 param_2) {
    *(undefined4 *)(param_1 + 0x14) = param_2;
    return;
}

void FUN_0000145c(undefined4 param_1, undefined4 param_2) {
    *(undefined4 *)(param_1 + 0x10) = param_2;
    return;
}

ushort FUN_00001460(int param_1) {
    return *(ushort *)(*(int *)PTR_DAT_40006000 +
                       ((uint) * (ushort *)PTR_DAT_40005c50 + (uint)(param_1 << 3) + 4) * 2);
}

ushort FUN_00001480(int param_1) {
    return *(ushort *)(*(int *)PTR_DAT_40006000 +
                       ((uint) * (ushort *)PTR_DAT_40005c50 + (uint)(param_1 << 3)) * 2);
}

void FUN_00001794(void) {
    uint uVar1;
    uint uVar2;
    uint uVar3;
    uint *puVar4;
    undefined *puVar5;

    puVar4 = (uint *)0x1ffff7e8;
    uVar1 = *puVar4;
    uVar2 = puVar4[1];
    uVar3 = puVar4[2];
    if (uVar1 != 0) {
        puVar5 = (undefined *)PTR_DAT_20000048;
        *(undefined *)(puVar5 + 2) = (char)uVar1;
        *(undefined *)(puVar5 + 4) = (char)(uVar1 >> 8);
        *(undefined *)(puVar5 + 6) = (char)(uVar1 >> 0x10);
        *(undefined *)(puVar5 + 8) = (char)(uVar1 >> 0x18);
        *(undefined *)(puVar5 + 10) = (char)uVar2;
        *(undefined *)(puVar5 + 0xc) = (char)(uVar2 >> 8);
        *(undefined *)(puVar5 + 0xe) = (char)(uVar2 >> 0x10);
        *(undefined *)(puVar5 + 0x10) = (char)(uVar2 >> 0x18);
        *(undefined *)(puVar5 + 0x12) = (char)uVar3;
        *(undefined *)(puVar5 + 0x14) = (char)(uVar3 >> 8);
        *(undefined *)(puVar5 + 0x16) = (char)(uVar3 >> 0x10);
        *(undefined *)(puVar5 + 0x18) = (char)(uVar3 >> 0x18);
    }
    return;
}

void FUN_00001da4(uint param_1, int param_2) {
    uint uVar1;

    if (param_2 == 0) {
        uVar1 = *(uint *)(DAT_40021000 + 0xc) & ~param_1;
    } else {
        uVar1 = *(uint *)(DAT_40021000 + 0xc) | param_1;
    }
    *(uint *)(DAT_40021000 + 0xc) = uVar1;
    return;
}

void FUN_00001c6c(undefined *param_1, int param_2, int param_3) {
    ushort uVar1;
    undefined *puVar2;
    int iVar3;
    int iVar4;

    iVar3 = param_3 + 1 >> 1;
    puVar2 = (undefined *)(*(int *)PTR_DAT_40006000 + param_2 * 2);
    FUN_00005a40();
    iVar4 = 0;
    if (iVar3 != 0) {
        do {
            uVar1 = *(ushort *)((int)puVar2 + 4);
            puVar2 = puVar2 + 4;
            *param_1 = (char)uVar1;
            param_1[1] = (char)(uVar1 >> 8);
            param_1 = param_1 + 2;
            iVar4 = iVar4 + 1;
        } while (iVar4 < iVar3);
    }
    return;
}

void FUN_000017b8(void) {
    char cVar1;
    code *pcVar2;
    undefined *puVar3;

    puVar3 = *(undefined **)PTR_DAT_2000016c;
    cVar1 = puVar3[8];
    if (cVar1 == 2 || cVar1 == 4) {
        FUN_00000cbc();
        cVar1 = puVar3[8];
    }
    if (cVar1 == 6) {
        if (puVar3[1] == 5) {
            if ((puVar3[0] & 0x7f) == 0) {
                FUN_000021bc((uint)puVar3[3]);
                pcVar2 = *(code **)(*(int *)PTR_DAT_20000178 + 0x20);
                (*pcVar2)();
            }
        }
        pcVar2 = *(code **)(*(int *)PTR_DAT_20000170 + 8);
        (*pcVar2)();
        cVar1 = 8;
    }
    puVar3[8] = cVar1;
    FUN_00001cac();
    return;
}

void FUN_00001a54(int param_1) {
    uint uVar1;
    uint uVar2;
    uint uVar3;
    uint uVar4;
    uint uVar5;
    uint uVar6;

    uVar4 = *(uint *)(DAT_e000ed0c + 0);
    uVar3 = (uVar4 >> 8) & 7;
    uVar2 = 4 - uVar3;
    uVar1 = (uint) * (byte *)(param_1 + 1);
    uVar5 = (uint) * (byte *)(param_1 + 2);
    uVar6 = (uint) * (byte *)param_1;
    if (*(char *)(param_1 + 3) == 0) {
        uVar1 = 1 << (uVar6 & 0x1f);
        uVar2 = (uint)(uVar6 >> 5);
        *(uint *)(DAT_e000e180 + uVar2 * 4) = uVar1;
    } else {
        uVar1 = (uVar1 << uVar2) | (uVar5 & (1 << uVar2) - 1);
        *(undefined *)((uVar4 & 0x700) + 0xe000e000 - ((uVar4 & 0x700) >> 1) + uVar6) =
            (char)((uint)(uVar1 << 4) | uVar3);
        uVar1 = 1 << (uVar6 & 0x1f);
        uVar2 = (uint)(uVar6 >> 5);
        *(uint *)(DAT_e000e100 + uVar2 * 4) = uVar1;
    }
    return;
}

void FUN_00001cac(void) {
    uint uVar1;

    uVar1 = (uint) * (byte *)(*(int *)PTR_DAT_200000a8 + 0x2c);
    FUN_00002220(0, uVar1);
    if ((*(byte *)(*(int *)PTR_DAT_2000016c + 8) == 8) ||
        (uVar1 = *(byte *)(*(int *)PTR_DAT_2000016c + 8), uVar1 == 9)) {
        *(undefined2 *)PTR_DAT_2000017c = 0x1000;
        *(undefined2 *)PTR_DAT_2000017e = 0x10;
    }
    return;
}

void FUN_00001c6c(undefined *param_1, int param_2, int param_3) {
    ushort uVar1;
    undefined *puVar2;
    int iVar3;
    int iVar4;

    iVar3 = param_3 + 1 >> 1;
    puVar2 = (undefined *)(*(int *)PTR_DAT_40006000 + param_2 * 2);
    FUN_00005a40();
    iVar4 = 0;
    if (iVar3 != 0) {
        do {
            uVar1 = *(ushort *)((int)puVar2 + 4);
            puVar2 = puVar2 + 4;
            *param_1 = (char)uVar1;
            param_1[1] = (char)(uVar1 >> 8);
            param_1 = param_1 + 2;
            iVar4 = iVar4 + 1;
        } while (iVar4 < iVar3);
    }
    return;
}

void FUN_000012b6(int param_1, ushort *param_2) {
    uint uVar1;
    uint uVar2;
    uint uVar3;
    uint uVar4;
    int iVar5;
    uint uVar6;
    uint uVar7;

    uVar7 = 0;
    uVar6 = 0;
    uVar4 = 0;
    uVar3 = 0;
    uVar2 = (uint) * (byte *)((int)param_2 + 3);
    uVar1 = uVar2 & 0xf;
    if ((uVar2 & 0x10) != 0) {
        uVar1 = uVar1 | (uint) * (byte *)((int)param_2 + 2);
    }
    if (*param_2 != 0) {
        iVar5 = *(int *)param_1;
        uVar2 = 0;
        do {
            uVar7 = 1 << (uVar2 & 0xff);
            if ((*param_2 & uVar7) != 0) {
                uVar6 = 0xf << (uVar2 & 0xff) * 4;
                iVar5 = iVar5 & ~uVar6 | (uVar1 << (uVar2 & 0xff) * 4) & uVar6;
                if (*(char *)((int)param_2 + 3) == 0x28) {
                    *(uint *)(param_1 + 0x14) = uVar7;
                } else if (*(char *)((int)param_2 + 3) == 0x48) {
                    *(uint *)(param_1 + 0x10) = uVar7;
                }
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < 8);
        *(int *)param_1 = iVar5;
    }
    if (0xff < *param_2) {
        iVar5 = *(int *)(param_1 + 4);
        uVar2 = 0;
        do {
            uVar4 = 1 << (uVar2 & 0xff) + 8;
            if ((*param_2 & uVar4) != 0) {
                uVar6 = 0xf << (uVar2 & 0xff) * 4;
                iVar5 = iVar5 & ~uVar6 | (uVar1 << (uVar2 & 0xff) * 4) & uVar6;
                if (*(char *)((int)param_2 + 3) == 0x28) {
                    *(uint *)(param_1 + 0x14) = uVar4;
                } else if (*(char *)((int)param_2 + 3) == 0x48) {
                    *(uint *)(param_1 + 0x10) = uVar4;
                }
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < 8);
        *(int *)(param_1 + 4) = iVar5;
    }
    return;
}

void FUN_000013c8(uint param_1, undefined4 param_2) {
    uint uVar1;
    uint uVar2;

    if ((param_1 & 0x80000000) == 0) {
        uVar2 = *(uint *)(DAT_40010000 + 4);
        uVar1 = *(uint *)(DAT_40010000 + 0x1c);
    } else {
        uVar2 = *(uint *)(DAT_40010000 + 0x1c);
        uVar1 = *(uint *)(DAT_40010000 + 4);
    }
    if ((param_1 & 0x600000) == 0x600000) {
        uVar1 = uVar1 & 0xf0ffffff;
        uVar2 = uVar2 & 0xf0ffffff;
    } else if ((param_1 & 0x200000) == 0x200000) {
        uVar1 = (uVar1 & ~(3 << ((uint)((byte)(param_1 >> 0x10) & 3) * 4))) | 0xf0000000;
    } else {
        uVar1 = (uVar1 & ~((uint)param_2 << ((param_1 >> 0x15) * 0x10 & 0xff))) | 0xf0000000;
    }
    if (param_2 != 0) {
        uVar1 = uVar1 | (uint)param_2 << ((param_1 >> 0x15) * 0x10 & 0xff);
    }
    if ((param_1 & 0x80000000) == 0) {
        *(uint *)(DAT_40010000 + 4) = uVar1;
        return;
    }
    *(uint *)(DAT_40010000 + 0x1c) = uVar1;
    return;
}

void FUN_00001d64(uint param_1, int param_2) {
    uint uVar1;

    if (param_2 == 0) {
        uVar1 = *(uint *)(DAT_40021000 + 0x10) & ~param_1;
    } else {
        uVar1 = *(uint *)(DAT_40021000 + 0x10) | param_1;
    }
    *(uint *)(DAT_40021000 + 0x10) = uVar1;
    return;
}

void FUN_00001e10(void *param_1) {
    uint uVar1;
    uint uVar2;
    uint uVar3;
    uint uVar4;

    uVar2 = *(uint *)(DAT_40021000 + 4);
    uVar1 = uVar2 & 0xc;
    if (uVar1 == 0) {
        *(undefined4 *)param_1 = 0x7a1200;
    } else if (uVar1 == 4) {
        *(undefined4 *)param_1 = 0x7a1200;
    } else if (uVar1 == 8) {
        uVar3 = (uVar2 >> 0x12) & 0x3f;
        uVar1 = (uVar2 & 0x10000) >> 0x10;
        uVar3 = uVar3 + 2;
        if (uVar1 == 0) {
            *(uint *)param_1 = uVar3 * 0x3d0900;
        } else if ((uVar2 & 0x20000) == 0) {
            *(uint *)param_1 = uVar3 * 0x7a1200;
        } else {
            *(uint *)param_1 = uVar3 * 0x3d0900;
        }
    } else {
        *(undefined4 *)param_1 = 0x7a1200;
    }
    uVar1 = (uVar2 >> 4) & 0xf;
    uVar2 = *(uint *)((int)PTR_DAT_20000034 + uVar1 * 4);
    uVar3 = *(uint *)param_1;
    *(uint *)((int)param_1 + 4) = uVar3 / uVar2;
    uVar2 = *(uint *)((int)PTR_DAT_20000034 + ((uVar2 >> 8) & 0xf) * 4);
    uVar3 = *(uint *)((int)param_1 + 4);
    *(uint *)((int)param_1 + 8) = uVar3 / uVar2;
    uVar2 = *(uint *)((int)PTR_DAT_20000034 + ((uVar2 >> 0xb) & 7) * 4);
    uVar3 = *(uint *)((int)param_1 + 4);
    *(uint *)((int)param_1 + 0xc) = uVar3 / uVar2;
    uVar1 = *(uint *)((int)PTR_DAT_20000044 + (uVar1 >> 0xe) * 4);
    uVar2 = *(uint *)((int)param_1 + 0xc);
    *(uint *)((int)param_1 + 0x10) = uVar2 / uVar1;
    return;
}

void FUN_00001d84(uint param_1, int param_2) {
    uint uVar1;

    if (param_2 == 0) {
        uVar1 = *(uint *)(DAT_40021000 + 0x18) & ~param_1;
    } else {
        uVar1 = *(uint *)(DAT_40021000 + 0x18) | param_1;
    }
    *(uint *)(DAT_40021000 + 0x18) = uVar1;
    return;
}

void FUN_00002052(undefined4 param_1, ushort param_2, ushort param_3) {
    FUN_0000047e(param_2, param_1, param_3);
    return;
}

uint FUN_00001ee4(uint param_1) {
    uint uVar1;
    uint uVar2;

    uVar2 = (param_1 >> 5) & 0x1f;
    if (uVar2 == 1) {
        uVar1 = *(uint *)DAT_40021000;
    } else if (uVar2 == 2) {
        uVar1 = *(uint *)(DAT_40021000 + 0x20);
    } else {
        uVar1 = *(uint *)(DAT_40021000 + 0x24);
    }
    if ((uVar1 & (1 << (param_1 & 0x1f))) == 0) {
        return 0;
    }
    return 1;
}

void FUN_00002174(void) {
    FUN_00001d84(8, 1);
    *(uint16_t *)0x20000000 = 0x800;
    *(uint8_t *)0x20000002 = 4;
    *(uint8_t *)0x20000003 = 3;
    FUN_000012b6(DAT_40010C00, 0x20000000);
    return;
}

void FUN_000021bc(uint param_1) {
    int iVar1;
    uint uVar2;
    uint uVar3;

    iVar1 = 0;
    uVar3 = (uint) * (byte *)PTR_DAT_200000a5;
    do {
        uVar2 = *(uint *)(*(int *)PTR_DAT_40005c00 + iVar1 * 4);
        uVar2 = uVar2 & 0x8f8f | (uint)(byte)((int)(uVar2 >> 8) + (int)(param_1 << 1)) << 8;
        *(uint *)(*(int *)PTR_DAT_40005c00 + iVar1 * 4) = uVar2;
        iVar1 = iVar1 + 1;
    } while (iVar1 < (int)uVar3);
    *(uint *)(*(int *)PTR_DAT_40005c00 + 0x4c) =
        *(uint *)(*(int *)PTR_DAT_40005c00 + 0x4c) | 0x80;
    return;
}

void FUN_00002220(int param_1, ushort param_2) {
    uint uVar1;
    undefined4 *puVar2;

    puVar2 = (undefined4 *)
             (*(int *)PTR_DAT_40006000 +
              ((uint) * (ushort *)PTR_DAT_40005c50 + (uint)(param_1 << 3) + 6) * 2);
    if (0x3e < param_2) {
        uVar1 = (uint)param_2 >> 5;
        if ((param_2 & 0x1f) == 0) {
            uVar1 = uVar1 - 1;
        }
        *puVar2 = 0x8000 | uVar1 << 10;
    } else {
        uVar1 = (uint)param_2 >> 1;
        if ((param_2 & 1) != 0) {
            uVar1 = uVar1 + 1;
        }
        *puVar2 = uVar1 << 10;
    }
    return;
}

void FUN_0000226c(uint param_1, undefined4 param_2) {
    uint uVar1;
    uint uVar2;

    uVar2 = *(uint *)(*(int *)PTR_DAT_40005c00 + param_1 * 4);
    uVar1 = uVar2 & 0x8fbf;
    if ((param_2 & 0x1000) != 0) {
        uVar1 = uVar2 ^ 0x1000;
    }
    if ((param_2 & 0x2000) != 0) {
        uVar1 = uVar1 ^ 0x2000;
    }
    *(uint *)(*(int *)PTR_DAT_40005c00 + param_1 * 4) = uVar1;
    return;
}

void FUN_000022e0(int param_1, ushort param_2) {
    *(undefined4 *)(*(int *)PTR_DAT_40006000 +
                     ((uint) * (ushort *)PTR_DAT_40005c50 + (uint)(param_1 << 3) + 2) * 2) =
        (uint)param_2;
    return;
}

void FUN_0000232c(uint param_1) {
    uint uVar1;

    uVar1 = *(uint *)(*(int *)PTR_DAT_40005c00 + param_1 * 4);
    *(uint *)(*(int *)PTR_DAT_40005c00 + param_1 * 4) = (uVar1 & 0x8fbf) ^ 0x3000;
    return;
}

void FUN_00002996(uint param_1) {
    uint uVar1;

    if (param_1 == 4) {
        uVar1 = *(uint *)(DAT_e000e000 + 0x10) | 4;
    } else {
        uVar1 = *(uint *)(DAT_e000e000 + 0x10) & 0xfffffffb;
    }
    *(uint *)(DAT_e000e000 + 0x10) = uVar1;
    return;
}

void FUN_00002b5c(int param_1, uint param_2) {
    if (param_2 == 0) {
        *(ushort *)param_1 = *(ushort *)param_1 & 0xfffe;
    } else {
        *(ushort *)param_1 = *(ushort *)param_1 | 1;
    }
    return;
}

void FUN_00002148(void) {
    FUN_00001d84(8, 1);
    *(uint16_t *)0x20000000 = 0x800;
    *(uint8_t *)0x20000002 = 4;
    *(uint8_t *)0x20000003 = 3;
    FUN_000012b6(DAT_40010C00, 0x20000000);
    return;
}

void FUN_00002174(void) {
    FUN_00001d84(8, 1);
    *(uint16_t *)0x20000000 = 0x800;
    *(uint8_t *)0x20000002 = 0x10;
    *(uint8_t *)0x20000003 = 3;
    FUN_000012b6(DAT_40010C00, 0x20000000);
    return;
}

void FUN_00002b5c(int param_1, uint param_2) {
    if (param_2 == 0) {
        *(ushort *)param_1 = *(ushort *)param_1 & 0xfffe;
    } else {
        *(ushort *)param_1 = *(ushort *)param_1 | 1;
    }
    return;
}

void FUN_0000350c(void) {
    // This is a placeholder for the function at 0x0000350c
}

void FUN_00003614(void) {
    // This is a placeholder for the function at 0x00003614
}

void FUN_00003888(void) {
    // This is a placeholder for the function at 0x00003888
}

void FUN_00002c8c(void) {
    undefined4 uVar1;
    undefined4 uVar2;
    undefined4 uVar3;
    char cVar4;
    byte bVar5;
    uint uVar6;
    int iVar7;
    undefined4 *puVar8;
    uint uVar9;
    uint uVar10;
    uint uVar11;
    uint uVar12;
    uint uVar13;
    uint uVar14;
    uint uVar15;
    uint uVar16;
    uint uVar17;
    uint uVar18;
    uint uVar19;
    uint uVar20;
    uint uVar21;
    uint uVar22;
    uint uVar23;
    uint uVar24;
    uint uVar25;
    uint uVar26;
    uint uVar27;
    uint uVar28;
    uint uVar29;
    uint uVar30;
    uint uVar31;
    uint uVar32;
    uint uVar33;
    uint uVar34;
    uint uVar35;
    uint uVar36;
    uint uVar37;
    uint uVar38;
    uint uVar39;
    uint uVar40;
    uint uVar41;
    uint uVar42;
    uint uVar43;
    uint uVar44;
    uint uVar45;
    uint uVar46;
    uint uVar47;
    uint uVar48;
    uint uVar49;
    uint uVar50;

    FUN_000003ba(0xbc, 0x34);
    FUN_000003ba(0x88, 0x34);
    FUN_000003ba(0x54, 0x34);
    FUN_000003ba(0x20, 0x34);
    puVar8 = (undefined4 *)0x8009308;
    uVar1 = *puVar8;
    uVar2 = puVar8[1];
    uVar3 = puVar8[2];
    local_f4 = puVar8[3];
    local_100 = uVar1;
    local_104 = uVar2;
    local_108 = uVar3;
    puVar8 = (undefined4 *)0x3090;
    uVar1 = *puVar8;
    uVar2 = puVar8[1];
    uVar3 = puVar8[2];
    local_110 = uVar1;
    local_10c = uVar2;
    uVar1 = puVar8[3];
    *(undefined4 *)0x4 = uVar3;
    *(undefined4 *)0x8 = uVar1;
    uVar14 = 0;
    uVar13 = 0;
    uVar12 = 0;
    uVar11 = 0;
    do {
        *(undefined *)((int)PTR_DAT_20000027 + uVar11) = 0;
        uVar11 = uVar11 + 1;
    } while (uVar11 < 8);
    if ((*(char *)PTR_DAT_200001b9 == 0) && (*(char *)PTR_DAT_200001c0 == 0)) {
        return;
    }
    if (*(char *)PTR_DAT_200001b9 != 0) {
        *(undefined2 *)PTR_DAT_20000190 = 0;
        FUN_00002c4c(0x10, 9);
    }
    goto LAB_00002e58;
}

void FUN_00003984(void) {
    // This is a placeholder for the function at 0x00003984
}

void FUN_00004e64(int param_1,int *param_2)

{
  ushort uVar1;
  uint uVar2;
  undefined1 auStack_34 [8];
  int local_2c;
  int local_28;

  *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) & 0xcfff | *(ushort *)((int)param_2 + 6)
  ;
  *(ushort *)(param_1 + 0xc) =
       *(ushort *)(param_1 + 0xc) & 0xe9f3 |
       *(ushort *)(param_2 + 1) | *(ushort *)(param_2 + 2) | *(ushort *)((int)param_2 + 10);
  *(ushort *)(param_1 + 0x14) = *(ushort *)(param_1 + 0x14) & 0xfcff | *(ushort *)(param_2 + 3);
  FUN_00001e10(auStack_34);
  if (param_1 == DAT_00004f38) {
    local_2c = local_28;
  }
  if ((*(ushort *)(param_1 + 0xc) & 0x8000) == 0) {
    uVar2 = (uint)(local_2c * 0x19) / (uint)(*param_2 << 2);
  }
  else {
    uVar2 = (uint)(local_2c * 0x19) / (uint)(*param_2 << 1);
  }
  if ((*(ushort *)(param_1 + 0xc) & 0x8000) == 0) {
    uVar1 = (ushort)(((uVar2 % 100) * 0x10 + 0x32) / 100) & 0xf;
  }
  else {
    uVar1 = (ushort)(((uVar2 % 100) * 8 + 0x32) / 100) & 7;
  }
  *(ushort *)(param_1 + 8) = (ushort)(uVar2 / 100 << 4) | uVar1;
  return;
}

void FUN_000012b6(int param_1, ushort *param_2) {
    uint uVar1;
    uint uVar2;
    uint uVar3;
    uint uVar4;
    int iVar5;
    uint uVar6;
    uint uVar7;

    uVar7 = 0;
    uVar6 = 0;
    uVar4 = 0;
    uVar3 = 0;
    uVar2 = (uint) * (byte *)((int)param_2 + 3);
    uVar1 = uVar2 & 0xf;
    if ((uVar2 & 0x10) != 0) {
        uVar1 = uVar1 | (uint) * (byte *)((int)param_2 + 2);
    }
    if (*param_2 != 0) {
        iVar5 = *(int *)param_1;
        uVar2 = 0;
        do {
            uVar7 = 1 << (uVar2 & 0xff);
            if ((*param_2 & uVar7) != 0) {
                uVar6 = 0xf << (uVar2 & 0xff) * 4;
                iVar5 = iVar5 & ~uVar6 | (uVar1 << (uVar2 & 0xff) * 4) & uVar6;
                if (*(char *)((int)param_2 + 3) == 0x28) {
                    *(uint *)(param_1 + 0x14) = uVar7;
                } else if (*(char *)((int)param_2 + 3) == 0x48) {
                    *(uint *)(param_1 + 0x10) = uVar7;
                }
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < 8);
        *(int *)param_1 = iVar5;
    }
    if (0xff < *param_2) {
        iVar5 = *(int *)(param_1 + 4);
        uVar2 = 0;
        do {
            uVar4 = 1 << (uVar2 & 0xff) + 8;
            if ((*param_2 & uVar4) != 0) {
                uVar6 = 0xf << (uVar2 & 0xff) * 4;
                iVar5 = iVar5 & ~uVar6 | (uVar1 << (uVar2 & 0xff) * 4) & uVar6;
                if (*(char *)((int)param_2 + 3) == 0x28) {
                    *(uint *)(param_1 + 0x14) = uVar4;
                } else if (*(char *)((int)param_2 + 3) == 0x48) {
                    *(uint *)(param_1 + 0x10) = uVar4;
                }
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < 8);
        *(int *)(param_1 + 4) = iVar5;
    }
    return;
}

void FUN_000013c8(uint param_1, undefined4 param_2) {
    uint uVar1;
    uint uVar2;

    if ((param_1 & 0x80000000) == 0) {
        uVar2 = *(uint *)(DAT_40010000 + 4);
        uVar1 = *(uint *)(DAT_40010000 + 0x1c);
    } else {
        uVar2 = *(uint *)(DAT_40010000 + 0x1c);
        uVar1 = *(uint *)(DAT_40010000 + 4);
    }
    if ((param_1 & 0x600000) == 0x600000) {
        uVar1 = uVar1 & 0xf0ffffff;
        uVar2 = uVar2 & 0xf0ffffff;
    } else if ((param_1 & 0x200000) == 0x200000) {
        uVar1 = (uVar1 & ~(3 << ((uint)((byte)(param_1 >> 0x10) & 3) * 4))) | 0xf0000000;
    } else {
        uVar1 = (uVar1 & ~((uint)param_2 << ((param_1 >> 0x15) * 0x10 & 0xff))) | 0xf0000000;
    }
    if (param_2 != 0) {
        uVar1 = uVar1 | (uint)param_2 << ((param_1 >> 0x15) * 0x10 & 0xff);
    }
    if ((param_1 & 0x80000000) == 0) {
        *(uint *)(DAT_40010000 + 4) = uVar1;
        return;
    }
    *(uint *)(DAT_40010000 + 0x1c) = uVar1;
    return;
}

void FUN_00003b00(void) {
    // This is a placeholder for the function at 0x00003b00
}

void FUN_00003b50(void) {
    // This is a placeholder for the function at 0x00003b50
}

void FUN_00003be0(void) {
    // This is a placeholder for the function at 0x00003be0
}

void FUN_00003c40(void) {
    // This is a placeholder for the function at 0x00003c40
}

void FUN_00003cc0(void) {
    // This is a placeholder for the function at 0x00003cc0
}

void FUN_00003d44(void) {
    // This is a placeholder for the function at 0x00003d44
}

void FUN_00003e00(void) {
    // This is a placeholder for the function at 0x00003e00
}

void FUN_00003e60(void) {
    // This is a placeholder for the function at 0x00003e60
}

void FUN_00003fa0(void) {
    // This is a placeholder for the function at 0x00003fa0
}

void FUN_00004264(void) {
    undefined *puVar1;
    undefined *puVar2;
    uint uVar3;
    int iVar4;
    uint uVar5;
    uint uVar6;
    undefined4 uVar7;
    uint uVar8;

    puVar1 = *(undefined **)PTR_DAT_2000016c;
    uVar7 = 0;
    if (puVar1[1] == 6) {
        if ((puVar1[0] & 0x7f) == 0) {
            puVar2 = *(undefined **)PTR_DAT_20000170;
            if (puVar1[2] == 1) {
                uVar7 = *(undefined4 *)(puVar2 + 0x1c);
            } else if (puVar1[2] == 2) {
                uVar7 = *(undefined4 *)(puVar2 + 0x20);
            } else if (puVar1[2] == 3) {
                uVar7 = *(undefined4 *)(puVar2 + 0x24);
            }
        }
    } else if (puVar1[1] < 7) {
        if (puVar1[1] == 0) {
            if (((*(ushort *)(puVar1 + 2) == 0) && (*(ushort *)(puVar1 + 6) == 2)) &&
                ((puVar1[4] == 0 && ((puVar1[0] & 0x7fU) == 0)))) {
                if (*(ushort *)(puVar1 + 4) == 0) {
                    uVar7 = DAT_08005e75;
                }
            } else {
                uVar3 = (uint)puVar1[0] & 0x7f;
                if (uVar3 == 1) {
                    iVar4 = (**(code **)(*(int *)PTR_DAT_20000170 + 0x18))
                        (puVar1[5]);
                    if ((iVar4 != 0) || (puVar1[10] != 0)) {
                        uVar7 = DAT_08005e75;
                    }
                } else if (uVar3 == 2) {
                    uVar3 = (uint)puVar1[5] & 0xf;
                    uVar8 = (uint)puVar1[5] & 0x70;
                    if ((puVar1[5] & 0x80) == 0) {
                        uVar5 = *(uint *)(*(int *)PTR_DAT_40005c00 + uVar3 * 4);
                        uVar6 = uVar5 & 0x3000;
                    } else {
                        uVar5 = *(uint *)(*(int *)PTR_DAT_40005c00 + uVar3 * 4);
                        uVar6 = uVar5 & 0x30;
                    }
                    if (((uVar3 < (uint) * (byte *)PTR_DAT_200000a5) && (uVar8 == 0)) && (uVar6 != 0)) {
                        uVar7 = DAT_08005e75;
                    }
                }
            }
        }
    } else if (puVar1[1] == 8) {
        if ((puVar1[0] & 0x7f) == 0) {
            uVar7 = DAT_08005df9;
        }
    } else if (puVar1[1] == 10) {
        if ((((puVar1[0] & 0x7f) == 1) && (puVar1[10] != 0)) &&
            (((*(ushort *)(puVar1 + 2) == 0 && (puVar1[4] == 0)) && (*(ushort *)(puVar1 + 6) == 1)))) {
            iVar4 = (**(code **)(*(int *)PTR_DAT_20000170 + 0x18))(puVar1[5]);
            if (iVar4 == 0) {
                uVar7 = DAT_08005e49;
            }
        }
    } else if ((puVar1[1] == 9) && ((puVar1[0] & 0x7f) == 0x21)) {
        puVar3[8] = 3;
        *(undefined2 *)PTR_DAT_2000017c = 0x3000;
    }
    if (uVar7 != 0) {
        *(undefined2 *)(puVar1 + 0x12) = 0;
        *(undefined4 *)(puVar1 + 0x18) = uVar7;
        (*(code *)uVar7)();
    }
    return;
}

void FUN_000012b6(int param_1, ushort *param_2) {
    uint uVar1;
    uint uVar2;
    uint uVar3;
    uint uVar4;
    int iVar5;
    uint uVar6;
    uint uVar7;

    uVar7 = 0;
    uVar6 = 0;
    uVar4 = 0;
    uVar3 = 0;
    uVar2 = (uint) * (byte *)((int)param_2 + 3);
    uVar1 = uVar2 & 0xf;
    if ((uVar2 & 0x10) != 0) {
        uVar1 = uVar1 | (uint) * (byte *)((int)param_2 + 2);
    }
    if (*param_2 != 0) {
        iVar5 = *(int *)param_1;
        uVar2 = 0;
        do {
            uVar7 = 1 << (uVar2 & 0xff);
            if ((*param_2 & uVar7) != 0) {
                uVar6 = 0xf << (uVar2 & 0xff) * 4;
                iVar5 = iVar5 & ~uVar6 | (uVar1 << (uVar2 & 0xff) * 4) & uVar6;
                if (*(char *)((int)param_2 + 3) == 0x28) {
                    *(uint *)(param_1 + 0x14) = uVar7;
                } else if (*(char *)((int)param_2 + 3) == 0x48) {
                    *(uint *)(param_1 + 0x10) = uVar7;
                }
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < 8);
        *(int *)param_1 = iVar5;
    }
    if (0xff < *param_2) {
        iVar5 = *(int *)(param_1 + 4);
        uVar2 = 0;
        do {
            uVar4 = 1 << (uVar2 & 0xff) + 8;
            if ((*param_2 & uVar4) != 0) {
                uVar6 = 0xf << (uVar2 & 0xff) * 4;
                iVar5 = iVar5 & ~uVar6 | (uVar1 << (uVar2 & 0xff) * 4) & uVar6;
                if (*(char *)((int)param_2 + 3) == 0x28) {
                    *(uint *)(param_1 + 0x14) = uVar4;
                } else if (*(char *)((int)param_2 + 3) == 0x48) {
                    *(uint *)(param_1 + 0x10) = uVar4;
                }
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < 8);
        *(int *)(param_1 + 4) = iVar5;
    }
    return;
}

void FUN_000043d0(void) {
    // This is a placeholder for the function at 0x000043d0
}

void FUN_0000448c(void) {
    // This is a placeholder for the function at 0x0000448c
}

void FUN_00004504(byte *param_1)

{
  undefined1 *puVar1;
  uint local_10;

  local_10 = (uint)param_1[2];
  FUN_0000531c(0xf4,1,&local_10);
  local_10 = (uint)*param_1;
  FUN_0000531c(0xf5,1,&local_10);
  local_10 = (uint)param_1[1];
  FUN_0000531c(0xf6,1,&local_10);
  FUN_0000529c(0xf4,1,DAT_00004580);
  FUN_0000529c(0xf5,1,DAT_00004584);
  FUN_0000529c(0xf6,1,DAT_00004588);
  puVar1 = DAT_0000458c;
  *DAT_0000458c = 0xe;
  puVar1[1] = 2;
  puVar1[2] = 0x92;
  puVar1[3] = 0;
  puVar1[4] = 0x15;
  puVar1[5] = 9;
  puVar1[6] = *param_1;
  puVar1[7] = param_1[1];
  puVar1[8] = param_1[2];
  FUN_00005200(DAT_0000458c,0x40);
  return;
}

void FUN_000012b6(int param_1, ushort *param_2) {
    uint uVar1;
    uint uVar2;
    uint uVar3;
    uint uVar4;
    int iVar5;
    uint uVar6;
    uint uVar7;

    uVar7 = 0;
    uVar6 = 0;
    uVar4 = 0;
    uVar3 = 0;
    uVar2 = (uint) * (byte *)((int)param_2 + 3);
    uVar1 = uVar2 & 0xf;
    if ((uVar2 & 0x10) != 0) {
        uVar1 = uVar1 | (uint) * (byte *)((int)param_2 + 2);
    }
    if (*param_2 != 0) {
        iVar5 = *(int *)param_1;
        uVar2 = 0;
        do {
            uVar7 = 1 << (uVar2 & 0xff);
            if ((*param_2 & uVar7) != 0) {
                uVar6 = 0xf << (uVar2 & 0xff) * 4;
                iVar5 = iVar5 & ~uVar6 | (uVar1 << (uVar2 & 0xff) * 4) & uVar6;
                if (*(char *)((int)param_2 + 3) == 0x28) {
                    *(uint *)(param_1 + 0x14) = uVar7;
                } else if (*(char *)((int)param_2 + 3) == 0x48) {
                    *(uint *)(param_1 + 0x10) = uVar7;
                }
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < 8);
        *(int *)param_1 = iVar5;
    }
    if (0xff < *param_2) {
        iVar5 = *(int *)(param_1 + 4);
        uVar2 = 0;
        do {
            uVar4 = 1 << (uVar2 & 0xff) + 8;
            if ((*param_2 & uVar4) != 0) {
                uVar6 = 0xf << (uVar2 & 0xff) * 4;
                iVar5 = iVar5 & ~uVar6 | (uVar1 << (uVar2 & 0xff) * 4) & uVar6;
                if (*(char *)((int)param_2 + 3) == 0x28) {
                    *(uint *)(param_1 + 0x14) = uVar4;
                } else if (*(char *)((int)param_2 + 3) == 0x48) {
                    *(uint *)(param_1 + 0x10) = uVar4;
                }
            }
            uVar2 = uVar2 + 1;
        } while (uVar2 < 8);
        *(int *)(param_1 + 4) = iVar5;
    }
    return;
}

void FUN_000013c8(uint param_1, undefined4 param_2) {
    uint uVar1;
    uint uVar2;

    if ((param_1 & 0x80000000) == 0) {
        uVar2 = *(uint *)(DAT_40010000 + 4);
        uVar1 = *(uint *)(DAT_40010000 + 0x1c);
    } else {
        uVar2 = *(uint *)(DAT_40010000 + 0x1c);
        uVar1 = *(uint *)(DAT_40010000 + 4);
    }
    if ((param_1 & 0x600000) == 0x600000) {
        uVar1 = uVar1 & 0xf0ffffff;
        uVar2 = uVar2 & 0xf0ffffff;
    } else if ((param_1 & 0x200000) == 0x200000) {
        uVar1 = (uVar1 & ~(3 << ((uint)((byte)(param_1 >> 0x10) & 3) * 4))) | 0xf0000000;
    } else {
        uVar1 = (uVar1 & ~((uint)param_2 << ((param_1 >> 0x15) * 0x10 & 0xff))) | 0xf0000000;
    }
    if (param_2 != 0) {
        uVar1 = uVar1 | (uint)param_2 << ((param_1 >> 0x15) * 0x10 & 0xff);
    }
    if ((param_1 & 0x80000000) == 0) {
        *(uint *)(DAT_40010000 + 4) = uVar1;
        return;
    }
    *(uint *)(DAT_40010000 + 0x1c) = uVar1;
    return;
}

void FUN_00004828(void) {
    // This is a placeholder for the function at 0x00004828
}

void FUN_00004928(void) {
    // This is a placeholder for the function at 0x00004928
}

void FUN_000049e8(void) {
    // This is a placeholder for the function at 0x000049e8
}

void FUN_00004a90(void) {
    // This is a placeholder for the function at 0x00004a90
}

void FUN_00004af0(void) {
    // This is a placeholder for the function at 0x00004af0
}

void FUN_00004d10(void) {
    // This is a placeholder for the function at 0x00004d10
}

void FUN_00004dac(void) {
    // This is a placeholder for the function at 0x00004dac
}

void FUN_00004cf6(void) {
    // This is a placeholder for the function at 0x00004cf6
}

void FUN_00004e1a(void) {
    // This is a placeholder for the function at 0x00004e1a
}

void FUN_000046a4(byte *param_1)

{
  undefined1 *puVar1;
  uint local_10;

  local_10 = (uint)(*param_1 >> 7);
  FUN_0000531c(0xd7,1,&local_10);
  local_10 = *param_1 & 1;
  FUN_0000531c(0xd8,1,&local_10);
  local_10 = (*param_1 & 2) >> 1;
  FUN_0000531c(0xd9,1,&local_10);
  local_10 = (*param_1 & 0x20) >> 5;
  FUN_0000531c(0xda,1,&local_10);
  local_10 = (*param_1 & 0x40) >> 6;
  FUN_0000531c(0xdb,1,&local_10);
  local_10 = (uint)param_1[1];
  FUN_0000531c(0xdc,1,&local_10);
  local_10 = (uint)param_1[2];
  FUN_0000531c(0xdd,1,&local_10);
  FUN_0000529c(0xd7,1,DAT_000047a0);
  FUN_0000529c(0xd8,1,DAT_000047a4);
  FUN_0000529c(0xd9,1,DAT_000047a8);
  FUN_0000529c(0xda,1,DAT_000047ac);
  FUN_0000529c(0xdb,1,DAT_000047b0);
  FUN_0000529c(0xdc,1,DAT_000047b4);
  FUN_0000529c(0xdd,1,DAT_000047b8);
  puVar1 = DAT_000047bc;
  *DAT_000047bc = 9;
  puVar1[1] = 2;
  puVar1[2] = 0x92;
  puVar1[3] = 0;
  puVar1[4] = 2;
  puVar1[5] = 4;
  puVar1[6] = *param_1;
  puVar1[7] = param_1[1];
  puVar1[8] = param_1[2];
  puVar1[9] = 0;
  FUN_00005200(DAT_000047bc,0x40);
  return;
}

void FUN_00004f46(int param_1,int param_2)

{
  *(ushort *)(param_1 + 4) = (ushort)((uint)(param_2 << 0x17) >> 0x17);
  return;
}

void FUN_00004f50(int param_1) {
    if (param_1 == 0) {
        FUN_00001458(DAT_00004f70, 0x100);
    } else {
        FUN_0000145c(DAT_00004f70, 0x100);
    }
    return;
}

uint FUN_00005200(undefined4 param_1,uint param_2)

{
  FUN_0000524c(param_1,0x100,param_2 & 0xffff);
  FUN_000022e0(2,0x40);
  FUN_0000232c(2);
  return param_2;
}

uint FUN_00002b74(int param_1, ushort param_2) {
    if (((*(ushort *)(param_1 + 0x10) & param_2) != 0) &&
        ((*(ushort *)(param_1 + 0xc) & param_2) != 0)) {
        return 1;
    }
    return 0;
}

void FUN_00002c4c(byte *param_1, int param_2) {
    int iVar1;

    if (param_2 != 0) {
        iVar1 = 0;
        do {
            while (*(int *)(DAT_40013800 + 0) & 0x40 != 0) {
            }
            *(char *)(DAT_40013800 + 0) = param_1[iVar1];
            iVar1 = iVar1 + 1;
        } while (iVar1 < param_2);
    }
    while (*(int *)(DAT_40013800 + 0) & 0x40 != 0) {
    }
    return;
}

void FUN_00005286(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  FUN_000004f8(param_2,param_1,param_3);
  return;
}

void FUN_0000524c(undefined2 *param_1,int param_2,int param_3)

{
  undefined2 *puVar1;
  int iVar2;

  puVar1 = (undefined2 *)(DAT_00005280 + param_2 * 2);
  for (iVar2 = param_3 + 1 >> 1; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_1;
    puVar1 = puVar1 + 2;
    param_1 = param_1 + 1;
  }
  return;
}

// Function @ 0x5470
void FUN_00005470(void)

{
  if (DAT_000054b8 != 0) {
    FUN_00002b5c(DAT_000054b8,6);
    FUN_00002b74(DAT_000054b8,0x101);
  }
  return;
}

// Function @ 0x541c
void FUN_0000541c(void)

{
  uint uVar1;

  uVar1 = FUN_00002b74(DAT_00005468,0x101);
  if ((char)uVar1 == '\0') {
    if (DAT_0000546c != 0) {
      FUN_00002b5c(DAT_0000546c,6);
      FUN_00002b74(DAT_0000546c,0x101);
    }
    DAT_0000546c = 0;
    DAT_00005468 = 0;
  }
  else {
    FUN_00002b5c(DAT_00005468,6);
  }
  return;
}

void FUN_0000539c(int param_1,int param_2,int param_3)

{
  uint uVar1;
  char cVar2;
  int iVar3;

  for (uVar1 = 0; (int)uVar1 < param_3; uVar1 = uVar1 + 1 & 0xff) {
    if (*(byte *)(param_2 + uVar1 * 2) < 0x3a) {
      iVar3 = *(byte *)(param_2 + uVar1 * 2) - 0x30;
    }
    else {
      iVar3 = *(byte *)(param_2 + uVar1 * 2) - 0x37;
    }
    if (*(byte *)(param_2 + uVar1 * 2 + 1) < 0x3a) {
      cVar2 = *(char *)(param_2 + uVar1 * 2 + 1) + -0x30;
    }
    else {
      cVar2 = *(char *)(param_2 + uVar1 * 2 + 1) + -0x37;
    }
    *(char *)(param_1 + uVar1) = cVar2 + (char)(iVar3 << 4);
  }
  return;
}

char FUN_0000529c(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;

  uVar2 = param_2 / 0x44 + (uint)(param_2 != (param_2 / 0x44) * 0x44) & 0xff;
  uVar1 = 0;
  while( true ) {
    if (uVar2 <= uVar1) {
      return '\0';
    }
    if (uVar2 - 1 == uVar1) {
      uVar3 = param_2 + uVar1 * -0x44;
    }
    else {
      uVar3 = 0x44;
    }
    FUN_00002052(param_3 + uVar1 * 0x44,param_1,uVar3 & 0xff);
    if (*DAT_00005318 != '\0') break;
    param_1 = param_1 + 0x44;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return *DAT_00005318;
}

char FUN_0000531c(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;

  uVar2 = param_2 / 0x44 + (uint)(param_2 != (param_2 / 0x44) * 0x44) & 0xff;
  uVar1 = 0;
  while( true ) {
    if (uVar2 <= uVar1) {
      return '\0';
    }
    if (uVar2 - 1 == uVar1) {
      uVar3 = param_2 + uVar1 * -0x44;
    }
    else {
      uVar3 = 0x44;
    }
    FUN_00005286(param_3 + uVar1 * 0x44,param_1,uVar3 & 0xff);
    if (*DAT_00005398 != '\0') break;
    param_1 = param_1 + 0x44;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return *DAT_00005398;
}

uint FUN_00005224(undefined4 param_1,uint param_2)

{
  FUN_0000524c(param_1,0xc0,param_2 & 0xffff);
  FUN_000022e0(1,8);
  FUN_0000232c(1);
  return param_2;
}

void FUN_00005460(void) {
    // This is a placeholder for the function at 0x00005460
}

void FUN_000054ac(void) {
    // This is a placeholder for the function at 0x000054ac
}

void FUN_00005a40(void) {
    // This is a placeholder for the function at 0x00005a40
}

void FUN_00005a44(void) {
    // This is a placeholder for the function at 0x00005a44
}

undefined4 FUN_000004a0(int param_1)

{
    uint uVar1;

    FUN_00001684();
    uVar1 = FUN_00001628((uint)(byte)(param_1 >> 8) * 2 + 0xa0);
    FUN_000016f8(uVar1);
    uVar1 = FUN_00001628((uint)(byte)param_1);
    FUN_000016f8(uVar1);
    FUN_00001684();
    uVar1 = FUN_00001628(0xa1);
    FUN_000016f8(uVar1);
    uVar1 = FUN_000015cc(0);
    FUN_000016c0();
    return uVar1;
}

void FUN_000004f8(ushort param_1, byte *param_2, ushort param_3) {
    ushort uVar1;

    if (param_3 != 0) {
        do {
            uVar1 = param_1;
            FUN_0000051c(uVar1, *param_2);
            param_1 = uVar1 + 1;
            param_2 = param_2 + 1;
            param_3 = param_3 - 1;
        } while (param_3 != 0);
    }
    return;
}

undefined8 FUN_00000312(undefined4 *param_1,byte *param_2,uint param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  bool bVar10;
  bool bVar11;

  uVar5 = param_3 - 0x20;
  if (0x1f < param_3) {
    do {
      uVar7 = *(undefined4 *)(param_2 + 4);
      uVar8 = *(undefined4 *)(param_2 + 8);
      uVar9 = *(undefined4 *)(param_2 + 0xc);
      bVar11 = 0x1f < uVar5;
      uVar5 = uVar5 - 0x20;
      *param_1 = *(undefined4 *)param_2;
      param_1[1] = uVar7;
      param_1[2] = uVar8;
      param_1[3] = uVar9;
      param_4 = *(undefined4 *)(param_2 + 0x10);
      uVar7 = *(undefined4 *)(param_2 + 0x14);
      uVar8 = *(undefined4 *)(param_2 + 0x18);
      uVar9 = *(undefined4 *)(param_2 + 0x1c);
      param_2 = param_2 + 0x20;
      param_1[4] = param_4;
      param_1[5] = uVar7;
      param_1[6] = uVar8;
      param_1[7] = uVar9;
      param_1 = param_1 + 8;
    } while (bVar11);
  }
  if ((uVar5 & 0x10) != 0) {
    param_4 = *(undefined4 *)param_2;
    uVar7 = *(undefined4 *)(param_2 + 4);
    uVar8 = *(undefined4 *)(param_2 + 8);
    uVar9 = *(undefined4 *)(param_2 + 0xc);
    param_2 = param_2 + 0x10;
    *param_1 = param_4;
    param_1[1] = uVar7;
    param_1[2] = uVar8;
    param_1[3] = uVar9;
    param_1 = param_1 + 4;
  }
  if ((int)(uVar5 << 0x1c) < 0) {
    param_4 = *(undefined4 *)param_2;
    uVar7 = *(undefined4 *)(param_2 + 4);
    param_2 = param_2 + 8;
    *param_1 = param_4;
    param_1[1] = uVar7;
    param_1 = param_1 + 2;
  }
  puVar2 = param_1;
  pbVar3 = param_2;
  if ((uVar5 & 4) != 0) {
    pbVar3 = param_2 + 4;
    param_4 = *(undefined4 *)param_2;
    puVar2 = param_1 + 1;
    *param_1 = param_4;
  }
  uVar6 = (undefined2)param_4;
  if ((uVar5 & 3) != 0) {
    bVar11 = (uVar5 & 2) != 0;
    uVar5 = uVar5 << 0x1f;
    bVar10 = (int)uVar5 < 0;
    pbVar4 = pbVar3;
    if (bVar11) {
      pbVar4 = pbVar3 + 2;
      uVar6 = *(undefined2 *)pbVar3;
    }
    pbVar3 = pbVar4;
    if (bVar10) {
      pbVar3 = pbVar4 + 1;
      uVar5 = (uint)*pbVar4;
    }
    puVar1 = puVar2;
    if (bVar11) {
      puVar1 = (undefined4 *)((int)puVar2 + 2);
      *(undefined2 *)puVar2 = uVar6;
    }
    puVar2 = puVar1;
    if (bVar10) {
      puVar2 = (undefined4 *)((int)puVar1 + 1);
      *(char *)puVar1 = (char)uVar5;
    }
    return CONCAT44(pbVar3,puVar2);
  }
  return CONCAT44(pbVar3,puVar2);
}

undefined4 * FUN_00000376(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;

  if (param_2 < 4) {
    if ((param_2 & 2) != 0) {
      puVar2 = (undefined1 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = 0;
      param_1 = (undefined4 *)((int)param_1 + 2);
      *puVar2 = 0;
    }
    puVar1 = param_1;
    if ((int)(param_2 << 0x1f) < 0) {
      puVar1 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = 0;
    }
    return puVar1;
  }
  if (((uint)param_1 & 3) != 0) {
    iVar5 = 4 - ((uint)param_1 & 3);
    puVar1 = param_1;
    if (iVar5 != 2) {
      puVar1 = (undefined4 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = 0;
    }
    param_1 = puVar1;
    if (1 < iVar5) {
      param_1 = (undefined4 *)((int)puVar1 + 2);
      *(undefined2 *)puVar1 = 0;
    }
    param_2 = param_2 - iVar5;
  }
  bVar6 = 0x1f < param_2;
  param_2 = param_2 - 0x20;
  do {
    if (bVar6) {
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = 0;
      param_1[7] = 0;
      param_1 = param_1 + 8;
      bVar6 = 0x1f < param_2;
      param_2 = param_2 - 0x20;
    }
  } while (bVar6);
  if ((param_2 & 0x10) != 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1 = param_1 + 4;
  }
  if ((int)(param_2 << 0x1c) < 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1 = param_1 + 2;
  }
  uVar4 = param_2 << 0x1e;
  puVar1 = param_1;
  if ((param_2 << 0x1c & 0x40000000) != 0) {
    puVar1 = param_1 + 1;
    *param_1 = 0;
  }
  if (uVar4 != 0) {
    puVar3 = puVar1;
    if ((int)uVar4 < 0) {
      puVar3 = (undefined4 *)((int)puVar1 + 2);
      *(undefined2 *)puVar1 = 0;
    }
    puVar1 = puVar3;
    if ((uVar4 & 0x40000000) != 0) {
      puVar1 = (undefined4 *)((int)puVar3 + 1);
      *(undefined1 *)puVar3 = 0;
    }
    return puVar1;
  }
  return puVar1;
}

undefined4 * FUN_000003ba(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  bool bVar4;

  bVar4 = 0x1f < param_2;
  param_2 = param_2 - 0x20;
  do {
    if (bVar4) {
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = 0;
      param_1[7] = 0;
      param_1 = param_1 + 8;
      bVar4 = 0x1f < param_2;
      param_2 = param_2 - 0x20;
    }
  } while (bVar4);
  if ((param_2 & 0x10) != 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1 = param_1 + 4;
  }
  if ((int)(param_2 << 0x1c) < 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1 = param_1 + 2;
  }
  uVar3 = param_2 << 0x1e;
  puVar2 = param_1;
  if ((param_2 << 0x1c & 0x40000000) != 0) {
    puVar2 = param_1 + 1;
    *param_1 = 0;
  }
  if (uVar3 != 0) {
    puVar1 = puVar2;
    if ((int)uVar3 < 0) {
      puVar1 = (undefined4 *)((int)puVar2 + 2);
      *(undefined2 *)puVar2 = 0;
    }
    puVar2 = puVar1;
    if ((uVar3 & 0x40000000) != 0) {
      puVar2 = (undefined4 *)((int)puVar1 + 1);
      *(undefined1 *)puVar1 = 0;
    }
    return puVar2;
  }
  return puVar2;
}
