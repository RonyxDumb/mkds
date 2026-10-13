/* Decompiled C draft; module arm9; ROM address 0209f650. No matching claim. */
#include "types.h"
#include "deps/0209f650_LoadChandelierMapObject.h"

void LoadChandelierMapObject(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = CreateMapObjectFromModel_from_thumb(param_1,uRam0209f68c);
  uVar1 = uRam0209f694;
  *puRam0209f690 = uVar2;
  StructMapObject_AddAnimationNsbca_from_thumb(uVar2,uVar1);
  StructMapObject_MaybeSetPolygonId
            (*(uint *)((uint)puRam0209f690 & 0xfffffffc) >> ((uint)puRam0209f690 & 3) * 8 |
             *(uint *)((uint)puRam0209f690 & 0xfffffffc) << ((uint)puRam0209f690 & 3) * -8 + 0x20,
             0x3f);
  return;
}

