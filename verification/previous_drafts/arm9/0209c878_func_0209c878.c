/* Decompiled C draft; module arm9; ROM address 0209c878. No matching claim. */
#include "types.h"
#include "deps/0209c878_func_0209c878.h"

void func_0209c878(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = CreateMapObjectFromModel_from_thumb(param_1,uRam0209c8a4);
  uVar1 = uRam0209c8ac;
  *puRam0209c8a8 = uVar2;
  StructMapObject_AddAnimationNsbtp_from_thumb(uVar2,uVar1);
  return;
}

