/* Decompiled C draft; module arm9; ROM address 020a7eb4. No matching claim. */
#include "types.h"
#include "deps/020a7eb4_LoadSanboMapObject.h"

void LoadSanboMapObject(undefined4 param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar3 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam020a7f08);
  uVar4 = uRam020a7f10;
  *puRam020a7f0c = uVar3;
  uVar4 = CreateMapObjectFromModel_2_from_thumb(param_1,uVar4);
  puVar2 = puRam020a7f0c;
  *puRam020a7f14 = uVar4;
  uVar1 = (uint)puVar2 & 3;
  uVar5 = *(uint *)((uint)puVar2 & 0xfffffffc);
  StructMapObject_MaybeSetPolygonId(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,0x3f);
  StructMapObject_MaybeSetPolygonId
            (*(uint *)((uint)puRam020a7f14 & 0xfffffffc) >> ((uint)puRam020a7f14 & 3) * 8 |
             *(uint *)((uint)puRam020a7f14 & 0xfffffffc) << ((uint)puRam020a7f14 & 3) * -8 + 0x20,
             0x3f);
  return;
}

