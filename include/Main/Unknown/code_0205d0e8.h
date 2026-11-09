#pragma once

#include "types.h"

typedef struct MinuteSecondMillisecondTime MinuteSecondMillisecondTime;

void CopyKartCupRecords(u8 from, u8 to);
s32 func_0205d140(void);
s32 func_0205d190(void);
u8 GetKartStartRank(u32 kart);
u8 GetKartPreviousWinCount(u32 kart);
u16 GetKartPreviousTotalPoints(u32 kart);
s32 GetCupWinningTeam(void);
s32 GetKartCupRank(u32 kart);
void SetTeamWinCountsAndPoints(s32 winningTeam);
void SetCupWinningTeam(s32 team);
void SetKartCupRank(s32 kart, u8 rank);
void GetKartCourseFinishTime(MinuteSecondMillisecondTime *finishTime, u32 kart, u32 course);
void SetKartCourseFinishTime(u32 kart, MinuteSecondMillisecondTime *finishTime);
void func_0205d88c(u32 kart, s32 b);
void ClearKartCourseTotalPoints(u32 kart);
void SetKartCourseResult(u32 kart, s32 rank, u32 points);
u8 GetCourseIndexInCup(void);
void ResetCupRecords(void);
