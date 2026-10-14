/* Decompiled C draft; module arm9; ROM address 021454c4. No matching claim. */
#include "types.h"
#include "deps/021454c4_func_021454c4.h"

int func_021454c4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = func_02142a30();
  if (iVar1 == 0) {
    SetSomeFunctionPtr(0x1d,param_1);
    iVar1 = WM_SomeFn(0x1d,4,param_2,param_3);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
    return iVar1;
  }
  return iVar1;
}

