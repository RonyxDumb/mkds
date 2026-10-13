/* Decompiled C draft; module arm9; ROM address 02099524. No matching claim. */
#include "types.h"
#include "deps/02099524_LoadOf6Tree1MapObject.h"

void LoadOf6Tree1MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam02099550);
  *puRam02099554 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

