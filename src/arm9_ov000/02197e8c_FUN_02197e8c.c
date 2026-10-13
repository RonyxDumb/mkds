/* Decompiled C draft; module arm9_ov000; ROM address 02197e8c. No matching claim. */
#include "types.h"
#include "deps/02197e8c_FUN_02197e8c.h"

undefined4
FUN_02197e8c(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            undefined4 *param_6)

{
  undefined4 uVar1;
  
  *param_6 = 0;
  if (param_1 == 0) {
    func_0x0213442c(DAT_02197f1c,DAT_02197f20,0,DAT_02197f24);
    return 1;
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    if ((param_5 == 0) || (param_4 == 0)) {
      param_4 = 0;
      param_5 = 0;
    }
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    uVar1 = (**(code **)(param_1 + 0x30))(param_1,param_2,param_3,param_4,param_5);
    *param_6 = uVar1;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
    if ((*(int *)(param_1 + 0x14) != 0) && (*(int *)(param_1 + 0x1c) == 0)) {
      FUN_0219a3f8((undefined4 *)(uintptr_t)(param_1));
      return 0;
    }
    return 1;
  }
  return 1;
}

