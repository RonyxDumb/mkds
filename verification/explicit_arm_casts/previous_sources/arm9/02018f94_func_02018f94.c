/* Decompiled C draft; module arm9; ROM address 02018f94. No matching claim. */
#include "types.h"
#include "deps/02018f94_func_02018f94.h"

void func_02018f94(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  
  uVar1 = param_1 + 0x20U & 3;
  uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xf) - 6 < 2) {
    *(int *)(param_1 + 0x28) =
         (int)((*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
               *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20) +
              (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
              *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20)) / 2;
    uVar1 = param_3 + 4 & 3;
    uVar5 = *(uint *)(param_3 + 4 & 0xfffffffc);
    uVar2 = param_2 + 4 & 3;
    uVar4 = *(uint *)(param_2 + 4 & 0xfffffffc);
    *(int *)(param_1 + 0x2c) =
         (int)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) +
              (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20)) / 2;
    uVar1 = param_3 + 8 & 3;
    uVar5 = *(uint *)(param_3 + 8 & 0xfffffffc);
    uVar2 = param_2 + 8 & 3;
    uVar4 = *(uint *)(param_2 + 8 & 0xfffffffc);
    *(int *)(param_1 + 0x30) =
         (int)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) +
              (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20)) / 2;
    iVar3 = VecFx32_Distance(param_2,param_3);
    *(int *)(param_1 + 0x60) = iVar3 / 2;
    iStack_20 = (*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
                *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20) -
                (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20);
    uVar1 = param_3 + 4 & 3;
    uVar5 = *(uint *)(param_3 + 4 & 0xfffffffc);
    uVar2 = param_2 + 4 & 3;
    uVar4 = *(uint *)(param_2 + 4 & 0xfffffffc);
    iStack_1c = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) -
                (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
    uVar1 = param_3 + 8 & 3;
    uVar5 = *(uint *)(param_3 + 8 & 0xfffffffc);
    uVar2 = param_2 + 8 & 3;
    uVar4 = *(uint *)(param_2 + 8 & 0xfffffffc);
    iStack_18 = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) -
                (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
    VecFx32_Normalize(&iStack_20,&iStack_20);
    *(short *)(param_1 + 0x50) = (short)iStack_20;
    *(short *)(param_1 + 0x52) = (short)iStack_1c;
    *(short *)(param_1 + 0x54) = (short)iStack_18;
    return;
  }
  return;
}

