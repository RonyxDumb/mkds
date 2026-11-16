#include "Main/Unknown/code_020b1a34.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b4000.h"
#include "code_0214d018.h"
#include "Main/Kart/KartTimes.h"

#pragma opt_arithtransformation off

// Absolute difference of two times (minutes, seconds, milliseconds) written to the out record (minutes capped to
// 99:59.999 from 100 minutes); returns non-zero when first >= second.
s32 ComputeTimeDifference(MinuteSecondMillisecondTotal *first, MinuteSecondMillisecondTotal *second,
                          MinuteSecondMillisecondTime *difference) {
    s32 firstMs;
    s32 secondMs;
    s32 differenceMs;
    BOOL firstNotLess;
    s32 minutes;
    s32 seconds;
    s32 milliseconds;

    firstMs = (first->mMinutes * 60 + first->mSeconds) * 1000 + first->mMilliseconds;
    secondMs = (second->mMinutes * 60 + second->mSeconds) * 1000 + second->mMilliseconds;
    firstNotLess = firstMs >= secondMs;
    if (firstNotLess != FALSE) {
        differenceMs = firstMs - secondMs;
    } else {
        differenceMs = secondMs - firstMs;
    }
    minutes = differenceMs / 60000;
    seconds = (differenceMs - minutes * 60000) / 1000;
    milliseconds = differenceMs % 1000;
    if (minutes < 100) {
        difference->mMinute = minutes;
        difference->mSecond = seconds;
        difference->mMillisecond = milliseconds;
    } else {
        difference->mMinute = 99;
        difference->mSecond = 59;
        difference->mMillisecond = 999;
    }
    return firstNotLess;
}

void func_020b1a34(void) {
    MinuteSecondMillisecondTime referenceLap;
    MinuteSecondMillisecondTime kartLap;
    MinuteSecondMillisecondTime difference;
    MinuteSecondMillisecondTotal totals[2];
    TimeDigits digits;
    u8 totalsIndex;
    u8 lap;

    if (gRaceMultiConfig->mMode == MODE_GRAND_PRIX || gRaceMultiConfig->mMode == MODE_TIME_ATTACK) {
        r2d_sStatus->mShowLapTime = 1;
    }
    if (r2d_sStatus->mUseTimeDifference == 0) {
        return;
    }
    for (totalsIndex = 0; totalsIndex < 2; totalsIndex++) {
        totals[totalsIndex].mMinutes = 0;
        totals[totalsIndex].mSeconds = 0;
        totals[totalsIndex].mMilliseconds = 0;
    }
    for (lap = 1; lap <= GetFollowedKartLastEndedLap(); lap++) {
        if (gRaceMultiConfig->mMode == MODE_TIME_ATTACK) {
            MI_CpuCopy8(&gRaceMultiConfig->mGhostLapTimes[lap - 1], &referenceLap, 4);
        }
        totals[0].mMinutes += referenceLap.mMinute;
        totals[0].mSeconds += referenceLap.mSecond;
        totals[0].mMilliseconds += referenceLap.mMillisecond;
        rstat_getDriverLapTime(Race_GetPlayerId(), lap, &kartLap.mMinute, &kartLap.mSecond, &kartLap.mMillisecond);
        totals[1].mMinutes += kartLap.mMinute;
        totals[1].mSeconds += kartLap.mSecond;
        totals[1].mMilliseconds += kartLap.mMillisecond;
    }
    r2d_sStatus->mTimeDifferenceSign = ComputeTimeDifference(&totals[1], &totals[0], &difference);
    SplitTimeDigits(difference.mMinute, difference.mSecond, difference.mMillisecond, &digits);
    r2d_sStatus->mTimeDifferenceDigits = digits;
}
