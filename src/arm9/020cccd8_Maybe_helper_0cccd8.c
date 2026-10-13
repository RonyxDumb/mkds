/* Decompiled C draft; module arm9; ROM address 020cccd8. No matching claim. */
#include "types.h"
#include "deps/020cccd8_Maybe_helper_0cccd8.h"

void Maybe_helper_0cccd8(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020ccce8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020cccf0)(param_1,*(uint *)(uRam020cccec & 0xfffffffc) >> (uRam020cccec & 3) * 8 |
                           *(uint *)(uRam020cccec & 0xfffffffc) << (uRam020cccec & 3) * -8 + 0x20,1)
  ;
  return;
}

