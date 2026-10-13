/* Decompiled C draft; module arm9_ov000; ROM address 02196714. No matching claim. */
#include "types.h"
#include "deps/02196714_FUN_02196714.h"

undefined4 FUN_02196714(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int local_18;
  int local_14 [2];
  
  local_18 = 0;
  local_14[0] = 0;
  iVar1 = FUN_0218e68c(param_2,0,&local_18,local_14);
  if (iVar1 == -1) {
    FUN_0219690c(param_1,DAT_021967a4);
    FUN_021965a0((int *)(uintptr_t)(param_1),5,DAT_021967a8);
    FUN_02190f4c((int *)(uintptr_t)(param_1),3,1);
    return 3;
  }
  if (0 < iVar1) {
    if (local_14[0] != 0) {
      FUN_0219690c(param_1,DAT_021967ac);
      *param_3 = 4;
      return 0;
    }
    if (local_18 != 0) {
      FUN_0219690c(param_1,DAT_021967b0);
      *param_3 = 3;
      return 0;
    }
  }
  *param_3 = 0;
  return 0;
}

