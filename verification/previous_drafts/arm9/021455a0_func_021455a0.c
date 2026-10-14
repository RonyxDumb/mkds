/* Decompiled C draft; module arm9; ROM address 021455a0. No matching claim. */
#include "types.h"
#include "deps/021455a0_func_021455a0.h"

int func_021455a0(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = func_02142988(2,7,9);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (param_2 != 0) {
    if (param_3 < 0x71) {
      CopyMemory16(param_2,uRam02145664,param_3);
      DC_SomeClean(uRam02145664,param_3);
      SetSomeFunctionPtr(0x18,param_1);
      iVar1 = WM_SomeFn(0x18,5,uRam02145664,param_3);
      if (iVar1 == 0) {
        iVar1 = 2;
      }
      return iVar1;
    }
    return 6;
  }
  return 6;
}

