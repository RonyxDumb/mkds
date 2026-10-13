/* Decompiled C draft; module arm9; ROM address 0209a52c. No matching claim. */
#include "types.h"
#include "deps/0209a52c_LoadOlgMush1MapObject.h"

void LoadOlgMush1MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam0209a558);
  *puRam0209a55c = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

