/* Decompiled C draft; module arm9; ROM address 0209a184. No matching claim. */
#include "types.h"
#include "deps/0209a184_Maybe_get_17b11c.h"

void Maybe_get_17b11c(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0209a190. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0209a198)(param_1,*(uint *)(uRam0209a194 & 0xfffffffc) >> (uRam0209a194 & 3) * 8 |
                           *(uint *)(uRam0209a194 & 0xfffffffc) << (uRam0209a194 & 3) * -8 + 0x20);
  return;
}

