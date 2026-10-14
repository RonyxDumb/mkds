/* Decompiled C draft; module arm9; ROM address 0209179c. No matching claim. */
#include "types.h"
#include "deps/0209179c_LoadSmanTopMapObject.h"

void LoadSmanTopMapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam020917c8);
  *puRam020917cc = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

