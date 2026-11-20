#pragma once

#include "types.h"

typedef struct RaceProgressKart RaceProgressKart;
typedef struct RankTimeGp RankTimeGp;

void StopRaceInput(void);
// In MODE_MISSION_RUN also calls CreateShapeMapObjectCountList.
void CreateRaceProgress(void *heap);
void SetRankTimeFromRankTimeGp(RankTimeGp *rankTimeGp);
// Updates the progress of each kart that is not removed (none in RACE_KIND_STAFF_ROLL), the rank order and the kart at
// each rank, the first place frames, and finishes karts with RACE_PROGRESS_KART_FLAG_FINISH_PENDING set; clears
// RACE_PROGRESS_KART_FLAG_FINISH_JUST_HAPPENED and, outside MODE_MISSION_RUN, starts the race end for that kart.
void UpdateRaceProgressKarts(void);
void UpdateRaceProgressKart(Vec3 *position, RaceProgressKart *kart);
void EnterRaceProgressKartCheckpoint(RaceProgressKart *kart, s32 checkpoint);
void SetRaceProgressKartFinishRequest(u32 kartIndex, u32 flag);
void CompleteRaceProgressKartLap(RaceProgressKart *kart);


