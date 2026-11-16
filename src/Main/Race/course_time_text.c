#include "Main/Race/course_time_text.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Graphics/minute_second_millisecond_text.h"
#include "Main/Menu/menu_shared_clear.h"

#pragma thumb on

void WriteCourseTimeText(s16 *text, int index) {
    MinuteSecondMillisecondTime *entry;
    entry = &g_GlobalB488->mCourseTimes[index];
    WriteMinuteSecondMillisecondText((text), entry->mMinute, entry->mSecond,
                                     g_GlobalB488->mCourseTimes[index].mMillisecond);
}

#pragma thumb off
