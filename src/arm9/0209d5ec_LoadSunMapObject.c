/* Decompiled C draft; module arm9; ROM address 0209d5ec. No matching claim. */
#include "types.h"
#include "deps/0209d5ec_LoadSunMapObject.h"

void LoadSunMapObject(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = CreateMapObjectFromModel_from_thumb(param_1,uRam0209d63c);
  uVar2 = uRam0209d644;
  *puRam0209d640 = uVar1;
  StructMapObject_AddAnimationNsbca_from_thumb(uVar1,uVar2);
  uVar2 = CreateMapObjectFromModel_from_thumb(param_1,uRam0209d648);
  *puRam0209d64c = uVar2;
  uVar2 = GetIncrementSomeItemCounter();
  StructMapObject_MaybeSetPolygonId
            (*(uint *)((uint)puRam0209d640 & 0xfffffffc) >> ((uint)puRam0209d640 & 3) * 8 |
             *(uint *)((uint)puRam0209d640 & 0xfffffffc) << ((uint)puRam0209d640 & 3) * -8 + 0x20,
             uVar2);
  return;
}

