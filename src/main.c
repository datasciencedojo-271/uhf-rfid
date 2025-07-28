#include "main.h"
#include "uart.h"
#include "rfid.h"
#include "utils.h"

// This is a buffer for storing commands received from the host.
uint8_t command_buffer[256];

// This is the main loop of the application.
void main_loop(void)
{
  char *pcVar1;
  byte *pbVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  uint unaff_r7;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined4 local_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 local_f4;
  byte local_f0 [52];
  undefined1 local_bc [52];
  undefined1 auStack_88 [51];
  undefined1 auStack_55 [53];

  // Zero out all the local buffers.
  utils_memset(auStack_55 + 1,0x34);
  utils_memset(auStack_88,0x34);
  utils_memset(local_bc,0x34);
  utils_memset(local_f0,0x34);

  // Initialize the command packet.
  local_100 = *DAT_0000308c;
  uStack_fc = DAT_0000308c[1];
  uStack_f8 = DAT_0000308c[2];
  local_f4 = DAT_0000308c[3];
  local_10c = DAT_00003094;
  local_108 = DAT_00003098;
  uStack_104 = DAT_0000309c;
  local_110 = DAT_00003090;

  // Zero out the command buffer.
  uVar9 = 0;
  uVar10 = 0;
  for (uVar11 = 0; uVar11 < 8; uVar11 = uVar11 + 1 & 0xff) {
    *(undefined1 *)(DAT_000030a0 + uVar11) = 0;
  }

  // If there are no commands to process, return.
  if ((*DAT_000030a4 == '\0') && (*DAT_000030a8 == '\0')) {
    return;
  }

  // If there is a command to process, handle it.
  if (*DAT_000030a4 != '\0') {
    // Send the command to the RFID module.
    *DAT_000030ac = 0;
    uart_write(&local_100,9);

    // Wait for a response from the RFID module.
    while (*DAT_000030ac < 300) {
      uVar10 = uVar10 + 1;
      watchdog_reset();
      if (((0x17 < *DAT_000030ac) && (*(char *)(DAT_000030b0 + 0x12) == -0x60)) &&
         (*(char *)(DAT_000030b0 + 0x13) == '\x04')) {
        *DAT_000030ac = 0;
        pcVar1 = DAT_000030b4;
        *DAT_000030b4 = *DAT_000030b4 + '\x01';
        if (*pcVar1 == '\0') {
          return;
        }
        *pcVar1 = '\0';
        *DAT_000030b8 = 0;
        *(undefined4 *)(DAT_000030bc + 400) = 1;
        *DAT_000030c0 = 1;
        return;
      }
      if (((0x23 < *DAT_000030ac) && (*(char *)(DAT_000030b0 + 6) == -0x60)) &&
         (((ushort)(*(byte *)(DAT_000030b0 + 7) + 8) <= *DAT_000030ac &&
          (*(char *)(DAT_000030b0 + 7) != '\x04')))) {
        unaff_r7 = *(byte *)(DAT_000030b0 + 7) - 0x18 & 0xff;
        utils_memcpy(auStack_55 + 1,DAT_000030b0 + 0xb,unaff_r7);
        break;
      }
      if (((0x29 < *DAT_000030ac) && (*(char *)(DAT_000030b0 + 0xc) == -0x60)) &&
         (((ushort)(*(byte *)(DAT_000030b0 + 0xd) + 0xe) <= *DAT_000030ac &&
          (*(char *)(DAT_000030b0 + 0xd) != '\x04')))) {
        unaff_r7 = *(byte *)(DAT_000030b0 + 0xd) - 0x18 & 0xff;
        utils_memcpy(auStack_55 + 1,DAT_000030b0 + 0x11,unaff_r7);
        break;
      }
      if ((((0x2f < *DAT_000030ac) && (*(char *)(DAT_000030b0 + 0x12) == -0x60)) &&
          ((ushort)(*(byte *)(DAT_000030b0 + 0x13) + 0x14) <= *DAT_000030ac)) &&
         (*(char *)(DAT_000030b0 + 0x13) != '\x04')) {
        unaff_r7 = *(byte *)(DAT_000030b0 + 0x13) - 0x18 & 0xff;
        utils_memcpy(auStack_55 + 1,DAT_000030b0 + 0x17,unaff_r7);
        break;
      }
      if (0xfffff < uVar10) {
        *DAT_000030ac = 0;
        pcVar1 = DAT_000030b4;
        *DAT_000030b4 = *DAT_000030b4 + '\x01';
        if (*pcVar1 == '\0') {
          return;
        }
        *pcVar1 = '\0';
        *DAT_000030b8 = 0;
        *(undefined4 *)(DAT_000030bc + 400) = 1;
        *DAT_000030c0 = 1;
        return;
      }
    }
    uVar10 = 0;
    do {
      if ((*(char *)(DAT_000030b0 + (*DAT_000030ac - 6)) == -0x60) ||
         (*(char *)(DAT_000030b0 + (*DAT_000030ac - 5)) == '\x04')) break;
      uVar10 = uVar10 + 1;
    } while (uVar10 < 0x100000);
  }
  if (*DAT_000030a8 == '\0') {
    *DAT_000030b4 = '\0';
    if (*DAT_000030d8 != '\0') {
      *DAT_000030b8 = 1;
      *(undefined4 *)(DAT_000030bc + 400) = 1;
      *DAT_000030c0 = 0;
    }
    iVar7 = utils_memcmp(DAT_000030dc,auStack_55 + 1,unaff_r7);
    if ((iVar7 != 0) || (*DAT_000030e0 = 0, *DAT_000030e4 == '\0')) {
      utils_memcpy(DAT_000034c4,auStack_55 + 1,unaff_r7);
      if (*DAT_000034c8 != '\0') {
        rfid_delay(100);
      }
      *DAT_000034cc = 0;
      rfid_set_bit(0x40000000);
      if (*DAT_000034d0 == '\0') {
        if (*DAT_000034d4 != '\0') {
          for (uVar10 = 0; (int)uVar10 < (int)unaff_r7; uVar10 = uVar10 + 1 & 0xff) {
            local_bc[uVar10] = auStack_55[unaff_r7 - uVar10];
          }
          if (*DAT_000034d8 == 0) {
            uVar10 = 0x10;
          }
          else {
            uVar10 = (uint)*DAT_000034d8;
          }
          utils_memcpy(local_f0,local_bc + *DAT_000034dc,uVar10);
          if (*DAT_000034e0 != '\0') {
            for (uVar11 = 0; uVar11 < uVar10 / 2; uVar11 = uVar11 + 1 & 0xff) {
              bVar6 = local_f0[uVar11];
              local_f0[uVar11] = local_f0[(uVar10 - 1) - uVar11];
              local_f0[(uVar10 - 1) - uVar11] = bVar6;
            }
          }
          for (uVar11 = 0; pbVar2 = DAT_000034e8, uVar11 < uVar10; uVar11 = uVar11 + 1 & 0xff) {
            if (*DAT_000034e4 == '\0') {
              bVar6 = rfid_get_response(local_f0[uVar11]);
              *DAT_000034e8 = bVar6;
              if ((0x40 < local_f0[uVar11]) && (local_f0[uVar11] < 0x5b)) {
                *DAT_000034ec = 0x20;
              }
              DAT_000034ec[2] = *(undefined1 *)(DAT_000034f0 + (uint)*DAT_000034e8);
              rfid_send_command(DAT_000034ec,8);
              rfid_delay(10);
              if ((0x40 < local_f0[uVar11]) && (local_f0[uVar11] < 0x5b)) {
                *DAT_000034ec = 0;
              }
              DAT_000034ec[2] = 0;
              rfid_send_command(DAT_000034ec,8);
              rfid_delay(10);
            }
            else {
              *DAT_000034e8 = local_f0[uVar11] >> 4;
              if ((9 < *pbVar2) && (*pbVar2 < 0x25)) {
                *DAT_000034ec = 0x20;
              }
              DAT_000034ec[2] = *(undefined1 *)(DAT_000034f0 + (uint)*DAT_000034e8);
              rfid_send_command(DAT_000034ec,8);
              rfid_delay(10);
              if ((9 < *DAT_000034e8) && (*DAT_000034e8 < 0x25)) {
                *DAT_000034ec = 0;
              }
              DAT_000034ec[2] = 0;
              rfid_send_command(DAT_000034ec,8);
              rfid_delay(10);
              pbVar2 = DAT_000034e8;
              *DAT_000034e8 = local_f0[uVar11] & 0xf;
              if ((9 < *pbVar2) && (*pbVar2 < 0x25)) {
                *DAT_000034ec = 0x20;
              }
              DAT_000034ec[2] = *(undefined1 *)(DAT_000034f0 + (uint)*DAT_000034e8);
              rfid_send_command(DAT_000034ec,8);
              rfid_delay(10);
              if ((9 < *DAT_000034e8) && (*DAT_000034e8 < 0x25)) {
                *DAT_000034ec = 0;
              }
              DAT_000034ec[2] = 0;
              rfid_send_command(DAT_000034ec,8);
              rfid_delay(10);
            }
          }
        }
        if (*DAT_000034f4 != '\0') {
          utils_memcpy(local_f0,auStack_88 + *DAT_000034f8,uVar9);
          if (*DAT_000034fc != '\0') {
            for (uVar10 = 0; uVar10 < uVar9 / 2; uVar10 = uVar10 + 1 & 0xff) {
              bVar6 = local_f0[uVar10];
              local_f0[uVar10] = local_f0[(uVar9 - 1) - uVar10];
              local_f0[(uVar9 - 1) - uVar10] = bVar6;
            }
          }
          for (uVar10 = 0; pbVar2 = DAT_000034e8, uVar10 < uVar9; uVar10 = uVar10 + 1 & 0xff) {
            if (*DAT_00003500 == '\0') {
              *DAT_000034e8 = local_f0[uVar10] >> 4;
              if ((9 < *pbVar2) && (*pbVar2 < 0x25)) {
                *DAT_000034ec = 0x20;
              }
              DAT_000034ec[2] = *(undefined1 *)(DAT_000034f0 + (uint)*DAT_000034e8);
              rfid_send_command(DAT_000034ec,8);
              rfid_delay(10);
              if ((9 < *DAT_000034e8) && (*DAT_000034e8 < 0x25)) {
                *DAT_000034ec = 0;
              }
              DAT_000034ec[2] = 0;
              rfid_send_command(DAT_000034ec,8);
              rfid_delay(10);
              pbVar2 = DAT_000034e8;
              *DAT_000034e8 = local_f0[uVar10] & 0xf;
              if ((9 < *pbVar2) && (*pbVar2 < 0x25)) {
                *DAT_000034ec = 0x20;
              }
              DAT_000034ec[2] = *(undefined1 *)(DAT_000034f0 + (uint)*DAT_000034e8);
              rfid_send_command(DAT_000034ec,8);
              rfid_delay(10);
              if ((9 < *DAT_000034e8) && (*DAT_000034e8 < 0x25)) {
                *DAT_000034ec = 0;
              }
              DAT_000034ec[2] = 0;
              rfid_send_command(DAT_000034ec,8);
              rfid_delay(10);
            }
            else {
              bVar6 = rfid_get_response(local_f0[uVar10]);
              *DAT_000034e8 = bVar6;
              if ((0x40 < local_f0[uVar10]) && (local_f0[uVar10] < 0x5b)) {
                *DAT_000034ec = 0x20;
              }
              DAT_000034ec[2] = *(undefined1 *)(DAT_000034f0 + (uint)*DAT_000034e8);
              rfid_send_command(DAT_000034ec,8);
              rfid_delay(10);
              if ((0x40 < local_f0[uVar10]) && (local_f0[uVar10] < 0x5b)) {
                *DAT_000034ec = 0;
              }
              DAT_000034ec[2] = 0;
              rfid_send_command(DAT_000034ec,8);
              rfid_delay(10);
            }
          }
        }
        if (*DAT_00003504 != '\0') {
          DAT_000034ec[2] = 0x28;
          rfid_send_command(DAT_000034ec,8);
          rfid_delay(10);
          DAT_000034ec[2] = 0;
          rfid_send_command(DAT_000034ec,8);
          rfid_delay(10);
        }
        if (*DAT_00003508 != '\0') {
          DAT_000034ec[2] = 0x2b;
          rfid_send_command(DAT_000034ec,8);
          rfid_delay(10);
          DAT_000034ec[2] = 0;
          rfid_send_command(DAT_000034ec,8);
          rfid_delay(10);
        }
      }
    }
  }
  else {
    if (*DAT_000030a4 != '\0') {
      rfid_delay(0x14);
    }
    uVar3 = local_108;
    if (*DAT_000030c4 == 0) {
      iVar8 = ((uint)*DAT_000030c8 - (uint)*DAT_000030cc) + 1;
      iVar7 = iVar8 * 2;
      if (iVar7 == 0x10 || iVar8 * -2 + 0x10 < 0 != SBORROW4(0x10,iVar7)) {
        uVar9 = 0x10;
      }
      else {
        uVar9 = (((uint)*DAT_000030c8 - (uint)*DAT_000030cc) + 1) * 2;
      }
    }
    else {
      iVar7 = ((uint)*DAT_000030c8 - (uint)*DAT_000030cc) + 1;
      uVar10 = (uint)*DAT_000030c4;
      uVar9 = iVar7 * 2;
      if (uVar10 == uVar9 || (int)(uVar10 + iVar7 * -2) < 0 != SBORROW4(uVar10,uVar9)) {
        uVar9 = (uint)*DAT_000030c4;
      }
      else {
        uVar9 = (((uint)*DAT_000030c8 - (uint)*DAT_000030cc) + 1) * 2;
      }
    }
    uVar9 = uVar9 & 0xff;
    uVar10 = (uVar9 + 1) * 0x800000 >> 0x18;
    if ((((uint)*DAT_000030c4 + ((int)(uint)*DAT_000030c4 >> 1) * -2 == 0) &&
        ((*DAT_000030c4 + 1) / 2 == uVar10)) && (*DAT_000030d0 == '\x01')) {
      uVar10 = uVar10 + 1 & 0xff;
    }
    local_10c = CONCAT31(local_10c._1_3_,*DAT_000030d4);
    local_108 = CONCAT31(local_108._1_3_,*DAT_000030cc);
    uVar4 = local_108;
    local_108._3_1_ = SUB41(uVar3,3);
    local_108._0_3_ = CONCAT12((char)uVar10,(short)uVar4);
    uVar5 = utils_checksum(&local_110,0xf);
    uStack_104 = CONCAT13(uVar5,(undefined3)uStack_104);
    *DAT_000030ac = 0;
    uart_write(&local_110,0x10);
    uVar11 = 0;
    do {
      if (299 < *DAT_000030ac) goto LAB_00003050;
      uVar11 = uVar11 + 1;
      watchdog_reset();
      if ((*DAT_000030ac == 6) && (*(char *)(DAT_000030b0 + 1) == '\x04')) {
        *DAT_000030ac = 0;
        pcVar1 = DAT_000030b4;
        *DAT_000030b4 = *DAT_000030b4 + '\x01';
        if (*pcVar1 == '\0') {
          return;
        }
        *pcVar1 = '\0';
        *DAT_000030b8 = 0;
        *(undefined4 *)(DAT_000030bc + 400) = 1;
        *DAT_000030c0 = 1;
        return;
      }
      if ((uVar10 * 2 + 0xf < (uint)*DAT_000030ac) &&
         ((ushort)(*(byte *)(DAT_000030b0 + 1) + 2) == *DAT_000030ac)) {
        if (*DAT_000030a4 == '\0') {
          unaff_r7 = ((uint)*(byte *)(DAT_000030b0 + 1) + uVar10 * -2) - 10 & 0xff;
          utils_memcpy(auStack_55 + 1,DAT_000030b0 + 7,unaff_r7);
        }
        utils_memcpy(auStack_88,unaff_r7 + 7 + DAT_000030b0,uVar10 << 1);
        goto LAB_00003050;
      }
    } while (uVar11 < 0x100000);
    *DAT_000030ac = 0;
    pcVar1 = DAT_000030b4;
    *DAT_000030b4 = *DAT_000030b4 + '\x01';
    if (*pcVar1 != '\0') {
      *pcVar1 = '\0';
      *DAT_000030b8 = 0;
      *(undefined4 *)(DAT_000030bc + 400) = 1;
      *DAT_000030c0 = 1;
    }
  }
  return;
}

int main(void) {
    // Main loop
    while (1) {
        main_loop();
    }
}
