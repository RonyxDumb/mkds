/* Decompiled C draft; module arm9; ROM address 02030364. No matching claim. */
#include "types.h"
#include "deps/02030364_func_02030364.h"

void func_02030364(ushort param_1,int param_2)

{
  param_1 = *puRam02030388 & 0xffc0 | param_1;
  if (param_2 != 0) {
    param_1 = param_1 | 0x20;
  }
  *puRam02030388 = param_1;
  return;
}

