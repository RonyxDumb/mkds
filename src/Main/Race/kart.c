#include "Main/Race/kart.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "cpu_copy_fill.h"
#include "Main/System/init_after_startup.h"

s32 IsRacerFinishedRace(u32 kartIndex) {
    BOOL ended = FALSE;
    switch (g_GlobalMV->mKarts[kartIndex].mStatus) {
        case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
        case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
        case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
            ended = TRUE;
            break;
    }
    return ended;
}

void GetPlayerTotalTime(s32 kartIndex, u8 *outMinute, u8 *outSecond, u16 *outMillisecond) {
    RaceProgressKart *kart = &g_GlobalMV->mKarts[kartIndex];
    BOOL enabled = TRUE;
    if (g_GlobalCO->mMode == MODE_BATTLE) {
        if (g_GlobalCO->mBattleKind == BATTLE_KIND_SHINE) {
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

void MaybeGetPlayerLapTime(s32 kartIndex, u16 lap, u8 *outMinute, u8 *outSecond, u16 *outMillisecond) {
    s32 lapSlot = lap - 1;
    MinuteSecondMillisecondTime *kartLapTimes = g_GlobalMV->mKarts[kartIndex].mLapTimes;
    MinuteSecondMillisecondTime *lapTime = &kartLapTimes[lapSlot];
    *outMinute = lapTime->mMinute;
    *outSecond = lapTime->mSecond;
    *outMillisecond = lapTime->mMillisecond;
}

u16 GetLeastTimeLap(u16 kartIndex, u8 *outMinute, u8 *outSecond, u16 *outMillisecond) {
    u16 bestLap = 1;
    u16 lap;
    BOOL first = TRUE;
    MinuteSecondMillisecondTime bestTime;
    MinuteSecondMillisecondTime *lapTime;
    BOOL isBest;
    MinuteSecondMillisecondTime *bestTimeRef;
    lap = 1;
    if (g_GlobalPE->mSettings->mLapCountOrBattleSeconds >= 1) {
        do {
            lapTime = &g_GlobalMV->mKarts[kartIndex].mLapTimes[lap - 1];
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
                        Mem_CpuCopy8(lapTime, bestTimeRef, 4);
                    }
                } else {
                    if (bestTimeRef != &bestTime) {
                        Mem_CpuCopy8(lapTime, bestTimeRef, 4);
                    }
                }
                if (isBest != FALSE) {
                    bestLap = lap;
                    bestTime = *lapTime;
                }
            }
            lap++;
        } while (lap <= g_GlobalPE->mSettings->mLapCountOrBattleSeconds);
    }
    *outMinute = bestTime.mMinute;
    *outSecond = bestTime.mSecond;
    *outMillisecond = bestTime.mMillisecond;
    return bestLap;
}
