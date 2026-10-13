/* Decompiled C draft; module arm9; ROM address 0203033c. No matching claim. */
#include "types.h"
#include "deps/0203033c_func_0203033c.h"

void func_0203033c(ushort param_1,int param_2)

{
  param_1 = *puRam02030360 & 0xffc0 | param_1;
  if (param_2 != 0) {
    param_1 = param_1 | 0x20;
  }
  *puRam02030360 = param_1;
  return;
}

