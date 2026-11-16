#pragma once

#include "types.h"
#include "Main/Race/race_start_sequence_work.h"

void MaybeClearGlobalB358(void);
void IncreaseB358Countdown(void);
void UpdateRaceStartSequenceSounds(void);
s32 GetRaceStartCountdown(void);
s32 IsRaceCountdownEnded(void);

void ResetGlobalB358(void);

void InitializeGlobalB358(void);

extern struct RaceStartSequence *g_GlobalB358;
