/* Decompiled C draft; module arm9; ROM address 020cce3c. No matching claim. */
#include "types.h"
#include "deps/020cce3c_Maybe_helper_0cce3c.h"

void Maybe_helper_0cce3c(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020cce4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020cce54)(param_1,*(uint *)(uRam020cce50 & 0xfffffffc) >> (uRam020cce50 & 3) * 8 |
                           *(uint *)(uRam020cce50 & 0xfffffffc) << (uRam020cce50 & 3) * -8 + 0x20,1)
  ;
  return;
}

