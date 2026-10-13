/* Decompiled C draft; module arm9; ROM address 01ffce48. No matching claim. */
#include "types.h"
#include "deps/01ffce48_func_01ffce48.h"

void func_01ffce48(uint param_1,uint param_2,int *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  *param_3 = uVar1 + ((int)(param_4 *
                           ((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                            *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) - uVar1))
                     >> 0xc);
  uVar1 = param_1 + 4 & 3;
  uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 4 & 3;
  uVar2 = *(uint *)(param_2 + 4 & 0xfffffffc);
  param_3[1] = uVar3 + ((int)(param_4 * ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - uVar3))
                       >> 0xc);
  uVar1 = param_1 + 8 & 3;
  uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 8 & 3;
  uVar2 = *(uint *)(param_2 + 8 & 0xfffffffc);
  param_3[2] = uVar3 + ((int)(param_4 * ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - uVar3))
                       >> 0xc);
  uVar1 = param_1 + 0xc & 3;
  uVar2 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 0xc & 3;
  uVar2 = *(uint *)(param_2 + 0xc & 0xfffffffc);
  param_3[3] = uVar3 + ((int)(param_4 * ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - uVar3))
                       >> 0xc);
  return;
}

