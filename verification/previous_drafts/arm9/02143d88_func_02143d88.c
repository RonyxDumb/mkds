/* Decompiled C draft; module arm9; ROM address 02143d88. No matching claim. */
#include "types.h"
#include "deps/02143d88_func_02143d88.h"

int func_02143d88(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = func_02142988(1,2);
  if (iVar1 == 0) {
    SetSomeFunctionPtr(2,param_1);
    iVar1 = WM_SomeFn(2,0);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
    return iVar1;
  }
  return iVar1;
}

