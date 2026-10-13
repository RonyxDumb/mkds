/* Decompiled C draft; module arm9; ROM address 020c79f0. No matching claim. */
#include "types.h"
#include "deps/020c79f0_Maybe_helper_0c79f0.h"

void Maybe_helper_0c79f0(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020c7a00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020c7a08)(param_1,*(uint *)(uRam020c7a04 & 0xfffffffc) >> (uRam020c7a04 & 3) * 8 |
                           *(uint *)(uRam020c7a04 & 0xfffffffc) << (uRam020c7a04 & 3) * -8 + 0x20,0)
  ;
  return;
}

