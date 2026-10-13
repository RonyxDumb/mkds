/* Decompiled C draft; module arm9; ROM address 020e04b0. No matching claim. */
#include "types.h"
#include "deps/020e04b0_func_020e04b0.h"

undefined4 func_020e04b0(uint param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar4 != 0) {
    MTX_MultVec33(param_1 + 4,uVar4 + 0x28,param_2);
    VecFx32_Add(uVar4 + 4,param_2,param_2);
    uVar1 = uVar4 + 0x130 & 3;
    uVar2 = *(uint *)(uVar4 + 0x130 & 0xfffffffc);
    if ((uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) &&
       (MTX_MultVec33(param_1 + 0x10,uVar4 + 0x28,param_3), uVar1 = param_3 + 4U & 3,
       uVar3 = *(uint *)(param_3 + 4U & 0xfffffffc), uVar2 = uVar4 + 0x120 & 3,
       uVar4 = *(uint *)(uVar4 + 0x120 & 0xfffffffc),
       (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) <
       (int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20))) {
      return 1;
    }
  }
  return 0;
}

