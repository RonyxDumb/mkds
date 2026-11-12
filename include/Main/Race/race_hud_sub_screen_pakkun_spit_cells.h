#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217b000.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void DrawRaceHudSubScreenPakkunSpitCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenPakkunSpitCells(void);

void ClearRaceHudSubScreenPakkunSpitCells(void);

extern struct RaceHudSubScreenCells *gRaceHudSubScreenPakkunSpitCells;
