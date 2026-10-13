/* Decompiled C draft; module arm9_ov000; ROM address 0219e4a0. No matching claim. */
#include "types.h"
#include "deps/0219e4a0_FUN_0219e4a0.h"

int FUN_0219e4a0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      param_3 = -1;
      iVar1 = 0xb;
    }
    else if (param_1 == 2) {
      param_3 = -0x32;
      iVar1 = 6;
    }
    else {
      iVar1 = param_1;
      if (param_1 == 3) {
        param_3 = -0x1e;
        iVar1 = 6;
      }
    }
    FUN_021a1a38(iVar1,param_3 - DAT_0219e4e4);
    return param_1;
  }
  return 0;
}

