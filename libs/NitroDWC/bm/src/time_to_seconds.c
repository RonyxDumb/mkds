#include "time_to_seconds.h"

#pragma thumb on

u32 TimeToSeconds(const RTCTime *time) {
    return time->mSecond + 0x3cu * (time->mMinute + 0x3cu * time->mHour);
}

#pragma thumb off
