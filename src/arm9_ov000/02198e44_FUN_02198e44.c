/* Decompiled C draft; module arm9_ov000; ROM address 02198e44. No matching claim. */
#include "types.h"
#include "deps/02198e44_FUN_02198e44.h"

undefined4 FUN_02198e44(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int local_18;
  
  iVar1 = FUN_0219903c(param_1,3,param_4 + 0x27,&local_18);
  if (iVar1 == 0) {
    return 0;
  }
  if (local_18 != 0) {
    return 1;
  }
  FUN_02197d84((int *)(uintptr_t)(param_1 + 0x50),param_2,0x20);
  FUN_02197d84((int *)(uintptr_t)(param_1 + 0x50),param_3,param_4);
  iVar1 = FUN_02198fdc(param_1);
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

