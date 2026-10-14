/* Decompiled C draft; module arm9; ROM address 020c7fa0. No matching claim. */
#include "types.h"
#include "deps/020c7fa0_Maybe_helper_0c7fa0.h"

void Maybe_helper_0c7fa0(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020c7fb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020c7fb8)(param_1,*(uint *)(uRam020c7fb4 & 0xfffffffc) >> (uRam020c7fb4 & 3) * 8 |
                           *(uint *)(uRam020c7fb4 & 0xfffffffc) << (uRam020c7fb4 & 3) * -8 + 0x20,0)
  ;
  return;
}

