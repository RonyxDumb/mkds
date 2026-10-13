/* Decompiled C draft; module arm9_ov000; ROM address 02198148. No matching claim. */
#include "types.h"
#include "deps/02198148_FUN_02198148.h"

undefined4 FUN_02198148(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    func_0x0213442c(DAT_021981c8,DAT_021981cc,0,0xd9);
    return 1;
  }
  if (*(int *)(param_1 + 0x34) != 0) {
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    *(int *)(*(int *)(param_1 + 8) + 0x1c) = *(int *)(*(int *)(param_1 + 8) + 0x1c) + 1;
    (**(code **)(param_1 + 0x34))(param_1,param_2);
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

