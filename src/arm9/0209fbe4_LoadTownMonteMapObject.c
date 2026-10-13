/* Decompiled C draft; module arm9; ROM address 0209fbe4. No matching claim. */
#include "types.h"
#include "deps/0209fbe4_LoadTownMonteMapObject.h"

void LoadTownMonteMapObject(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = uRam0209fc24;
  uVar2 = uRam0209fc20;
  *(undefined4 *)(param_1 + 0x14) = uRam0209fc1c;
  uVar2 = CreateMapObjectFromModelAndAnimation_from_thumb(param_1,uVar2,uVar1);
  *puRam0209fc28 = uVar2;
  StructMapObject_MaybeSetPolygonId(uVar2,0x3f);
  return;
}

