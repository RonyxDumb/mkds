/* Decompiled C draft; module arm9; ROM address 020e4fb0. No matching claim. */
#include "types.h"
#include "deps/020e4fb0_Maybe_get_17b7f0.h"

void Maybe_get_17b7f0(void)

{
                    /* WARNING: Could not recover jumptable at 0x020e4fbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020e4fc4)(*(uint *)(uRam020e4fc0 & 0xfffffffc) >> (uRam020e4fc0 & 3) * 8 |
                   *(uint *)(uRam020e4fc0 & 0xfffffffc) << (uRam020e4fc0 & 3) * -8 + 0x20);
  return;
}

