/* Decompiled C draft; module arm9; ROM address 02143dd0. No matching claim. */
#include "types.h"
#include "deps/02143dd0_func_02143dd0.h"

int func_02143dd0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = func_02142a30();
  if (iVar1 == 0) {
    SetSomeFunctionPtr(1,param_1);
    iVar1 = WM_SomeFn(1,0);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
    return iVar1;
  }
  return iVar1;
}

