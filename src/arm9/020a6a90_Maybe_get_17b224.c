/* Decompiled C draft; module arm9; ROM address 020a6a90. No matching claim. */
#include "types.h"
#include "deps/020a6a90_Maybe_get_17b224.h"

void Maybe_get_17b224(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020a6a9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020a6aa4)(param_1,*(uint *)(uRam020a6aa0 & 0xfffffffc) >> (uRam020a6aa0 & 3) * 8 |
                           *(uint *)(uRam020a6aa0 & 0xfffffffc) << (uRam020a6aa0 & 3) * -8 + 0x20);
  return;
}

