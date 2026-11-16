#include "date_time_to_seconds.h"
#include "Main/Net/block_transfer_and_thread_globals.h"
#include "thread_scheduler.h"
#include "multiboot_piece_buffers.h"
#include "vram_bank_display_setup.h"

s32 Rtc_Date_GetDays(const RTCDate *date) {
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

s32 Rtc_Time_GetSeconds(const RTCTime *time) {
    return (time->mHour * 60 + time->mMinute) * 60 + time->mSecond;
}

s64 Rtc_DateTime_GetSeconds(const RTCDate *date, const RTCTime *time) {
    s32 day;
    s32 sec;

    day = Rtc_Date_GetDays(date);
    if (day == -1) {
        return -1;
    }
    sec = Rtc_Time_GetSeconds(time);
    if (sec == -1) {
        return -1;
    }
    return (s64) day * 86400 + sec;
}
