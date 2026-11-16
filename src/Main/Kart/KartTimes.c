#include "Main/Kart/KartTimes.h"
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

s32 rstat_hasDriverFinished(u32 kartIndex) {
    BOOL ended = FALSE;
    switch (gRaceStatus->field0[kartIndex].mStatus) {
        case 1:
        case 2:
        case 3:
            ended = TRUE;
            break;
    }
    return ended;
}

void rstat_getDriverTotalTime(s32 kartIndex, u8 *outMinute, u8 *outSecond, u16 *outMillisecond) {
    RaceProgressKart *kart = OFFSET_PTR(RaceProgressKart, &gRaceStatus->mKarts[0], kartIndex * 0x8c);
    BOOL g = TRUE;
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        if (gRaceMultiConfig->mBattleKind == BATTLE_KIND_SHINE) {
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
            Unk0217aa1c_144_00 *finishTime = &kart->mLapTimes[5];
            *outMinute = finishTime->field2;
            *outSecond = finishTime->field3;
            *outMillisecond = finishTime->field0;
            return;
        }
    }
    *outMinute = 0;
    *outSecond = 0;
    *outMillisecond = 0;
}

void rstat_getDriverLapTime(s32 kartIndex, u16 lap, u8 *outMinute, u8 *outSecond, u16 *outMillisecond) {
    s32 lapSlot = lap - 1;
    Unk0217aa1c_144_00 *kartLapTimes =
        OFFSET_PTR(Unk0217aa1c_144_00, &gRaceStatus->mKarts[0].mLapTimes[0], kartIndex * 0x8c);
    Unk0217aa1c_144_00 *lapTime = &kartLapTimes[lapSlot];
    *outMinute = lapTime->field2;
    *outSecond = lapTime->field3;
    *outMillisecond = lapTime->field0;
}

u16 rstat_getDriverBestLapTime(u16 kartIndex, u8 *outMinute, u8 *outSecond, u16 *outMillisecond) {
    u16 bestLap = 1;
    u16 lap;
    BOOL first = TRUE;
    u32 kartOffset;
    Unk0217aa1c_144_00 bestTime;
    Unk0217aa1c_144_00 *lapTime;
    BOOL isBest;
    Unk0217aa1c_144_00 *bestTimeRef;
    lap = 1;
    if (gMapData->mSettings->mLapCountOrBattleSeconds >= 1) {
        kartOffset = kartIndex * 0x8c;
        do {
            lapTime = OFFSET_PTR(Unk0217aa1c_144_00, &gRaceStatus->mKarts[0].mLapTimes[0], kartOffset) + (lap - 1);
            if (first != FALSE) {
                first = FALSE;
                bestLap = lap;
                bestTime = *lapTime;
            } else {
                bestTimeRef = &bestTime;
                isBest = FALSE;
                if (((lapTime->field2 * 60 + lapTime->field3) * 1000 + lapTime->field0) <=
                    (u32) ((bestTime.field2 * 60 + bestTime.field3) * 1000 + bestTime.field0)) {
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
        } while (lap <= gMapData->mSettings->mLapCountOrBattleSeconds);
    }
    *outMinute = bestTime.field2;
    *outSecond = bestTime.field3;
    *outMillisecond = bestTime.field0;
    return bestLap;
}
