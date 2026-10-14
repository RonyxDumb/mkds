/* Decompiled C draft; module arm9; ROM address 0209989c. No matching claim. */
#include "types.h"
#include "deps/0209989c_Maybe_get_17b128.h"

void Maybe_get_17b128(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020998a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020998b0)(param_1,*(uint *)(uRam020998ac & 0xfffffffc) >> (uRam020998ac & 3) * 8 |
                           *(uint *)(uRam020998ac & 0xfffffffc) << (uRam020998ac & 3) * -8 + 0x20);
  return;
}

