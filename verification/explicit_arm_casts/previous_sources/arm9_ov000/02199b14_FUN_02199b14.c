/* Decompiled C draft; module arm9_ov000; ROM address 02199b14. No matching claim. */
#include "types.h"
#include "deps/02199b14_FUN_02199b14.h"

undefined4 FUN_02199b14(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) != 1) {
    iVar1 = FUN_02199fa4();
    if (iVar1 != 0) {
      return 1;
    }
    return 0;
  }
  FUN_02198514();
  iVar1 = FUN_02198b8c(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = FUN_021982f4(param_1,2,param_2,param_3);
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

