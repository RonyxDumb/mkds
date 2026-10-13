/* Decompiled C draft; module arm9; ROM address 020ced10. No matching claim. */
#include "types.h"
#include "deps/020ced10_Maybe_helper_0ced10.h"

void Maybe_helper_0ced10(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020ced20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020ced28)(param_1,*(uint *)(uRam020ced24 & 0xfffffffc) >> (uRam020ced24 & 3) * 8 |
                           *(uint *)(uRam020ced24 & 0xfffffffc) << (uRam020ced24 & 3) * -8 + 0x20,0)
  ;
  return;
}

