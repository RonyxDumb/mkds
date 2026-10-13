/* Decompiled C draft; module arm9; ROM address 020996d4. No matching claim. */
#include "types.h"
#include "deps/020996d4_Maybe_get_17b13c.h"

void Maybe_get_17b13c(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020996e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020996e8)(param_1,*(uint *)(uRam020996e4 & 0xfffffffc) >> (uRam020996e4 & 3) * 8 |
                           *(uint *)(uRam020996e4 & 0xfffffffc) << (uRam020996e4 & 3) * -8 + 0x20);
  return;
}

