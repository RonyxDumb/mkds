/* Decompiled C draft; module arm9; ROM address 02099a7c. No matching claim. */
#include "types.h"
#include "deps/02099a7c_LoadOsaTree1cMapObject.h"

void LoadOsaTree1cMapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam02099aa8);
  *puRam02099aac = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

