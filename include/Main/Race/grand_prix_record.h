#pragma once

#include "types.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Save/course_time_record.h"
#include "Main/Graphics/time_format.h"

BOOL IsDateEarlier(const DateBytes *firstDate, const DateBytes *secondDate);
void InitWLMenuResetRaceSetup(void *heap);
void InitWLMenuRequestMPWaitMenuArchives(void *heap);
void InitWLMenuRequestMPWaitResultArchives(void *heap);
void InitWLMenuRequestMPWaitRaceArchives(void *heap);
u32 SomeMissionLevelStageChecking(void);
BOOL CheckUpdateGrandPrixResult(void);
BOOL StructCP_IsBBetterThanA(TimeRecord *storedRecord, TimeRecord *newRecord);
void StructCP_CreateFromCurrent(TimeRecord *record);
void StructCP_SetTimeFromCPAndTime(TimeRecord *firstTime, MinuteSecondMillisecondTime *secondTime, TimeRecord *sum);

#include "00/Menu/wi_fi_vs_matching.h"

extern const u8 g_RacerPositionToCupResultTable[8];
