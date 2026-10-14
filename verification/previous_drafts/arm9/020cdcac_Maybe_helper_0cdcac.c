/* Decompiled C draft; module arm9; ROM address 020cdcac. No matching claim. */
#include "types.h"
#include "deps/020cdcac_Maybe_helper_0cdcac.h"

void Maybe_helper_0cdcac(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020cdcbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020cdcc4)(param_1,*(uint *)(uRam020cdcc0 & 0xfffffffc) >> (uRam020cdcc0 & 3) * 8 |
                           *(uint *)(uRam020cdcc0 & 0xfffffffc) << (uRam020cdcc0 & 3) * -8 + 0x20,0)
  ;
  return;
}

