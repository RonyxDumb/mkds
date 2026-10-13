/* Decompiled C draft; module arm7; ROM address 0600b5cc. No matching claim. */
#include "types.h"
#include "deps/0600b5cc_FUN_0600b5cc.h"

undefined4 FUN_0600b5cc(uint param_1)

{
  uint uVar1;
  
  if (param_1 < 2) {
    uVar1 = *(uint *)(DAT_0600b61c & 0xfffffffc) >> (DAT_0600b61c & 3) * 8 |
            *(uint *)(DAT_0600b61c & 0xfffffffc) << (DAT_0600b61c & 3) * -8 + 0x20;
    *(ushort *)(uVar1 + 0x33a) = *(ushort *)(uVar1 + 0x33a) & 0xff7f | (ushort)((param_1 & 1) << 7);
    if (param_1 == 1) {
      *DAT_0600b624 = *DAT_0600b620;
    }
    return 0;
  }
  return 5;
}

