#pragma once

#include "types.h"

BOOL mgcnt_isDriverShineCountLow(u16 kartIndex);
BOOL mgcnt_isDriverDead(int kartIndex);
void mgcnt_updateDriverBalloonShineInventoryCount(u16 kartIndex, s32 amount);
// TRUE when the kart's mTeamId equals Standings.mWinnerTeamId and mEndTimer is below 0, the end being reached.
BOOL mgcnt_hasDriverWon(s32 kartIndex);
