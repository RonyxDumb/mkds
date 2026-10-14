/* Decompiled C draft; module arm9; ROM address 020ce3f8. No matching claim. */
#include "types.h"
#include "deps/020ce3f8_Maybe_helper_0ce3f8.h"

void Maybe_helper_0ce3f8(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020ce408. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020ce410)(param_1,*(uint *)(uRam020ce40c & 0xfffffffc) >> (uRam020ce40c & 3) * 8 |
                           *(uint *)(uRam020ce40c & 0xfffffffc) << (uRam020ce40c & 3) * -8 + 0x20,0)
  ;
  return;
}

