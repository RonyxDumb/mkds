#include "Main/Unknown/code_0215228c.h"

#pragma thumb on

u32 ComputeSecondsOfDay(const RTCTime *values) {
    return values->mSecond + 0x3cu * (values->mMinute + 0x3cu * values->mHour);
}

#pragma thumb off
