#pragma once

#include "types.h"
#include "Main/Unknown/unk_021759c0.h" // MinuteSecondMillisecondTime

typedef struct GhostRecordHead GhostRecordHead;
typedef struct PlayerRecord PlayerRecord;

void FillPlayerRecord(PlayerRecord *a);
s32 GetGhostFinishTimeByIndex(s32 ghostRecordIndex, MinuteSecondMillisecondTime *finishTime);
s32 GetGhostLapTimeByIndex(s32 ghostRecordIndex, s32 lapNumber, MinuteSecondMillisecondTime *lapTime);
BOOL GetGhostFinishTime(GhostRecordHead *ghostRecord, MinuteSecondMillisecondTime *finishTime);
s32 GetGhostLapTime(GhostRecordHead *ghostRecord, s32 lapNumber, MinuteSecondMillisecondTime *lapTime);
void ReadSlotGhostRecord(u32 slotIndex);
