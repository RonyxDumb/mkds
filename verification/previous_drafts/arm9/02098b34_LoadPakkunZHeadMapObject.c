/* Decompiled C draft; module arm9; ROM address 02098b34. No matching claim. */
#include "types.h"
#include "deps/02098b34_LoadPakkunZHeadMapObject.h"

void LoadPakkunZHeadMapObject(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam02098b60);
  *puRam02098b64 = uVar1;
  StructMapObject_SomeFn_6(uVar1,0x1e);
  return;
}

