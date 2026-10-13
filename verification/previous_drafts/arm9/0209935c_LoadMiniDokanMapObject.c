/* Decompiled C draft; module arm9; ROM address 0209935c. No matching claim. */
#include "types.h"
#include "deps/0209935c_LoadMiniDokanMapObject.h"

void LoadMiniDokanMapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam02099388);
  *puRam0209938c = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

