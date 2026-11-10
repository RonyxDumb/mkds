#pragma once

#include "types.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/code_02116a4c.h"

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

#include "00/code_021832d8.h"
