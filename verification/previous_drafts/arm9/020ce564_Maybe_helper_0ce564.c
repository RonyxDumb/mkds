/* Decompiled C draft; module arm9; ROM address 020ce564. No matching claim. */
#include "types.h"
#include "deps/020ce564_Maybe_helper_0ce564.h"

void Maybe_helper_0ce564(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020ce574. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020ce57c)(param_1,*(uint *)(uRam020ce578 & 0xfffffffc) >> (uRam020ce578 & 3) * 8 |
                           *(uint *)(uRam020ce578 & 0xfffffffc) << (uRam020ce578 & 3) * -8 + 0x20,1)
  ;
  return;
}

