/* Decompiled C draft; module arm9; ROM address 02012ffc. No matching claim. */
#include "types.h"
#include "deps/02012ffc_ModelBlock_SetSomethingToAllMaterials_MaybeTraslucent.h"

void ModelBlock_SetSomethingToAllMaterials_MaybeTraslucent(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 0x18) != '\0') {
    do {
      ModelBlock_SomeTexPltFn(param_1,uVar1,param_2);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(byte *)(param_1 + 0x18));
    return;
  }
  return;
}

