/* Decompiled C draft; module arm9; ROM address 020ad904. No matching claim. */
#include "types.h"
#include "deps/020ad904_SetDispcntTopDisplayFrameSelect.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetDispcntTopDisplayFrameSelect(uint param_1)

{
  _DAT_04000000 = _DAT_04000000 & uRam020ad920 | param_1;
  return;
}

