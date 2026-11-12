#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217b000.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void UpdateRaceHudSubScreenShine16Cells(void);
void DrawRaceHudSubScreenShine16Cells(RaceHudOamBuffer *oamBuffer);
s32 CreateRaceHudSubScreenCrabCells(void);

extern struct RaceHudSubScreenCells *gRaceHudSubScreenShine16Cells;
