/* Decompiled C draft; module arm7; ROM address 0600ae00. No matching claim. */
#include "types.h"
#include "deps/0600ae00_FUN_0600ae00.h"

undefined4 FUN_0600ae00(uint param_1)

{
  *(short *)((*(uint *)(DAT_0600ae24 & 0xfffffffc) >> (DAT_0600ae24 & 3) * 8 |
             *(uint *)(DAT_0600ae24 & 0xfffffffc) << (DAT_0600ae24 & 3) * -8 + 0x20) + 0x354) =
       (short)(param_1 >> 1);
  *DAT_0600ae28 = (short)param_1;
  return 0;
}

