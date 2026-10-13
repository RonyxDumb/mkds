/* Decompiled C draft; module arm9; ROM address 02094d9c. No matching claim. */
#include "types.h"
#include "deps/02094d9c_Maybe_get_17b0dc.h"

void Maybe_get_17b0dc(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02094da8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02094db0)(param_1,*(uint *)(uRam02094dac & 0xfffffffc) >> (uRam02094dac & 3) * 8 |
                           *(uint *)(uRam02094dac & 0xfffffffc) << (uRam02094dac & 3) * -8 + 0x20);
  return;
}

