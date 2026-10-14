/* Decompiled C draft; module arm9; ROM address 020997b8. No matching claim. */
#include "types.h"
#include "deps/020997b8_Maybe_get_17b120.h"

void Maybe_get_17b120(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020997c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020997cc)(param_1,*(uint *)(uRam020997c8 & 0xfffffffc) >> (uRam020997c8 & 3) * 8 |
                           *(uint *)(uRam020997c8 & 0xfffffffc) << (uRam020997c8 & 3) * -8 + 0x20);
  return;
}

