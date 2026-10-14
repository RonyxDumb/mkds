/* Decompiled C draft; module arm7; ROM address 037fbd0c. No matching claim. */
#include "types.h"
#include "deps/037fbd0c_FUN_037fbd0c.h"

void FUN_037fbd0c(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 * 0x10 + 0x4000400) & 0x7fffffff;
  if ((param_2 & 1) != 0) {
    uVar1 = uVar1 | 0x8000;
  }
  *(uint *)(DAT_037fbd34 + param_1 * 0x10) = uVar1;
  return;
}

