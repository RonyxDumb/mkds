/* Decompiled C draft; module arm9; ROM address 020c76ac. No matching claim. */
#include "types.h"
#include "deps/020c76ac_Maybe_helper_0c76ac.h"

void Maybe_helper_0c76ac(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020c76bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020c76c4)(param_1,*(uint *)(uRam020c76c0 & 0xfffffffc) >> (uRam020c76c0 & 3) * 8 |
                           *(uint *)(uRam020c76c0 & 0xfffffffc) << (uRam020c76c0 & 3) * -8 + 0x20,0)
  ;
  return;
}

