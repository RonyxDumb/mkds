/* Decompiled C draft; module arm7; ROM address 060181f8. No matching claim. */
#include "types.h"
#include "deps/060181f8_FUN_060181f8.h"

void FUN_060181f8(void)

{
  short sVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint unaff_r5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar5 = *(uint *)(DAT_060184fc & 0xfffffffc) >> (DAT_060184fc & 3) * 8 |
          *(uint *)(DAT_060184fc & 0xfffffffc) << (DAT_060184fc & 3) * -8 + 0x20;
  iVar6 = uVar5 + DAT_06018500;
  uVar8 = uVar5 + 0x1c4 & 3;
  uVar7 = *(uint *)(uVar5 + 0x1c4 & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  if (uVar8 == 0xffffffff) {
    return;
  }
  if (*(short *)(uVar5 + 0x34c) != 0x40) {
    FUN_060090b4(uVar5 + 0x1c4,uVar8);
    return;
  }
  if ((int)((uint)*(ushort *)(uVar8 + 0x24) << 0x17) < 0) {
    if ((*(ushort *)(uVar8 + 0x34) & 1) == 0) {
      uVar7 = iVar6 + 0x28U & 3;
      uVar3 = *(uint *)(iVar6 + 0x28U & 0xfffffffc);
      *(uint *)(iVar6 + 0x28) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
    }
    else {
      uVar7 = iVar6 + 0x2cU & 3;
      uVar3 = *(uint *)(iVar6 + 0x2cU & 0xfffffffc);
      *(uint *)(iVar6 + 0x2c) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
    }
  }
  else if ((*(ushort *)(uVar8 + 0x28) & 1) == 0) {
    uVar7 = iVar6 + 0x28U & 3;
    uVar3 = *(uint *)(iVar6 + 0x28U & 0xfffffffc);
    *(uint *)(iVar6 + 0x28) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
  }
  else {
    uVar7 = iVar6 + 0x2cU & 3;
    uVar3 = *(uint *)(iVar6 + 0x2cU & 0xfffffffc);
    *(uint *)(iVar6 + 0x2c) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
  }
  iVar4 = thunk_FUN_03806b2c(*(ushort *)(uVar8 + 0x18) & 0xf0,0x10);
  uVar7 = iVar6 + 0x24U & 3;
  uVar3 = *(uint *)(iVar6 + 0x24U & 0xfffffffc);
  *(uint *)(iVar6 + 0x24) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + iVar4 + -1;
  bVar2 = true;
  sVar1 = *(short *)(uVar5 + 0x350);
  if (sVar1 == 1) {
    if ((*(ushort *)(uVar8 + 0x24) & 1) == 0) {
      unaff_r5 = FUN_0600ef30((ushort *)(uintptr_t)(uVar8 + 0x2e));
      if ((unaff_r5 == 0xff) || (iVar4 = FUN_0600e918(), iVar4 != 0x40)) {
        iVar6 = FUN_0600e918(unaff_r5);
        if (iVar6 == 0x30) {
          iVar6 = FUN_06013528(uVar8 + 0x2e,0xa0);
          if (iVar6 != 0) goto LAB_06018460;
          iVar6 = FUN_06013d2c(uVar8 + 0x2e,7);
        }
        else {
          iVar6 = FUN_06013528(uVar8 + 0x2e,0xc0);
          if (iVar6 != 0) goto LAB_06018460;
          iVar6 = FUN_0601364c(uVar8 + 0x2e,7);
        }
        if (iVar6 != 0) {
          FUN_060143ac();
        }
      }
      else {
        FUN_0600eb40(unaff_r5 & 0xffff,((uint)*(ushort *)(uVar8 + 0x24) << 0x13) >> 0x1f);
        uVar7 = FUN_0600e884(unaff_r5);
        if (*(ushort *)(uVar8 + 0x3a) == uVar7) {
          uVar7 = iVar6 + 0x3cU & 3;
          uVar3 = *(uint *)(iVar6 + 0x3cU & 0xfffffffc);
          *(uint *)(iVar6 + 0x3c) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
        }
        else {
          FUN_0600a954((undefined2 *)(uintptr_t)(uVar8 + 0x28),(undefined2 *)(uintptr_t)(uVar8 + 0x34));
          bVar2 = false;
        }
      }
    }
  }
  else if (((sVar1 == 2) || (sVar1 == 3)) && ((*(ushort *)(uVar8 + 0x24) & 1) == 0)) {
    if ((*(short *)(uVar5 + 0x352) != 0) && ((*(ushort *)(uVar8 + 0x24) & 0x2000) == 0)) {
      if ((*(ushort *)(uVar8 + 0x28) & 1) == 0) {
        if (sVar1 != 3) {
          *(ushort *)(uVar5 + 0x3d2) = *(ushort *)(uVar5 + 0x3d2) & 0xfffd;
        }
      }
      else {
        *(ushort *)(uVar5 + 0x3d2) = *(ushort *)(uVar5 + 0x3d2) & 0xfffe;
      }
      if (((*(short *)(uVar5 + 0x3d2) == 0) && (*(short *)(uVar5 + 0x19c) == 0)) &&
         (*(short *)(uVar5 + 0x1a8) == 0)) {
        FUN_0600ae00(1);
      }
    }
    unaff_r5 = (uint)*(ushort *)(uVar5 + 0x3cc);
    uVar7 = FUN_0600e884(unaff_r5);
    if (*(ushort *)(uVar8 + 0x3a) == uVar7) {
      uVar7 = iVar6 + 0x3cU & 3;
      uVar3 = *(uint *)(iVar6 + 0x3cU & 0xfffffffc);
      *(uint *)(iVar6 + 0x3c) = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 1;
    }
    else {
      FUN_0600a954((undefined2 *)(uintptr_t)(uVar8 + 0x2e),(undefined2 *)(uintptr_t)(uVar8 + 0x34));
      bVar2 = false;
    }
  }
LAB_06018460:
  if (bVar2) {
    FUN_060090b4(uVar5 + 0x1c4,uVar8);
  }
  else {
    *(short *)(uVar8 + 0x12) = (short)unaff_r5;
    FUN_0600eba4(unaff_r5 & 0xffff,*(ushort *)(uVar8 + 0x22) & 0xff);
    FUN_0600ea94(unaff_r5,*(undefined2 *)(uVar8 + 0x3a));
    FUN_0600ea58(unaff_r5);
    *(short *)(uVar8 + 0x16) = *(short *)(uVar8 + 0x20) + -0x18;
    *(undefined2 *)(uVar8 + 0xc) = 0x180;
    *(short *)(uVar8 + 0xe) = (short)(*(ushort *)(uVar8 + 0x16) + 0x2d >> 1);
    FUN_0600f19c(uVar5 + 0x1c4,uVar8);
  }
  if (*(short *)(uVar5 + 0x1cc) != 0) {
    FUN_06008a8c(2,6);
  }
  return;
}

