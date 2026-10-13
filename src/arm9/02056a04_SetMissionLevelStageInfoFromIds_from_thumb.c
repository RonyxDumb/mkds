/* Decompiled C draft; module arm9; ROM address 02056a04. No matching claim. */
#include "types.h"
#include "deps/02056a04_SetMissionLevelStageInfoFromIds_from_thumb.h"

void SetMissionLevelStageInfoFromIds_from_thumb(int param_1,int param_2,undefined4 param_3)

{
  SetMissionLevelStageInfo_from_thumb
            ((byte *)(uintptr_t)(*(int *)(*piRam02056a28 + 0x10) + param_2 + (param_1 + -1) * 9 + 3),(char *)(uintptr_t)(param_3));
  return;
}

