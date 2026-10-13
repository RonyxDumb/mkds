/* Decompiled C draft; module arm9; ROM address 020ce118. No matching claim. */
#include "types.h"
#include "deps/020ce118_Maybe_helper_0ce118.h"

void Maybe_helper_0ce118(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020ce128. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020ce130)(param_1,*(uint *)(uRam020ce12c & 0xfffffffc) >> (uRam020ce12c & 3) * 8 |
                           *(uint *)(uRam020ce12c & 0xfffffffc) << (uRam020ce12c & 3) * -8 + 0x20,1)
  ;
  return;
}

