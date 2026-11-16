#pragma once

#include "types.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/code_02116a4c.h"

BOOL IsDateEarlier(const DateBytes *firstDate, const DateBytes *secondDate);
void func_0203b0f8(void *heap);
void func_0203b194(void *heap);
void func_0203b1c8(void *heap);
void func_0203b1fc(void *heap);
u32 race_saveMrResult(void);
BOOL race_saveGpResult(void);
BOOL race_isNkgpBetter(TimeRecord *storedRecord, TimeRecord *newRecord);
void race_createNkgpEntry(TimeRecord *record);
void race_addTimes(TimeRecord *firstTime, Unk0217aa1c_144_00 *secondTime, TimeRecord *sum);

#include "00/code_021832d8.h"
