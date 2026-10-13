/* Decompiled C draft; module arm9; ROM address 02147914. No matching claim. */
#include "types.h"
#include "deps/02147914_func_02147914.h"

void func_02147914(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  func_021470f8();
  uVar1 = param_1 + 0x24U & 3;
  uVar2 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  *(uint *)(param_2 + 0x24) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x28U & 3;
  uVar2 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  *(uint *)(param_2 + 0x28) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x2cU & 3;
  uVar2 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  *(uint *)(param_2 + 0x2c) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  return;
}

