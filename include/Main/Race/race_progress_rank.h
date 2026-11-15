#pragma once

#include "types.h"
#include "Main/Item/item_objects_and_race_progress.h"


// The lap count it compares with is unnamed.
BOOL IsKartOnLastLap(u16 kartIndex);
// Removes kart a from the race: if it had not ended, gives it the lowest rank still in the race, moves the karts ranked
// below it up by one and counts it as removed (RaceProgress.mHeader.mRemovedCount); sets its status to 4; in Battle
// also calls EliminateKartAndCheckWinner; calls StartKartRemovalFromProgress for the kart and SetRaceHudKartRemoved(a,
// 1); then runs the end handler of the mode when IsRaceEndConditionMet holds.
void RemoveRaceProgressKart(u16 kartIndex);
u16 LookupRankPoints(u8 rank);
