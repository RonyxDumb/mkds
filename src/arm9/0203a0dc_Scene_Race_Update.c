/* Decompiled C draft; module arm9; ROM address 0203a0dc. No matching claim. */
#include "types.h"
#include "deps/0203a0dc_Scene_Race_Update.h"

void Scene_Race_Update(int param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = func_02049b6c();
  if (iVar3 != 0) goto LAB_0203a330;
  iVar3 = Struct5624_HasXflag1();
  if (iVar3 != 0) goto LAB_0203a2e4;
  if (param_1 == 0) goto switchD_0203a14c_default;
  iVar3 = GetCurrentRaceMode_1();
  if (iVar3 == 5) {
    iVar3 = func_0205bba8();
  }
  else {
    iVar3 = func_020b2e34();
  }
  if (iVar3 != 0) {
    func_0203a8e0(iVar3);
    func_0203a520(param_1,iVar3);
  }
  uVar4 = GetDisplayMode();
  uVar5 = DAT_0203a394;
  switch(uVar4) {
  case 0:
    break;
  case 1:
    bVar2 = false;
    uVar5 = GetSomeFrameCount_2500();
    if ((uVar5 < param_2) && (iVar3 = func_0210f75c(1), iVar3 != 0)) {
      bVar2 = true;
      SetGlobalP_BFlagBit1(0);
    }
    if (!bVar2) {
      uVar4 = GetMasterInputUnitIndex();
      iVar3 = TestInputKeys(uVar4,DAT_0203a38c);
      if (iVar3 == 0) {
        GetMasterInputUnitIndex();
        iVar3 = HasTouchPressed();
        if (iVar3 != 0) {
          bVar2 = true;
          MaybePlaySseqFromSarc0(5);
          SetGlobalP_BFlagBit1(1);
        }
      }
      else {
        bVar2 = true;
        MaybePlaySseqFromSarc0(5);
        SetGlobalP_BFlagBit1(1);
      }
    }
    if (bVar2) {
      *(undefined2 *)(param_1 + 4) = 0;
    }
    break;
  case 2:
    iVar3 = GetCurrentRaceMode_1();
    if (((iVar3 == 0) || (iVar3 == 1)) && (iVar3 = func_0203c0bc(), iVar3 != 0)) {
      *(undefined2 *)(param_1 + 4) = 2;
    }
    break;
  case 3:
    goto LAB_0203a204;
  case 4:
LAB_0203a204:
    iVar3 = IsRaceIntroInFadeOut();
    if (iVar3 == 0) {
      if (param_2 < 0x5b) break;
      uVar4 = GetMasterInputUnitIndex();
      iVar3 = TestInputKeys(uVar4,DAT_0203a390);
      if (iVar3 == 0) {
        GetMasterInputUnitIndex();
        iVar3 = AnotherHasTouchPressed();
        if (iVar3 == 0) break;
      }
    }
    *(undefined2 *)(param_1 + 4) = 2;
    SetNextRaceDisplayMode(0);
    break;
  case 5:
    iVar3 = func_0203a9ec(param_2);
    if (iVar3 != 0) {
      *(undefined2 *)(param_1 + 4) = 10;
    }
    break;
  case 6:
    iVar3 = GetCurrentInternalCourseId();
    if (iVar3 == 0x36) {
      uVar5 = DAT_0203a398;
    }
    if (uVar5 < param_2) {
      *(undefined2 *)(param_1 + 4) = 0xf;
    }
    else {
      iVar3 = CheckIsEnding(param_2);
      if (iVar3 != 0) {
        func_0x0219e0c4();
        *(undefined2 *)(param_1 + 4) = 0xf;
      }
    }
  }
switchD_0203a14c_default:
  iVar3 = func_0203afe4(param_2);
  if (iVar3 != 0) {
    func_02062464();
  }
  SomeUpdateFn();
LAB_0203a2e4:
  func_020aeb7c();
  uVar4 = GetDisplayMode();
  switch(uVar4) {
  case 0:
    break;
  case 1:
    goto switchD_0203a2f0_default;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  default:
    goto switchD_0203a2f0_default;
  }
  LoopFn_RaceMenuOptions_from_thumb();
switchD_0203a2f0_default:
  iVar3 = IsRaceOptionMenuOn_from_thumb();
  if (iVar3 == 0) {
    Struct5624_SetXflag1(0);
  }
  else {
    Struct5624_SetXflag1(1);
  }
LAB_0203a330:
  uVar6 = *(uint *)(DAT_0203a39c & 0xfffffffc) >> (DAT_0203a39c & 3) * 8 |
          *(uint *)(DAT_0203a39c & 0xfffffffc) << (DAT_0203a39c & 3) * -8 + 0x20;
  uVar5 = uVar6 + 0xc;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) == 6) {
    if (param_2 < DAT_0203a3a0) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
  }
  else {
    bVar2 = true;
  }
  if ((bVar2) &&
     ((uVar6 = uVar6 + 8, uVar5 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
      (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) != 5 ||
      (iVar3 = func_02037a20(), iVar3 == 0)))) {
    RaceRenderingFogRelated();
  }
  func_020ae824();
  LoopFn_RaceMenuOptions2_from_thumb();
  return;
}

