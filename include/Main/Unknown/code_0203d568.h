#pragma once

#include "types.h"

typedef struct RaceProgressKart RaceProgressKart;
typedef struct RankTimeGp RankTimeGp;

void rstat_finalize(void);
// In mode 4 also creates the mission object.
void rstat_init(void *heap);
void rstat_loadRankTimeGp(RankTimeGp *rankTimeGp);
// Updates every kart's progress, the rank order, the first place frames and the pending finishes, and consumes flag 8.
void rstat_handleCheckPoints(void);
void rstat_updateDriverProgress(Vec3 *position, RaceProgressKart *kart);
void rstat_setCurrentCpoi(RaceProgressKart *kart, s32 checkpoint);
void rstat_203E4C4(u32 kartIndex, u32 b);
void rstat_handleLapChange(RaceProgressKart *kart);
