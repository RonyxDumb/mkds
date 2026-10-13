/* Decompiled C draft; module arm9_ov000; ROM address 021994c4. No matching claim. */
#include "types.h"
#include "deps/021994c4_FUN_021994c4.h"

undefined4 FUN_021994c4(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_3 + 3;
  iVar1 = param_4 + -3;
  if (param_2 == 100) {
    iVar1 = FUN_021996b8(param_1,iVar2,iVar1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  else if (param_2 == 0x65) {
    iVar1 = FUN_02199614(param_1,iVar2,iVar1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  else if (param_2 == 0x66) {
    iVar1 = thunk_FUN_02198b9c(param_1,param_3,param_4);
    if (iVar1 == 0) {
      return 0;
    }
  }
  else if (param_2 == 0x67) {
    iVar1 = FUN_0219958c(param_1,iVar2,iVar1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  else if ((param_2 == 0x68) && (iVar1 = FUN_02199554(), iVar1 == 0)) {
    return 0;
  }
  return 1;
}

