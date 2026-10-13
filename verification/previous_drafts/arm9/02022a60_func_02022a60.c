/* Decompiled C draft; module arm9; ROM address 02022a60. No matching claim. */
#include "types.h"
#include "deps/02022a60_func_02022a60.h"

void func_02022a60(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = func_02022a90();
  *(undefined4 *)(iVar1 + 0x24) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x28) = param_2;
  *(undefined4 *)(iVar1 + 0x2c) = param_3;
  return;
}

