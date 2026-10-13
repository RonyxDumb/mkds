/* Decompiled C draft; module arm9; ROM address 02145708. No matching claim. */
#include "types.h"
#include "deps/02145708_func_02145708.h"

int func_02145708(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = func_02142a30();
  if (iVar1 != 0) {
    return iVar1;
  }
  if (param_2 < 4) {
    if (param_2 != 0) {
      if (param_3 == 0) {
        return 6;
      }
      DC_SomeClean(param_3,0x50);
    }
    SetSomeFunctionPtr(0x14,param_1);
    iVar1 = WM_SomeFn(0x14,2,param_2,param_3);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
    return iVar1;
  }
  return 6;
}

