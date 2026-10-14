/* Decompiled C draft; module arm9; ROM address 020cdf34. No matching claim. */
#include "types.h"
#include "deps/020cdf34_Maybe_helper_0cdf34.h"

void Maybe_helper_0cdf34(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020cdf44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020cdf4c)(param_1,*(uint *)(uRam020cdf48 & 0xfffffffc) >> (uRam020cdf48 & 3) * 8 |
                           *(uint *)(uRam020cdf48 & 0xfffffffc) << (uRam020cdf48 & 3) * -8 + 0x20,0)
  ;
  return;
}

