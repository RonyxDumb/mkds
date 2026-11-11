#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void UpdateRaceGoalSOffset(void);
void InitRaceGoalS(void);

void DrawRaceGoalSTeams(RaceHudOamBuffer *oamBuffer);
void DrawRaceGoalSTeamNumber(RaceHudOamBuffer *oamBuffer, s32 number, s32 positionX, s32 positionY);
void DrawRaceGoalSTeamKart(RaceHudOamBuffer *oamBuffer, u32 kartIndex, s32 positionX, s32 positionY);
void DrawRaceGoalSKarts(RaceHudOamBuffer *oamBuffer);
void UpdateRaceGoalS(void);
void WriteRaceGoalSRowTiles(s32 row, s32 style);
