/* Decompiled C draft; module arm9; ROM address 020e0538. No matching claim. */
#include "types.h"
#include "deps/020e0538_func_020e0538.h"

void func_020e0538(uint param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar1 != 0) {
    MTX_MultVec33(param_1 + 4,uVar1 + 0x28,param_2);
    VecFx32_Add(uVar1 + 4,param_2,param_2);
    return;
  }
  return;
}

