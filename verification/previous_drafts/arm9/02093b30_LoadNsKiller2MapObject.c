/* Decompiled C draft; module arm9; ROM address 02093b30. No matching claim. */
#include "types.h"
#include "deps/02093b30_LoadNsKiller2MapObject.h"

void LoadNsKiller2MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = CreateMapObjectFromModel_from_thumb(param_1,uRam02093b6c);
  uVar2 = uRam02093b74;
  *puRam02093b70 = uVar1;
  uVar2 = func_0209bd90(param_1,uVar2);
  *puRam02093b78 = uVar2;
  StructMapObject_MaybeSetPolygonId(uVar2,0x3f);
  return;
}

