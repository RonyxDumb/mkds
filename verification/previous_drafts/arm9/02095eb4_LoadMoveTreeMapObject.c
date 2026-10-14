/* Decompiled C draft; module arm9; ROM address 02095eb4. No matching claim. */
#include "types.h"
#include "deps/02095eb4_LoadMoveTreeMapObject.h"

void LoadMoveTreeMapObject(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = CreateMapObjectFromModel_from_thumb(param_1,uRam02095ef0);
  uVar1 = uRam02095ef8;
  *puRam02095ef4 = uVar2;
  StructMapObject_AddAnimationNsbca_from_thumb(uVar2,uVar1);
  StructMapObject_MaybeSetPolygonId
            (*(uint *)((uint)puRam02095ef4 & 0xfffffffc) >> ((uint)puRam02095ef4 & 3) * 8 |
             *(uint *)((uint)puRam02095ef4 & 0xfffffffc) << ((uint)puRam02095ef4 & 3) * -8 + 0x20,
             0x3f);
  return;
}

