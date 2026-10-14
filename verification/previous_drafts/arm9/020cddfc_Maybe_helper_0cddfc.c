/* Decompiled C draft; module arm9; ROM address 020cddfc. No matching claim. */
#include "types.h"
#include "deps/020cddfc_Maybe_helper_0cddfc.h"

void Maybe_helper_0cddfc(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020cde0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020cde14)(param_1,*(uint *)(uRam020cde10 & 0xfffffffc) >> (uRam020cde10 & 3) * 8 |
                           *(uint *)(uRam020cde10 & 0xfffffffc) << (uRam020cde10 & 3) * -8 + 0x20,0)
  ;
  return;
}

