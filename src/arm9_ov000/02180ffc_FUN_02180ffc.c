/* Decompiled C draft; module arm9_ov000; ROM address 02180ffc. No matching claim. */
#include "types.h"
#include "deps/02180ffc_FUN_02180ffc.h"

void FUN_02180ffc(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined2 local_10 [2];
  
  iVar2 = func_0x02125f54();
  if (iVar2 != 0) {
    func_0x02125fc0();
    return;
  }
  iVar2 = func_0x02125f88();
  piVar1 = DAT_021810d0;
  if (iVar2 != 0) {
    local_10[0] = *DAT_021810cc;
    local_10[1] = DAT_021810cc[1];
    iVar2 = *DAT_021810d0;
    iVar5 = *(int *)(iVar2 + 0x10);
    if (iVar5 < 0) {
      *(int *)(iVar2 + 0x10) = iVar5 + 1;
      iVar2 = *piVar1;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x38),local_10[*(int *)(iVar2 + 0x10)]);
      uVar4 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x3c),6);
      func_0x02126570(uVar3,uVar4);
      return;
    }
    if (iVar5 == 0) {
      *(undefined4 *)(iVar2 + 0x10) = 1;
      iVar2 = *piVar1;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x38),local_10[*(int *)(iVar2 + 0x10)]);
      uVar4 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x3c),4);
      func_0x02126570(uVar3,uVar4);
      return;
    }
    if (*(char *)(*DAT_021810d4 + 0x28) == '\0') {
      if (*(int *)(*DAT_021810d8 + 0xc) == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(*DAT_021810d8 + 0x10);
      }
    }
    else {
      iVar5 = 1;
    }
    if (iVar5 == 0) {
      *(undefined4 *)(iVar2 + 0xc) = 2;
      func_ov000_021806e0(*(undefined4 *)(*DAT_021810d0 + 0xc));
    }
  }
  return;
}

