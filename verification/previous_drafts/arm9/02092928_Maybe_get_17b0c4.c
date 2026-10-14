/* Decompiled C draft; module arm9; ROM address 02092928. No matching claim. */
#include "types.h"
#include "deps/02092928_Maybe_get_17b0c4.h"

void Maybe_get_17b0c4(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02092934. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0209293c)(param_1,*(uint *)(uRam02092938 & 0xfffffffc) >> (uRam02092938 & 3) * 8 |
                           *(uint *)(uRam02092938 & 0xfffffffc) << (uRam02092938 & 3) * -8 + 0x20);
  return;
}

