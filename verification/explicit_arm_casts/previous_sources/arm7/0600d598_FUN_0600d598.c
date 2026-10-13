/* Decompiled C draft; module arm7; ROM address 0600d598. No matching claim. */
#include "types.h"
#include "deps/0600d598_FUN_0600d598.h"

void FUN_0600d598(void)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  uint uVar6;
  
  uVar3 = *(uint *)(DAT_0600d868 & 0xfffffffc) >> (DAT_0600d868 & 3) * 8 |
          *(uint *)(DAT_0600d868 & 0xfffffffc) << (DAT_0600d868 & 3) * -8 + 0x20;
  iVar9 = uVar3 + DAT_0600d86c;
  *DAT_0600d870 = 0x4000;
  sVar1 = *(short *)(uVar3 + 0x350);
  if (sVar1 == 1) {
    uVar8 = iVar9 + 0x80U & 3;
    uVar6 = *(uint *)(iVar9 + 0x80U & 0xfffffffc);
    iVar7 = (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + (uint)*(ushort *)(uVar3 + 0x3da);
    uVar2 = *DAT_0600d874;
    FUN_060096e4(iVar7 + 0x2c,uVar2 & 0xff);
    FUN_060096e4(iVar7 + 0x2d,uVar2 >> 8);
    if (*(short *)(uVar3 + 0x352) == 1) {
      *DAT_0600d878 = *(short *)(uVar3 + 0x33c) + *DAT_0600d878 + 1;
    }
    uVar3 = *(uint *)(DAT_0600d868 & 0xfffffffc) >> (DAT_0600d868 & 3) * 8 |
            *(uint *)(DAT_0600d868 & 0xfffffffc) << (DAT_0600d868 & 3) * -8 + 0x20;
    *(ushort *)(uVar3 + 0x530) = ~*(ushort *)(uVar3 + 0x52e) | *(ushort *)(uVar3 + 0x532);
    if (((*DAT_0600d87c & 0x18) == 0) && ((*DAT_0600d87c & 6) != 2)) {
      uVar3 = iVar9 + 0x8cU & 3;
      uVar8 = *(uint *)(iVar9 + 0x8cU & 0xfffffffc);
      *(uint *)(iVar9 + 0x8c) = uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20 | 2;
    }
    else {
      uVar3 = iVar9 + 0x8cU & 3;
      uVar8 = *(uint *)(iVar9 + 0x8cU & 0xfffffffc);
      *(uint *)(iVar9 + 0x8c) = (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) & 0xfffffffd;
      FUN_0600c614();
    }
  }
  else {
    if (sVar1 == 2) {
      if (*(short *)(uVar3 + 0x356) == 0) {
        *DAT_0600d878 = (short)DAT_0600d880;
      }
      else {
        *DAT_0600d878 = *(short *)(uVar3 + 0x33c) + *DAT_0600d878 + 1;
      }
      if (*(short *)(uVar3 + 0x35e) == 2) {
        FUN_0600ae00(2);
      }
    }
    else if (sVar1 != 3) {
      return;
    }
    if (*(short *)(uVar3 + 0x34c) == 0x40) {
      bVar10 = *(short *)(uVar3 + 0x3b6) == 1;
      if ((*(short *)(uVar3 + 0x358) != 0) &&
         ((*(short *)(uVar3 + 0x3ba) == 1 ||
          ((*(short *)(uVar3 + 0x3ba) == 0 && (*(short *)(uVar3 + 0x3b8) == 1)))))) {
        bVar10 = true;
      }
    }
    else {
      bVar10 = true;
    }
    if (bVar10) {
      *DAT_0600d884 = *DAT_0600d884 | 1;
    }
    else {
      *DAT_0600d884 = *DAT_0600d884 & 0xfffe;
    }
    if (10 < *DAT_0600d888) {
      *DAT_0600d88c = 0;
    }
    *(short *)(uVar3 + 0x3b6) = *(short *)(uVar3 + 0x3b6) + -1;
    if (*(short *)(uVar3 + 0x3b6) == 0) {
      *(undefined2 *)(uVar3 + 0x3b6) = *(undefined2 *)(uVar3 + 0x3b4);
    }
    sVar1 = *(short *)(uVar3 + 0x3ba);
    *(short *)(uVar3 + 0x3ba) = sVar1 + -1;
    if (sVar1 == 0) {
      *(short *)(uVar3 + 0x3ba) = *(short *)(uVar3 + 0x3b8) + -1;
    }
    uVar8 = 0;
    do {
      iVar7 = iVar9 + uVar8 * 0x14;
      if ((*(short *)(iVar9 + uVar8 * 0x14) != 0) &&
         (uVar6 = iVar7 + 0xcU & 3, uVar5 = *(uint *)(iVar7 + 0xcU & 0xfffffffc),
         uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20, *(short *)(uVar6 + 8) == 0)) {
        uVar5 = uVar3 + 0x3ec & 3;
        uVar4 = *(uint *)(uVar3 + 0x3ec & 0xfffffffc);
        uVar6 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) - (uint)*(ushort *)(uVar6 + 4) &
                0xffff;
        if (((*(ushort *)(uVar3 + 0x3d0) < uVar6) &&
            (uVar5 = iVar7 + 8U & 3, uVar4 = *(uint *)(iVar7 + 8U & 0xfffffffc),
            ((uint)*(ushort *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0xc) << 0x1c) >>
            0x1e != 0)) || ((uint)*(ushort *)(uVar3 + 0x3d0) * 8 < uVar6)) {
          FUN_06014708(uVar8);
          uVar6 = iVar7 + 8U & 3;
          uVar5 = *(uint *)(iVar7 + 8U & 0xfffffffc);
          *(undefined2 *)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) = 2;
          FUN_06008a8c(0,0xe);
          *(short *)(iVar9 + 0xae) = *(short *)(iVar9 + 0xae) + 1;
        }
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 2);
    *DAT_0600d890 = 0xd;
  }
  return;
}

