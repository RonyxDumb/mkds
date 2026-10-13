/* Decompiled C draft; module arm9_ov000; ROM address 02199fb0. No matching claim. */
#include "types.h"
#include "deps/02199fb0_FUN_02199fb0.h"

undefined4 FUN_02199fb0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 < 5) {
    if (*(int *)(param_1 + 0x10) == 0) {
      if (iVar1 == 4) {
        *(undefined4 *)(param_1 + 0x14) = 1;
      }
      FUN_02198514(param_1);
    }
    else {
      FUN_02198514();
      iVar1 = FUN_021982f4(param_1,param_2,0,0);
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  else if (iVar1 != 7) {
    FUN_02198514();
    iVar1 = FUN_021981d0(param_1,param_3);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}

