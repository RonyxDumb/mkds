#pragma once

#include "types.h"
#include "Main/Item/item_objects_and_race_progress.h"


// TRUE when the kart has not ended and its mLap equals GetLapCount().
BOOL IsKartOnLastLap(u16 kartIndex);
// Removes the kart from the race: if it had not ended, gives it the lowest rank still in the race, moves the karts
// ranked below its old rank up by one and counts it as removed (RaceProgress.mHeader.mRemovedCount); in MODE_BATTLE
// (ended or not) calls EliminateKartAndCheckWinner; sets its status to RACE_PROGRESS_KART_STATUS_REMOVED; calls
// StartKartRemovalFromProgress for the kart and SetRaceHudKartRemoved(kartIndex, 1); then, when IsRaceEndConditionMet
// holds, runs the end handler of the mode (none in MODE_TIME_ATTACK).
void RemoveRaceProgressKart(u16 kartIndex);
u16 LookupRankPoints(u8 rank);
