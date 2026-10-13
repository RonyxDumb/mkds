/* Decompiled C draft; module arm9; ROM address 02099440. No matching claim. */
#include "types.h"
#include "deps/02099440_LoadBankEgg1MapObject.h"

void LoadBankEgg1MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam0209946c);
  *puRam02099470 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

