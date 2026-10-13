/* Decompiled C draft; module arm7; ROM address 0600cf6c. No matching claim. */
#include "types.h"
#include "deps/0600cf6c_FUN_0600cf6c.h"

void FUN_0600cf6c(void)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ushort uVar8;
  int iVar9;
  
  uVar5 = DAT_0600d19c;
  iVar9 = (*(uint *)(DAT_0600d19c & 0xfffffffc) >> (DAT_0600d19c & 3) * 8 |
          *(uint *)(DAT_0600d19c & 0xfffffffc) << (DAT_0600d19c & 3) * -8 + 0x20) + DAT_0600d1a0;
  *DAT_0600d1a4 = 2;
  if (*(short *)((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                 *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x34c) == 0x12) {
    FUN_06011ea8();
  }
  else {
    uVar8 = *DAT_0600d1a8 & 0xf00;
    if (uVar8 == 0x300) {
      uVar5 = iVar9 + 0x8cU & 3;
      uVar6 = *(uint *)(iVar9 + 0x8cU & 0xfffffffc);
      if (((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) & 2) != 0) {
        FUN_0600c614();
      }
      uVar7 = *(uint *)(DAT_0600d19c & 0xfffffffc) >> (DAT_0600d19c & 3) * 8 |
              *(uint *)(DAT_0600d19c & 0xfffffffc) << (DAT_0600d19c & 3) * -8 + 0x20;
      uVar5 = uVar7 + 0x558;
      uVar6 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      *(uint *)(uVar7 + 0x558) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 1;
      FUN_06008a8c(0,8);
    }
    else if (uVar8 == 0x800) {
      uVar5 = iVar9 + 0x44U & 3;
      uVar6 = *(uint *)(iVar9 + 0x44U & 0xfffffffc);
      if (*(ushort *)(iVar9 + 0x9e) <=
          (*(ushort *)((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 4) & 0xff)) {
        *DAT_0600d1ac = 2;
        *(short *)(iVar9 + 0xa8) = *(short *)(iVar9 + 0xa8) + 1;
      }
      uVar5 = iVar9 + 0x90U & 3;
      uVar6 = *(uint *)(iVar9 + 0x90U & 0xfffffffc);
      uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
      *(short *)(uVar5 + 0x18) = *(short *)(uVar5 + 0x18) + 1;
    }
    else if (uVar8 == 0xb00) {
      uVar1 = (undefined2)DAT_0600d1b0;
      *DAT_0600d1b4 = uVar1;
      *DAT_0600d1b8 = uVar1;
      *DAT_0600d1bc = uVar1;
      *DAT_0600d1c0 = uVar1;
      uVar7 = (uint)*(ushort *)(iVar9 + 0x98);
      uVar6 = iVar9 + 0x44U & 3;
      uVar2 = *(uint *)(iVar9 + 0x44U & 0xfffffffc);
      uVar6 = (uint)*(ushort *)((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + 2);
      uVar2 = iVar9 + 0x90U & 3;
      uVar3 = *(uint *)(iVar9 + 0x90U & 0xfffffffc);
      iVar4 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0x1a;
      if (((1 < uVar6) &&
          ((int)((uint)*(ushort *)
                        ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                         *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x33a) << 0x1b)
           < 0)) && ((*DAT_0600d1c4 & 1) == 0)) {
        *DAT_0600d1c8 = *DAT_0600d1c8 ^ 1;
      }
      if ((*(ushort *)
            ((*(uint *)(DAT_0600d19c & 0xfffffffc) >> (DAT_0600d19c & 3) * 8 |
             *(uint *)(DAT_0600d19c & 0xfffffffc) << (DAT_0600d19c & 3) * -8 + 0x20) + 0x690) & 0x40
          ) != 0) {
        while (1 < uVar6) {
          uVar6 = (uVar6 << 0xf) >> 0x10;
          if ((uVar6 & 1) != 0) {
            *(short *)(iVar4 + 6) = *(short *)(iVar4 + 6) + 1;
          }
          uVar7 = (uVar7 << 0xf) >> 0x10;
          if ((uVar7 & 1) != 0) {
            uVar5 = iVar9 + 0x90U & 3;
            uVar2 = *(uint *)(iVar9 + 0x90U & 0xfffffffc);
            iVar4 = iVar4 + (uint)*(ushort *)
                                   ((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 0x16);
          }
        }
      }
    }
    if ((uVar8 != 0x800) && ((*DAT_0600d1cc & 2) == 0)) {
      if (*(short *)(iVar9 + 0x3c) != 0) {
        *DAT_0600d1d0 = 2;
        *DAT_0600d1d4 = 0;
        if ((*DAT_0600d1a4 & 0x1000) == 0) {
          FUN_0600ca18();
        }
        else {
          *(short *)(iVar9 + 0xac) = *(short *)(iVar9 + 0xac) + 1;
        }
        *(short *)(iVar9 + 0xaa) = *(short *)(iVar9 + 0xaa) + 1;
      }
      *DAT_0600d1d8 = 2;
    }
    FUN_06008a8c(0,0xe);
  }
  return;
}

