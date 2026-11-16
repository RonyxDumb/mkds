#pragma once

#include "types.h"

// The kart's place, 1 for first. In mode 5 reads the net table.
u32 rstat_getPlace(u32 kartIndex);
// The time jitters while the clock runs.
void rstat_getLapTime(u8 *outMinute, u8 *outSecond, u16 *outMillisecond);
void rstat_initInputRecorders(void);
