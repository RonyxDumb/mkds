/* Decompiled C draft; module arm9; ROM address 020ca54c. No matching claim. */
#include "types.h"
#include "deps/020ca54c_Maybe_helper_0ca54c.h"

void Maybe_helper_0ca54c(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020ca55c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020ca564)(param_1,*(uint *)(uRam020ca560 & 0xfffffffc) >> (uRam020ca560 & 3) * 8 |
                           *(uint *)(uRam020ca560 & 0xfffffffc) << (uRam020ca560 & 3) * -8 + 0x20,0)
  ;
  return;
}

