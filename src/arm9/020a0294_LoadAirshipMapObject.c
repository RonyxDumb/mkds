/* Decompiled C draft; module arm9; ROM address 020a0294. No matching claim. */
#include "types.h"
#include "deps/020a0294_LoadAirshipMapObject.h"

void LoadAirshipMapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_from_thumb(param_1,uRam020a02c0);
  *puRam020a02c4 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

