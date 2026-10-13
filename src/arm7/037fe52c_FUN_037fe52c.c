/* Decompiled C draft; module arm7; ROM address 037fe52c. No matching claim. */
#include "types.h"
#include "deps/037fe52c_FUN_037fe52c.h"

void FUN_037fe52c(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 0x24) = param_2;
  uVar1 = param_1 + 0x24U & 3;
  uVar2 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  *(uint *)(param_1 + 0x28) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_3;
  return;
}

