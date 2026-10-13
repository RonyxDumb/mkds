/* Decompiled C draft; module arm9; ROM address 020b2f58. No matching claim. */
#include "types.h"
#include "deps/020b2f58_IsCurrentMission_Boss6OrBoss7_from_thumb.h"

undefined4 IsCurrentMission_Boss6OrBoss7_from_thumb(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = GetCurrentMissionLevel_0();
  if (((iVar1 == 6) && (iVar1 = GetCurrentMissionLevelStage_0(), iVar1 == 9)) ||
     ((iVar1 = GetCurrentMissionLevel_0(), iVar1 == 7 &&
      (iVar1 = GetCurrentMissionLevelStage_0(), iVar1 == 9)))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

