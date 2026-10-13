/* Decompiled C draft; module arm9; ROM address 02099998. No matching claim. */
#include "types.h"
#include "deps/02099998_LoadKinoHouse1MapObject.h"

void LoadKinoHouse1MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam020999c4);
  *puRam020999c8 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

