/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define RTC_ConvertDateToDay Rtc_Date_GetDays
#define RTCi_ConvertTimeToSecond Rtc_Time_GetSeconds
#define RTC_ConvertDateTimeToSecond Rtc_DateTime_GetSeconds
#include "nitro/types.h"
#include "RTC_api.h"
#include "RTC_convert.h"
#include "code32.h"
extern s32 RTC_ConvertDateToDay(const RTCDate * date);
extern s32 RTCi_ConvertTimeToSecond(const RTCTime * time);
s64 RTC_ConvertDateTimeToSecond(const RTCDate * date, const RTCTime * time)
{
    s32 day = RTC_ConvertDateToDay(date);
    if (day == -1)
        return -1;
    s32 second = RTCi_ConvertTimeToSecond(time);
    if (second == -1)
        return -1;
    return ((s64)day) * (60 * 60 * 24) + second;
}
