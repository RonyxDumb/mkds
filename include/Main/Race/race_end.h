#pragma once

#include "types.h"
#include "Main/Race/race_end_work.h"

void UpdateRaceEnd(void);

void ResetRaceEndFrames(void);
void ClearRaceEndPointer(void);

void SetKartCupRanks(void);
void SetCupWinningTeamFromRecords(void);
void InitRaceEnd(void);

void RequestRaceEndStemSet(void);

extern struct RaceEnd *gRaceEnd;
