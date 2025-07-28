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

int FUN_00000230(char *param_1, char *param_2, int param_3) {
    uint uVar1;
    char *pcVar2;
    char *pcVar3;
    uint uVar4;
    int iVar5;

    uVar4 = (uint)param_2;
    uVar1 = (uint)param_1;
    if ((param_3 & 1) == 0) {
        if ((param_3 & 2) == 0) {
            if ((param_3 & 4) == 0) {
                if ((param_3 & 8) == 0) {
                    if ((param_3 & 0x10) == 0) {
                        if ((param_3 & 0x20) == 0) {
                            if ((param_3 & 0x40) == 0) {
                                if ((param_3 & 0x80) == 0) {
                                    return 0;
                                }
                                iVar5 = (int)(uVar1 - uVar4);
                            } else {
                                iVar5 = (int)(uVar1 - uVar4);
                            }
                        } else {
                            iVar5 = (int)(uVar1 - uVar4);
                        }
                    } else {
                        iVar5 = (int)(uVar1 - uVar4);
                    }
                } else {
                    iVar5 = (int)(uVar1 - uVar4);
                }
            } else {
                iVar5 = (int)(uVar1 - uVar4);
            }
        } else {
            iVar5 = (int)(uVar1 - uVar4);
        }
    } else {
        iVar5 = (int)(uVar1 - uVar4);
    }
    return iVar5;
}

void FUN_00000288(void)

