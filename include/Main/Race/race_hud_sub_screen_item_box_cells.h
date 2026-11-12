#pragma once

#include "types.h"
#include "Main/Race/race_new_record_ta.h"
#include "Main/MapObjects/data_0217b000.h"

void UpdateRaceHudSubScreenItemBoxCells(void);
void DrawRaceHudSubScreenItemBoxCells(RaceHudOamBuffer *oamBuffer);
void RefreshRaceNewRecordTaRecordFlags(void);
s32 IsRaceNewRecordTaFinishRecord(void);
BOOL IsRaceNewRecordTaFinishRecordFirst(void);
s32 IsRaceNewRecordTaBestLapRecord(void);

extern struct RaceHudSubScreenCells *gRaceHudSubScreenItemBoxCells;
extern s32 gRaceHudSubScreenItemBoxNearOnly;
