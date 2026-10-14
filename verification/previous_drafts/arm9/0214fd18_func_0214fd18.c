/* Decompiled C draft; module arm9; ROM address 0214fd18. No matching claim. */
#include "types.h"
#include "deps/0214fd18_func_0214fd18.h"

int func_0214fd18(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int aiStack_8 [2];
  
  iVar1 = func_0214fd54(param_1,param_2,uRam0214fd50,(undefined4)(uintptr_t)(aiStack_8));
  if (iVar1 == 0) {
    func_021501c0();
    return aiStack_8[0];
  }
  return iVar1;
}

