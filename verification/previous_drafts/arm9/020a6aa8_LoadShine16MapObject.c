/* Decompiled C draft; module arm9; ROM address 020a6aa8. No matching claim. */
#include "types.h"
#include "deps/020a6aa8_LoadShine16MapObject.h"

void LoadShine16MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModelAndAnimation_from_thumb(param_1,uRam020a6ad8,uRam020a6adc);
  *puRam020a6ae0 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

