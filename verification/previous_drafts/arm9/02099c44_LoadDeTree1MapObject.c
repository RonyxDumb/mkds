/* Decompiled C draft; module arm9; ROM address 02099c44. No matching claim. */
#include "types.h"
#include "deps/02099c44_LoadDeTree1MapObject.h"

void LoadDeTree1MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam02099c70);
  *puRam02099c74 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

