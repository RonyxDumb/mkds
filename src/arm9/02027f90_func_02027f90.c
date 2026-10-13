/* Decompiled C draft; module arm9; ROM address 02027f90. No matching claim. */
#include "types.h"
#include "deps/02027f90_func_02027f90.h"

void func_02027f90(ushort param_1,int param_2)

{
  param_1 = *puRam02027fb4 & 0xffc0 | param_1;
  if (param_2 != 0) {
    param_1 = param_1 | 0x20;
  }
  *puRam02027fb4 = param_1;
  return;
}

