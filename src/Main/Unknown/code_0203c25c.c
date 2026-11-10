#include "Main/Unknown/code_0203c25c.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020b1cdc.h"
#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_02077bc0.h"

u16 LookupRankPoints(u8 a) {
    u16 r = 0;
    RankPointRow *t = gRaceProgress->mRankPointFile;
    if (t != NULL) {
        switch (gRaceSetup->mMode) {
            case MODE_GRAND_PRIX:
                break;
            case MODE_VS: {
                u16 k = 1;
                if (gRaceSetup->mUseTeams != 0) {
                    if (gRaceSetup->mKartCount > 3) {
                        if (gRaceSetup->mTeamKartCounts[0] <= 1 || gRaceSetup->mTeamKartCounts[1] <= 1) {
                            k = 8;
                        } else {
                            k = 0xf;
                        }
                    } else {
                        k = 8;
                    }
                }
                r = k + 8 - gRaceSetup->mKartCount;
                break;
            }
            case 5:
                r = 9 - gRaceSetup->mKartCount;
                break;
        }
        r = (t + r + 1)->mPoints[a - 1];
    }
    return r;
}

void RemoveRaceProgressKart(u16 a) {
    u32 o;
    RaceProgressKart *p = &gRaceProgress->mKarts[a];
    BOOL f = FALSE;
    switch (p->mStatus) {
        case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
        case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
        case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
            f = TRUE;
            break;
    }
    if (f == FALSE) {
        u32 v;
        s32 i;
        o = p->mRank;
        v = (u16) (gRaceSetup->mKartCount - gRaceProgress->mHeader.mRemovedCount);
        p->mRank = gRaceSetup->mKartCount - gRaceProgress->mHeader.mRemovedCount;
        for (i = 0; i < gRaceSetup->mKartCount; i++) {
            RaceProgressKart *q = &gRaceProgress->mKarts[i];
            if (i != a) {
                u32 m = q->mRank;
                if (m > o && m <= v) {
                    q->mRank--;
                }
            }
        }
        gRaceProgress->mHeader.mRemovedCount++;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        EliminateKartAndCheckWinner(a);
    }
    p->mStatus = RACE_PROGRESS_KART_STATUS_REMOVED;
    StartKartRemovalFromProgress(GetKart(a));
    SetRaceHudKartRemoved(a, 1);
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
            case 5:
                FinishRemainingWiFiRaceKarts();
                break;
            default:
                FinishRemainingRaceProgressKarts();
                break;
        }
    }
}

BOOL IsKartOnLastLap(u16 a) {
    BOOL f = FALSE;
    BOOL r;
    switch (gRaceProgress->mKarts[a].mStatus) {
        case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
        case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
        case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
            f = TRUE;
            break;
    }
    r = f == FALSE;
    if (r != FALSE) {
        r = GetLapCount() == gRaceProgress->mKarts[a].mLap;
    }
    return r != FALSE;
}