{
    uint uVar1;
    int iVar2;
    uint *puVar3;
    uint *puVar4;
    uint uVar5;
    uint uVar6;

    uVar5 = (uint)PTR_DAT_00005e64;
    uVar6 = (uint)PTR_DAT_00005e84;
    if (3 < (uint)PTR_DAT_00005e64) {
        iVar2 = PTR_DAT_00005e84 & 3;
        if (iVar2 == 0) {
            uVar1 = uVar5 & 3;
            if (uVar1 == 0) {
                FUN_00000312();
                return;
            }
        } else {
            uVar1 = uVar5 & 3;
        }
        uVar5 = uVar5 - uVar1;
        puVar3 = (uint *)uVar6;
        puVar4 = (uint *)((int)PTR_DAT_00005e84 - iVar2);
        if (iVar2 < 3) {
            if (iVar2 < 2) {
                *puVar4 = (uint) * (byte *)puVar3;
            } else {
                *(uint16_t *)puVar4 = *(uint16_t *)puVar3;
            }
        }
        if (2 < iVar2) {
            puVar4[1] = *(uint * )((int)puVar3 + 1);
        }
        uVar6 = uVar6 + uVar1;
        PTR_DAT_00005e84 = (int)uVar6;
        PTR_DAT_00005e64 = (uint *)uVar5;
        if ((int)uVar5 < 8) {
            if ((int)uVar5 < 5) {
                return;
            }
            *(uint *)uVar6 = *(uint *)((int)puVar3 + 4);
            return;
        }
        do {
            *(uint *)uVar6 = *(uint *)((int)puVar3 + 4);
            uVar5 = uVar5 - 8;
            uVar6 = uVar6 + 8;
            *(uint *)((int)PTR_DAT_00005e84 + 4) = *(uint *)((int)puVar3 + 8);
            puVar3 = (uint *)((int)puVar3 + 8);
            PTR_DAT_00005e84 = (int)uVar6;
            PTR_DAT_00005e64 = (uint *)uVar5;
        } while (7 < (int)uVar5);
        if (3 < (int)uVar5) {
            *(uint *)uVar6 = *(uint *)((int)puVar3 + 4);
        }
        return;
    }
    return;
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

void FUN_000039e4(void) {
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

void FUN_00004504(void) {
    // This is a placeholder for the function at 0x00004504
}

void FUN_000046a4(void) {
    // This is a placeholder for the function at 0x000046a4
}

void FUN_000047c0(void) {
    // This is a placeholder for the function at 0x000047c0
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

void FUN_00004e64(void) {
    // This is a placeholder for the function at 0x00004e64
}

void FUN_00004f46(void) {
    // This is a placeholder for the function at 0x00004f46
}

void FUN_00004f50(void) {
    // This is a placeholder for the function at 0x00004f50
}

void FUN_00005200(void) {
    // This is a placeholder for the function at 0x00005200
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

void FUN_00005286(void) {
    // This is a placeholder for the function at 0x00005286
}

void FUN_0000529c(void) {
    // This is a placeholder for the function at 0x0000529c
}

void FUN_0000531c(void) {
    // This is a placeholder for the function at 0x0000531c
}

void FUN_0000539c(void) {
    // This is a placeholder for the function at 0x0000539c
}

void FUN_000053ec(void) {
    // This is a placeholder for the function at 0x000053ec
}

void FUN_00005424(void) {
    // This is a placeholder for the function at 0x00005424
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

void FUN_00000312(void)

{
    uint uVar1;
    uint uVar2;
    uint *puVar3;
    uint *puVar4;

    puVar3 = (uint *)PTR_DAT_00005e84;
    puVar4 = (uint *)PTR_DAT_00005e64;
    if ((int)PTR_DAT_00005e64 < 0x21) {
        if ((int)PTR_DAT_00005e64 < 0x11) {
            if ((int)PTR_DAT_00005e64 < 1) {
                return;
            }
            if (-1 < (int)((uint)PTR_DAT_00005e64 << 0x1e)) {
                if (((uint)PTR_DAT_00005e64 & 2) == 0) {
                    if (((uint)PTR_DAT_00005e64 & 1) != 0) {
                        *(undefined *)puVar3 = *(undefined *)puVar4;
                    }
                } else {
                    *(uint16_t *)puVar3 = *(uint16_t *)puVar4;
                }
                return;
            }
            if ((((uint)PTR_DAT_00005e64 & 2) != 0) && (((uint)PTR_DAT_00005e64 & 1) != 0)) {
                *(uint16_t *)puVar3 = *(uint16_t *)puVar4;
                *(undefined *)((int)puVar3 + 2) = *(undefined *)((int)puVar4 + 2);
                return;
            }
        }
        if (-1 < (int)((uint)PTR_DAT_00005e64 << 0x1c)) {
            uVar1 = *puVar4;
            uVar2 = puVar4[1];
            puVar4 = puVar4 + 2;
            *puVar3 = uVar1;
            puVar3[1] = uVar2;
            puVar3 = puVar3 + 2;
        }
        *(uint *)puVar3 = *(uint *)puVar4;
        return;
    }
    do {
        uVar1 = *puVar4;
        uVar2 = puVar4[1];
        puVar4 = puVar4 + 2;
        *puVar3 = uVar1;
        puVar3[1] = uVar2;
        uVar1 = *puVar4;
        uVar2 = puVar4[1];
        puVar4 = puVar4 + 2;
        *puVar3 = uVar1;
        puVar3[1] = uVar2;
        puVar3 = puVar3 + 4;
        PTR_DAT_00005e64 = (uint *)((int)PTR_DAT_00005e64 - 0x20);
    } while (0x20 < (int)PTR_DAT_00005e64);
    if (-1 < (int)((uint)PTR_DAT_00005e64 << 0x1c)) {
        uVar1 = *puVar4;
        uVar2 = puVar4[1];
        *puVar3 = uVar1;
        puVar3[1] = uVar2;
    }
    return;
}

void FUN_00000376(undefined4 param_1, int param_2) {
    uint uVar1;

    if (param_2 < 4) {
        if (-1 < (param_2 << 0x1f)) {
            if ((param_2 & 1) != 0) {
                *(undefined *)param_1 = 0;
            }
        } else {
            *(undefined *)param_1 = 0;
            *(undefined *)(param_1 + 1) = 0;
            if ((param_2 & 2) != 0) {
                *(undefined *)(param_1 + 2) = 0;
            }
        }
    } else {
        uVar1 = param_1 & 3;
        if (uVar1 != 0) {
            uVar1 = 4 - uVar1;
            param_2 = param_2 - uVar1;
            if (uVar1 < 3) {
                if (uVar1 < 2) {
                    *(undefined *)(param_1 & 0xfffffffc) = 0;
                } else {
                    *(uint16_t *)(param_1 & 0xfffffffc) = 0;
                }
            }
            if (2 < uVar1) {
                *(uint *)(param_1 & 0xfffffffc) = 0;
            }
            param_1 = param_1 + uVar1;
        }
        FUN_000003ba(param_1, param_2);
    }
    return;
}

void FUN_000003ba(int param_1, int param_2) {
    undefined4 uVar1;

    uVar1 = 0;
    if (0x1f < param_2) {
        do {
            *(undefined4 *)param_1 = 0;
            *(undefined4 *)(param_1 + 4) = 0;
            *(undefined4 *)(param_1 + 8) = 0;
            *(undefined4 *)(param_1 + 0xc) = 0;
            *(undefined4 *)(param_1 + 0x10) = 0;
            *(undefined4 *)(param_1 + 0x14) = 0;
            *(undefined4 *)(param_1 + 0x18) = 0;
            *(undefined4 *)(param_1 + 0x1c) = 0;
            param_1 = param_1 + 0x20;
            param_2 = param_2 - 0x20;
        } while (0x1f < param_2);
    }
    if (-1 < (param_2 << 0x1c)) {
        *(undefined4 *)param_1 = 0;
        *(undefined4 *)(param_1 + 4) = 0;
        *(undefined4 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0xc) = 0;
        uVar1 = 0;
    }
    if ((param_2 & 0x10) != 0) {
        *(undefined4 *)(param_1 + 0x10) = 0;
        uVar1 = 0;
        *(undefined4 *)(param_1 + 0x14) = 0;
    }
    if ((param_2 & 8) != 0) {
        *(undefined4 *)(param_1 + 0x18) = uVar1;
    }
    if ((param_2 & 4) != 0) {
        *(undefined4 *)(param_1 + 0x1c) = uVar1;
    }
    if ((param_2 & 2) != 0) {
        *(undefined2 *)(param_1 + 0x1e) = 0;
    }
    if ((param_2 & 1) != 0) {
        *(undefined *)(param_1 + 0x1f) = 0;
    }
    return;
}
