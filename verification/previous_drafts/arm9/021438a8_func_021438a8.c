/* Decompiled C draft; module arm9; ROM address 021438a8. No matching claim. */
#include "types.h"
#include "deps/021438a8_func_021438a8.h"

int func_021438a8(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = func_02142988(1,5);
  if (iVar1 == 0) {
    SetSomeFunctionPtr(0xb,param_1);
    iVar1 = WM_SomeFn(0xb,0);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
    return iVar1;
  }
  return iVar1;
}

