/* Decompiled C draft; module arm9_ov000; ROM address 02194160. No matching claim. */
#include "types.h"
#include "deps/02194160_FUN_02194160.h"

int FUN_02194160(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (*param_2 == 100) {
    func_0x0213442c(DAT_021941b8,DAT_021941bc,0,DAT_021941c0);
  }
  if (*param_2 != 0x69) {
    if (param_2[1] == 0) {
      iVar1 = FUN_021943f0((int *)(uintptr_t)(param_1),param_2);
    }
    else {
      iVar1 = FUN_02194590((int *)(uintptr_t)(param_1),param_2);
    }
  }
  if ((iVar1 == 0) && (*param_2 == 0x69)) {
    iVar1 = FUN_021941c4((int *)(uintptr_t)(param_1),param_2);
  }
  return iVar1;
}

