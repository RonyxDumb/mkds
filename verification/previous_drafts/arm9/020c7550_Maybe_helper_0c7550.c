/* Decompiled C draft; module arm9; ROM address 020c7550. No matching claim. */
#include "types.h"
#include "deps/020c7550_Maybe_helper_0c7550.h"

void Maybe_helper_0c7550(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020c7560. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020c7568)(param_1,*(uint *)(uRam020c7564 & 0xfffffffc) >> (uRam020c7564 & 3) * 8 |
                           *(uint *)(uRam020c7564 & 0xfffffffc) << (uRam020c7564 & 3) * -8 + 0x20,0)
  ;
  return;
}

