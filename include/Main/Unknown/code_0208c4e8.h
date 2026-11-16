#pragma once

#include "types.h"

typedef struct KartTurnEffects KartTurnEffects;

// Calls mShowEffects: shows every present effect object of the Kart set again.
void dptc_showAll(KartTurnEffects *p0);
// Calls mHideEffects: hides every present effect object of the Kart set.
void dptc_hideAll(KartTurnEffects *p0);
// Asks dptc_updateContRedSparks to restart the level 4 group: sets mLevel4RestartFrames to 0 and
// mLevel4RestartRequested to 1.
void dptc_208C520(KartTurnEffects *p0);
