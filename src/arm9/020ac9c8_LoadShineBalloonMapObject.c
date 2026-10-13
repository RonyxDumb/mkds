/* Decompiled C draft; module arm9; ROM address 020ac9c8. No matching claim. */
#include "types.h"
#include "deps/020ac9c8_LoadShineBalloonMapObject.h"

void LoadShineBalloonMapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam020ac9f4);
  *puRam020ac9f8 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

