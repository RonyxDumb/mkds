/* Decompiled C draft; module arm7; ROM address 037fbfa4. No matching claim. */
#include "types.h"
#include "deps/037fbfa4_FUN_037fbfa4.h"

int FUN_037fbfa4(int param_1)

{
  if (param_1 < 0x20) {
    return (int)*(char *)(DAT_037fc00c + param_1);
  }
  if (0x3f < param_1) {
    if (0x5f < param_1) {
      return *(char *)(DAT_037fc00c + (0x20 - (param_1 + -0x60))) * -0x1000000 >> 0x18;
    }
    return *(char *)(DAT_037fc00c + param_1 + -0x40) * -0x1000000 >> 0x18;
  }
  return (int)*(char *)(DAT_037fc00c + (0x40 - param_1));
}

