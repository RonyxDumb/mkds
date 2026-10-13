/* Decompiled C draft; module arm9; ROM address 020cefc0. No matching claim. */
#include "types.h"
#include "deps/020cefc0_Maybe_helper_0cefc0.h"

void Maybe_helper_0cefc0(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020cefd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020cefd8)(param_1,*(uint *)(uRam020cefd4 & 0xfffffffc) >> (uRam020cefd4 & 3) * 8 |
                           *(uint *)(uRam020cefd4 & 0xfffffffc) << (uRam020cefd4 & 3) * -8 + 0x20,0)
  ;
  return;
}

