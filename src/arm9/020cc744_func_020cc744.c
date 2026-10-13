/* Decompiled C draft; module arm9; ROM address 020cc744. No matching claim. */
#include "types.h"
#include "deps/020cc744_func_020cc744.h"

void func_020cc744(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_10;
  undefined1 local_f [7];
  
  iVar1 = GetB488_SinglePlayerMenuTarget();
  if (iVar1 == 2) {
    iVar1 = GetGlobalCA_from_thumb();
    SetNextCupId(*(undefined4 *)(iVar1 + 0xcc));
    iVar1 = GetGlobalCA_from_thumb();
    SetNextCourse(*(undefined4 *)(iVar1 + 0xd0));
  }
  else {
    iVar1 = GetGlobalCA_from_thumb();
    if (*(int *)(iVar1 + 200) == 0) {
      iVar1 = GetGlobalCA_from_thumb();
      iVar1 = *(int *)(iVar1 + 0xd4);
      if (iVar1 == 0) {
        iVar1 = GetGlobalCA_from_thumb();
        *(undefined4 *)(iVar1 + 0xc0) = 1;
      }
      else if (iVar1 == 1) {
        iVar1 = GetGlobalCA_from_thumb();
        *(undefined4 *)(iVar1 + 0xc0) = 2;
      }
      else if (iVar1 == 2) {
        iVar1 = GetGlobalCA_from_thumb();
        *(undefined4 *)(iVar1 + 0xc0) = 3;
      }
    }
    iVar1 = GetGlobalCA_from_thumb();
    SetNextCpuMode(*(undefined4 *)(iVar1 + 0xc0));
    iVar1 = GetGlobalCA_from_thumb();
    if ((*(int *)(iVar1 + 200) != 2) &&
       (iVar1 = GetGlobalCA_from_thumb(), *(int *)(iVar1 + 200) != 3)) {
      iVar1 = GetGlobalCA_from_thumb();
      *(undefined4 *)(iVar1 + 0xdc) = 0;
    }
    iVar1 = GetGlobalCA_from_thumb();
    switch(*(undefined4 *)(iVar1 + 200)) {
    case 0:
      func_020ccbb8();
      break;
    case 1:
      func_020ccb78();
      break;
    case 2:
    case 3:
    case 4:
      func_020ccab0();
    }
    iVar1 = GetGlobalCA_from_thumb();
    SetNextRaceMode(*(undefined4 *)(iVar1 + 200));
    iVar1 = GetGlobalCA_from_thumb();
    SetNextCupId(*(undefined4 *)(iVar1 + 0xcc));
    iVar1 = GetGlobalCA_from_thumb();
    if (*(int *)(iVar1 + 200) == 0) {
      iVar1 = GetGlobalCA_from_thumb();
      iVar2 = GetGlobalCA_from_thumb();
      uVar3 = func_020ae3a4(*(undefined4 *)(iVar2 + 0xcc),0);
      *(undefined4 *)(iVar1 + 0xd0) = uVar3;
    }
    iVar1 = GetGlobalCA_from_thumb();
    SetNextCourse(*(undefined4 *)(iVar1 + 0xd0));
    iVar1 = GetGlobalCA_from_thumb();
    if (*(int *)(iVar1 + 200) == 1) {
      iVar1 = GetGlobalCA_from_thumb();
      *(undefined4 *)(iVar1 + 0xd4) = 2;
    }
    else {
      iVar1 = GetGlobalCA_from_thumb();
      if (*(int *)(iVar1 + 200) == 2) {
        iVar1 = GetGlobalCA_from_thumb();
        *(undefined4 *)(iVar1 + 0xd4) = 0;
      }
      else {
        iVar1 = GetGlobalCA_from_thumb();
        if (((*(int *)(iVar1 + 200) == 3) && (iVar1 = GetPMaybeState_1(), iVar1 != 0)) &&
           (iVar1 = func_020cae38(), iVar1 != 0)) {
          iVar1 = GetGlobalCA_from_thumb();
          *(undefined4 *)(iVar1 + 0xd4) = 1;
        }
      }
    }
    iVar1 = GetGlobalCA_from_thumb();
    SetNextCcMode(*(undefined4 *)(iVar1 + 0xd4));
    iVar1 = GetGlobalCA_from_thumb();
    SetNextMirrorMode(*(undefined4 *)(iVar1 + 0xd8));
    iVar1 = GetGlobalCA_from_thumb();
    SetNextTimeTrialGhost(*(undefined4 *)(iVar1 + 0xe0));
    iVar1 = GetGlobalCA_from_thumb();
    SetNextBattleMode(*(undefined4 *)(iVar1 + 0xe4));
    iVar1 = GetGlobalCA_from_thumb();
    SetNextTeamMode(*(undefined4 *)(iVar1 + 0xdc));
    iVar1 = GetGlobalCA_from_thumb();
    MaybeSetNextRuleParam(*(undefined2 *)(iVar1 + 0xe8));
    iVar1 = GetGlobalCA_from_thumb();
    SetNextRules(*(undefined4 *)(iVar1 + 0xec));
    iVar1 = GetGlobalCA_from_thumb();
    SetNextCourseMode(*(undefined4 *)(iVar1 + 0xf0));
    iVar1 = GetGlobalCA_from_thumb();
    if ((*(int *)(iVar1 + 200) == 4) && (iVar1 = func_020cbad0(), iVar1 == 0)) {
      iVar1 = GetGlobalCA_from_thumb();
      iVar2 = (uint)*(ushort *)(iVar1 + DAT_020cc990) * 0x2c;
      iVar1 = GetGlobalCA_from_thumb();
      Maybe_missionTable(*(undefined1 *)(*(int *)(iVar1 + 0xf8) + iVar2 + 6),&local_10,local_f);
      iVar1 = GetGlobalCA_from_thumb();
      func_02044380((undefined2 *)(uintptr_t)(*(int *)(iVar1 + 0xf8) + iVar2),local_10,local_f[0]);
    }
  }
  iVar1 = GetGlobalCA_from_thumb();
  if (*(int *)(iVar1 + 200) == 0) {
    func_020cc9a8(0);
  }
  else {
    func_020cc9a8(1);
  }
  iVar1 = func_020cc994();
  if (iVar1 != 0) {
    func_02045ed0();
    SetB488_B2(0);
  }
  return;
}

