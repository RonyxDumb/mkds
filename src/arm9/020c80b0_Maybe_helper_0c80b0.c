/* Decompiled C draft; module arm9; ROM address 020c80b0. No matching claim. */
#include "types.h"
#include "deps/020c80b0_Maybe_helper_0c80b0.h"

void Maybe_helper_0c80b0(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020c80c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020c80c8)(param_1,*(uint *)(uRam020c80c4 & 0xfffffffc) >> (uRam020c80c4 & 3) * 8 |
                           *(uint *)(uRam020c80c4 & 0xfffffffc) << (uRam020c80c4 & 3) * -8 + 0x20,1)
  ;
  return;
}

