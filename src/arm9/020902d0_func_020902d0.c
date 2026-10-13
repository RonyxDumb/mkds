/* Decompiled C draft; module arm9; ROM address 020902d0. No matching claim. */
#include "types.h"
#include "deps/020902d0_func_020902d0.h"

void func_020902d0(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 + 0xb0U & 3;
  uVar2 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_0207c614();
    return;
  }
  return;
}

