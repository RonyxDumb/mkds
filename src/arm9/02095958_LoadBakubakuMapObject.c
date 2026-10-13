/* Decompiled C draft; module arm9; ROM address 02095958. No matching claim. */
#include "types.h"
#include "deps/02095958_LoadBakubakuMapObject.h"

void LoadBakubakuMapObject(undefined4 param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar3 = CreateMapObjectFromModel_from_thumb(param_1,uRam020959ac);
  uVar4 = uRam020959b4;
  *puRam020959b0 = uVar3;
  uVar4 = func_0209bd90(param_1,uVar4);
  puVar2 = puRam020959b0;
  *puRam020959b8 = uVar4;
  uVar1 = (uint)puVar2 & 3;
  uVar5 = *(uint *)((uint)puVar2 & 0xfffffffc);
  StructMapObject_MaybeSetPolygonId(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,0x3f);
  StructMapObject_MaybeSetPolygonId
            (*(uint *)((uint)puRam020959b8 & 0xfffffffc) >> ((uint)puRam020959b8 & 3) * 8 |
             *(uint *)((uint)puRam020959b8 & 0xfffffffc) << ((uint)puRam020959b8 & 3) * -8 + 0x20,
             0x3f);
  return;
}

