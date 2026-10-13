/* Decompiled C draft; module arm9_ov000; ROM address 021a93e0. No matching claim. */
#include "types.h"
#include "deps/021a93e0_FUN_021a93e0.h"

int FUN_021a93e0(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0xc);
  piVar2 = (int *)(iVar3 + DAT_021a9430);
  iVar1 = *piVar2;
  while( true ) {
    if (iVar1 != 0) {
      piVar2 = (int *)(iVar3 + DAT_021a9438);
      *param_1 = *(int *)(iVar3 + DAT_021a9434) - *piVar2;
      return *(int *)(iVar3 + DAT_021a9430) + *piVar2;
    }
    iVar1 = FUN_021a9d68(param_2);
    if (iVar1 == 9) break;
    iVar1 = *piVar2;
  }
  *param_1 = 0;
  return 0;
}

