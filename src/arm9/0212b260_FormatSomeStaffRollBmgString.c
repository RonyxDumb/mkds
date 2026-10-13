/* Decompiled C draft; module arm9; ROM address 0212b260. No matching claim. */
#include "types.h"
#include "deps/0212b260_FormatSomeStaffRollBmgString.h"

/* WARNING: Removing unreachable block (ram,0x0212b390) */

void FormatSomeStaffRollBmgString(void)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  short *psVar14;
  short asStack_ec [100];
  
  uVar9 = DAT_0212b5d0;
  uVar11 = *(uint *)(DAT_0212b5d0 & 0xfffffffc) >> (DAT_0212b5d0 & 3) * 8 |
           *(uint *)(DAT_0212b5d0 & 0xfffffffc) << (DAT_0212b5d0 & 3) * -8 + 0x20;
  uVar5 = uVar11 + 8 & 3;
  uVar8 = *(uint *)(uVar11 + 8 & 0xfffffffc);
  uVar4 = uVar11 + 0xc & 3;
  uVar7 = *(uint *)(uVar11 + 0xc & 0xfffffffc);
  *(uint *)(uVar11 + 8) =
       (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) +
       (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20);
  uVar5 = uVar9 & 3;
  uVar4 = *(uint *)(uVar9 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 8;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  iVar13 = (int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) >> 0xc;
  iVar12 = iVar13 + -8;
  if (iVar12 < 0) {
    iVar12 = iVar13 + 0xf8;
  }
  iVar13 = iVar12 >> 0x1f;
  iVar6 = GetVramBg0BaseOffset_Bottom();
  Mem_CpuFastMemorySet
            (0,(undefined4 *)(uintptr_t)(iVar6 + ((int)(((uint)(iVar12 * 0x1000000 + iVar13) >> 0x18 | iVar13 << 8) - iVar13)
                       >> 3) * 0x400),0x400);
  uVar4 = DAT_0212b5d0;
  uVar7 = *(uint *)(DAT_0212b5d0 & 0xfffffffc) >> (DAT_0212b5d0 & 3) * 8 |
          *(uint *)(DAT_0212b5d0 & 0xfffffffc) << (DAT_0212b5d0 & 3) * -8 + 0x20;
  uVar5 = uVar7 + 0x14 & 3;
  uVar9 = *(uint *)(uVar7 + 0x14 & 0xfffffffc);
  uVar5 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
  if (0 < (int)uVar5) {
    uVar9 = uVar7 + 0xc & 3;
    uVar8 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
    *(uint *)(uVar7 + 0x14) = uVar5 - (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20);
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar9 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    uVar5 = uVar9 + 0x14;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if ((int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) < 1) {
      *(undefined4 *)(uVar9 + 4) = 2;
    }
    return;
  }
  uVar5 = uVar7 + 8 & 3;
  uVar8 = *(uint *)(uVar7 + 8 & 0xfffffffc);
  uVar4 = uVar7 + 0x10 & 3;
  uVar9 = *(uint *)(uVar7 + 0x10 & 0xfffffffc);
  if ((int)(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) <=
      (int)(uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20)) {
    return;
  }
  iVar12 = 0;
  bVar3 = false;
  Mem_CpuFill8((uint *)(void *)(asStack_ec),0,200);
  iVar13 = DAT_0212b5d4;
  uVar5 = DAT_0212b5d0;
  do {
    uVar9 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
    uVar4 = uVar9 + 0x18 & 3;
    uVar7 = *(uint *)(uVar9 + 0x18 & 0xfffffffc);
    psVar14 = (short *)(uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20);
    sVar2 = *psVar14;
    if (sVar2 == 0x1a) {
      bVar1 = *(byte *)(psVar14 + 1);
      sVar2 = psVar14[2];
      if (*(char *)((int)psVar14 + 3) == '\x01') {
        uVar4 = 0;
        if (sVar2 != 99) {
          uVar4 = (uint)(ushort)psVar14[3];
        }
        switch(sVar2) {
        case 0:
          *(undefined4 *)(uVar9 + 0x854) = 0x40;
          if (uVar4 == 0) {
            uVar7 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                    *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
            uVar4 = uVar7 + 0x854;
            uVar9 = uVar4 & 3;
            uVar4 = *(uint *)(uVar4 & 0xfffffffc);
            *(uint *)(uVar7 + 0x854) = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20 | 0x200;
          }
          else if (uVar4 == 1) {
            uVar7 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                    *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
            uVar4 = uVar7 + 0x854;
            uVar9 = uVar4 & 3;
            uVar4 = *(uint *)(uVar4 & 0xfffffffc);
            *(uint *)(uVar7 + 0x854) = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20 | 0x400;
          }
          else if (uVar4 == 2) {
            uVar7 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                    *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
            uVar4 = uVar7 + 0x854;
            uVar9 = uVar4 & 3;
            uVar4 = *(uint *)(uVar4 & 0xfffffffc);
            *(uint *)(uVar7 + 0x854) = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20 | 0x800;
          }
          break;
        case 1:
          uVar7 = uVar9 + 0x10 & 3;
          uVar8 = *(uint *)(uVar9 + 0x10 & 0xfffffffc);
          bVar3 = true;
          *(uint *)(uVar9 + 0x10) =
               (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) + uVar4 * 0x10000;
          break;
        case 2:
          *(char *)(uVar9 + 0x850) = (char)(uVar4 << 1) + '\x01';
          break;
        case 3:
          *(char *)(uVar9 + 0x1c) = (char)uVar4;
          break;
        case 4:
          *(int *)(uVar9 + 0xc) = (int)((longlong)iVar13 * (longlong)(int)(uVar4 << 0xc) >> 0x25);
          break;
        case 5:
          break;
        default:
          if (sVar2 == 99) {
            bVar3 = true;
            *(undefined4 *)(uVar9 + 0x14) = 0xd0000;
          }
        }
      }
      uVar7 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
      uVar4 = uVar7 + 0x18;
      uVar9 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      *(uint *)(uVar7 + 0x18) = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + (uint)bVar1;
    }
    else if (sVar2 == 10) {
      uVar4 = uVar9 + 0x10 & 3;
      uVar7 = *(uint *)(uVar9 + 0x10 & 0xfffffffc);
      bVar3 = true;
      *(uint *)(uVar9 + 0x10) = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 0x10000;
      uVar7 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
      uVar4 = uVar7 + 0x18;
      uVar9 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      *(uint *)(uVar7 + 0x18) = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 2;
    }
    else if (sVar2 == 0) {
      *(short **)(uVar9 + 0x18) = psVar14 + 1;
    }
    else {
      asStack_ec[iVar12] = sVar2;
      uVar4 = uVar9 + 0x18 & 3;
      uVar7 = *(uint *)(uVar9 + 0x18 & 0xfffffffc);
      iVar12 = iVar12 + 1;
      *(uint *)(uVar9 + 0x18) = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 2;
    }
  } while (!bVar3);
  Mem_CpuFill8((uint *)(uintptr_t)((*(uint *)(DAT_0212b5d0 & 0xfffffffc) >> (DAT_0212b5d0 & 3) * 8 |
               *(uint *)(DAT_0212b5d0 & 0xfffffffc) << (DAT_0212b5d0 & 3) * -8 + 0x20) + 0x50),0,
               0x800);
  uVar10 = 0;
  if (*(char *)((*(uint *)(DAT_0212b5d0 & 0xfffffffc) >> (DAT_0212b5d0 & 3) * 8 |
                *(uint *)(DAT_0212b5d0 & 0xfffffffc) << (DAT_0212b5d0 & 3) * -8 + 0x20) + 0x850) ==
      '\x03') {
    uVar10 = 2;
  }
  G2d_Text_PrintString4
            ((*(uint *)(DAT_0212b5d0 & 0xfffffffc) >> (DAT_0212b5d0 & 3) * 8 |
             *(uint *)(DAT_0212b5d0 & 0xfffffffc) << (DAT_0212b5d0 & 3) * -8 + 0x20) + 0x40,8,uVar10
             ,0xf0);
  uVar9 = *(uint *)(DAT_0212b5d0 & 0xfffffffc) >> (DAT_0212b5d0 & 3) * 8 |
          *(uint *)(DAT_0212b5d0 & 0xfffffffc) << (DAT_0212b5d0 & 3) * -8 + 0x20;
  uVar5 = uVar9 + 8 & 3;
  uVar4 = *(uint *)(uVar9 + 8 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  iVar13 = (int)uVar5 >> 0x1f;
  iVar13 = ((int)((((uint)(((int)uVar5 >> 0xc) * 0x1000000 + iVar13) >> 0x18 | iVar13 << 8) - iVar13
                  ) + 0xc0) >> 3) * 8;
  if (0xff < iVar13) {
    iVar13 = iVar13 + -0x100;
  }
  if (0x100 < iVar13 + 0x10) {
    AllocateReserveTEQSub(0x14,iVar13 << 7,uVar9 + 0x50,(0x100 - iVar13) * 0x80);
    AllocateReserveTEQSub
              (0x14,0,(*(uint *)(DAT_0212b5d0 & 0xfffffffc) >> (DAT_0212b5d0 & 3) * 8 |
                      *(uint *)(DAT_0212b5d0 & 0xfffffffc) << (DAT_0212b5d0 & 3) * -8 + 0x20) + 0x50
                      + iVar13 * 0x80,(iVar13 + -0xf0) * 0x80);
    return;
  }
  AllocateReserveTEQSub(0x14,iVar13 << 7,uVar9 + 0x50,0x800);
  return;
}

