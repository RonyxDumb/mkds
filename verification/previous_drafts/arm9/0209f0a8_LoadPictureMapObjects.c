/* Decompiled C draft; module arm9; ROM address 0209f0a8. No matching claim. */
#include "types.h"
#include "deps/0209f0a8_LoadPictureMapObjects.h"

void LoadPictureMapObjects(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = CreateMapObjectFromModel_from_thumb(param_1,uRam0209f10c);
  uVar1 = uRam0209f114;
  *puRam0209f110 = uVar2;
  StructMapObject_AddAnimationNsbca_from_thumb(uVar2,uVar1);
  uVar2 = CreateMapObjectFromModel_from_thumb(param_1,uRam0209f118);
  uVar1 = uRam0209f120;
  *puRam0209f11c = uVar2;
  StructMapObject_AddAnimationNsbca_from_thumb(uVar2,uVar1);
  StructMapObject_MaybeSetPolygonId
            (*(uint *)((uint)puRam0209f110 & 0xfffffffc) >> ((uint)puRam0209f110 & 3) * 8 |
             *(uint *)((uint)puRam0209f110 & 0xfffffffc) << ((uint)puRam0209f110 & 3) * -8 + 0x20,
             0x3f);
  StructMapObject_MaybeSetPolygonId
            (*(uint *)((uint)puRam0209f11c & 0xfffffffc) >> ((uint)puRam0209f11c & 3) * 8 |
             *(uint *)((uint)puRam0209f11c & 0xfffffffc) << ((uint)puRam0209f11c & 3) * -8 + 0x20,
             0x3f);
  return;
}

