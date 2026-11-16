#pragma once

#include "types.h"

typedef struct MinuteSecondMillisecondTime MinuteSecondMillisecondTime;

void CopyKartCupRecords(u8 from, u8 to);
s32 ComputeMissionRecordValue(void);
s32 ComputeGrandPrixRecordValue(void);
u8 GetKartStartRank(u32 kart);
u8 GetKartPreviousWinCount(u32 kart);
u16 GetKartPreviousTotalPoints(u32 kart);
s32 GetCupWinningTeam(void);
s32 GetKartCupRank(u16 kart);
void SetTeamWinCountsAndPoints(s32 winningTeam);
void SetCupWinningTeam(s32 team);
void SetKartCupRank(s32 kart, u8 rank);
void GetKartCourseFinishTime(MinuteSecondMillisecondTime *finishTime, u16 kart, u32 course);
void SetKartCourseFinishTime(u32 kart, MinuteSecondMillisecondTime *finishTime);
void SetBattleKartCourseResult(u32 kart, s32 isAlive);
void ClearKartCourseTotalPoints(u32 kart);
void SetKartCourseResult(u32 kart, s32 rank, u32 points);
u8 GetCourseIndexInCup(void);
void ResetCupRecords(void);

void CreateCupRecords(void *heap);

// Largest total of points in a cup record, for a kart or a team.
#define CUP_RECORD_TOTAL_POINTS_MAX 9999
