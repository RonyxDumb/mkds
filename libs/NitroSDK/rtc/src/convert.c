#include "convert.h"
#include "Main/Net/wbt_os_thread_globals.h"
#include "os_thread.h"
#include "mb_data.h"
#include "code_02148950.h"

s32 RTC_ConvertDateToDay(const RTCDate *date) {
    s32 days;

    if (date->mYear >= CLOCK_YEAR_COUNT || date->mMonth < 1 || date->mMonth > CLOCK_MONTH_MAX || date->mDay < 1 ||
        date->mDay > CLOCK_DAY_MAX || date->mWeek >= RTC_WEEK_MAX || date->mMonth < 1 ||
        date->mMonth > CLOCK_MONTH_MAX) {
        return -1;
    }
    days = date->mDay - 1;
    // The month is 1-based.
    days += (sDayOfYear - 1)[date->mMonth];
    if (date->mMonth >= CLOCK_MARCH && (date->mYear & CLOCK_LEAP_YEAR_MASK) == 0) {
        days++;
    }
    days += date->mYear * 365;
    days += (date->mYear + 3) / 4;
    return days;
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
