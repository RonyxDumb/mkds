/* Decompiled C draft; module arm9; ROM address 02099b60. No matching claim. */
#include "types.h"
#include "deps/02099b60_LoadOlaTree1cMapObject.h"

void LoadOlaTree1cMapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam02099b8c);
  *puRam02099b90 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

