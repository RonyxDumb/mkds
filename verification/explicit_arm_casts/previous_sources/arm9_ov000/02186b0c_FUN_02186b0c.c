/* Decompiled C draft; module arm9_ov000; ROM address 02186b0c. No matching claim. */
#include "types.h"
#include "deps/02186b0c_FUN_02186b0c.h"

undefined4 FUN_02186b0c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar5 = param_1 + DAT_02186bc4;
  uVar6 = DAT_02186bd0;
  if (*(int *)(param_1 + DAT_02186bc8) == 0) {
    uVar6 = DAT_02186bcc;
  }
  *(int *)(param_1 + DAT_02186bc8) = *(int *)(param_1 + DAT_02186bc8) + 1;
  iVar1 = FUN_021882f8(param_3,param_4,0,0);
  iVar2 = func_0x0213a434(uVar6);
  iVar3 = func_0x0213a434(param_2);
  iVar3 = iVar1 + iVar2 + -2 + iVar3;
  iVar2 = *(int *)(iVar5 + 4);
  iVar4 = *(int *)(iVar5 + 8) - iVar2;
  if (iVar4 < iVar3) {
    iVar2 = FUN_02186998(param_1,iVar5,(iVar3 - iVar4) + 1);
    if (iVar2 == 0) {
      return 1;
    }
    iVar2 = *(int *)(iVar5 + 4);
    iVar4 = *(int *)(iVar5 + 8) - iVar2;
  }
  iVar2 = func_0x0200d9e0(iVar2,iVar4,uVar6,param_2);
  *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + iVar2;
  iVar2 = FUN_021882f8(param_3,param_4,*(int *)(iVar5 + 4),
                       (*(int *)(iVar5 + 8) - *(int *)(iVar5 + 4)) + -1);
  if (-1 < iVar2) {
    *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + iVar1;
    **(undefined1 **)(iVar5 + 4) = 0;
    return 0;
  }
  return 1;
}

