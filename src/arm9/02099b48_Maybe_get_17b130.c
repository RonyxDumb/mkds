/* Decompiled C draft; module arm9; ROM address 02099b48. No matching claim. */
#include "types.h"
#include "deps/02099b48_Maybe_get_17b130.h"

void Maybe_get_17b130(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02099b54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02099b5c)(param_1,*(uint *)(uRam02099b58 & 0xfffffffc) >> (uRam02099b58 & 3) * 8 |
                           *(uint *)(uRam02099b58 & 0xfffffffc) << (uRam02099b58 & 3) * -8 + 0x20);
  return;
}

