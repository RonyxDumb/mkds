/* Decompiled C draft; module arm7; ROM address 0600b39c. No matching claim. */
#include "types.h"
#include "deps/0600b39c_FUN_0600b39c.h"

undefined4 FUN_0600b39c(uint param_1)

{
  if ((param_1 != 0) && (param_1 < 0x100)) {
    *(short *)((*(uint *)(DAT_0600b3dc & 0xfffffffc) >> (DAT_0600b3dc & 3) * 8 |
               *(uint *)(DAT_0600b3dc & 0xfffffffc) << (DAT_0600b3dc & 3) * -8 + 0x20) + 0x3b8) =
         (short)param_1;
    *DAT_0600b3e0 = (short)param_1;
    *DAT_0600b3e4 = 0;
    return 0;
  }
  return 5;
}

