/* Decompiled C draft; module arm9; ROM address 0209a280. No matching claim. */
#include "types.h"
#include "deps/0209a280_LoadNsCannon1MapObject.h"

void LoadNsCannon1MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam0209a2ac);
  *puRam0209a2b0 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

