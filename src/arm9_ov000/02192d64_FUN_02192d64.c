/* Decompiled C draft; module arm9_ov000; ROM address 02192d64. No matching claim. */
#include "types.h"
#include "deps/02192d64_FUN_02192d64.h"

undefined4 FUN_02192d64(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (0 < *(int *)(iVar1 + DAT_02192de4)) {
    FUN_02190b80((undefined4)(uintptr_t)(param_1),param_2,DAT_02192de8);
    FUN_02190b58(param_1,param_2,*(undefined4 *)(iVar1 + DAT_02192dec));
    FUN_02190b80((undefined4)(uintptr_t)(param_1),param_2,*(undefined4 *)(iVar1 + DAT_02192df0));
    FUN_02190b80((undefined4)(uintptr_t)(param_1),param_2,DAT_02192df4);
    *(undefined4 *)(iVar1 + DAT_02192de4) = 0;
  }
  if (0 < *(int *)(iVar1 + DAT_02192df8)) {
    FUN_02190b80((undefined4)(uintptr_t)(param_1),param_2,DAT_02192dfc);
    FUN_02190b58(param_1,param_2,*(undefined4 *)(iVar1 + DAT_02192dec));
    FUN_02190b80((undefined4)(uintptr_t)(param_1),param_2,*(undefined4 *)(iVar1 + DAT_02192e00));
    FUN_02190b80((undefined4)(uintptr_t)(param_1),param_2,DAT_02192df4);
    *(undefined4 *)(iVar1 + DAT_02192df8) = 0;
  }
  return 0;
}

