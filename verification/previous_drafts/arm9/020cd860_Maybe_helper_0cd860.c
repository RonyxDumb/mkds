/* Decompiled C draft; module arm9; ROM address 020cd860. No matching claim. */
#include "types.h"
#include "deps/020cd860_Maybe_helper_0cd860.h"

void Maybe_helper_0cd860(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020cd870. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020cd878)(param_1,*(uint *)(uRam020cd874 & 0xfffffffc) >> (uRam020cd874 & 3) * 8 |
                           *(uint *)(uRam020cd874 & 0xfffffffc) << (uRam020cd874 & 3) * -8 + 0x20,0)
  ;
  return;
}

