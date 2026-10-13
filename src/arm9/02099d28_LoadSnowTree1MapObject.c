/* Decompiled C draft; module arm9; ROM address 02099d28. No matching claim. */
#include "types.h"
#include "deps/02099d28_LoadSnowTree1MapObject.h"

void LoadSnowTree1MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam02099d54);
  *puRam02099d58 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

