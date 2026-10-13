/* Decompiled C draft; module arm9_ov000; ROM address 021a471c. No matching claim. */
#include "types.h"
#include "deps/021a471c_FUN_021a471c.h"

void FUN_021a471c(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar1 = func_0x0213a434(param_2);
  iVar2 = DAT_021a475c - *(int *)(param_1 + DAT_021a475c);
  iVar4 = iVar1 + 1;
  if (iVar2 < iVar1 + 1) {
    iVar4 = iVar2;
  }
  if (iVar4 != 0) {
    func_0x02134eb8(param_1 + *(int *)(param_1 + DAT_021a475c),param_2,iVar4);
    piVar3 = (int *)(param_1 + DAT_021a475c);
    *piVar3 = *piVar3 + iVar4;
    *(undefined1 *)(param_1 + *piVar3 + -1) = 0;
  }
  return;
}

