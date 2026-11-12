#pragma once

#include "types.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Unknown/code_020f36d8.h"

void StoreRaceProgressKartLapTime(RaceProgressKart *raceProgressKart, s32 pastFinalLap);
void AddLapTimes(const MinuteSecondMillisecondTime *augend, const MinuteSecondMillisecondTime *addend,
                 MinuteSecondMillisecondTime *result);
// d is a sub-frame correction.
void ComputeRaceTime(u8 *minuteOut, u8 *secondOut, u16 *millisecondOut, s32 frameFraction, u32 frames);
s16 FindKartCheckpointBackward(RaceProgressKart *raceProgressKart, s32 *progressOut, Vec3 *pos, u16 routeIndex,
                               u16 checkpointIndex, s32 depth);
s16 FindKartCheckpointForward(RaceProgressKart *raceProgressKart, s32 *progressOut, Vec3 *pos, u16 routeIndex,
                              u16 checkpointIndex, s32 depth);
BOOL TryGetKartCheckpointProgress(RaceProgressKart *raceProgressKart, s32 *progressOut, Vec3 *pos, u16 routeIndex,
                                  u16 checkpointIndex);
s32 ComputeProgressBetweenCheckpoints(const Vec3 *pos, u16 fromIndex, u16 toIndex);
BOOL IsPointBetweenCheckpointLines(const Vec3 *pos, const CourseMapCheckpoint *fromCheckpoint,
                                   const CourseMapCheckpoint *toCheckpoint);
void UpdateRaceClock(void);
