/* Decompiled C draft; module arm9_ov000; ROM address 021982f4. No matching claim. */
#include "types.h"
#include "deps/021982f4_FUN_021982f4.h"

undefined4 FUN_021982f4(int param_1,undefined4 param_2,int param_3,int param_4)

{
  if (param_1 == 0) {
    func_0x0213442c(DAT_0219838c,DAT_02198390,0,0x69);
    return 1;
  }
  *(undefined4 *)(param_1 + 0x18) = param_2;
  if (*(int *)(param_1 + 0x28) != 0) {
    if ((param_4 == 0) || (param_3 == 0)) {
      param_3 = 0;
      param_4 = 0;
    }
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    *(int *)(*(int *)(param_1 + 8) + 0x1c) = *(int *)(*(int *)(param_1 + 8) + 0x1c) + 1;
    (**(code **)(param_1 + 0x28))(param_1,param_2,param_3,param_4);
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

