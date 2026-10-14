/* Decompiled C draft; module arm9; ROM address 020ac9b0. No matching claim. */
#include "types.h"
#include "deps/020ac9b0_Maybe_get_17b33c.h"

void Maybe_get_17b33c(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020ac9bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020ac9c4)(param_1,*(uint *)(uRam020ac9c0 & 0xfffffffc) >> (uRam020ac9c0 & 3) * 8 |
                           *(uint *)(uRam020ac9c0 & 0xfffffffc) << (uRam020ac9c0 & 3) * -8 + 0x20);
  return;
}

