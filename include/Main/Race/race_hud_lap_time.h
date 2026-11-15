#pragma once

#include "types.h"
#include "Main/Race/data_021759c0.h" // MinuteSecondMillisecondTime
#include "tp.h"

// Minutes, seconds and milliseconds summed part by part (seconds and milliseconds can pass 59 and 999).
typedef struct MinuteSecondMillisecondTotal {
    /* 00 */ s32 mMinutes;
    /* 04 */ s32 mSeconds;
    /* 08 */ s32 mMilliseconds;
} MinuteSecondMillisecondTotal;

s32 ComputeTimeDifference(MinuteSecondMillisecondTotal *first, MinuteSecondMillisecondTotal *second,
                          MinuteSecondMillisecondTime *difference);
void StartRaceHudLapTimeDisplay(void);

// Largest lap time difference shown: 99 minutes, 59 seconds and 999 milliseconds.
#define RACE_HUD_LAP_TIME_MAX_MINUTE 99
#define RACE_HUD_LAP_TIME_MAX_SECOND 59
#define RACE_HUD_LAP_TIME_MAX_MILLISECOND 999
