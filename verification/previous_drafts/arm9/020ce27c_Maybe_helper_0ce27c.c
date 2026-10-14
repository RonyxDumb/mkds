/* Decompiled C draft; module arm9; ROM address 020ce27c. No matching claim. */
#include "types.h"
#include "deps/020ce27c_Maybe_helper_0ce27c.h"

void Maybe_helper_0ce27c(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020ce28c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020ce294)(param_1,*(uint *)(uRam020ce290 & 0xfffffffc) >> (uRam020ce290 & 3) * 8 |
                           *(uint *)(uRam020ce290 & 0xfffffffc) << (uRam020ce290 & 3) * -8 + 0x20,0)
  ;
  return;
}

