/* Decompiled C draft; module arm9; ROM address 020130d4. No matching claim. */
#include "types.h"
#include "deps/020130d4_ModelBlock_SetPolygonId.h"

void ModelBlock_SetPolygonId(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 0x18) != '\0') {
    do {
      ModelBlock_SomeTexPltFn_3(param_1,uVar1,param_2);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(byte *)(param_1 + 0x18));
    return;
  }
  return;
}

