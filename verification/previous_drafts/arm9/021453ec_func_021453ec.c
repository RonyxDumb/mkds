/* Decompiled C draft; module arm9; ROM address 021453ec. No matching claim. */
#include "types.h"
#include "deps/021453ec_func_021453ec.h"

int func_021453ec(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = func_02142988(2,7,9);
  if (iVar1 == 0) {
    SetSomeFunctionPtr(0x21,param_1);
    iVar1 = WM_SomeFn(0x21,1,param_2);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
    return iVar1;
  }
  return iVar1;
}

