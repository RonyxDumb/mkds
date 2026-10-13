/* Decompiled C draft; module arm9_ov000; ROM address 02186d04. No matching claim. */
#include "types.h"
#include "deps/02186d04_FUN_02186d04.h"

void FUN_02186d04(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xc) == 0) {
      FUN_02186a10(param_1,param_1 + DAT_02186d60);
    }
    FUN_02186a10(param_1,param_1 + DAT_02186d64);
    if (*(int *)(param_1 + DAT_02186d68) != 0) {
      (**(code **)(param_1 + 0x18))(DAT_02186d6c,*(int *)(param_1 + DAT_02186d68),0);
      *(undefined4 *)(param_1 + DAT_02186d68) = 0;
    }
    if (*(int *)(param_1 + DAT_02186d70) != 0) {
      (**(code **)(param_1 + 0x18))(DAT_02186d74,*(int *)(param_1 + DAT_02186d70),0);
      *(undefined4 *)(param_1 + DAT_02186d70) = 0;
    }
    func_0x0214d168(param_1,0,DAT_02186d78);
  }
  return;
}

