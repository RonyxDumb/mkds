/* Decompiled C draft; module arm9; ROM address 02096d68. No matching claim. */
#include "types.h"
#include "deps/02096d68_func_02096d68.h"

void func_02096d68(undefined4 param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar3 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam02096dd4);
  uVar4 = uRam02096ddc;
  *puRam02096dd8 = uVar3;
  uVar3 = CreateMapObjectFromModelAndAnimation_from_thumb(param_1,uVar4,uRam02096de0);
  uVar4 = uRam02096de8;
  *puRam02096de4 = uVar3;
  uVar4 = CreateMapObjectFromModel_2_from_thumb(param_1,uVar4);
  puVar2 = puRam02096de4;
  *puRam02096dec = uVar4;
  uVar1 = (uint)puVar2 & 3;
  uVar5 = *(uint *)((uint)puVar2 & 0xfffffffc);
  StructMapObject_MaybeSetPolygonId(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,0x3f);
  StructMapObject_MaybeSetPolygonId
            (*(uint *)((uint)puRam02096dec & 0xfffffffc) >> ((uint)puRam02096dec & 3) * 8 |
             *(uint *)((uint)puRam02096dec & 0xfffffffc) << ((uint)puRam02096dec & 3) * -8 + 0x20,
             0x3f);
  return;
}

