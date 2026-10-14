/* Decompiled C draft; module arm9; ROM address 02145668. No matching claim. */
#include "types.h"
#include "deps/02145668_func_02145668.h"

int func_02145668(undefined4 param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = func_02142a30();
  if (iVar1 != 0) {
    return iVar1;
  }
  if (param_2 < 4) {
    if (param_2 != 0) {
      if (param_4 == 0) {
        return 6;
      }
      DC_SomeClean(param_4,0x50);
    }
    SetSomeFunctionPtr(0x27,param_1);
    iVar1 = WM_SomeFn(0x27,3,param_2,param_4);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
    return iVar1;
  }
  return 6;
}

