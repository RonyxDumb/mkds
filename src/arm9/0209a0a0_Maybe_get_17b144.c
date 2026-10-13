/* Decompiled C draft; module arm9; ROM address 0209a0a0. No matching claim. */
#include "types.h"
#include "deps/0209a0a0_Maybe_get_17b144.h"

void Maybe_get_17b144(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0209a0ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0209a0b4)(param_1,*(uint *)(uRam0209a0b0 & 0xfffffffc) >> (uRam0209a0b0 & 3) * 8 |
                           *(uint *)(uRam0209a0b0 & 0xfffffffc) << (uRam0209a0b0 & 3) * -8 + 0x20);
  return;
}

