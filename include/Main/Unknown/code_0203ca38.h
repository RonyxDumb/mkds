#pragma once

#include "types.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_0207a7fc.h"

// Declared here until the code that defines them is decompiled.

// Steps the clock, sends the net finish requests, handles the mode 2 / 4 end and sets mRaceDone.
void rstat_update(void);
void rstat_loseMission(u16 kartIndex);
// Mission run per-call step of the end of the selected entry: after a goal (flag 0x10) or a failure end (flag 0x20) it
// counts RaceProgress.mFramesSinceFinish or mFramesSinceFailure and, past the wait, runs the closing calls
// (StructMQRacerEntry_SomeFn_15, StructMQRacerEntry_SomeFn_21_ById, mgcnt_forceEnd) and clears the flag; before the entry has ended it tests the mission
// end checks and ends the entry with rstat_finishMission, kind 2, 3 or 4.
void rstat_handleMissionMode(void);
BOOL rstat_shouldStoreMgResults(void);
void rstat_203D078(void);
void rstat_storeRaceResults(void);
