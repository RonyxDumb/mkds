#pragma once

#include "types.h"
#include "Main/Unknown/code_020f36d8.h"

// Declared here until the code that defines them is decompiled.

// The lap count it compares with is unnamed.
BOOL rstat_isDriverInFinalLap(u16 a);
// Removes kart a from the race: if it had not ended, gives it the lowest rank still in the race, moves the karts ranked
// below it up by one and counts it as removed (RaceProgress.mUnk_000[0].mRemovedCount); sets its status to 4; in Battle
// also calls mgcnt_killDriver; calls func_02069044 for the kart and SetRaceHudKartRemoved(a, 1); then runs
// the end handler of the mode when rstat_shouldTryFinish holds.
void rstat_203C2E4(u16 a);
u16 rstat_getRankPoints(u8 a);
