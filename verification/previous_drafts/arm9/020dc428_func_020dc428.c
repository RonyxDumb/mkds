/* Decompiled C draft; module arm9; ROM address 020dc428. No matching claim. */
#include "types.h"
#include "deps/020dc428_func_020dc428.h"

void func_020dc428(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = uRam020dc440;
  *(undefined4 *)(param_1 + 0xe8) = uRam020dc43c;
  *(undefined4 *)(param_1 + 0xec) = uVar1;
  return;
}

