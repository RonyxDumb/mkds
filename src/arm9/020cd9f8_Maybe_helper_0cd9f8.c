/* Decompiled C draft; module arm9; ROM address 020cd9f8. No matching claim. */
#include "types.h"
#include "deps/020cd9f8_Maybe_helper_0cd9f8.h"

void Maybe_helper_0cd9f8(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020cda08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020cda10)(param_1,*(uint *)(uRam020cda0c & 0xfffffffc) >> (uRam020cda0c & 3) * 8 |
                           *(uint *)(uRam020cda0c & 0xfffffffc) << (uRam020cda0c & 3) * -8 + 0x20,0)
  ;
  return;
}

