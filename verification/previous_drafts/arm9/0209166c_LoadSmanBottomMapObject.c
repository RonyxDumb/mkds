/* Decompiled C draft; module arm9; ROM address 0209166c. No matching claim. */
#include "types.h"
#include "deps/0209166c_LoadSmanBottomMapObject.h"

void LoadSmanBottomMapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam02091698);
  *puRam0209169c = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

