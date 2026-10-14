/* Decompiled C draft; module arm9; ROM address 02099ef0. No matching claim. */
#include "types.h"
#include "deps/02099ef0_LoadTownTree1MapObject.h"

void LoadTownTree1MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam02099f1c);
  *puRam02099f20 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

