/* Decompiled C draft; module arm9; ROM address 020303e8. No matching claim. */
#include "types.h"
#include "deps/020303e8_func_020303e8.h"

undefined4 func_020303e8(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 local_1c;
  
  local_1c = 0xffffffff;
  uVar2 = GetDirectInputUnitIndex();
  piVar1 = DAT_02030628;
  iVar6 = *DAT_02030628;
  switch(*(undefined4 *)(iVar6 + 0x30)) {
  case 0:
    *(int *)(iVar6 + 0x34) = *(int *)(iVar6 + 0x34) + 1;
    iVar5 = *(int *)(*piVar1 + 0x34);
    if (iVar5 < 10) {
      uVar2 = ComputeValueInterpolation_from_thumb(1,0xffffff40,0,iVar5,10);
      *(undefined4 *)(*DAT_02030628 + 0x38) = uVar2;
    }
    else {
      *(undefined4 *)(*piVar1 + 0x34) = 0;
      *(undefined4 *)(*piVar1 + 0x38) = 0;
      *(undefined4 *)(*piVar1 + 0x30) = 1;
    }
    func_020309d8();
    break;
  case 1:
    iVar8 = 0;
    iVar7 = -1;
    iVar5 = func_02030708();
    if (iVar5 != 0) {
      uVar3 = func_020306e0(uVar2);
      uVar4 = func_020306b8(uVar2);
      iVar8 = func_02128210(uVar3,uVar4);
      iVar7 = func_020291c4(uVar3,uVar4,*(undefined4 *)(iVar6 + 0x10));
    }
    iVar5 = func_02030688(uVar2,1);
    if (iVar5 == 0) {
      iVar5 = func_02030688(uVar2,2);
      piVar1 = DAT_02030628;
      if ((iVar5 == 0) && (iVar8 == 0)) {
        iVar5 = func_02030688(uVar2,0x40);
        if (iVar5 != 0) {
          iVar5 = *(int *)(*DAT_02030628 + 0x28);
          if (0 < iVar5) {
            *(int *)(*DAT_02030628 + 0x28) = iVar5 + -1;
            func_02030954(1);
            func_0203062c(0);
            break;
          }
        }
        iVar5 = func_02030688(uVar2,0x80);
        piVar1 = DAT_02030628;
        if (iVar5 != 0) {
          iVar5 = *(int *)(*DAT_02030628 + 0x28);
          if (iVar5 < 1) {
            *(int *)(*DAT_02030628 + 0x28) = iVar5 + 1;
            func_02030954(1);
            func_0203062c(0);
            break;
          }
        }
        if (iVar7 == 0) {
          *(undefined4 *)(*DAT_02030628 + 0x30) = 2;
          func_02030954(*(int *)(*piVar1 + 0x28) != 0);
          func_02030654(4);
          *(undefined4 *)(*DAT_02030628 + 0x28) = 0;
          StructP_SetAFlag4_SkipBattleIntro();
          *(undefined4 *)(*DAT_02030628 + 0x2c) = 2;
        }
        else if (iVar7 == 1) {
          *(undefined4 *)(*DAT_02030628 + 0x30) = 2;
          func_02030954(*(int *)(*piVar1 + 0x28) != 1);
          func_02030654(4);
          *(undefined4 *)(*DAT_02030628 + 0x28) = 1;
          StructP_SetAFlag4_SkipBattleIntro();
          *(undefined4 *)(*DAT_02030628 + 0x2c) = 2;
        }
      }
      else {
        *(undefined4 *)(*DAT_02030628 + 0x2c) = 0;
        *(undefined4 *)(*piVar1 + 0x30) = 3;
        func_02128310();
      }
    }
    else {
      StructP_SetAFlag4_SkipBattleIntro(*(int *)(*DAT_02030628 + 0x28) == 1);
      piVar1 = DAT_02030628;
      *(undefined4 *)(*DAT_02030628 + 0x2c) = 2;
      *(undefined4 *)(*piVar1 + 0x30) = 2;
      func_02030954(0);
      func_02030654(4);
    }
    break;
  case 2:
    *(int *)(iVar6 + 0x34) = *(int *)(iVar6 + 0x34) + 1;
    if (4 < *(int *)(*piVar1 + 0x34)) {
      *(undefined4 *)(*piVar1 + 0x34) = 0;
      *(undefined4 *)(*piVar1 + 0x30) = 3;
      func_02030954(1);
    }
    break;
  case 3:
    *(int *)(iVar6 + 0x34) = *(int *)(iVar6 + 0x34) + 1;
    iVar5 = *(int *)(*piVar1 + 0x34);
    if (iVar5 < 10) {
      uVar2 = ComputeValueInterpolation_from_thumb(1,0,0xffffff40,iVar5,10);
      *(undefined4 *)(*DAT_02030628 + 0x38) = uVar2;
    }
    else {
      *(undefined4 *)(*piVar1 + 0x38) = 0;
      *(undefined4 *)(*piVar1 + 0x30) = 4;
    }
    func_020309d8();
    break;
  case 4:
    local_1c = *(undefined4 *)(iVar6 + 0x2c);
  }
  if (*(int *)(*DAT_02030628 + 0x30) != 4) {
    func_02124c30(*(undefined4 *)(iVar6 + 0xc),*(undefined4 *)(iVar6 + 8),
                  *(undefined4 *)(iVar6 + 0x14),*(undefined4 *)(*DAT_02030628 + 0x20),
                  *(undefined4 *)(iVar6 + 0x18));
  }
  return local_1c;
}

