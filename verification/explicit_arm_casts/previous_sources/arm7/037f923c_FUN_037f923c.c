/* Decompiled C draft; module arm7; ROM address 037f923c. No matching claim. */
#include "types.h"
#include "deps/037f923c_FUN_037f923c.h"

void FUN_037f923c(uint *param_1,uint param_2)

{
  if (*(uint *)(DAT_037f929c & 0xfffffffc) >> (DAT_037f929c & 3) * 8 == 0 &&
      *(uint *)(DAT_037f929c & 0xfffffffc) << (DAT_037f929c & 3) * -8 + 0x20 == 0) {
    FUN_037f91f4(param_2);
  }
  else {
    FUN_037f9678(param_1,DAT_037f92a0);
    param_1[1] = param_2;
    *param_1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 | 0x80;
    param_1[0x12] = 1;
    FUN_037f9710(param_1);
  }
  return;
}

