/* Decompiled C draft; module arm9_ov000; ROM address 021a0c30. No matching claim. */
#include "types.h"
#include "deps/021a0c30_FUN_021a0c30.h"

int FUN_021a0c30(char *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (*param_1 == '\0') {
    uVar2 = FUN_0219a760(*(undefined4 *)(param_1 + 4),0,0);
    FUN_0218b4f8(*(undefined4 *)(*DAT_021a0ca0 + 0xe4),uVar2,*(undefined2 *)(param_1 + 2),
                 *(undefined4 *)(param_1 + 8));
    iVar3 = FUN_0219e594();
    if (iVar3 != 0) {
      return 2;
    }
  }
  uVar2 = DAT_021a0ca4;
  piVar1 = DAT_021a0ca0;
  iVar3 = 0;
  while( true ) {
    uVar4 = FUN_021988d8(**(undefined4 **)(*piVar1 + 4));
    iVar5 = FUN_0219ac7c(uVar4,*(undefined4 *)(param_1 + 8),*param_1,DAT_021a0ca8,uVar2,param_1);
    if (iVar5 == 0) {
      return 0;
    }
    if (iVar5 != 3) break;
    iVar3 = iVar3 + 1;
    if (4 < iVar3) {
      return 3;
    }
  }
  return iVar5;
}

