/* Decompiled C draft; module arm9; ROM address 02099608. No matching claim. */
#include "types.h"
#include "deps/02099608_LoadOm6Tree1MapObject.h"

void LoadOm6Tree1MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam02099634);
  *puRam02099638 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

