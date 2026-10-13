/* Decompiled C draft; module arm9; ROM address 01ff9c9c. No matching claim. */
#include "types.h"
#include "deps/01ff9c9c_func_01ff9c9c.h"

void func_01ff9c9c(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x4c0U & 3;
  uVar2 = *(uint *)(param_1 + 0x4c0U & 0xfffffffc);
  if ((param_2 & 0x1000000) != (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
    *(uint *)(param_1 + 0x4c0) = param_2 & 0x1000000;
  }
  return;
}

