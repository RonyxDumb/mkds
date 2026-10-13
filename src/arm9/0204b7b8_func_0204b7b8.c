/* Decompiled C draft; module arm9; ROM address 0204b7b8. No matching claim. */
#include "types.h"
#include "deps/0204b7b8_func_0204b7b8.h"

void func_0204b7b8(code *param_1)

{
  ushort uVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  
  iVar6 = 0;
  bVar2 = true;
  uVar3 = Card_GetResult();
  CleanupUnlockBackup_from_thumb();
  piVar7 = DAT_0204b958;
  *(undefined4 *)(*DAT_0204b958 + 0x10) = 0;
  switch(uVar3) {
  case 0:
    DC_SomeClean(*(undefined4 *)(*piVar7 + 0x28),*(undefined4 *)(*piVar7 + 0x30));
    iVar4 = *DAT_0204b958;
    if (*(int *)(iVar4 + 0x38) == 0) {
      piVar7 = *(int **)(iVar4 + 0x28);
      iVar4 = *(int *)(iVar4 + 0x30);
    }
    else {
      piVar7 = (int *)(*(int *)(iVar4 + 0x28) + 8);
      iVar4 = *(int *)(iVar4 + 0x30) + -8;
      iVar5 = func_0204b960();
      if (iVar5 == 0) {
        iVar6 = 4;
      }
    }
    if (iVar6 == 0) {
      iVar4 = func_0204b084(piVar7,iVar4,*(undefined4 *)(*DAT_0204b958 + 0x34));
      if (iVar4 == 0) {
        iVar6 = 3;
      }
      else {
        iVar4 = func_0204b258(*(undefined4 *)(*DAT_0204b958 + 0x28),
                              *(undefined4 *)(*DAT_0204b958 + 0x30),0);
        if (iVar4 == 0) {
          iVar6 = 3;
        }
        else if ((*(int *)(*DAT_0204b958 + 0x34) != 0) &&
                (*piVar7 != *(int *)(*DAT_0204b958 + 0x34))) {
          iVar6 = 3;
        }
      }
    }
    break;
  case 1:
  case 4:
  case 6:
    iVar6 = 2;
    break;
  default:
    iVar6 = 1;
  }
  piVar7 = DAT_0204b958;
  iVar4 = *DAT_0204b958;
  iVar8 = *(int *)(iVar4 + 0x28);
  uVar1 = *(ushort *)(iVar8 + *(int *)(iVar4 + 0x30) + -4);
  iVar5 = *(int *)(iVar4 + 0x14);
  if (iVar5 != 0) {
    if (iVar5 == 1) {
      if (iVar6 == 2) {
        bVar2 = true;
      }
      else {
        *(int *)(iVar4 + 0x1c) = iVar6;
        *(undefined4 *)(*piVar7 + 0x20) = *(undefined4 *)(*piVar7 + 0x28);
        *(ushort *)(*piVar7 + 0x24) = uVar1;
        iVar4 = *piVar7;
        iVar8 = *(int *)(iVar4 + 0x28) + *(int *)(iVar4 + 0x30);
        func_0204b714(*(undefined4 *)(iVar4 + 0x18),iVar8,*(int *)(iVar4 + 0x30),param_1,2,
                      *(undefined4 *)(iVar4 + 0x34),*(undefined4 *)(iVar4 + 0x38));
        bVar2 = false;
      }
    }
    else if (iVar5 == 2) {
      if (iVar6 == 0) {
        if ((*(int *)(iVar4 + 0x1c) == 0) &&
           (((*(ushort *)(iVar4 + 0x24) == 0 && (uVar1 == DAT_0204b95c)) ||
            ((uint)uVar1 <= (uint)*(ushort *)(iVar4 + 0x24))))) {
          iVar8 = *(int *)(iVar4 + 0x20);
        }
      }
      else {
        iVar5 = *(int *)(iVar4 + 0x1c);
        if (iVar5 == 0) {
          iVar6 = 0;
          iVar8 = *(int *)(iVar4 + 0x20);
        }
        else if ((iVar6 == 2) || (iVar5 == 2)) {
          iVar6 = 2;
        }
        else if ((iVar6 == 1) || (iVar5 == 1)) {
          iVar6 = 1;
        }
        else if ((iVar6 == 4) && (iVar5 == 4)) {
          iVar6 = 4;
        }
        else {
          iVar6 = 3;
        }
      }
    }
  }
  if (bVar2) {
    if (iVar6 == 0) {
      if (param_1 != (code *)0x0) {
        (*param_1)(iVar8,*(undefined4 *)(*DAT_0204b958 + 0x30));
      }
      SX1Zero_from_thumb();
      return;
    }
    if (iVar6 == 2) {
      *(undefined4 *)(*DAT_0204b958 + 0xc) = 0;
    }
    func_0204b344(iVar6);
  }
  return;
}

