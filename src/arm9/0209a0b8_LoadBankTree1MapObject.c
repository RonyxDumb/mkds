/* Decompiled C draft; module arm9; ROM address 0209a0b8. No matching claim. */
#include "types.h"
#include "deps/0209a0b8_LoadBankTree1MapObject.h"

void LoadBankTree1MapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam0209a0e4);
  *puRam0209a0e8 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

