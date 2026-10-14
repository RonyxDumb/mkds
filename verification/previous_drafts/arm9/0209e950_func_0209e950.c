/* Decompiled C draft; module arm9; ROM address 0209e950. No matching claim. */
#include "types.h"
#include "deps/0209e950_func_0209e950.h"

void func_0209e950(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam0209e980);
  *puRam0209e984 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  *(undefined4 *)(param_1 + 0x1c) = 1;
  return;
}

