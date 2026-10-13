/* Decompiled C draft; module arm9; ROM address 01ffc064. No matching claim. */
#include "types.h"
#include "deps/01ffc064_func_01ffc064.h"

void func_01ffc064(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_4 + 0x1d0U & 3;
  uVar2 = *(uint *)(param_4 + 0x1d0U & 0xfffffffc);
  VecFx32_AddScale1((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_3,param_4 + 300,
                    param_2,param_1);
  return;
}

