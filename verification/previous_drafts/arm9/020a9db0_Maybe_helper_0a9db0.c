/* Decompiled C draft; module arm9; ROM address 020a9db0. No matching claim. */
#include "types.h"
#include "deps/020a9db0_Maybe_helper_0a9db0.h"

void Maybe_helper_0a9db0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModel_2_from_thumb(param_1,uRam020a9ddc);
  *puRam020a9de0 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  return;
}

