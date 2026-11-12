#pragma once

#include "types.h"
#include "code_0214d93c.h" // RTCDate, RTCTime

s64 RTC_ConvertDateTimeToSecond(const RTCDate *date, const RTCTime *time);

s32 RTCi_ConvertTimeToSecond(const RTCTime *time);

s32 RTC_ConvertDateToDay(const RTCDate *date);
