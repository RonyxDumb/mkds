/* Decompiled C draft; module arm9; ROM address 02092140. No matching claim. */
#include "types.h"
#include "deps/02092140_func_02092140.h"

void func_02092140(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = CreateMapObjectFromModel_from_thumb(param_1,uRam0209216c);
  uVar1 = uRam02092174;
  *puRam02092170 = uVar2;
  StructMapObject_AddAnimationNsbca_from_thumb(uVar2,uVar1);
  return;
}

