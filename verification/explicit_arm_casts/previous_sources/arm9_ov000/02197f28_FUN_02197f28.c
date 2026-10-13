/* Decompiled C draft; module arm9_ov000; ROM address 02197f28. No matching claim. */
#include "types.h"
#include "deps/02197f28_FUN_02197f28.h"

undefined4
FUN_02197f28(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            int param_6,int param_7,int param_8)

{
  code *pcVar1;
  
  if (param_1 == 0) {
    func_0x0213442c(DAT_02197fdc,DAT_02197fe0,0,DAT_02197fe4);
    return 1;
  }
  if (param_8 == 0) {
    pcVar1 = *(code **)(param_1 + 0x2c);
  }
  else {
    pcVar1 = *(code **)(param_1 + 0x28);
  }
  if (pcVar1 != (code *)0x0) {
    if ((param_7 == 0) || (param_6 == 0)) {
      param_6 = 0;
      param_7 = 0;
    }
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    if (param_2 != 0) {
      *(int *)(param_2 + 0x24) = *(int *)(param_2 + 0x24) + 1;
    }
    (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
    if (param_2 != 0) {
      *(int *)(param_2 + 0x24) = *(int *)(param_2 + 0x24) + -1;
    }
    if ((*(int *)(param_1 + 0x14) != 0) && (*(int *)(param_1 + 0x1c) == 0)) {
      FUN_0219a3f8(param_1);
      return 0;
    }
    return 1;
  }
  return 1;
}

