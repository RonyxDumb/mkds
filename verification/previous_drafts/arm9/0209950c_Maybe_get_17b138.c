/* Decompiled C draft; module arm9; ROM address 0209950c. No matching claim. */
#include "types.h"
#include "deps/0209950c_Maybe_get_17b138.h"

void Maybe_get_17b138(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02099518. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02099520)(param_1,*(uint *)(uRam0209951c & 0xfffffffc) >> (uRam0209951c & 3) * 8 |
                           *(uint *)(uRam0209951c & 0xfffffffc) << (uRam0209951c & 3) * -8 + 0x20);
  return;
}

