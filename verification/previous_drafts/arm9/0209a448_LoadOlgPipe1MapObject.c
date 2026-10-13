/* Decompiled C draft; module arm9; ROM address 0209a448. No matching claim. */
#include "types.h"
#include "deps/0209a448_LoadOlgPipe1MapObject.h"

void LoadOlgPipe1MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam0209a474);
  *puRam0209a478 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

