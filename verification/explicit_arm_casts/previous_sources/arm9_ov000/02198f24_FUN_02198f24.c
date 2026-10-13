/* Decompiled C draft; module arm9_ov000; ROM address 02198f24. No matching claim. */
#include "types.h"
#include "deps/02198f24_FUN_02198f24.h"

undefined4 FUN_02198f24(int param_1,undefined4 param_2)

{
  int iVar1;
  int local_10;
  
  iVar1 = FUN_0219903c(param_1,1,0x27,&local_10);
  if (iVar1 == 0) {
    return 0;
  }
  if (local_10 != 0) {
    return 1;
  }
  FUN_02197d84(param_1 + 0x50,param_2,0x20);
  iVar1 = FUN_02198fdc(param_1);
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

