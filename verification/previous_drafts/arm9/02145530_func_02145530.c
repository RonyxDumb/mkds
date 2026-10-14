/* Decompiled C draft; module arm9; ROM address 02145530. No matching claim. */
#include "types.h"
#include "deps/02145530_func_02145530.h"

int func_02145530(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = func_02142a30();
  if (iVar1 != 0) {
    return iVar1;
  }
  if ((param_2 != 0) && (param_2 != 1)) {
    return 6;
  }
  SetSomeFunctionPtr(0x19,param_1);
  iVar1 = WM_SomeFn(0x19,1,param_2);
  if (iVar1 == 0) {
    iVar1 = 2;
  }
  return iVar1;
}

