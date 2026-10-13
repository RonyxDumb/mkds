/* Decompiled C draft; module arm9; ROM address 02098b1c. No matching claim. */
#include "types.h"
#include "deps/02098b1c_Maybe_get_17b104.h"

void Maybe_get_17b104(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02098b28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02098b30)(param_1,*(uint *)(uRam02098b2c & 0xfffffffc) >> (uRam02098b2c & 3) * 8 |
                           *(uint *)(uRam02098b2c & 0xfffffffc) << (uRam02098b2c & 3) * -8 + 0x20);
  return;
}

