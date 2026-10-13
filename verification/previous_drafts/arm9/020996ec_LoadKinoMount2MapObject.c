/* Decompiled C draft; module arm9; ROM address 020996ec. No matching claim. */
#include "types.h"
#include "deps/020996ec_LoadKinoMount2MapObject.h"

void LoadKinoMount2MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam02099718);
  *puRam0209971c = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

