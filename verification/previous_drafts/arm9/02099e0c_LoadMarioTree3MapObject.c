/* Decompiled C draft; module arm9; ROM address 02099e0c. No matching claim. */
#include "types.h"
#include "deps/02099e0c_LoadMarioTree3MapObject.h"

void LoadMarioTree3MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam02099e38);
  *puRam02099e3c = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

