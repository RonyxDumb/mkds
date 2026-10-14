/* Decompiled C draft; module arm9; ROM address 02099fbc. No matching claim. */
#include "types.h"
#include "deps/02099fbc_Maybe_get_17b118.h"

void Maybe_get_17b118(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02099fc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02099fd0)(param_1,*(uint *)(uRam02099fcc & 0xfffffffc) >> (uRam02099fcc & 3) * 8 |
                           *(uint *)(uRam02099fcc & 0xfffffffc) << (uRam02099fcc & 3) * -8 + 0x20);
  return;
}

