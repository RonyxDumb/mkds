/* Decompiled C draft; module arm9_ov000; ROM address 02199a0c. No matching claim. */
#include "types.h"
#include "deps/02199a0c_FUN_02199a0c.h"

undefined4 FUN_02199a0c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 1;
  if (param_2 == 0) {
    iVar1 = FUN_02199dd0(param_1,param_3,param_4);
    if (iVar1 == 0) {
      return 0;
    }
  }
  else if (param_2 == 1) {
    iVar1 = FUN_02199d4c(param_1,param_3,param_4);
    if (iVar1 == 0) {
      return 0;
    }
  }
  else if (param_2 == 2) {
    iVar1 = FUN_02199c98(param_1,param_3,param_4);
    if (iVar1 == 0) {
      return 0;
    }
  }
  else if (param_2 == 3) {
    iVar1 = FUN_02199bb4((undefined4 *)(uintptr_t)(param_1),param_3,param_4);
    if (iVar1 == 0) {
      return 0;
    }
  }
  else if (param_2 == 4) {
    iVar1 = FUN_02199b70();
    if (iVar1 == 0) {
      return 0;
    }
  }
  else if (param_2 == 5) {
    iVar1 = FUN_02199b14(param_1,param_3,param_4);
    if (iVar1 == 0) {
      return 0;
    }
  }
  else if ((param_2 == 6) && (iVar1 = FUN_02199ad8(), iVar1 == 0)) {
    return 0;
  }
  return 1;
}

