/* Decompiled C draft; module arm7; ROM address 0600c580. No matching claim. */
#include "types.h"
#include "deps/0600c580_FUN_0600c580.h"

uint FUN_0600c580(uint param_1)

{
  if (DAT_0600c5a0 <= param_1) {
    param_1 = param_1 - *(ushort *)
                         ((*(uint *)(DAT_0600c5a4 & 0xfffffffc) >> (DAT_0600c5a4 & 3) * 8 |
                          *(uint *)(DAT_0600c5a4 & 0xfffffffc) << (DAT_0600c5a4 & 3) * -8 + 0x20) +
                         0x3de);
  }
  return param_1;
}

