/* Decompiled C draft; module arm9_ov003; ROM address 021ba394. No matching claim. */
#include "types.h"
#include "deps/021ba394_func_ov003_021ba394.h"

undefined4 func_ov003_021ba394(int *param_1)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 local_50;
  undefined4 local_44;
  undefined1 auStack_40 [44];
  
  bVar1 = false;
  local_50 = 0xffffffff;
  bVar2 = true;
  iVar8 = 0;
  iVar7 = 0;
  if (((code *)*DAT_021ba508 == (code *)0x0) || (*DAT_021ba50c == 0)) {
    return 0xffffffff;
  }
  iVar4 = (*(code *)*DAT_021ba508)(DAT_021ba510);
  if (iVar4 == 0) {
    return 0xffffffff;
  }
  iVar5 = FUN_021baaac(0,0,0,DAT_021ba514);
  if (iVar5 != 0) {
    func_0x0200fb08(auStack_40);
    func_0x0200f950(auStack_40,DAT_021ba518,0,DAT_021ba51c,0x13);
    do {
      func_0x0200ea3c(DAT_021ba520,&local_44,1);
      switch(local_44) {
      default:
        goto switchD_021ba420_caseD_0;
      case 4:
      case 8:
      case 0x12:
        break;
      case 5:
        if (!bVar1) {
          if (iVar7 < 8) {
            iVar7 = iVar7 + 1;
          }
          else {
            iVar8 = FUN_021babc0(iVar4,0x40);
            iVar5 = FUN_021baa68();
            if (iVar5 == 0) goto switchD_021ba420_caseD_0;
            bVar1 = true;
          }
        }
        break;
      case 10:
        bVar2 = false;
        local_50 = 0;
        break;
      case 0x13:
        if (!bVar1) {
          if (iVar7 != 0) {
            iVar8 = FUN_021babc0(iVar4,0x40);
          }
          iVar5 = FUN_021baa68();
          if (iVar5 == 0) goto switchD_021ba420_caseD_0;
          bVar1 = true;
        }
      }
    } while (bVar2);
    if (iVar8 == 0) {
      piVar6 = (int *)(*(code *)*DAT_021ba508)(0x58);
    }
    else {
      piVar6 = (int *)(*(code *)*DAT_021ba508)((iVar8 + -1) * 0x54 + 0x58);
    }
    if (piVar6 != (int *)0x0) {
      *param_1 = (int)piVar6;
      *piVar6 = iVar8;
      iVar7 = 0;
      if (0 < iVar8) {
        piVar6 = piVar6 + 1;
        iVar5 = iVar4;
        do {
          FUN_021ba778(iVar5,piVar6);
          iVar5 = iVar5 + 0xc0;
          piVar6 = piVar6 + 0x15;
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar8);
      }
    }
switchD_021ba420_caseD_0:
    func_0x0200f8b8(auStack_40);
    uVar3 = DAT_021ba520;
    do {
      iVar8 = func_0x0200ea3c(uVar3,&local_44,0);
    } while (iVar8 == 1);
  }
  (*(code *)*DAT_021ba50c)(iVar4);
  return local_50;
}

