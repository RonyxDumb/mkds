/* Decompiled C draft; module arm9_ov000; ROM address 0219cd74. No matching claim. */
#include "types.h"
#include "deps/0219cd74_FUN_0219cd74.h"

void FUN_0219cd74(undefined4 param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_34;
  undefined1 auStack_2c [24];
  
  piVar2 = DAT_0219ce44;
  bVar1 = false;
  local_34 = 0;
  iVar4 = *DAT_0219ce44;
  if (0 < *(int *)(iVar4 + 0x14)) {
    iVar5 = 0;
    do {
      iVar4 = func_0x02152a1c(*(int *)(iVar4 + 0x18) + iVar5);
      if (iVar4 == 1) {
        uVar3 = FUN_0219c9c4();
        func_0x02152458(uVar3,*(int *)(*piVar2 + 0x18) + iVar5,auStack_2c);
        iVar4 = func_0x0213a074(auStack_2c,param_2 + 0x8e);
        if (iVar4 == 0) {
          FUN_0218ee1c(param_1,*(undefined4 *)(param_2 + 4));
          func_0x02152468(*(int *)(*piVar2 + 0x18) + iVar5,*(undefined4 *)(param_2 + 4));
          bVar1 = true;
        }
      }
      else {
        iVar4 = func_0x02152a1c(*(int *)(*piVar2 + 0x18) + iVar5);
        if ((iVar4 == 3) || (iVar4 = func_0x02152a1c(*(int *)(*piVar2 + 0x18) + iVar5), iVar4 == 2))
        {
          iVar6 = *(int *)(param_2 + 4);
          uVar3 = FUN_0219c9c4();
          iVar4 = func_0x02152520(uVar3,*(int *)(*piVar2 + 0x18) + iVar5);
          if (iVar6 == iVar4) {
            FUN_0218ee1c(param_1,iVar6);
            bVar1 = true;
          }
        }
      }
      iVar5 = iVar5 + 0xc;
      local_34 = local_34 + 1;
      iVar4 = *piVar2;
    } while (local_34 < *(int *)(iVar4 + 0x14));
  }
  if (bVar1) {
    FUN_0219d128(*(undefined4 *)(param_2 + 4));
    return;
  }
  FUN_0218ed74(param_1,*(undefined4 *)(param_2 + 4));
  return;
}

