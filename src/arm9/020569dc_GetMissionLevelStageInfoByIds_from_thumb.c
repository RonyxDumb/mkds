/* Decompiled C draft; module arm9; ROM address 020569dc. No matching claim. */
#include "types.h"
#include "deps/020569dc_GetMissionLevelStageInfoByIds_from_thumb.h"

undefined4 GetMissionLevelStageInfoByIds_from_thumb(int param_1,int param_2,undefined4 param_3)

{
  GetMissionLevelStageInfo_from_thumb
            ((byte *)(uintptr_t)(*(int *)(*piRam02056a00 + 0x10) + param_2 + (param_1 + -1) * 9 + 3),(undefined1 *)(uintptr_t)(param_3));
  return 1;
}

