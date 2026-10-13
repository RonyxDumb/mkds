/* Decompiled C draft; module arm9_ov000; ROM address 02199bb4. No matching claim. */
#include "types.h"
#include "deps/02199bb4_FUN_02199bb4.h"

undefined4 FUN_02199bb4(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_1[3] != 3) {
    iVar1 = FUN_02199fa4();
    if (iVar1 != 0) {
      return 1;
    }
    return 0;
  }
  if (param_3 < 0x20) {
    iVar1 = FUN_02199fa4();
    if (iVar1 != 0) {
      return 1;
    }
    return 0;
  }
  iVar1 = FUN_02197b08(param_2,(int)(uintptr_t)(param_1 + 0x1a));
  if (iVar1 == 0) {
    iVar1 = FUN_02199fa4((undefined4)(uintptr_t)(param_1));
    if (iVar1 != 0) {
      return 1;
    }
    return 0;
  }
  if (*(int *)(param_1[2] + 0x20) != 0) {
    param_1[3] = 4;
    iVar1 = FUN_0218e8c4();
    iVar1 = FUN_02198394(param_1[2],(int)(uintptr_t)(param_1),*param_1,*(undefined2 *)(param_1 + 1),
                         iVar1 - param_1[0x23],param_2 + 0x20,param_3 + -0x20);
    if (iVar1 != 0) {
      return 1;
    }
    return 0;
  }
  iVar1 = FUN_02198b8c(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  FUN_02198514(param_1);
  return 1;
}

