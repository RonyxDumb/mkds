/* Decompiled C draft; module arm9; ROM address 02104ee0. No matching claim. */
#include "types.h"
#include "deps/02104ee0_func_02104ee0.h"

void func_02104ee0(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  func_020deb2c(param_1 + 0x50,param_2,0,
                ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x10000) != 0,0);
  return;
}

