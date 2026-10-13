/* Decompiled C draft; module arm9; ROM address 01ffc008. No matching claim. */
#include "types.h"
#include "deps/01ffc008_func_01ffc008.h"

void func_01ffc008(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  undefined1 auStack_30 [12];
  undefined1 auStack_24 [16];
  
  VecFx32_Subtract(param_4 + 0x80,param_4 + 0x8c,auStack_30);
  VecFx32_Add(auStack_30,param_2,auStack_24);
  uVar1 = param_4 + 0x1d0U & 3;
  uVar2 = *(uint *)(param_4 + 0x1d0U & 0xfffffffc);
  VecFx32_AddScale1((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_3,param_4 + 0x15c,
                    auStack_24,param_1);
  return;
}

