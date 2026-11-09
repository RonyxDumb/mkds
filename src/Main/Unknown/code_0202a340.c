#include "Main/Unknown/code_0202a340.h"
#include "Main/Unknown/code_02025000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02025cd0.h"

#pragma thumb on

void func_0202a340(s16 *a, int index) {
    MinuteSecondMillisecondTime *entry;
    entry = &data_0217b488->mCourseTimes[index];
    WriteMinuteSecondMillisecondText((a), entry->mMinute, entry->mSecond,
                                     data_0217b488->mCourseTimes[index].mMillisecond);
}

#pragma thumb off
