/* Decompiled C draft; module arm9; ROM address 020f2d98. No matching claim. */
#include "types.h"
#include "deps/020f2d98_func_020f2d98.h"

void func_020f2d98(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = uRam020f2da8;
  *(undefined4 *)(param_1 + 300) = param_2;
  *(undefined4 *)(param_1 + 0x124) = uVar1;
  return;
}

