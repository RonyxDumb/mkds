/* Decompiled C draft; module arm9; ROM address 02091654. No matching claim. */
#include "types.h"
#include "deps/02091654_Maybe_get_17b0b4.h"

void Maybe_get_17b0b4(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02091660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02091668)(param_1,*(uint *)(uRam02091664 & 0xfffffffc) >> (uRam02091664 & 3) * 8 |
                           *(uint *)(uRam02091664 & 0xfffffffc) << (uRam02091664 & 3) * -8 + 0x20);
  return;
}

