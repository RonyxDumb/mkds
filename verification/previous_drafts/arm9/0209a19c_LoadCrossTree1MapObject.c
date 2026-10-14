/* Decompiled C draft; module arm9; ROM address 0209a19c. No matching claim. */
#include "types.h"
#include "deps/0209a19c_LoadCrossTree1MapObject.h"

void LoadCrossTree1MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam0209a1c8);
  *puRam0209a1cc = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

