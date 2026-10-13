/* Decompiled C draft; module arm9; ROM address 020998b4. No matching claim. */
#include "types.h"
#include "deps/020998b4_LoadKinoHouse2MapObject.h"

void LoadKinoHouse2MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam020998e0);
  *puRam020998e4 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

