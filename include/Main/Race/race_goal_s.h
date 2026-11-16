#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void UpdateRaceGoalSOffset(void);
void SomeAlloc_0(void);

void StructRA_SomeFn_2(RaceHudOamBuffer *oamBuffer);
void DrawRaceGoalSTeamNumber(RaceHudOamBuffer *oamBuffer, s32 number, s32 positionX, s32 positionY);
void DrawRaceGoalSTeamKart(RaceHudOamBuffer *oamBuffer, u32 kartIndex, s32 positionX, s32 positionY);
void StructRA_SomeFn_3(RaceHudOamBuffer *oamBuffer);
void UpdateRaceGoalS(void);
void WriteRaceGoalSRowTiles(s32 row, s32 style);

void ClearRaceGoalSPointer(void);
