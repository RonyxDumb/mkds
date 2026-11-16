#include "Main/Race/race_progress_rank.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Race/race_hud_kart_removed.h"
#include "Main/Race/race_end_condition.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Kart/karts.h"
#include "Main/System/init_after_startup.h"

u16 LookupRankPoints(u8 rank) {
    u16 rowOffset = 0;
    RankPointRow *rows = g_GlobalMV->mRankPointFile;
    if (rows != NULL) {
        switch (g_GlobalCO->mMode) {
            case MODE_GRAND_PRIX:
                break;
            case MODE_VS: {
                u16 baseRow = 1;
                if (g_GlobalCO->mUseTeams != 0) {
                    if (g_GlobalCO->mKartCount > 3) {
                        if (g_GlobalCO->mTeamKartCounts[0] <= 1 || g_GlobalCO->mTeamKartCounts[1] <= 1) {
                            baseRow = 8;
                        } else {
                            baseRow = 0xf;
                        }
                    } else {
                        baseRow = 8;
                    }
                }
                rowOffset = baseRow + 8 - g_GlobalCO->mKartCount;
                break;
            }
            case MODE_WIFI:
                rowOffset = 9 - g_GlobalCO->mKartCount;
                break;
        }
        rowOffset = (rows + rowOffset + 1)->mPoints[rank - 1];
    }
    return rowOffset;
}

void RemoveRaceProgressKart(u16 kartIndex) {
    u32 oldRank;
    RaceProgressKart *progressKart = &g_GlobalMV->mKarts[kartIndex];
    BOOL hasEnded = FALSE;
    switch (progressKart->mStatus) {
        case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
        case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
        case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
            hasEnded = TRUE;
            break;
    }
    if (hasEnded == FALSE) {
        u32 lastRank;
        s32 otherIndex;
        oldRank = progressKart->mRank;
        lastRank = (u16) (g_GlobalCO->mKartCount - g_GlobalMV->mHeader.mRemovedCount);
        progressKart->mRank = g_GlobalCO->mKartCount - g_GlobalMV->mHeader.mRemovedCount;
        for (otherIndex = 0; otherIndex < g_GlobalCO->mKartCount; otherIndex++) {
            RaceProgressKart *otherKart = &g_GlobalMV->mKarts[otherIndex];
            if (otherIndex != kartIndex) {
                u32 otherRank = otherKart->mRank;
                if (otherRank > oldRank && otherRank <= lastRank) {
                    otherKart->mRank--;
                }
            }
        }
        g_GlobalMV->mHeader.mRemovedCount++;
    }
    if (g_GlobalCO->mMode == MODE_BATTLE) {
        EliminateKartAndCheckWinner(kartIndex);
    }
    progressKart->mStatus = RACE_PROGRESS_KART_STATUS_REMOVED;
    StructMQRacerEntry_SomeFn_34(GetRacerMQEntry(kartIndex));
    SetRaceHudKartRemoved(kartIndex, 1);
    if (IsRaceEndConditionMet() != 0) {
        switch (g_GlobalCO->mMode) {
            case MODE_TIME_ATTACK:
                break;
            case MODE_BATTLE:
                RaceModeBattle_OrMissionRun_SomeFn();
                break;
            case MODE_MISSION_RUN:
                RaceModeMissionRun_SomeFn();
                break;
            case MODE_WIFI:
                RaceModeNet_SomeFn();
                break;
            default:
                RaceModeDefault_SomeFn();
                break;
        }
    }
}

BOOL UpdatePlayerLapCountIfNot123(u16 kartIndex) {
    BOOL hasEnded = FALSE;
    BOOL result;
    switch (g_GlobalMV->mKarts[kartIndex].mStatus) {
        case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
        case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
        case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
            hasEnded = TRUE;
            break;
    }
    result = hasEnded == FALSE;
    if (result != FALSE) {
        result = GetCurrentLapCount() == g_GlobalMV->mKarts[kartIndex].mLap;
    }
    return result != FALSE;
}
