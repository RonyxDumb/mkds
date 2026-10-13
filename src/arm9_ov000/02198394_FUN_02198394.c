/* Decompiled C draft; module arm9_ov000; ROM address 02198394. No matching claim. */
#include "types.h"
#include "deps/02198394_FUN_02198394.h"

undefined4
FUN_02198394(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7)

{
  if ((param_1 == 0) || (param_2 == 0)) {
    func_0x0213442c(DAT_02198440,DAT_02198444,0,0x3d);
  }
  if ((param_1 == 0) || (param_2 == 0)) {
    return 1;
  }
  if (*(int *)(param_1 + 0x20) == 0) {
    return 1;
  }
  if ((param_7 == 0) || (param_6 == 0)) {
    param_6 = 0;
    param_7 = 0;
  }
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  *(int *)(param_2 + 0x24) = *(int *)(param_2 + 0x24) + 1;
  (**(code **)(param_1 + 0x20))(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
  *(int *)(param_2 + 0x24) = *(int *)(param_2 + 0x24) + -1;
  if ((*(int *)(param_1 + 0x14) != 0) && (*(int *)(param_1 + 0x1c) == 0)) {
    FUN_0219a3f8((undefined4 *)(uintptr_t)(param_1));
    return 0;
  }
  return 1;
}

