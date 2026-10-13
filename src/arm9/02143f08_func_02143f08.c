/* Decompiled C draft; module arm9; ROM address 02143f08. No matching claim. */
#include "types.h"
#include "deps/02143f08_func_02143f08.h"

int func_02143f08(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = func_02142988(1,1);
  if (iVar1 == 0) {
    SetSomeFunctionPtr(4,param_1);
    iVar1 = WM_SomeFn(4,0);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
    return iVar1;
  }
  return iVar1;
}

