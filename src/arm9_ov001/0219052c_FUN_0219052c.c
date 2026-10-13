/* Decompiled C draft; module arm9_ov001; ROM address 0219052c. No matching claim. */
#include "types.h"
#include "deps/0219052c_FUN_0219052c.h"

/* WARNING: Removing unreachable block (ram,0x02190546) */
/* WARNING: Removing unreachable block (ram,0x0219056a) */

undefined4 FUN_0219052c(int param_1)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(*DAT_021905e4 + 8) == 4) {
    uVar1 = FUN_02181b54();
    iVar3 = FUN_02181b68(uVar1);
  }
  else {
    iVar3 = 0;
  }
  if (*(int *)(*DAT_021905e4 + 8) == 4) {
    sVar2 = FUN_02181b54();
    iVar4 = FUN_02181b68(sVar2 + 1);
  }
  else {
    iVar4 = 0;
  }
  FUN_02192694();
  FUN_021924cc();
  iVar5 = FUN_021881a8(param_1,param_1 + DAT_021905e8,0,
                       *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021905ec));
  if (((iVar5 != 0) &&
      (iVar3 = FUN_021881a8(iVar3,iVar3 + DAT_021905f0,
                            *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021905f4),0), iVar3 != 0)
      ) && (iVar3 = FUN_021881a8(iVar4,iVar4 + DAT_021905f0,
                                 *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021905f4),0),
           iVar3 != 0)) {
    FUN_021905f8(param_1);
  }
  return 0;
}

