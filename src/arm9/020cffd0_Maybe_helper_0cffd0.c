/* Decompiled C draft; module arm9; ROM address 020cffd0. No matching claim. */
#include "types.h"
#include "deps/020cffd0_Maybe_helper_0cffd0.h"

void Maybe_helper_0cffd0(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020cffe0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020cffe8)(param_1,*(uint *)(uRam020cffe4 & 0xfffffffc) >> (uRam020cffe4 & 3) * 8 |
                           *(uint *)(uRam020cffe4 & 0xfffffffc) << (uRam020cffe4 & 3) * -8 + 0x20,1)
  ;
  return;
}

