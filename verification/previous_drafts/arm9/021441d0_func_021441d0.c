/* Decompiled C draft; module arm9; ROM address 021441d0. No matching claim. */
#include "types.h"
#include "deps/021441d0_func_021441d0.h"

int func_021441d0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  Wm_GetGlobal();
  iVar1 = func_02142988(1,9);
  if (iVar1 == 0) {
    SetSomeFunctionPtr(0x23,param_1);
    iVar1 = WM_SomeFn(0x23,1,param_2);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
    return iVar1;
  }
  return iVar1;
}

