/* Decompiled C draft; module arm7; ROM address 0600a888. No matching claim. */
#include "types.h"
#include "deps/0600a888_FUN_0600a888.h"

void FUN_0600a888(void)

{
  FUN_0600a684();
  thunk_FUN_037fb24c(0,(*(uint *)(DAT_0600a8c4 & 0xfffffffc) >> (DAT_0600a8c4 & 3) * 8 |
                       *(uint *)(DAT_0600a8c4 & 0xfffffffc) << (DAT_0600a8c4 & 3) * -8 + 0x20) +
                       DAT_0600a8c8,0xb4);
  return;
}

