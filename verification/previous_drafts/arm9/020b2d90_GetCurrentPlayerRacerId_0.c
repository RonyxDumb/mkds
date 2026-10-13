/* Decompiled C draft; module arm9; ROM address 020b2d90. No matching claim. */
#include "types.h"
#include "deps/020b2d90_GetCurrentPlayerRacerId_0.h"

int GetCurrentPlayerRacerId_0(void)

{
  return (int)*(char *)((*(uint *)(uRam020b2da0 & 0xfffffffc) >> (uRam020b2da0 & 3) * 8 |
                        *(uint *)(uRam020b2da0 & 0xfffffffc) << (uRam020b2da0 & 3) * -8 + 0x20) +
                       0x62);
}

