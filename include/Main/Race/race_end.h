#pragma once

#include "types.h"
#include "Main/Race/data_0217b35c.h"

void UpdateRaceEnd(void);

void ResetRaceEndFrames(void);
void ClearRaceEndPointer(void);

void SetKartCupRanks(void);
void SetCupWinningTeamFromRecords(void);
void InitRaceEnd(void);

void RequestRaceEndStemSet(void);

extern struct RaceEnd *gRaceEnd;
