/* Decompiled C draft; module arm9; ROM address 02056a4c. No matching claim. */
#include "types.h"
#include "deps/02056a4c_SetMissionLevelStageInfo_from_thumb.h"

void SetMissionLevelStageInfo_from_thumb(byte *param_1,char *param_2)

{
  if (*param_2 != '\0') {
    *param_1 = *param_1 & 0xfe | 1;
    *param_1 = *param_1 & 1 | (byte)(((byte)param_2[1] & 0x7f) << 1);
    return;
  }
  *param_1 = *param_1 & 0xfe;
  return;
}

