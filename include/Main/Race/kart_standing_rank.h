#pragma once

#include "types.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Race/race_end_condition.h"
#include "Main/Kart/karts.h"


// Steps the clock, sends the net finish requests, handles the mode 2 / 4 end and sets mRaceDone.
void UpdateRaceProgress(void);
void FinishRaceProgressKartMissionFailed(u16 kartIndex);
// Mission run per-call step of the end of the selected entry: after a goal (flag 0x10) or a failure end (flag 0x20) it
// counts RaceProgress.mFramesSinceFinish or mFramesSinceFailure and, past the wait, runs the closing calls
// (FinishKartAtMissionRunEnd, StartKartRaceEndWrapper, FinishStandings) and clears the flag; before the entry has ended
// it tests the mission end checks and ends the entry with FinishRaceProgressKartWithEndKind, kind 2, 3 or 4.
void AdvanceMissionRunEnd(void);
BOOL ShouldFinishBattle(void);
void UpdateBattleKartStatuses(void);
void FinishRaceProgress(void);
