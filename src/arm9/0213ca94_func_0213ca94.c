/* Decompiled C draft; module arm9; ROM address 0213ca94. No matching claim. */
#include "types.h"
#include "deps/0213ca94_func_0213ca94.h"

void func_0213ca94(uint param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_1 + 8 & 3;
  uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 4 & 3;
  uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (uVar1 < uVar3 + param_3) {
    param_3 = uVar1 - uVar3;
  }
  func_0213c9e8((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + uVar3 * 2,param_2,
                param_3);
  uVar1 = param_1 + 8 & 3;
  uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc);
  *(uint *)(param_1 + 8) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_3;
  return;
}

