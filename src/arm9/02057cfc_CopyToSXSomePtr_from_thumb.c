/* Decompiled C draft; module arm9; ROM address 02057cfc. No matching claim. */
#include "types.h"
#include "deps/02057cfc_CopyToSXSomePtr_from_thumb.h"

void CopyToSXSomePtr_from_thumb(undefined4 param_1,undefined4 param_2)

{
                    /* WARNING: Could not recover jumptable at 0x02057d06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02057d0c)(param_1,*(undefined4 *)(*piRam02057d08 + 0x68),param_2);
  return;
}

