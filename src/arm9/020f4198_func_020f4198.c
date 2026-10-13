/* Decompiled C draft; module arm9; ROM address 020f4198. No matching claim. */
#include "types.h"
#include "deps/020f4198_func_020f4198.h"

bool func_020f4198(int param_1,undefined2 param_2)

{
  bool bVar1;
  
  bVar1 = *(short *)(param_1 + 0x10) == 0;
  if (bVar1) {
    *(undefined2 *)(param_1 + 0x10) = param_2;
  }
  return bVar1;
}

