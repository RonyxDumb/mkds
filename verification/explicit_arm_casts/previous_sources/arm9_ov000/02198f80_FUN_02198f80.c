/* Decompiled C draft; module arm9_ov000; ROM address 02198f80. No matching claim. */
#include "types.h"
#include "deps/02198f80_FUN_02198f80.h"

undefined4 FUN_02198f80(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int local_18 [2];
  
  iVar1 = FUN_0219903c(param_1,0,param_3 + 7,local_18);
  if (iVar1 == 0) {
    return 0;
  }
  if (local_18[0] != 0) {
    return 1;
  }
  FUN_02197d84(param_1 + 0x50,param_2,param_3);
  iVar1 = FUN_02198fdc(param_1);
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

