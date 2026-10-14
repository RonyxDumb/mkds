/* Decompiled C draft; module arm9; ROM address 02135258. No matching claim. */
#include "types.h"
#include "deps/02135258_func_02135258.h"

undefined4 func_02135258(uint param_1,undefined4 param_2,int param_3)

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
  func_02134eb8((uint *)(uintptr_t)((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + uVar3),param_2,
                param_3);
  uVar1 = param_1 + 8 & 3;
  uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc);
  *(uint *)(param_1 + 8) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_3;
  return 1;
}

