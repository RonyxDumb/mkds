/* Decompiled C draft; module arm9; ROM address 020cd464. No matching claim. */
#include "types.h"
#include "deps/020cd464_Maybe_helper_0cd464.h"

void Maybe_helper_0cd464(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020cd474. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020cd47c)(param_1,*(uint *)(uRam020cd478 & 0xfffffffc) >> (uRam020cd478 & 3) * 8 |
                           *(uint *)(uRam020cd478 & 0xfffffffc) << (uRam020cd478 & 3) * -8 + 0x20,1)
  ;
  return;
}

