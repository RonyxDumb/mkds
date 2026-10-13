/* Decompiled C draft; module arm9; ROM address 0209a34c. No matching claim. */
#include "types.h"
#include "deps/0209a34c_Maybe_get_17b15c.h"

void Maybe_get_17b15c(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0209a358. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0209a360)(param_1,*(uint *)(uRam0209a35c & 0xfffffffc) >> (uRam0209a35c & 3) * 8 |
                           *(uint *)(uRam0209a35c & 0xfffffffc) << (uRam0209a35c & 3) * -8 + 0x20);
  return;
}

