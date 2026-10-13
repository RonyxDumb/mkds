/* Decompiled C draft; module arm9; ROM address 02099980. No matching claim. */
#include "types.h"
#include "deps/02099980_Maybe_get_17b148.h"

void Maybe_get_17b148(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0209998c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02099994)(param_1,*(uint *)(uRam02099990 & 0xfffffffc) >> (uRam02099990 & 3) * 8 |
                           *(uint *)(uRam02099990 & 0xfffffffc) << (uRam02099990 & 3) * -8 + 0x20);
  return;
}

