#include "convert.h"
#include "Main/Net/data_0216f000.h"
#include "os_thread.h"
#include "mb_data.h"

s32 RTC_ConvertDateToDay(const RTCDate *date) {
    s32 dayNum;

    if (date->mYear >= 100 || date->mMonth < 1 || date->mMonth > 12 || date->mDay < 1 || date->mDay > 31 ||
        date->mWeek >= RTC_WEEK_MAX || date->mMonth < 1 || date->mMonth > 12) {
        return -1;
    }
    dayNum = date->mDay - 1;
    // The month is 1-based.
    dayNum += (sDayOfYear - 1)[date->mMonth];
    if (date->mMonth >= 3 && (date->mYear & 3) == 0) {
        dayNum++;
    }
    dayNum += date->mYear * 365;
    dayNum += (date->mYear + 3) / 4;
    return dayNum;
}

s32 RTCi_ConvertTimeToSecond(const RTCTime *time) {
    return (time->mHour * 60 + time->mMinute) * 60 + time->mSecond;
}

s64 RTC_ConvertDateTimeToSecond(const RTCDate *date, const RTCTime *time) {
    s32 day;
    s32 sec;

    day = RTC_ConvertDateToDay(date);
    if (day == -1) {
        return -1;
    }
    sec = RTCi_ConvertTimeToSecond(time);
    if (sec == -1) {
        return -1;
    }
    return (s64) day * 86400 + sec;
}
