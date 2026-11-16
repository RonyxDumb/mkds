#pragma once

#include "types.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void DrawRaceTimeDigits(RaceHudOamBuffer *oamBuffer);
void MaybeWhenFewSecondsRemaining(void);

void ClearRaceTimeDigitsPointer(void);

extern struct RaceTimeDigits *gRaceTimeDigits;
