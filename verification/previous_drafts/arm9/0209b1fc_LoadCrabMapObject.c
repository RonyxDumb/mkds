/* Decompiled C draft; module arm9; ROM address 0209b1fc. No matching claim. */
#include "types.h"
#include "deps/0209b1fc_LoadCrabMapObject.h"

void LoadCrabMapObject(undefined4 param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar3 = CreateMapObjectFromModelAndAnimation_from_thumb(param_1,uRam0209b258,uRam0209b25c);
  uVar4 = uRam0209b264;
  *puRam0209b260 = uVar3;
  uVar4 = CreateMapObjectFromModelAndAnimation_from_thumb(param_1,uVar4,uRam0209b268);
  puVar2 = puRam0209b260;
  *puRam0209b26c = uVar4;
  uVar1 = (uint)puVar2 & 3;
  uVar5 = *(uint *)((uint)puVar2 & 0xfffffffc);
  StructMapObject_MaybeSetPolygonId(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,0x3f);
  StructMapObject_MaybeSetPolygonId
            (*(uint *)((uint)puRam0209b26c & 0xfffffffc) >> ((uint)puRam0209b26c & 3) * 8 |
             *(uint *)((uint)puRam0209b26c & 0xfffffffc) << ((uint)puRam0209b26c & 3) * -8 + 0x20,
             0x3f);
  return;
}

