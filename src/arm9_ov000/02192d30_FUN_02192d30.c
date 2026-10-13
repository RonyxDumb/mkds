/* Decompiled C draft; module arm9_ov000; ROM address 02192d30. No matching claim. */
#include "types.h"
#include "deps/02192d30_FUN_02192d30.h"

int FUN_02192d30(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar2 + DAT_02192d60,param_2);
  if ((iVar1 == 0) && (iVar1 = FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar2 + DAT_02192d60,param_3), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}

