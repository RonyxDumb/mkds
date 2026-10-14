/* Decompiled C draft; module arm9; ROM address 02099d10. No matching claim. */
#include "types.h"
#include "deps/02099d10_Maybe_get_17b168.h"

void Maybe_get_17b168(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02099d1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02099d24)(param_1,*(uint *)(uRam02099d20 & 0xfffffffc) >> (uRam02099d20 & 3) * 8 |
                           *(uint *)(uRam02099d20 & 0xfffffffc) << (uRam02099d20 & 3) * -8 + 0x20);
  return;
}

