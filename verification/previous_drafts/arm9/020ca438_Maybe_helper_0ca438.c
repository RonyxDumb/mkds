/* Decompiled C draft; module arm9; ROM address 020ca438. No matching claim. */
#include "types.h"
#include "deps/020ca438_Maybe_helper_0ca438.h"

void Maybe_helper_0ca438(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020ca448. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020ca450)(param_1,*(uint *)(uRam020ca44c & 0xfffffffc) >> (uRam020ca44c & 3) * 8 |
                           *(uint *)(uRam020ca44c & 0xfffffffc) << (uRam020ca44c & 3) * -8 + 0x20,0)
  ;
  return;
}

