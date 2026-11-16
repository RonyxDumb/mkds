#pragma once

#include "types.h"

typedef struct RaceProgressKart RaceProgressKart;
typedef struct RankTimeGp RankTimeGp;

void StopRaceInput(void);
// In mode 4 also creates the mission object.
void InitializeGlobalMV(void *heap);
void LoadCurrentCourseRanktime(RankTimeGp *rankTimeGp);
// Updates every kart's progress, the rank order, the first place frames and the pending finishes, and consumes flag 8.
void UpdateRaceProgressKarts(void);
void UpdateRaceProgressKart(Vec3 *position, RaceProgressKart *kart);
void EnterRaceProgressKartCheckpoint(RaceProgressKart *kart, s32 checkpoint);
void SetRaceProgressKartFinishRequest(u32 kartIndex, u32 flag);
void CompleteRaceProgressKartLap(RaceProgressKart *kart);


