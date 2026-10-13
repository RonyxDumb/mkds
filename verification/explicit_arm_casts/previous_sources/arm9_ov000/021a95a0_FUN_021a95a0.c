/* Decompiled C draft; module arm9_ov000; ROM address 021a95a0. No matching claim. */
#include "types.h"
#include "deps/021a95a0_FUN_021a95a0.h"

undefined4 FUN_021a95a0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_021a9d68();
  if (iVar1 != 1) {
    return 1;
  }
  iVar1 = FUN_021a9aa0(param_1);
  if (iVar1 == 0) {
    iVar1 = FUN_021a9d68(param_1);
    if (iVar1 != 5) {
      return 1;
    }
    iVar1 = FUN_021a9610(param_1);
    if (iVar1 != 0) {
      return 1;
    }
    FUN_021a998c(param_1);
  }
  else {
    FUN_021aa5e0(*(undefined4 *)(param_1 + 0xc));
    FUN_021a998c(param_1);
    iVar1 = FUN_021a9610(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

