#pragma once

#include "types.h"

// Only meaningful after all laps.
u16 rstat_getDriverBestLapTime(u16 kartIndex, u8 *outMinute, u8 *outSecond, u16 *outMillisecond);
void rstat_getDriverLapTime(s32 kartIndex, u16 lap, u8 *outMinute, u8 *outSecond, u16 *outMillisecond);
void rstat_getDriverTotalTime(s32 kartIndex, u8 *outMinute, u8 *outSecond, u16 *outMillisecond);
// True for status 1, 2 and 3.
s32 rstat_hasDriverFinished(u32 kartIndex);
