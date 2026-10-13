/* Decompiled C draft; module arm9; ROM address 02091784. No matching claim. */
#include "types.h"
#include "deps/02091784_Maybe_get_17b0b8.h"

void Maybe_get_17b0b8(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02091790. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02091798)(param_1,*(uint *)(uRam02091794 & 0xfffffffc) >> (uRam02091794 & 3) * 8 |
                           *(uint *)(uRam02091794 & 0xfffffffc) << (uRam02091794 & 3) * -8 + 0x20);
  return;
}

