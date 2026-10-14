/* Decompiled C draft; module arm9; ROM address 02098d04. No matching claim. */
#include "types.h"
#include "deps/02098d04_func_02098d04.h"

void func_02098d04(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = CreateMapObjectFromModel_from_thumb(param_1,uRam02098d40);
  uVar1 = uRam02098d48;
  *puRam02098d44 = uVar2;
  StructMapObject_AddAnimationNsbca_from_thumb(uVar2,uVar1);
  StructMapObject_SomeFn_6
            (*(uint *)((uint)puRam02098d44 & 0xfffffffc) >> ((uint)puRam02098d44 & 3) * 8 |
             *(uint *)((uint)puRam02098d44 & 0xfffffffc) << ((uint)puRam02098d44 & 3) * -8 + 0x20,
             0x1f);
  return;
}

