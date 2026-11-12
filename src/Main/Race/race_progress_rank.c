#include "Main/Race/race_progress_rank.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Race/race_entries.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Race/race_hud_kart_removed.h"
#include "Main/Race/race_end_condition.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Kart/karts.h"

u16 LookupRankPoints(u8 rank) {
    u16 rowOffset = 0;
    RankPointRow *rows = gRaceProgress->mRankPointFile;
    if (rows != NULL) {
        switch (gRaceSetup->mMode) {
            case MODE_GRAND_PRIX:
                break;
            case MODE_VS: {
                u16 baseRow = 1;
                if (gRaceSetup->mUseTeams != 0) {
                    if (gRaceSetup->mKartCount > 3) {
                        if (gRaceSetup->mTeamKartCounts[0] <= 1 || gRaceSetup->mTeamKartCounts[1] <= 1) {
                            baseRow = 8;
                        } else {
                            baseRow = 0xf;
                        }
                    } else {
                        baseRow = 8;
                    }
                }
                rowOffset = baseRow + 8 - gRaceSetup->mKartCount;
                break;
            }
            case MODE_WIFI:
                rowOffset = 9 - gRaceSetup->mKartCount;
                break;
        }
        rowOffset = (rows + rowOffset + 1)->mPoints[rank - 1];
    }
    return rowOffset;
}

void RemoveRaceProgressKart(u16 kartIndex) {
    u32 oldRank;
    RaceProgressKart *progressKart = &gRaceProgress->mKarts[kartIndex];
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
        lastRank = (u16) (gRaceSetup->mKartCount - gRaceProgress->mHeader.mRemovedCount);
        progressKart->mRank = gRaceSetup->mKartCount - gRaceProgress->mHeader.mRemovedCount;
        for (otherIndex = 0; otherIndex < gRaceSetup->mKartCount; otherIndex++) {
            RaceProgressKart *otherKart = &gRaceProgress->mKarts[otherIndex];
            if (otherIndex != kartIndex) {
                u32 otherRank = otherKart->mRank;
                if (otherRank > oldRank && otherRank <= lastRank) {
                    otherKart->mRank--;
                }
            }
        }
        gRaceProgress->mHeader.mRemovedCount++;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        EliminateKartAndCheckWinner(kartIndex);
    }
    progressKart->mStatus = RACE_PROGRESS_KART_STATUS_REMOVED;
    StartKartRemovalFromProgress(GetKart(kartIndex));
    SetRaceHudKartRemoved(kartIndex, 1);
    if (IsRaceEndConditionMet() != 0) {
        switch (gRaceSetup->mMode) {
            case MODE_TIME_ATTACK:
                break;
            case MODE_BATTLE:
                EliminateKartsUntilWinnerDecided();
                break;
            case MODE_MISSION_RUN:
                FinishRemainingMissionRunKarts();
                break;
            case MODE_WIFI:
                FinishRemainingWiFiRaceKarts();
                break;
            default:
                FinishRemainingRaceProgressKarts();
                break;
        }
    }
}

BOOL IsKartOnLastLap(u16 kartIndex) {
    BOOL hasEnded = FALSE;
    BOOL result;
    switch (gRaceProgress->mKarts[kartIndex].mStatus) {
        case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
        case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
        case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
            hasEnded = TRUE;
            break;
    }
    result = hasEnded == FALSE;
    if (result != FALSE) {
        result = GetLapCount() == gRaceProgress->mKarts[kartIndex].mLap;
    }
    return result != FALSE;
}
