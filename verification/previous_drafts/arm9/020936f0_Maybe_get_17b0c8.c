/* Decompiled C draft; module arm9; ROM address 020936f0. No matching claim. */
#include "types.h"
#include "deps/020936f0_Maybe_get_17b0c8.h"

void Maybe_get_17b0c8(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020936fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02093704)(param_1,*(uint *)(uRam02093700 & 0xfffffffc) >> (uRam02093700 & 3) * 8 |
                           *(uint *)(uRam02093700 & 0xfffffffc) << (uRam02093700 & 3) * -8 + 0x20);
  return;
}

