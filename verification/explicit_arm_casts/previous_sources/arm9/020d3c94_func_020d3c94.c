/* Decompiled C draft; module arm9; ROM address 020d3c94. No matching claim. */
#include "types.h"
#include "deps/020d3c94_func_020d3c94.h"

void func_020d3c94(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x58U & 3;
  uVar2 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  func_020d2c2c(param_1 + 4,param_1 + 0x10,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,
                (int)*(short *)(param_1 + 100),param_2,param_3);
  return;
}

