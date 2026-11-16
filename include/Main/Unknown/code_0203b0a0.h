#pragma once

#include "types.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/code_02116a4c.h"

BOOL IsDateEarlier(const DateBytes *firstDate, const DateBytes *secondDate);
void sub_203B0F8(void *heap);
void sub_203B194(void *heap);
void sub_203B1C8(void *heap);
void sub_203B1FC(void *heap);
u32 race_saveMrResult(void);
BOOL race_saveGpResult(void);
BOOL race_isNkgpBetter(TimeRecord *storedRecord, TimeRecord *newRecord);
void race_createNkgpEntry(TimeRecord *record);
void race_addTimes(TimeRecord *firstTime, Unk0217aa1c_144_00 *secondTime, TimeRecord *sum);

#include "00/code_021832d8.h"
