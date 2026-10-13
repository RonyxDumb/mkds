/* Decompiled C draft; module arm9; ROM address 020e57a0. No matching claim. */
#include "types.h"
#include "deps/020e57a0_func_020e57a0.h"

void func_020e57a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint local_1c;
  uint local_18;
  undefined4 local_14;
  
  uVar1 = param_1 + 0x5cU & 3;
  uVar2 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
  local_18 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x58U & 3;
  uVar2 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  local_1c = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  local_14 = 0;
  func_020eafc4(param_2,param_1 + 4,param_1 + 0x28,param_1 + 0x58,&local_1c,param_3,param_4);
  return;
}

