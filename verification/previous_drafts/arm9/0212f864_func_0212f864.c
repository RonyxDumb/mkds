/* Decompiled C draft; module arm9; ROM address 0212f864. No matching claim. */
#include "types.h"
#include "deps/0212f864_func_0212f864.h"

void func_0212f864(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  param_1[1] = 0;
  uVar1 = (uint)(param_1 + 1) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  *param_1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  param_1[3] = 0;
  uVar1 = (uint)(param_1 + 3) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  param_1[2] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  return;
}

