/* Decompiled C draft; module arm9; ROM address 02102e8c. No matching claim. */
#include "types.h"
#include "deps/02102e8c_func_02102e8c.h"

undefined4 func_02102e8c(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x10U & 3;
  uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  func_02102eb8(param_2,0);
  func_020f8e3c(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0xf2);
  return 1;
}

