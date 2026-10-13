/* Decompiled C draft; module arm9_ov000; ROM address 0219cc94. No matching claim. */
#include "types.h"
#include "deps/0219cc94_FUN_0219cc94.h"

void FUN_0219cc94(undefined4 param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_38;
  undefined1 auStack_30 [28];
  
  piVar2 = DAT_0219cd70;
  bVar1 = false;
  local_38 = 0;
  iVar5 = *DAT_0219cd70;
  iVar4 = *(int *)(iVar5 + 0x14);
  if (0 < iVar4) {
    iVar6 = 0;
    do {
      iVar4 = func_0x02152a1c(*(int *)(iVar5 + 0x18) + iVar6);
      if (iVar4 == 1) {
        uVar3 = FUN_0219c9c4();
        func_0x02152458(uVar3,*(int *)(*piVar2 + 0x18) + iVar6,auStack_30);
        iVar4 = func_0x0213a074(auStack_30,param_2 + 0x8e);
        if (iVar4 == 0) {
          func_0x02152468(*(int *)(*piVar2 + 0x18) + iVar6,*(undefined4 *)(param_2 + 4));
          func_0x021529bc(*(int *)(*piVar2 + 0x18) + iVar6);
          bVar1 = true;
        }
      }
      else {
        iVar4 = func_0x02152a1c(*(int *)(*piVar2 + 0x18) + iVar6);
        if ((iVar4 == 3) || (iVar4 = func_0x02152a1c(*(int *)(*piVar2 + 0x18) + iVar6), iVar4 == 2))
        {
          iVar5 = *(int *)(param_2 + 4);
          uVar3 = FUN_0219c9c4();
          iVar4 = func_0x02152520(uVar3,*(int *)(*piVar2 + 0x18) + iVar6);
          if (iVar5 == iVar4) {
            func_0x02152468(*(int *)(*piVar2 + 0x18) + iVar6,iVar5);
            func_0x021529bc(*(int *)(*piVar2 + 0x18) + iVar6);
            bVar1 = true;
          }
        }
      }
      iVar6 = iVar6 + 0xc;
      local_38 = local_38 + 1;
      iVar5 = *piVar2;
      iVar4 = *(int *)(iVar5 + 0x14);
    } while (local_38 < iVar4);
  }
  if (bVar1) {
    FUN_0219d14c(*(undefined4 *)(iVar5 + 0x18),iVar4,*(undefined4 *)(param_2 + 4));
    FUN_0219d504();
    *(undefined1 *)(*DAT_0219cd70 + 0x1d) = 1;
  }
  return;
}

