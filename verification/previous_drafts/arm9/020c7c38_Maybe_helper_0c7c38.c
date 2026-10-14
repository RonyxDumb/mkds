/* Decompiled C draft; module arm9; ROM address 020c7c38. No matching claim. */
#include "types.h"
#include "deps/020c7c38_Maybe_helper_0c7c38.h"

void Maybe_helper_0c7c38(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020c7c48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020c7c50)(param_1,*(uint *)(uRam020c7c4c & 0xfffffffc) >> (uRam020c7c4c & 3) * 8 |
                           *(uint *)(uRam020c7c4c & 0xfffffffc) << (uRam020c7c4c & 3) * -8 + 0x20,0)
  ;
  return;
}

