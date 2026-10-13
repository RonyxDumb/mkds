/* Decompiled C draft; module arm9; ROM address 020a3eb8. No matching claim. */
#include "types.h"
#include "deps/020a3eb8_LoadBalloonMapObject.h"

void LoadBalloonMapObject(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModelAndAnimation_from_thumb(param_1,uRam020a3f0c,uRam020a3f10);
  *puRam020a3f14 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  StructMapObject_SomeFn_6
            (*(uint *)((uint)puRam020a3f14 & 0xfffffffc) >> ((uint)puRam020a3f14 & 3) * 8 |
             *(uint *)((uint)puRam020a3f14 & 0xfffffffc) << ((uint)puRam020a3f14 & 3) * -8 + 0x20,
             0x1a);
  StructMapObject_SomeFn_7
            (*(uint *)((uint)puRam020a3f14 & 0xfffffffc) >> ((uint)puRam020a3f14 & 3) * 8 |
             *(uint *)((uint)puRam020a3f14 & 0xfffffffc) << ((uint)puRam020a3f14 & 3) * -8 + 0x20,0)
  ;
  *(undefined4 *)(param_1 + 0x1c) = 1;
  return;
}

