/* Decompiled C draft; module arm9; ROM address 02056a2c. No matching claim. */
#include "types.h"
#include "deps/02056a2c_GetMissionLevelStageInfo_from_thumb.h"

void GetMissionLevelStageInfo_from_thumb(byte *param_1,undefined1 *param_2)

{
  if ((*param_1 & 1) != 0) {
    *param_2 = 1;
    param_2[1] = *param_1 >> 1;
    return;
  }
  *param_2 = 0;
  return;
}

