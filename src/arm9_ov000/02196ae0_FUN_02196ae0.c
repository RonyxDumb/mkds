/* Decompiled C draft; module arm9_ov000; ROM address 02196ae0. No matching claim. */
#include "types.h"
#include "deps/02196ae0_FUN_02196ae0.h"

void FUN_02196ae0(int param_1,int param_2)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + param_2) = 0;
  iVar1 = func_0x0213a038(param_1,DAT_02196b80,8);
  if (iVar1 == 0) {
    FUN_02196d0c(param_1,param_2);
    return;
  }
  iVar1 = func_0x0213a038(param_1,DAT_02196b84,9);
  if (iVar1 == 0) {
    FUN_02196ca4(param_1,param_2);
    return;
  }
  iVar1 = func_0x0213a038(param_1,DAT_02196b84,9);
  if (iVar1 == 0) {
    FUN_02196ca4(param_1,param_2);
    return;
  }
  iVar1 = func_0x0213a038(param_1,DAT_02196b88,8);
  if (iVar1 == 0) {
    FUN_02196c00(param_1,param_2);
    return;
  }
  iVar1 = func_0x0213a038(param_1,DAT_02196b8c,8);
  if (iVar1 == 0) {
    FUN_02196b90(param_1,param_2);
  }
  return;
}

