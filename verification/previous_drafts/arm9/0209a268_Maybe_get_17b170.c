/* Decompiled C draft; module arm9; ROM address 0209a268. No matching claim. */
#include "types.h"
#include "deps/0209a268_Maybe_get_17b170.h"

void Maybe_get_17b170(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0209a274. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0209a27c)(param_1,*(uint *)(uRam0209a278 & 0xfffffffc) >> (uRam0209a278 & 3) * 8 |
                           *(uint *)(uRam0209a278 & 0xfffffffc) << (uRam0209a278 & 3) * -8 + 0x20);
  return;
}

