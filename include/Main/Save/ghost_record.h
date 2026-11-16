#pragma once

#include "types.h"
#include "Main/Race/race_setup_block.h" // MinuteSecondMillisecondTime
#include "touch_panel_sampling.h"

typedef struct GhostRecordHead GhostRecordHead;
typedef struct PlayerRecord PlayerRecord;

void StructTK_SomeFn_from_thumb(PlayerRecord *record);
s32 GetGhostFinishTimeByIndex(s32 ghostRecordIndex, MinuteSecondMillisecondTime *finishTime);
s32 GetGhostLapTimeByIndex(s32 ghostRecordIndex, s32 lapNumber, MinuteSecondMillisecondTime *lapTime);
BOOL StructNKPG_CopyToTime_from_thumb(GhostRecordHead *ghostRecord, MinuteSecondMillisecondTime *finishTime);
s32 StructNKPG_AnotherCopyToTime_from_thumb(GhostRecordHead *ghostRecord, s32 lapNumber, MinuteSecondMillisecondTime *lapTime);
void ReadSlotGhostRecord(u32 slotIndex);

typedef struct SlotGhostRecord SlotGhostRecord;

void WriteSlotGhostRecord(u8 index, SlotGhostRecord *source);
