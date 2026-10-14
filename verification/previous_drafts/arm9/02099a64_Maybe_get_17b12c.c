/* Decompiled C draft; module arm9; ROM address 02099a64. No matching claim. */
#include "types.h"
#include "deps/02099a64_Maybe_get_17b12c.h"

void Maybe_get_17b12c(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02099a70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02099a78)(param_1,*(uint *)(uRam02099a74 & 0xfffffffc) >> (uRam02099a74 & 3) * 8 |
                           *(uint *)(uRam02099a74 & 0xfffffffc) << (uRam02099a74 & 3) * -8 + 0x20);
  return;
}

