/* Decompiled C draft; module arm9; ROM address 0202f478. No matching claim. */
#include "types.h"
#include "deps/0202f478_SetSomeDispcntTopMask.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetSomeDispcntTopMask(uint param_1)

{
  _DAT_04000000 = _DAT_04000000 & uRam0202f494 | param_1;
  return;
}

