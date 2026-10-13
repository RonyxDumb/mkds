/* Decompiled C draft; module arm9_ov000; ROM address 02198258. No matching claim. */
#include "types.h"
#include "deps/02198258_FUN_02198258.h"

undefined4 FUN_02198258(int param_1,int param_2,int param_3,undefined4 param_4)

{
  if (param_1 == 0) {
    func_0x0213442c(DAT_021982ec,DAT_021982f0,0,0x94);
    return 1;
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    if ((param_3 == 0) || (param_2 == 0)) {
      param_2 = 0;
      param_3 = 0;
    }
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    *(int *)(*(int *)(param_1 + 8) + 0x1c) = *(int *)(*(int *)(param_1 + 8) + 0x1c) + 1;
    (**(code **)(param_1 + 0x2c))(param_1,param_2,param_3,param_4);
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

