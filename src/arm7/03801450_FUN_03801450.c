/* Decompiled C draft; module arm7; ROM address 03801450. No matching claim. */
#include "types.h"
#include "deps/03801450_FUN_03801450.h"

bool FUN_03801450(void)

{
  return *(uint *)(DAT_03801468 & 0xfffffffc) >> (DAT_03801468 & 3) * 8 == 0 &&
         *(uint *)(DAT_03801468 & 0xfffffffc) << (DAT_03801468 & 3) * -8 + 0x20 == 0;
}

