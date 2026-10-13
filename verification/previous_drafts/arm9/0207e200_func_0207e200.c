/* Decompiled C draft; module arm9; ROM address 0207e200. No matching claim. */
#include "types.h"
#include "deps/0207e200_func_0207e200.h"

void func_0207e200(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 0x2cc;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar1 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x10;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  *param_1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  param_1[4] = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar1 = func_020853f0(*(undefined2 *)(param_2 + 4));
  param_1[7] = uVar1;
  uVar1 = (uint)(param_1 + 7) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc);
  param_1[8] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  param_1[9] = 0;
  param_1[1] = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  param_1[5] = 0xffffffff;
  param_1[6] = 0;
  return;
}

