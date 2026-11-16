#pragma once

#include "types.h"
#include "Main/Race/race_new_record_ta.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

void UpdateRaceHudSubScreenItemBoxCells(void);
void DrawRaceHudSubScreenItemBoxCells(RaceHudOamBuffer *oamBuffer);
void RefreshRaceNewRecordTaRecordFlags(void);
s32 IsRaceNewRecordTaFinishRecord(void);
BOOL IsRaceNewRecordTaFinishRecordFirst(void);
s32 GetLastTimeTrialWasRecord(void);

extern struct RaceHudSubScreenCells *gRaceHudSubScreenItemBoxCells;
extern s32 gRaceHudSubScreenItemBoxNearOnly;
