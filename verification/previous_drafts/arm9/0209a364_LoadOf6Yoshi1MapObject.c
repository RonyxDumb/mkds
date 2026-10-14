/* Decompiled C draft; module arm9; ROM address 0209a364. No matching claim. */
#include "types.h"
#include "deps/0209a364_LoadOf6Yoshi1MapObject.h"

void LoadOf6Yoshi1MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam0209a390);
  *puRam0209a394 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

