/* Decompiled C draft; module arm9; ROM address 020ae770. No matching claim. */
#include "types.h"
#include "deps/020ae770_func_020ae770.h"

void func_020ae770(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  for (iVar4 = 0; iVar4 < param_3 + -1; iVar4 = iVar4 + 1) {
    piVar2 = (int *)(param_1 + iVar4 * 4);
    for (iVar3 = param_3 + -1; iVar4 < iVar3; iVar3 = iVar3 + -1) {
      iVar1 = *(int *)(param_1 + iVar3 * 4);
      iVar5 = *piVar2;
      if (*(int *)(param_2 + iVar1 * 4) < *(int *)(param_2 + iVar5 * 4)) {
        *piVar2 = iVar1;
        *(int *)(param_1 + iVar3 * 4) = iVar5;
      }
    }
  }
  return;
}

