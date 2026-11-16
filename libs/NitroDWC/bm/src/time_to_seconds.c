#include "time_to_seconds.h"

#pragma thumb on

u32 ComputeTimeSeconds_from_thumb(const RTCTime *values) {
    return values->mSecond + 0x3cu * (values->mMinute + 0x3cu * values->mHour);
}

#pragma thumb off
