/* Decompiled C draft; module arm9; ROM address 020f9c40. No matching claim. */
#include "types.h"
#include "deps/020f9c40_func_020f9c40.h"

void func_020f9c40(int param_1)

{
  undefined2 uVar1;
  
  if (*(short *)(param_1 + 0xda) != -1) {
    uVar1 = func_020d5344();
    *(undefined2 *)(param_1 + 0xda) = uVar1;
    return;
  }
  return;
}

