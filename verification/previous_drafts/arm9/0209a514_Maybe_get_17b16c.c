/* Decompiled C draft; module arm9; ROM address 0209a514. No matching claim. */
#include "types.h"
#include "deps/0209a514_Maybe_get_17b16c.h"

void Maybe_get_17b16c(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0209a520. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0209a528)(param_1,*(uint *)(uRam0209a524 & 0xfffffffc) >> (uRam0209a524 & 3) * 8 |
                           *(uint *)(uRam0209a524 & 0xfffffffc) << (uRam0209a524 & 3) * -8 + 0x20);
  return;
}

