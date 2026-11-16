#pragma once

#include "types.h"

// Only meaningful after all laps.
u16 GetLeastTimeLap(u16 kartIndex, u8 *outMinute, u8 *outSecond, u16 *outMillisecond);
void MaybeGetPlayerLapTime(s32 kartIndex, u16 lap, u8 *outMinute, u8 *outSecond, u16 *outMillisecond);
void GetPlayerTotalTime(s32 kartIndex, u8 *outMinute, u8 *outSecond, u16 *outMillisecond);
// True for status 1, 2 and 3.
s32 IsRacerFinishedRace(u32 kartIndex);
