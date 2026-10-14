/* Decompiled C draft; module arm9; ROM address 020c7820. No matching claim. */
#include "types.h"
#include "deps/020c7820_Maybe_helper_0c7820.h"

void Maybe_helper_0c7820(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020c7830. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020c7838)(param_1,*(uint *)(uRam020c7834 & 0xfffffffc) >> (uRam020c7834 & 3) * 8 |
                           *(uint *)(uRam020c7834 & 0xfffffffc) << (uRam020c7834 & 3) * -8 + 0x20,0)
  ;
  return;
}

