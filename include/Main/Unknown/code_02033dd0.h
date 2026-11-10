#pragma once

#include "types.h"

s32 IsResultsBattleTimerBelow300(void);
s32 IsResultsBattleTimerRunOut(void);
s32 AreResultsBattleRanksAllZero(void);
void FillResultsBattleEntries(void);
void AssignResultsBattleTeamOrderByScore(void);
void AssignResultsBattleTeamOrder(void);
void WriteGhostGetScanRegisters(void);
