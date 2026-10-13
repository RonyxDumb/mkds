/* Decompiled C draft; module arm7; ROM address 03801030. No matching claim. */
#include "types.h"
#include "deps/03801030_FUN_03801030.h"

bool FUN_03801030(void)

{
  bool bVar1;
  
  bVar1 = ((*(uint *)(DAT_03801054 & 0xfffffffc) >> (DAT_03801054 & 3) * 8 |
           *(uint *)(DAT_03801054 & 0xfffffffc) << (DAT_03801054 & 3) * -8 + 0x20) & 0x100000) == 0;
  if (!bVar1) {
    *DAT_03801058 = 1;
  }
  return bVar1;
}

