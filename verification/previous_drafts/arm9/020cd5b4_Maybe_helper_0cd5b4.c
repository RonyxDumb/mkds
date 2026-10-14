/* Decompiled C draft; module arm9; ROM address 020cd5b4. No matching claim. */
#include "types.h"
#include "deps/020cd5b4_Maybe_helper_0cd5b4.h"

void Maybe_helper_0cd5b4(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020cd5c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020cd5cc)(param_1,*(uint *)(uRam020cd5c8 & 0xfffffffc) >> (uRam020cd5c8 & 3) * 8 |
                           *(uint *)(uRam020cd5c8 & 0xfffffffc) << (uRam020cd5c8 & 3) * -8 + 0x20,0)
  ;
  return;
}

