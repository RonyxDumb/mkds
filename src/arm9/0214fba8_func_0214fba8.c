/* Decompiled C draft; module arm9; ROM address 0214fba8. No matching claim. */
#include "types.h"
#include "deps/0214fba8_func_0214fba8.h"

int func_0214fba8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int aiStack_8 [2];
  
  iVar1 = func_0214fbe4(param_1,param_2,uRam0214fbe0,(undefined4)(uintptr_t)(aiStack_8));
  if (iVar1 == 0) {
    func_021501c0();
    return aiStack_8[0];
  }
  return iVar1;
}

