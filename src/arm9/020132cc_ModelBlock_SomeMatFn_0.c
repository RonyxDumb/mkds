/* Decompiled C draft; module arm9; ROM address 020132cc. No matching claim. */
#include "types.h"
#include "deps/020132cc_ModelBlock_SomeMatFn_0.h"

void ModelBlock_SomeMatFn_0(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 0x18) != '\0') {
    do {
      ModelBlock_SomeTexPltFn_4(param_1,uVar1,param_2);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(byte *)(param_1 + 0x18));
    return;
  }
  return;
}

