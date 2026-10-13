/* Decompiled C draft; module arm9; ROM address 020995f0. No matching claim. */
#include "types.h"
#include "deps/020995f0_Maybe_get_17b158.h"

void Maybe_get_17b158(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020995fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02099604)(param_1,*(uint *)(uRam02099600 & 0xfffffffc) >> (uRam02099600 & 3) * 8 |
                           *(uint *)(uRam02099600 & 0xfffffffc) << (uRam02099600 & 3) * -8 + 0x20);
  return;
}

