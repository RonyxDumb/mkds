/* Decompiled C draft; module arm9; ROM address 02143b7c. No matching claim. */
#include "types.h"
#include "deps/02143b7c_func_02143b7c.h"

int func_02143b7c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = func_02142988(1,7);
  if (iVar1 == 0) {
    SetSomeFunctionPtr(9,param_1);
    iVar1 = WM_SomeFn(9,0);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
    return iVar1;
  }
  return iVar1;
}

