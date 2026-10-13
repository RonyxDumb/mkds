/* Decompiled C draft; module arm7; ROM address 037f9660. No matching claim. */
#include "types.h"
#include "deps/037f9660_FUN_037f9660.h"

void FUN_037f9660(void)

{
  *DAT_037f9674 =
       (*(uint *)((uint)DAT_037f9674 & 0xfffffffc) >> ((uint)DAT_037f9674 & 3) * 8 |
       *(uint *)((uint)DAT_037f9674 & 0xfffffffc) << ((uint)DAT_037f9674 & 3) * -8 + 0x20) + 1;
  return;
}

