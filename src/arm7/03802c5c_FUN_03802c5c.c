/* Decompiled C draft; module arm7; ROM address 03802c5c. No matching claim. */
#include "types.h"
#include "deps/03802c5c_FUN_03802c5c.h"

uint FUN_03802c5c(void)

{
  return *(uint *)(DAT_03802c68 & 0xfffffffc) >> (DAT_03802c68 & 3) * 8 |
         *(uint *)(DAT_03802c68 & 0xfffffffc) << (DAT_03802c68 & 3) * -8 + 0x20;
}

