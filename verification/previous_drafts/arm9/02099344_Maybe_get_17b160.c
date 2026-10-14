/* Decompiled C draft; module arm9; ROM address 02099344. No matching claim. */
#include "types.h"
#include "deps/02099344_Maybe_get_17b160.h"

void Maybe_get_17b160(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02099350. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02099358)(param_1,*(uint *)(uRam02099354 & 0xfffffffc) >> (uRam02099354 & 3) * 8 |
                           *(uint *)(uRam02099354 & 0xfffffffc) << (uRam02099354 & 3) * -8 + 0x20);
  return;
}

