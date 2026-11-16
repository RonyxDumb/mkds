#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void UpdateRaceGoalSOffset(void);
void r2dres_init(void);

void r2dres_renderTeamResults(RaceHudOamBuffer *oamBuffer);
void r2dres_renderTeamTotalPoints(RaceHudOamBuffer *oamBuffer, s32 number, s32 x, s32 y);
void r2dres_renderTeamDriverResult(RaceHudOamBuffer *oamBuffer, u32 kartIndex, s32 x, s32 y);
void r2dres_renderResults(RaceHudOamBuffer *oamBuffer);
void r2dres_update(void);
void func_020c3b6c(s32 row, s32 style);
