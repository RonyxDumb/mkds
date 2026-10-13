/* Decompiled C draft; module arm9; ROM address 020adc04. No matching claim. */
#include "types.h"
#include "deps/020adc04_IsCurrentMissionLevelStageBeaten_from_thumb.h"

void IsCurrentMissionLevelStageBeaten_from_thumb(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 auStack_10 [8];
  
  uVar1 = GetCurrentMissionLevel();
  uVar2 = GetCurrentMissionLevelStage();
  IsMissionStageBeaten(uVar1,uVar2,auStack_10);
  return;
}

