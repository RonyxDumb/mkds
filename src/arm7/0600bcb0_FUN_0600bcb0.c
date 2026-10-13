/* Decompiled C draft; module arm7; ROM address 0600bcb0. No matching claim. */
#include "types.h"
#include "deps/0600bcb0_FUN_0600bcb0.h"

undefined4 FUN_0600bcb0(uint param_1)

{
  if (param_1 < 0x100) {
    *(short *)((*(uint *)(DAT_0600bcdc & 0xfffffffc) >> (DAT_0600bcdc & 3) * 8 |
               *(uint *)(DAT_0600bcdc & 0xfffffffc) << (DAT_0600bcdc & 3) * -8 + 0x20) + 0x32a) =
         (short)param_1;
    *DAT_0600bce0 = (short)param_1;
    return 0;
  }
  return 5;
}

