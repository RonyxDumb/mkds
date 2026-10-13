/* Decompiled C draft; module arm9; ROM address 020cc6dc. No matching claim. */
#include "types.h"
#include "deps/020cc6dc_GetIsTeams.h"

int GetIsTeams(void)

{
  return (int)*(char *)((*(uint *)(uRam020cc6ec & 0xfffffffc) >> (uRam020cc6ec & 3) * 8 |
                        *(uint *)(uRam020cc6ec & 0xfffffffc) << (uRam020cc6ec & 3) * -8 + 0x20) +
                       0x58);
}

