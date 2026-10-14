/* Decompiled C draft; module arm9; ROM address 0209f2b0. No matching claim. */
#include "types.h"
#include "deps/0209f2b0_LoadRainStarMapObject.h"

void LoadRainStarMapObject(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = CreateMapObjectFromModel_from_thumb(param_1,uRam0209f2ec);
  uVar1 = uRam0209f2f4;
  *puRam0209f2f0 = uVar2;
  StructMapObject_AddAnimationNsbta_from_thumb(uVar2,uVar1);
  StructMapObject_MaybeSetPolygonId
            (*(uint *)((uint)puRam0209f2f0 & 0xfffffffc) >> ((uint)puRam0209f2f0 & 3) * 8 |
             *(uint *)((uint)puRam0209f2f0 & 0xfffffffc) << ((uint)puRam0209f2f0 & 3) * -8 + 0x20,
             0x3f);
  return;
}

