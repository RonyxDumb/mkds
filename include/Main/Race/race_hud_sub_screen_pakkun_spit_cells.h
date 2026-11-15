#pragma once

#include "types.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void DrawRaceHudSubScreenPakkunSpitCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenPakkunSpitCells(void);

void ClearRaceHudSubScreenPakkunSpitCells(void);

extern struct RaceHudSubScreenCells *gRaceHudSubScreenPakkunSpitCells;
