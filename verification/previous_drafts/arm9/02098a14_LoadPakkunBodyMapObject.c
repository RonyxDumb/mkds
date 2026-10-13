/* Decompiled C draft; module arm9; ROM address 02098a14. No matching claim. */
#include "types.h"
#include "deps/02098a14_LoadPakkunBodyMapObject.h"

void LoadPakkunBodyMapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam02098a50);
  *puRam02098a54 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  StructMapObject_SomeFn_6
            (*(uint *)((uint)puRam02098a54 & 0xfffffffc) >> ((uint)puRam02098a54 & 3) * 8 |
             *(uint *)((uint)puRam02098a54 & 0xfffffffc) << ((uint)puRam02098a54 & 3) * -8 + 0x20,
             0x1f);
  return;
}

