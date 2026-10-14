/* Decompiled C draft; module arm9; ROM address 020cd710. No matching claim. */
#include "types.h"
#include "deps/020cd710_Maybe_helper_0cd710.h"

void Maybe_helper_0cd710(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020cd720. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020cd728)(param_1,*(uint *)(uRam020cd724 & 0xfffffffc) >> (uRam020cd724 & 3) * 8 |
                           *(uint *)(uRam020cd724 & 0xfffffffc) << (uRam020cd724 & 3) * -8 + 0x20,1)
  ;
  return;
}

