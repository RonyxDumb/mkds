/* Decompiled C draft; module arm9; ROM address 020cd30c. No matching claim. */
#include "types.h"
#include "deps/020cd30c_Maybe_helper_0cd30c.h"

void Maybe_helper_0cd30c(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020cd31c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020cd324)(param_1,*(uint *)(uRam020cd320 & 0xfffffffc) >> (uRam020cd320 & 3) * 8 |
                           *(uint *)(uRam020cd320 & 0xfffffffc) << (uRam020cd320 & 3) * -8 + 0x20,0)
  ;
  return;
}

