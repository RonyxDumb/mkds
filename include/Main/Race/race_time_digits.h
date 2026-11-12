#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217b000.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void DrawRaceTimeDigits(RaceHudOamBuffer *oamBuffer);
void UpdateRaceTimeDigits(void);

void ClearRaceTimeDigitsPointer(void);

extern struct RaceTimeDigits *gRaceTimeDigits;
