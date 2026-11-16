#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void r2d_renderMissionValueAndTarget(RaceHudOamBuffer *oamBuffer);
void r2d_20B9DFC(RaceHudOamBuffer *oamBuffer);
void UpdateRaceModeCount(void);
void InitRaceModeCount(void);
BOOL IsRaceKeyRecordingNotFull(void);
void r2d_renderItemSpinner(RaceHudOamBuffer *oamBuffer);
void r2d_updateItemSpinner(void);
u32 r2d_finalizeItemSpinner(void);
