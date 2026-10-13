/* Decompiled C draft; module arm9; ROM address 020578e8. No matching claim. */
#include "types.h"
#include "deps/020578e8_CopyToSXSomePtr0x30_from_thumb.h"

void CopyToSXSomePtr0x30_from_thumb(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020578f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020578f8)(param_1,*(undefined4 *)(*piRam020578f4 + 0x68),0x30);
  return;
}

