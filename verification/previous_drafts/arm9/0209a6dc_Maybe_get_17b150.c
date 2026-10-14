/* Decompiled C draft; module arm9; ROM address 0209a6dc. No matching claim. */
#include "types.h"
#include "deps/0209a6dc_Maybe_get_17b150.h"

void Maybe_get_17b150(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0209a6e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0209a6f0)(param_1,*(uint *)(uRam0209a6ec & 0xfffffffc) >> (uRam0209a6ec & 3) * 8 |
                           *(uint *)(uRam0209a6ec & 0xfffffffc) << (uRam0209a6ec & 3) * -8 + 0x20);
  return;
}

