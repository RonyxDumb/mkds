/* Decompiled C draft; module arm9; ROM address 0209196c. No matching claim. */
#include "types.h"
#include "deps/0209196c_LoadCowMapObject.h"

void LoadCowMapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModelAndAnimation_from_thumb(param_1,uRam0209199c,uRam020919a0);
  *puRam020919a4 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

