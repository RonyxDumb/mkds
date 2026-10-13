/* Decompiled C draft; module arm9; ROM address 020c541c. No matching claim. */
#include "types.h"
#include "deps/020c541c_func_020c541c.h"

void func_020c541c(int param_1)

{
  longlong lVar1;
  short sVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_r4;
  uint uVar7;
  int iVar9;
  uint uVar8;
  
  uVar7 = (*(uint *)(DAT_020c55a4 & 0xfffffffc) >> (DAT_020c55a4 & 3) * 8 |
          *(uint *)(DAT_020c55a4 & 0xfffffffc) << (DAT_020c55a4 & 3) * -8 + 0x20) + 4;
  uVar3 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar8 = uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20;
  ComputeValueInterpolation_from_thumb(1,0xffffff80,0,uVar8);
  uVar3 = *(uint *)(DAT_020c55a4 & 0xfffffffc) >> (DAT_020c55a4 & 3) * 8 |
          *(uint *)(DAT_020c55a4 & 0xfffffffc) << (DAT_020c55a4 & 3) * -8 + 0x20;
  uVar7 = uVar3 + 0x14 & 3;
  uVar6 = *(uint *)(uVar3 + 0x14 & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  lVar1 = CONCAT44(uVar7,DAT_020c55a4);
  if (uVar7 != 9) {
    uVar6 = uVar3 + 0x18 & 3;
    uVar5 = *(uint *)(uVar3 + 0x18 & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    lVar1 = CONCAT44(uVar7,uVar6);
    if (((((int)uVar7 < (int)uVar6) && (lVar1 = CONCAT44(uVar7,uVar6), 0x1d < (int)uVar8)) &&
        (iVar9 = uVar8 - 10, lVar1 = CONCAT44(uVar7,uVar6), iVar9 < 0x54)) &&
       (lVar1 = (longlong)DAT_020c55ac *
                (longlong)
                ((int)((longlong)DAT_020c55a8 * (longlong)iVar9 >> 0x21) - (iVar9 >> 0x1f)),
       7 < iVar9 - (int)lVar1)) {
      return;
    }
  }
  uVar7 = uVar3 + 0x18 & 3;
  uVar3 = *(uint *)(uVar3 + 0x18 & 0xfffffffc);
  uVar7 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
  switch(uVar7) {
  case 0:
    unaff_r4 = 7;
    break;
  case 1:
    unaff_r4 = 6;
    break;
  case 2:
    unaff_r4 = 5;
    break;
  case 3:
    unaff_r4 = 4;
    break;
  case 4:
    unaff_r4 = 3;
    break;
  case 5:
    unaff_r4 = 2;
    break;
  case 6:
    unaff_r4 = 1;
    break;
  case 7:
    unaff_r4 = 0;
  }
  if (7 < (int)uVar7) {
    return;
  }
  uVar4 = GetB3C4_Cell_RaceGoalMrM(unaff_r4,(int)lVar1,(int)((ulonglong)lVar1 >> 0x20));
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  return;
}

