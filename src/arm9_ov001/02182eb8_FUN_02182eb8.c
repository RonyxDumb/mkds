/* Decompiled C draft; module arm9_ov001; ROM address 02182eb8. No matching claim. */
#include "types.h"
#include "deps/02182eb8_FUN_02182eb8.h"

void FUN_02182eb8(int param_1,int param_2)

{
  int iVar1;
  
  *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + param_2;
  if (4 < *(int *)(param_1 + 0xa8)) {
    *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + -5;
    *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0xa4) + 1;
    iVar1 = func_0x0209b634(*DAT_02182f18);
    if (iVar1 <= *(int *)(param_1 + 0xa4)) {
      iVar1 = func_0x0209b634(*DAT_02182f18);
      *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0xa4) - iVar1;
    }
  }
  return;
}

