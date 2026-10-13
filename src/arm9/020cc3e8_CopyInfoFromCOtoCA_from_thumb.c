/* Decompiled C draft; module arm9; ROM address 020cc3e8. No matching claim. */
#include "types.h"
#include "deps/020cc3e8_CopyInfoFromCOtoCA_from_thumb.h"

void CopyInfoFromCOtoCA_from_thumb(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0;
  do {
    iVar5 = uVar6 * 0x18;
    iVar3 = GetGlobalCA_from_thumb();
    uVar4 = GetRacerCharacterId(uVar6);
    *(undefined4 *)(iVar3 + iVar5) = uVar4;
    iVar3 = GetGlobalCA_from_thumb();
    uVar4 = GetRacerKartId(uVar6);
    *(undefined4 *)(iVar3 + iVar5 + 4) = uVar4;
    iVar3 = GetGlobalCA_from_thumb();
    uVar4 = GetRacerType_0(uVar6);
    *(undefined4 *)(iVar3 + iVar5 + 8) = uVar4;
    iVar3 = GetIsTeams();
    if (iVar3 == 0) {
      iVar3 = GetGlobalCA_from_thumb();
      *(undefined4 *)(iVar3 + iVar5 + 0xc) = 0xffffffff;
    }
    else {
      iVar3 = GetGlobalCA_from_thumb();
      uVar4 = GetRacerTeam(uVar6);
      *(undefined4 *)(iVar3 + iVar5 + 0xc) = uVar4;
    }
    iVar3 = GetGlobalCA_from_thumb();
    uVar4 = Maybe_helper_0cc6a4(uVar6);
    *(undefined4 *)(iVar3 + iVar5 + 0x10) = uVar4;
    iVar3 = GetGlobalCA_from_thumb();
    *(undefined4 *)(iVar3 + iVar5 + 0x14) = 0;
    uVar6 = uVar6 + 1 & 0xffff;
  } while (uVar6 < 8);
  iVar3 = GetGlobalCA_from_thumb();
  uVar4 = GetCurrentCupIndex();
  *(undefined4 *)(iVar3 + 0xcc) = uVar4;
  iVar3 = GetGlobalCA_from_thumb();
  uVar4 = GetCurrentRaceCpuMode();
  *(undefined4 *)(iVar3 + 0xc0) = uVar4;
  iVar3 = GetGlobalCA_from_thumb();
  uVar4 = GetRacerCount();
  *(undefined4 *)(iVar3 + 0xc4) = uVar4;
  iVar3 = GetPMaybeState_1();
  if (iVar3 == 0) {
    iVar3 = GetGlobalCA_from_thumb();
    uVar4 = GetCurrentRaceMode();
    *(undefined4 *)(iVar3 + 200) = uVar4;
  }
  else {
    uVar4 = GetCurrentRaceMode();
    switch(uVar4) {
    case 0:
    case 1:
    case 4:
      iVar3 = GetGlobalCA_from_thumb();
      *(undefined4 *)(iVar3 + 200) = 3;
      break;
    case 2:
    case 3:
    case 5:
      iVar3 = GetGlobalCA_from_thumb();
      *(undefined4 *)(iVar3 + 200) = uVar4;
    }
  }
  iVar3 = func_020cae38();
  if (iVar3 == 0) {
    iVar3 = GetGlobalCA_from_thumb();
    uVar4 = GetCurrentInternalCourseId_1();
    *(undefined4 *)(iVar3 + 0xd0) = uVar4;
  }
  else {
    iVar3 = GetGlobalCA_from_thumb();
    *(undefined4 *)(iVar3 + 0xd0) = 10;
  }
  iVar3 = GetGlobalCA_from_thumb();
  uVar4 = GetCurrrentCcType();
  *(undefined4 *)(iVar3 + 0xd4) = uVar4;
  iVar3 = GetGlobalCA_from_thumb();
  uVar4 = GetIsMirror();
  *(undefined4 *)(iVar3 + 0xd8) = uVar4;
  iVar3 = GetGlobalCA_from_thumb();
  uVar4 = GetIsTeams();
  *(undefined4 *)(iVar3 + 0xdc) = uVar4;
  iVar3 = GetGlobalCA_from_thumb();
  uVar4 = GetCurrentBattleType();
  *(undefined4 *)(iVar3 + 0xe4) = uVar4;
  iVar3 = GetGlobalCA_from_thumb();
  uVar4 = GetCurrentBattleType();
  *(undefined4 *)(iVar3 + 0xe4) = uVar4;
  iVar3 = GetGlobalCA_from_thumb();
  uVar2 = GetMaybeNextRuleParam();
  *(undefined2 *)(iVar3 + 0xe8) = uVar2;
  iVar3 = GetGlobalCA_from_thumb();
  uVar4 = GetCurrentRaceRules();
  *(undefined4 *)(iVar3 + 0xec) = uVar4;
  iVar3 = GetCurrentRaceMode();
  if (iVar3 == 4) {
    iVar3 = GetGlobalCA_from_thumb();
    uVar1 = GetCurrentMissionLevel_1();
    *(undefined1 *)(iVar3 + 0xfc) = uVar1;
    iVar3 = GetGlobalCA_from_thumb();
    uVar1 = GetCurrentMissionStage();
    *(undefined1 *)(iVar3 + 0xfd) = uVar1;
  }
  return;
}

