/* Decompiled C draft; module arm9; ROM address 020c5804. No matching claim. */
#include "types.h"
#include "deps/020c5804_func_020c5804.h"

void func_020c5804(int param_1)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar3 = (*(uint *)(DAT_020c5938 & 0xfffffffc) >> (DAT_020c5938 & 3) * 8 |
          *(uint *)(DAT_020c5938 & 0xfffffffc) << (DAT_020c5938 & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
    return;
  }
  iVar4 = func_020b1d0c();
  if (iVar4 == 0) {
    return;
  }
  uVar3 = (*(uint *)(DAT_020c5938 & 0xfffffffc) >> (DAT_020c5938 & 3) * 8 |
          *(uint *)(DAT_020c5938 & 0xfffffffc) << (DAT_020c5938 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  switch(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) {
  case 0:
    func_020c55b0(param_1);
    return;
  case 1:
    break;
  case 2:
    break;
  case 3:
    goto LAB_020c5884;
  case 4:
    func_020c541c(param_1);
    break;
  case 5:
LAB_020c5884:
    uVar3 = (*(uint *)(DAT_020c593c & 0xfffffffc) >> (DAT_020c593c & 3) * 8 |
            *(uint *)(DAT_020c593c & 0xfffffffc) << (DAT_020c593c & 3) * -8 + 0x20) + 4;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    ComputeValueInterpolation_from_thumb(1,0x40,0,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    uVar3 = (*(uint *)(DAT_020c593c & 0xfffffffc) >> (DAT_020c593c & 3) * 8 |
            *(uint *)(DAT_020c593c & 0xfffffffc) << (DAT_020c593c & 3) * -8 + 0x20) + 8;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar5 = GetB3C4_Cell_RaceGoalM(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar5);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
    return;
  }
  return;
}

