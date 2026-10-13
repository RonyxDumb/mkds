/* Decompiled C draft; module arm9; ROM address 0210a664. No matching claim. */
#include "types.h"
#include "deps/0210a664_func_0210a664.h"

void func_0210a664(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = uRam0210a678;
  *(undefined4 *)(param_1 + 0x484) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  return;
}

