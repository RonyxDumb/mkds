/* Decompiled C draft; module arm9; ROM address 02143bd4. No matching claim. */
#include "types.h"
#include "deps/02143bd4_func_02143bd4.h"

int func_02143bd4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = func_02142988(1,2);
  if (iVar1 == 0) {
    SetSomeFunctionPtr(8,param_1);
    iVar1 = WM_SomeFn(8,1,param_2);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
    return iVar1;
  }
  return iVar1;
}

