#include "Main/Race/kart.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/data_020f36d8.h"
#include "code_0214d018.h"
#include "Main/System/init_after_startup.h"

s32 IsKartEnded(u32 kartIndex) {
    BOOL ended = FALSE;
    switch (gRaceProgress->mKarts[kartIndex].mStatus) {
        case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
        case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
        case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
            ended = TRUE;
            break;
    }
    return ended;
}

void GetKartFinishTime(s32 kartIndex, u8 *outMinute, u8 *outSecond, u16 *outMillisecond) {
    RaceProgressKart *kart = &gRaceProgress->mKarts[kartIndex];
    BOOL enabled = TRUE;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        if (gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
            enabled = FALSE;
        }
    }
    if (enabled != FALSE) {
        BOOL ended = FALSE;
        switch (kart->mStatus) {
            case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
            case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
            case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
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
    MinuteSecondMillisecondTime bestTime;
    MinuteSecondMillisecondTime *lapTime;
    BOOL isBest;
    MinuteSecondMillisecondTime *bestTimeRef;
    lap = 1;
    if (gCourseMap->mSettings->mLapCountOrBattleSeconds >= 1) {
        do {
            lapTime = &gRaceProgress->mKarts[kartIndex].mLapTimes[lap - 1];
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
