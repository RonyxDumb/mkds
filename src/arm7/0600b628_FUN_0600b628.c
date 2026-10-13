/* Decompiled C draft; module arm7; ROM address 0600b628. No matching claim. */
#include "types.h"
#include "deps/0600b628_FUN_0600b628.h"

undefined4 FUN_0600b628(uint param_1)

{
  uint uVar1;
  
  if (param_1 < 2) {
    uVar1 = *(uint *)(DAT_0600b664 & 0xfffffffc) >> (DAT_0600b664 & 3) * 8 |
            *(uint *)(DAT_0600b664 & 0xfffffffc) << (DAT_0600b664 & 3) * -8 + 0x20;
    *(ushort *)(uVar1 + 0x33a) = *(ushort *)(uVar1 + 0x33a) & 0xffbf | (ushort)((param_1 & 1) << 6);
    return 0;
  }
  return 5;
}

