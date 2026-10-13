/* Decompiled C draft; module arm9; ROM address 020989fc. No matching claim. */
#include "types.h"
#include "deps/020989fc_Maybe_get_17b10c.h"

void Maybe_get_17b10c(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02098a08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02098a10)(param_1,*(uint *)(uRam02098a0c & 0xfffffffc) >> (uRam02098a0c & 3) * 8 |
                           *(uint *)(uRam02098a0c & 0xfffffffc) << (uRam02098a0c & 3) * -8 + 0x20);
  return;
}

