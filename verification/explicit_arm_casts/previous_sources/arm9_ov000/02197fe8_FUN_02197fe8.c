/* Decompiled C draft; module arm9_ov000; ROM address 02197fe8. No matching claim. */
#include "types.h"
#include "deps/02197fe8_FUN_02197fe8.h"

undefined4 FUN_02197fe8(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  
  if (param_1 == 0) {
    func_0x0213442c(DAT_0219808c,DAT_02198090,0,DAT_02198094);
    return 1;
  }
  puVar1 = (undefined4 *)FUN_0218dbf8(*(undefined4 *)(param_1 + 0x9c),param_2);
  if (puVar1 != (undefined4 *)0x0) {
    if ((param_4 == 0) || (param_3 == 0)) {
      param_3 = 0;
      param_4 = 0;
    }
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    *(int *)(*(int *)(param_1 + 8) + 0x1c) = *(int *)(*(int *)(param_1 + 8) + 0x1c) + 1;
    (*(code *)*puVar1)(param_1,param_2,param_3,param_4,param_5);
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

