/* Decompiled C draft; module arm9; ROM address 01ff9490. No matching claim. */
#include "types.h"
#include "deps/01ff9490_func_01ff9490.h"

void func_01ff9490(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 + 0x18U & 3;
  uVar2 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
  *param_1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 0x1cU & 3;
  uVar2 = *(uint *)(param_2 + 0x1cU & 0xfffffffc);
  param_1[5] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  param_1[1] = 0;
  param_1[0xc] = 0;
  uVar1 = param_2 + 0x1cU & 3;
  uVar2 = *(uint *)(param_2 + 0x1cU & 0xfffffffc);
  param_1[0xd] = (uint)*(ushort *)(param_2 + 0x2e) *
                 ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * -2 + 0x2000) * 8;
  param_1[4] = 0;
  return;
}

