/* Decompiled C draft; module arm9; ROM address 02092940. No matching claim. */
#include "types.h"
#include "deps/02092940_LoadBasabasaMapObject.h"

void LoadBasabasaMapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModelAndAnimation_from_thumb(param_1,uRam02092970,uRam02092974);
  *puRam02092978 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

