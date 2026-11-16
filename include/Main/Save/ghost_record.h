#pragma once

#include "types.h"
#include "Main/Race/race_setup_block.h" // MinuteSecondMillisecondTime
#include "touch_panel_sampling.h"

typedef struct GhostRecordHead GhostRecordHead;
typedef struct PlayerRecord PlayerRecord;

void FillPlayerRecord(PlayerRecord *record);
s32 GetGhostFinishTimeByIndex(s32 ghostRecordIndex, MinuteSecondMillisecondTime *finishTime);
s32 GetGhostLapTimeByIndex(s32 ghostRecordIndex, s32 lapNumber, MinuteSecondMillisecondTime *lapTime);
BOOL GetGhostFinishTime(GhostRecordHead *ghostRecord, MinuteSecondMillisecondTime *finishTime);
s32 GetGhostLapTime(GhostRecordHead *ghostRecord, s32 lapNumber, MinuteSecondMillisecondTime *lapTime);
void ReadSlotGhostRecord(u32 slotIndex);

typedef struct SlotGhostRecord SlotGhostRecord;

void WriteSlotGhostRecord(u8 index, SlotGhostRecord *source);
