/* Decompiled C draft; module arm9; ROM address 020997d0. No matching claim. */
#include "types.h"
#include "deps/020997d0_LoadKinoMount1MapObject.h"

void LoadKinoMount1MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam020997fc);
  *puRam02099800 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

