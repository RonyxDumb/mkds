#include "Main/Unknown/code_0203c5f8.h"
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
#include "Main/Unknown/code_020f36d8.h"
#include "code_0214d018.h"

s32 IsKartEnded(u32 kartIndex) {
    BOOL ended = FALSE;
    switch (gRaceProgress->mKarts[kartIndex].mStatus) {
        case 1:
        case 2:
        case 3:
            ended = TRUE;
            break;
    }
    return ended;
}

void GetKartFinishTime(s32 kartIndex, u8 *outMinute, u8 *outSecond, u16 *outMillisecond) {
    RaceProgressKart *kart = &gRaceProgress->mKarts[kartIndex];
    BOOL g = TRUE;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        if (gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
            g = FALSE;
        }
    }
    if (g != FALSE) {
        BOOL ended = FALSE;
        switch (kart->mStatus) {
            case 1:
            case 2:
            case 3:
                ended = TRUE;
                break;
        }
        if (ended != FALSE) {
            MinuteSecondMillisecondTime *finishTime = &kart->mLapTimes[5];
            *outMinute = finishTime->mMinute;
            *outSecond = finishTime->mSecond;
            *outMillisecond = finishTime->mMillisecond;
            return;
        }
    }
    *outMinute = 0;
    *outSecond = 0;
    *outMillisecond = 0;
}

void GetKartLapTime(s32 kartIndex, u16 lap, u8 *outMinute, u8 *outSecond, u16 *outMillisecond) {
    s32 lapSlot = lap - 1;
    MinuteSecondMillisecondTime *kartLapTimes = gRaceProgress->mKarts[kartIndex].mLapTimes;
    MinuteSecondMillisecondTime *lapTime = &kartLapTimes[lapSlot];
    *outMinute = lapTime->mMinute;
    *outSecond = lapTime->mSecond;
    *outMillisecond = lapTime->mMillisecond;
}

u16 GetKartBestLapTime(u16 kartIndex, u8 *outMinute, u8 *outSecond, u16 *outMillisecond) {
    u16 bestLap = 1;
    u16 lap;
    BOOL first = TRUE;
    u32 kartOffset;
    MinuteSecondMillisecondTime bestTime;
    MinuteSecondMillisecondTime *lapTime;
    BOOL isBest;
    MinuteSecondMillisecondTime *bestTimeRef;
    lap = 1;
    if (gCourseMap->mSettings->mLapCountOrBattleSeconds >= 1) {
        kartOffset = kartIndex * 0x8c;
        do {
            lapTime =
                OFFSET_PTR(MinuteSecondMillisecondTime, &gRaceProgress->mKarts[0].mLapTimes[0], kartOffset) + (lap - 1);
            if (first != FALSE) {
                first = FALSE;
                bestLap = lap;
                bestTime = *lapTime;
            } else {
                bestTimeRef = &bestTime;
                isBest = FALSE;
                if (((lapTime->mMinute * 60 + lapTime->mSecond) * 1000 + lapTime->mMillisecond) <=
                    (u32) ((bestTime.mMinute * 60 + bestTime.mSecond) * 1000 + bestTime.mMillisecond)) {
                    isBest = TRUE;
                    if (lapTime != bestTimeRef) {
                        MI_CpuCopy8(lapTime, bestTimeRef, 4);
                    }
                } else {
                    if (bestTimeRef != &bestTime) {
                        MI_CpuCopy8(lapTime, bestTimeRef, 4);
                    }
                }
                if (isBest != FALSE) {
                    bestLap = lap;
                    bestTime = *lapTime;
                }
            }
            lap++;
        } while (lap <= gCourseMap->mSettings->mLapCountOrBattleSeconds);
    }
    *outMinute = bestTime.mMinute;
    *outSecond = bestTime.mSecond;
    *outMillisecond = bestTime.mMillisecond;
    return bestLap;
}
