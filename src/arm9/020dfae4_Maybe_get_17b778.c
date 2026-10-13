/* Decompiled C draft; module arm9; ROM address 020dfae4. No matching claim. */
#include "types.h"
#include "deps/020dfae4_Maybe_get_17b778.h"

void Maybe_get_17b778(void)

{
                    /* WARNING: Could not recover jumptable at 0x020dfaf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020dfaf8)(*(uint *)(uRam020dfaf4 & 0xfffffffc) >> (uRam020dfaf4 & 3) * 8 |
                   *(uint *)(uRam020dfaf4 & 0xfffffffc) << (uRam020dfaf4 & 3) * -8 + 0x20);
  return;
}

