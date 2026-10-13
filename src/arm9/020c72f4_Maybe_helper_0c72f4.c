/* Decompiled C draft; module arm9; ROM address 020c72f4. No matching claim. */
#include "types.h"
#include "deps/020c72f4_Maybe_helper_0c72f4.h"

void Maybe_helper_0c72f4(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020c7304. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020c730c)(param_1,*(uint *)(uRam020c7308 & 0xfffffffc) >> (uRam020c7308 & 3) * 8 |
                           *(uint *)(uRam020c7308 & 0xfffffffc) << (uRam020c7308 & 3) * -8 + 0x20,0)
  ;
  return;
}

