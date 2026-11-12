#pragma once

#include "types.h"
#include "Main/Race/race_new_record_ta.h"

void UpdateRaceHudSubScreenItemBoxCells(void);
void DrawRaceHudSubScreenItemBoxCells(RaceHudOamBuffer *oamBuffer);
void RefreshRaceNewRecordTaRecordFlags(void);
s32 IsRaceNewRecordTaFinishRecord(void);
BOOL IsRaceNewRecordTaFinishRecordFirst(void);
s32 IsRaceNewRecordTaBestLapRecord(void);
