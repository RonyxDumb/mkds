/* Decompiled C draft; module arm9; ROM address 020d0cbc. No matching claim. */
#include "types.h"
#include "deps/020d0cbc_Maybe_helper_0d0cbc.h"

void Maybe_helper_0d0cbc(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020d0ccc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020d0cd4)(param_1,*(uint *)(uRam020d0cd0 & 0xfffffffc) >> (uRam020d0cd0 & 3) * 8 |
                           *(uint *)(uRam020d0cd0 & 0xfffffffc) << (uRam020d0cd0 & 3) * -8 + 0x20,1)
  ;
  return;
}

