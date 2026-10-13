/* Decompiled C draft; module arm7; ROM address 03802f20. No matching claim. */
#include "types.h"
#include "deps/03802f20_FUN_03802f20.h"

void FUN_03802f20(void)

{
  FUN_03802db8();
  *DAT_03802f54 =
       *(uint *)((uint)DAT_03802f54 & 0xfffffffc) >> ((uint)DAT_03802f54 & 3) * 8 |
       *(uint *)((uint)DAT_03802f54 & 0xfffffffc) << ((uint)DAT_03802f54 & 3) * -8 + 0x20 | 0x40;
  *DAT_03802f58 = 0x40;
  return;
}

