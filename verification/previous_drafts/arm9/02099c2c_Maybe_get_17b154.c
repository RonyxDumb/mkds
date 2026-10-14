/* Decompiled C draft; module arm9; ROM address 02099c2c. No matching claim. */
#include "types.h"
#include "deps/02099c2c_Maybe_get_17b154.h"

void Maybe_get_17b154(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02099c38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02099c40)(param_1,*(uint *)(uRam02099c3c & 0xfffffffc) >> (uRam02099c3c & 3) * 8 |
                           *(uint *)(uRam02099c3c & 0xfffffffc) << (uRam02099c3c & 3) * -8 + 0x20);
  return;
}

