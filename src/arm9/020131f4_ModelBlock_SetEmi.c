/* Decompiled C draft; module arm9; ROM address 020131f4. No matching claim. */
#include "types.h"
#include "deps/020131f4_ModelBlock_SetEmi.h"

void ModelBlock_SetEmi(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 0x18) != '\0') {
    do {
      ModelBlock_SomeTexPltFn_7(param_1,uVar1,param_2);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(byte *)(param_1 + 0x18));
    return;
  }
  return;
}

