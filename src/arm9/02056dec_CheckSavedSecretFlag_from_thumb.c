/* Decompiled C draft; module arm9; ROM address 02056dec. No matching claim. */
#include "types.h"
#include "deps/02056dec_CheckSavedSecretFlag_from_thumb.h"

void CheckSavedSecretFlag_from_thumb(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02056df6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02056dfc)(param_1,*(int *)*puRam02056df8 + 0x20);
  return;
}

