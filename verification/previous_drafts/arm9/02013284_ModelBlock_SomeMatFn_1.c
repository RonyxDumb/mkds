/* Decompiled C draft; module arm9; ROM address 02013284. No matching claim. */
#include "types.h"
#include "deps/02013284_ModelBlock_SomeMatFn_1.h"

void ModelBlock_SomeMatFn_1(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 0x18) != '\0') {
    do {
      ModelBlock_SomeTexPltFn_5(param_1,uVar1,param_2);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(byte *)(param_1 + 0x18));
    return;
  }
  return;
}

