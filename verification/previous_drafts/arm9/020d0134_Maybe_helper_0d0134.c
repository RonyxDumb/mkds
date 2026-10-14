/* Decompiled C draft; module arm9; ROM address 020d0134. No matching claim. */
#include "types.h"
#include "deps/020d0134_Maybe_helper_0d0134.h"

void Maybe_helper_0d0134(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020d0144. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020d014c)(param_1,*(uint *)(uRam020d0148 & 0xfffffffc) >> (uRam020d0148 & 3) * 8 |
                           *(uint *)(uRam020d0148 & 0xfffffffc) << (uRam020d0148 & 3) * -8 + 0x20,1)
  ;
  return;
}

