/* Decompiled C draft; module arm9; ROM address 0212bc20. No matching claim. */
#include "types.h"
#include "deps/0212bc20_func_0212bc20.h"

void func_0212bc20(uint param_1)

{
  if (param_1 != 0) {
    SND_UnlockChannel(param_1,0);
    *puRam0212bc54 =
         (*(uint *)((uint)puRam0212bc54 & 0xfffffffc) >> ((uint)puRam0212bc54 & 3) * 8 |
         *(uint *)((uint)puRam0212bc54 & 0xfffffffc) << ((uint)puRam0212bc54 & 3) * -8 + 0x20) &
         ~param_1;
    return;
  }
  return;
}

