/* Decompiled C draft; module arm9; ROM address 01ff9684. No matching claim. */
#include "types.h"
#include "deps/01ff9684_func_01ff9684.h"

void func_01ff9684(undefined4 *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  *param_1 = 0x1000;
  param_1[5] = 0x1000;
  param_1[1] = 0;
  uVar1 = param_2 + 0x24U & 3;
  uVar2 = *(uint *)(param_2 + 0x24U & 0xfffffffc);
  param_1[0xc] = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) *
                 (uint)*(ushort *)(param_2 + 0x2c) * -0x10;
  uVar1 = param_2 + 0x28U & 3;
  uVar2 = *(uint *)(param_2 + 0x28U & 0xfffffffc);
  param_1[0xd] = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) *
                 (uint)*(ushort *)(param_2 + 0x2e) * 0x10;
  param_1[4] = 0;
  return;
}

