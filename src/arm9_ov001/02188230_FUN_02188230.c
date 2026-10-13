/* Decompiled C draft; module arm9_ov001; ROM address 02188230. No matching claim. */
#include "types.h"
#include "deps/02188230_FUN_02188230.h"

undefined4 FUN_02188230(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + -1;
  iVar1 = -**(int **)(param_1 + 0xa0);
  iVar2 = *(int *)(param_1 + 0xac);
  if (iVar2 == iVar1 || iVar2 + **(int **)(param_1 + 0xa0) < 0 != SBORROW4(iVar2,iVar1)) {
    *(int *)(param_1 + 0xac) = iVar1;
    return 1;
  }
  return 0;
}

