/* Decompiled C draft; module arm9; ROM address 020cc18c. No matching claim. */
#include "types.h"
#include "deps/020cc18c_SetTopDispcntTileObjMappingRemoveBoundary.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetTopDispcntTileObjMappingRemoveBoundary(uint param_1)

{
  _DAT_04000000 = _DAT_04000000 & uRam020cc1a8 | param_1;
  return;
}

