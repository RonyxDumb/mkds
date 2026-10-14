/* Decompiled C draft; module arm9; ROM address 02099fd4. No matching claim. */
#include "types.h"
#include "deps/02099fd4_LoadGardenTree1MapObject.h"

void LoadGardenTree1MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam0209a000);
  *puRam0209a004 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

