/* Decompiled C draft; module arm9; ROM address 0209a430. No matching claim. */
#include "types.h"
#include "deps/0209a430_Maybe_get_17b14c.h"

void Maybe_get_17b14c(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0209a43c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0209a444)(param_1,*(uint *)(uRam0209a440 & 0xfffffffc) >> (uRam0209a440 & 3) * 8 |
                           *(uint *)(uRam0209a440 & 0xfffffffc) << (uRam0209a440 & 3) * -8 + 0x20);
  return;
}

