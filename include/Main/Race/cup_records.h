#pragma once

#include "types.h"

typedef struct MinuteSecondMillisecondTime MinuteSecondMillisecondTime;

void CopyKartCupRecords(u8 from, u8 to);
s32 ComputeMissionInternalScore(void);
s32 ComputeGrandPrixRecordValue(void);
u8 GetKartStartRank(u32 kart);
u8 GetKartPreviousWinCount(u32 kart);
u16 GetKartPreviousTotalPoints(u32 kart);
s32 GetCupWinningTeam(void);
s32 GetSomeRacerPosition(u16 kart);
void SetTeamWinCountsAndPoints(s32 winningTeam);
void SetCupWinningTeam(s32 team);
void SetKartCupRank(s32 kart, u8 rank);
void GetKartCourseFinishTime(MinuteSecondMillisecondTime *finishTime, u16 kart, u32 course);
void SetKartCourseFinishTime(u32 kart, MinuteSecondMillisecondTime *finishTime);
void SetBattleKartCourseResult(u32 kart, s32 isAlive);
void ClearKartCourseTotalPoints(u32 kart);
void SetKartCourseResult(u32 kart, s32 rank, u32 points);
u8 GetSomeLUMaxIndex(void);
void CreateGlobalLU(void);

void InitializeGlobalLU(void *heap);

// Largest total of Grand Prix points a kart keeps in a cup record.
#define CUP_RECORD_TOTAL_POINTS_MAX 9999
