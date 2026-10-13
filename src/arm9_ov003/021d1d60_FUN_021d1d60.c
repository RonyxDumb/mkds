/* Decompiled C draft; module arm9_ov003; ROM address 021d1d60. No matching claim. */
#include "types.h"
#include "deps/021d1d60_FUN_021d1d60.h"

void FUN_021d1d60(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_021d1d88();
  iVar3 = 0;
  iVar2 = iVar1;
  if (0 < param_1) {
    do {
      *(int *)(iVar2 + 4) = param_2;
      param_2 = param_2 + param_3;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < param_1);
  }
  *(char *)(iVar1 + 3) = (char)param_1;
  return;
}

