/* Decompiled C draft; module arm9_ov000; ROM address 021981d0. No matching claim. */
#include "types.h"
#include "deps/021981d0_FUN_021981d0.h"

undefined4 FUN_021981d0(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    func_0x0213442c(DAT_02198250,DAT_02198254,0,0xba);
    return 1;
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    *(int *)(*(int *)(param_1 + 8) + 0x1c) = *(int *)(*(int *)(param_1 + 8) + 0x1c) + 1;
    (**(code **)(param_1 + 0x30))(param_1,param_2);
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x1c) = *(int *)(*(int *)(param_1 + 8) + 0x1c) + -1;
    if ((*(int *)(*(int *)(param_1 + 8) + 0x14) != 0) &&
       (*(int *)(*(int *)(param_1 + 8) + 0x1c) == 0)) {
      FUN_0219a3f8();
      return 0;
    }
    return 1;
  }
  return 1;
}

