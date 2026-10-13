/* Decompiled C draft; module arm7; ROM address 0600b564. No matching claim. */
#include "types.h"
#include "deps/0600b564_FUN_0600b564.h"

undefined4 FUN_0600b564(ushort *param_1)

{
  FUN_0600a954((undefined2 *)(uintptr_t)((*(uint *)(DAT_0600b5c0 & 0xfffffffc) >> (DAT_0600b5c0 & 3) * 8 |
               *(uint *)(DAT_0600b5c0 & 0xfffffffc) << (DAT_0600b5c0 & 3) * -8 + 0x20) + 0x3a8),
               param_1);
  FUN_0600a954((undefined2 *)(uintptr_t)(DAT_0600b5c4),param_1);
  if ((*param_1 & 1) == 0) {
    *DAT_0600b5c8 = *DAT_0600b5c8 | 0x400;
  }
  else {
    *DAT_0600b5c8 = *DAT_0600b5c8 & 0xfbff;
  }
  return 0;
}

