#include "Main/Unknown/code_0203c25c.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020b1cdc.h"
#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_02077bc0.h"

u16 rstat_getRankPoints(u8 a) {
    u16 r = 0;
    RankPointRow *t = gRaceStatus->mRankPointFile;
    if (t != NULL) {
        switch (gRaceMultiConfig->mMode) {
            case MODE_GRAND_PRIX:
                break;
            case MODE_VS: {
                u16 k = 1;
                if (gRaceMultiConfig->mUseTeams != 0) {
                    if (gRaceMultiConfig->mKartCount > 3) {
                        if (gRaceMultiConfig->mTeamKartCounts[0] <= 1 || gRaceMultiConfig->mTeamKartCounts[1] <= 1) {
                            k = 8;
                        } else {
                            k = 0xf;
                        }
                    } else {
                        k = 8;
                    }
                }
                r = k + 8 - gRaceMultiConfig->mKartCount;
                break;
            }
            case 5:
                r = 9 - gRaceMultiConfig->mKartCount;
                break;
        }
        r = (t + r + 1)->mPoints[a - 1];
    }
    return r;
}

void rstat_203C2E4(u16 a) {
    u32 o;
    RaceProgressKart *p = OFFSET_PTR(RaceProgressKart, &gRaceStatus->mKarts[0], a * 0x8c);
    BOOL f = FALSE;
    switch (p->mStatus) {
        case 1:
        case 2:
        case 3:
            f = TRUE;
            break;
    }
    if (f == FALSE) {
        u32 v;
        s32 i;
        o = p->mRank;
        v = (u16) (gRaceMultiConfig->mKartCount - gRaceStatus->field0[0].mRemovedCount);
        p->mRank = gRaceMultiConfig->mKartCount - gRaceStatus->field0[0].mRemovedCount;
        for (i = 0; i < gRaceMultiConfig->mKartCount; i++) {
            RaceProgressKart *q = OFFSET_PTR(RaceProgressKart, &gRaceStatus->mKarts[0], i * 0x8c);
            if (i != a) {
                u32 m = q->mRank;
                if (m > o && m <= v) {
                    q->mRank--;
                }
            }
        }
        gRaceStatus->field0[0].mRemovedCount++;
    }
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        mgcnt_killDriver(a);
    }
    p->mStatus = 4;
    func_02069044(driver_getById(a));
    SetRaceHudKartRemoved(a, 1);
    if (rstat_shouldTryFinish() != 0) {
        switch (gRaceMultiConfig->mMode) {
            case MODE_TIME_ATTACK:
                break;
            case MODE_BATTLE:
                mgcnt_tryFinish();
                break;
            case MODE_MISSION_RUN:
                rstat_tryFinishMr();
                break;
            case 5:
                rstat_tryFinishNt();
                break;
            default:
                rstat_tryFinishGpVs();
                break;
        }
    }
}

BOOL rstat_isDriverInFinalLap(u16 a) {
    BOOL f = FALSE;
    BOOL r;
    switch (gRaceStatus->field0[a].mStatus) {
        case 1:
        case 2:
        case 3:
            f = TRUE;
            break;
    }
    r = f == FALSE;
    if (r != FALSE) {
        r = rconf_getLapCount() == gRaceStatus->field0[a].mLap;
    }
    return r != FALSE;
}
