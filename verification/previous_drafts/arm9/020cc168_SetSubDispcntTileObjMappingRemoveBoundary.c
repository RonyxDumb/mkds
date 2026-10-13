/* Decompiled C draft; module arm9; ROM address 020cc168. No matching claim. */
#include "types.h"
#include "deps/020cc168_SetSubDispcntTileObjMappingRemoveBoundary.h"

void SetSubDispcntTileObjMappingRemoveBoundary(uint param_1)

{
  *puRam020cc184 =
       (*(uint *)((uint)puRam020cc184 & 0xfffffffc) >> ((uint)puRam020cc184 & 3) * 8 |
       *(uint *)((uint)puRam020cc184 & 0xfffffffc) << ((uint)puRam020cc184 & 3) * -8 + 0x20) &
       uRam020cc188 | param_1;
  return;
}

