#include "Main/Race/course_time_text.h"
#include "Main/Unknown/code_02025000.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Graphics/minute_second_millisecond_text.h"

#pragma thumb on

void WriteCourseTimeText(s16 *text, int index) {
    MinuteSecondMillisecondTime *entry;
    entry = &gMenuShared->mCourseTimes[index];
    WriteMinuteSecondMillisecondText((text), entry->mMinute, entry->mSecond,
                                     gMenuShared->mCourseTimes[index].mMillisecond);
}

#pragma thumb off
