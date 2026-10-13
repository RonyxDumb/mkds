/* Decompiled C draft; module arm9; ROM address 0209a610. No matching claim. */
#include "types.h"
#include "deps/0209a610_LoadOpaTree1MapObject.h"

void LoadOpaTree1MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam0209a63c);
  *puRam0209a640 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

