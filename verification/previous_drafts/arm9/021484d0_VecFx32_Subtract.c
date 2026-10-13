/* Decompiled C draft; module arm9; ROM address 021484d0. No matching claim. */
#include "types.h"
#include "deps/021484d0_VecFx32_Subtract.h"

void VecFx32_Subtract(uint param_1,uint param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  *param_3 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) -
             (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
             *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20);
  uVar1 = param_1 + 4 & 3;
  uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar2 = param_2 + 4 & 3;
  uVar3 = *(uint *)(param_2 + 4 & 0xfffffffc);
  param_3[1] = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) -
               (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  uVar1 = param_1 + 8 & 3;
  uVar4 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar2 = param_2 + 8 & 3;
  uVar3 = *(uint *)(param_2 + 8 & 0xfffffffc);
  param_3[2] = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) -
               (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  return;
}

