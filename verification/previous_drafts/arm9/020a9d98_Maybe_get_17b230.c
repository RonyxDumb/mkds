/* Decompiled C draft; module arm9; ROM address 020a9d98. No matching claim. */
#include "types.h"
#include "deps/020a9d98_Maybe_get_17b230.h"

void Maybe_get_17b230(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020a9da4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020a9dac)(param_1,*(uint *)(uRam020a9da8 & 0xfffffffc) >> (uRam020a9da8 & 3) * 8 |
                           *(uint *)(uRam020a9da8 & 0xfffffffc) << (uRam020a9da8 & 3) * -8 + 0x20);
  return;
}

