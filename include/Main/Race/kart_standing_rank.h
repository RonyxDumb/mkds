#pragma once

#include "types.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Race/race_end_condition.h"
#include "Main/Kart/karts.h"


// Steps the race clock; in MODE_WIFI finishes each kart whose mFinishRequest is set; updates the kart progress; in
// MODE_BATTLE sets the kart statuses and calls FinishRaceProgress when no kart is racing; in MODE_MISSION_RUN calls
// AdvanceMissionRunEnd; sets mRaceDone when the Time Attack kart has ended, otherwise (FinishRaceProgress) once the
// finished count reaches the kart count.
void UpdateRaceProgress(void);
void FinishRaceProgressKartMissionFailed(u16 kartIndex);
// Mission run per-call step of the end of the entry RaceSetup.mEntryIndex (nothing for a negative index): once the kart
// has ended, with RACE_PROGRESS_KART_FLAG_GOAL_WAIT it counts RaceProgress.mFramesSinceFinish and past
// RaceSetup.mFinishWaitFrameCount runs the closing calls (FinishKartAtMissionRunEnd, StartKartRaceEndWrapper,
// RequestRaceEndStemSet, StartRaceEndSeq, FinishStandings in MODE_MISSION_RUN) and clears the flag; with FAILURE_WAIT
// it counts mFramesSinceFailure (only while IsEntryKartNormalOrNotMissionRun) past RACE_FAILURE_WAIT_FRAMES and runs
// the same calls without RequestRaceEndStemSet; before the kart has ended it tests the mission end checks and ends it
// with FinishRaceProgressKartWithEndKind, kind RACE_END_KIND_KART_STATE, RACE_END_KIND_CONTACT or RACE_END_KIND_FAILED.
void AdvanceMissionRunEnd(void);
BOOL ShouldFinishBattle(void);
void UpdateBattleKartStatuses(void);
void FinishRaceProgress(void);

// Counted calls of a mission run failure wait (counted only while the entry kart is normal); the entry kart is ended on
// the call after this many.
#define RACE_FAILURE_WAIT_FRAMES 0x3c
