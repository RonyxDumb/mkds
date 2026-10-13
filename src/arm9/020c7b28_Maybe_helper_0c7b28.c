/* Decompiled C draft; module arm9; ROM address 020c7b28. No matching claim. */
#include "types.h"
#include "deps/020c7b28_Maybe_helper_0c7b28.h"

void Maybe_helper_0c7b28(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020c7b38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020c7b40)(param_1,*(uint *)(uRam020c7b3c & 0xfffffffc) >> (uRam020c7b3c & 3) * 8 |
                           *(uint *)(uRam020c7b3c & 0xfffffffc) << (uRam020c7b3c & 3) * -8 + 0x20,0)
  ;
  return;
}

