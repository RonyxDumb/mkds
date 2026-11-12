#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void DrawRaceHudSubScreenCoinCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenCoinCells(void);
void ClearRaceHudSubScreenCoinCells(void);
s32 CreateRaceHudSubScreenCoinCells(void);
s32 GetMissionRunMapObjectAlphaLimit(void);
