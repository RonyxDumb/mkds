#pragma once

#include "types.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Save/course_time_record.h"
#include "Main/Graphics/time_format.h"

BOOL IsDateEarlier(const DateBytes *firstDate, const DateBytes *secondDate);
void InitWLMenuResetRaceSetup(void *heap);
void InitWLMenuRequestMPState21(void *heap);
void InitWLMenuRequestMPState18(void *heap);
void InitWLMenuRequestMPState16(void *heap);
u32 TrySetMissionRecord(void);
BOOL TrySetGrandPrixRecord(void);
BOOL ShouldSetGrandPrixRecord(TimeRecord *storedRecord, TimeRecord *newRecord);
void FillGrandPrixRecord(TimeRecord *record);
void SumTimes(TimeRecord *firstTime, MinuteSecondMillisecondTime *secondTime, TimeRecord *sum);

#include "00/Menu/wi_fi_vs_matching.h"

extern const u8 gCupRankTable[8];
