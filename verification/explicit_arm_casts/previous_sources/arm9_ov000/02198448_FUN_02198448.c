/* Decompiled C draft; module arm9_ov000; ROM address 02198448. No matching claim. */
#include "types.h"
#include "deps/02198448_FUN_02198448.h"

undefined4 FUN_02198448(int param_1)

{
  if (param_1 == 0) {
    func_0x0213442c(DAT_021984ac,DAT_021984b0,0,0x1b);
    return 1;
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    (**(code **)(param_1 + 0x24))(param_1);
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
    if ((*(int *)(param_1 + 0x14) != 0) && (*(int *)(param_1 + 0x1c) == 0)) {
      FUN_0219a3f8(param_1);
      return 0;
    }
    return 1;
  }
  return 1;
}

