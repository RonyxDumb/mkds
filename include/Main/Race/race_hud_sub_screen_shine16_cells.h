#pragma once

#include "types.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void UpdateRaceHudSubScreenShine16Cells(void);
void DrawRaceHudSubScreenShine16Cells(RaceHudOamBuffer *oamBuffer);
s32 CreateRaceHudSubScreenCrabCells(void);

extern struct RaceHudSubScreenCells *gRaceHudSubScreenShine16Cells;
