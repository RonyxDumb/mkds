/* Decompiled C draft; module arm9; ROM address 02099ed8. No matching claim. */
#include "types.h"
#include "deps/02099ed8_Maybe_get_17b124.h"

void Maybe_get_17b124(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02099ee4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02099eec)(param_1,*(uint *)(uRam02099ee8 & 0xfffffffc) >> (uRam02099ee8 & 3) * 8 |
                           *(uint *)(uRam02099ee8 & 0xfffffffc) << (uRam02099ee8 & 3) * -8 + 0x20);
  return;
}

