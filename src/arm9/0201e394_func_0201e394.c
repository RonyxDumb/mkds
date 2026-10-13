/* Decompiled C draft; module arm9; ROM address 0201e394. No matching claim. */
#include "types.h"
#include "deps/0201e394_func_0201e394.h"

void func_0201e394(short *param_1,undefined4 param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  
  *param_3 = (*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
             *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20) +
             (int)*param_1;
  uVar1 = (uint)(param_3 + 1) & 3;
  uVar2 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
  param_3[1] = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + (int)param_1[1];
  uVar1 = (uint)(param_3 + 2) & 3;
  uVar2 = *(uint *)((uint)(param_3 + 2) & 0xfffffffc);
  param_3[2] = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + (int)param_1[2];
  return;
}

