#pragma once

#include "types.h"
#include "clock_chip_access.h" // RTCDate, RTCTime

// Limits RTC_ConvertDateToDay accepts: years 0 to 99, months 1 to 12, days 1 to 31 and a weekday below RTC_WEEK_MAX. A
// leap year has its low two bits clear, and its extra day counts from the month after February.
#define CLOCK_YEAR_COUNT 100
#define CLOCK_MONTH_MAX 12
#define CLOCK_DAY_MAX 31
#define CLOCK_LEAP_YEAR_MASK 3
#define CLOCK_MARCH 3

s64 RTC_ConvertDateTimeToSecond(const RTCDate *date, const RTCTime *time);

s32 RTCi_ConvertTimeToSecond(const RTCTime *time);

s32 RTC_ConvertDateToDay(const RTCDate *date);
