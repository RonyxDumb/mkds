/* Decompiled C draft; module arm9; ROM address 020adb34. No matching claim. */
#include "types.h"
#include "deps/020adb34_MaybeAllMissionStagesBeatenWithStarRank_from_thumb.h"

undefined4 MaybeAllMissionStagesBeatenWithStarRank_from_thumb(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_18;
  
  iVar1 = GetCurrentMissionLevel();
  if ((((iVar1 < 1) || (iVar1 = GetCurrentMissionLevel(), 6 < iVar1)) ||
      (iVar1 = GetCurrentMissionLevelStage(), iVar1 < 1)) ||
     (iVar1 = GetCurrentMissionLevelStage(), 9 < iVar1)) {
    uVar2 = 0;
  }
  else {
    for (iVar1 = 1; iVar1 < 7; iVar1 = iVar1 + 1) {
      for (iVar5 = 1; iVar5 < 10; iVar5 = iVar5 + 1) {
        iVar3 = IsMissionStageBeaten(iVar1,iVar5,&local_18);
        iVar4 = GetCurrentMissionLevel();
        if ((iVar1 == iVar4) && (iVar4 = GetCurrentMissionLevelStage(), iVar5 == iVar4)) {
          if ((iVar3 != 0) && (local_18 - 5U < 3)) {
            return 0;
          }
        }
        else {
          if (iVar3 == 0) {
            return 0;
          }
          if (((local_18 != 5) && (local_18 != 6)) && (local_18 != 7)) {
            return 0;
          }
        }
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}

