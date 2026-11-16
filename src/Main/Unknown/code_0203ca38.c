#include "Main/Unknown/code_0203ca38.h"
#include "Main/Unknown/code_0203c25c.h"
#include "Main/Kart/KartTimes.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a128c.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020b3f64.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/code_0203d568.h"
#include "Main/Race/RaceProgress.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_02077bc0.h"

static inline s32 func_0203ca38_inline(u32 i) {
    return mgcnt_getDriverPlace(i) + 1;
}

void rstat_storeRaceResults(void) {
    RaceProgress *raceProgress;
    s32 winningTeamIndex = -1;
    RaceSetup *raceSetup = gRaceMultiConfig;
    s32 mode = raceSetup->mMode;
    u32 kartIndex;
    BOOL usesTeams = FALSE;
    switch (mode) {
        case MODE_BATTLE:
        case MODE_VS:
            if (raceSetup->mUseTeams != 0) {
                usesTeams = TRUE;
            }
            break;
    }
    switch (mode) {
        case MODE_GRAND_PRIX:
        case MODE_VS:
        case 5: {
            for (kartIndex = 0; kartIndex < raceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
                u32 t;
                u8 rank;
                u32 rankPoints = 0;
                if (raceSetup->mMode == 5) {
                    t = gStruct217AA14->mUnk_104[gStruct217AA18->mParticipantOfKart[kartIndex & 0xff]].mRank;
                } else {
                    t = gRaceStatus->mKarts[kartIndex].mRank;
                }
                rank = t;
                if (gRaceStatus->mUnk_000[kartIndex].mStatus != 4) {
                    rankPoints = rstat_getRankPoints(rank);
                }
                rres_setPlaceAndPoints(kartIndex, rank, rankPoints);
                rres_setRaceTime(kartIndex, &gRaceStatus->mKarts[kartIndex].mLapTimes[5]);
                if (gRaceMultiConfig->mMode == 5) {
                    if (gRaceStatus->mUnk_000[kartIndex].mStatus == 4) {
                        rres_clearTotalRankPoints(kartIndex);
                    }
                }
                if (usesTeams != FALSE) {
                    if (rank == 1) {
                        winningTeamIndex = gRaceMultiConfig->mCurrentEntries[kartIndex].mPlayer.mTeamIndex;
                    }
                }
                raceSetup = gRaceMultiConfig;
            }
            break;
        }
        case MODE_BATTLE: {
            s32 e;
            if (usesTeams != FALSE) {
                kartIndex = 0;
                if (kartIndex < raceSetup->mKartCount) {
                    raceProgress = gRaceStatus;
                    do {
                        if (raceProgress->mUnk_000[kartIndex].mStatus == 1) {
                            if (usesTeams != FALSE) {
                                if (winningTeamIndex == -1) {
                                    raceSetup = gRaceMultiConfig;
                                    winningTeamIndex = raceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex;
                                }
                            }
                        }
                        kartIndex = (u16) (kartIndex + 1);
                    } while (kartIndex < raceSetup->mKartCount);
                }
            }
            for (kartIndex = 0; kartIndex < gRaceMultiConfig->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
                gRaceStatus->mUnk_000[kartIndex].mFlags |= 2;
                if (gRaceStatus->mUnk_000[kartIndex].mStatus == 1) {
                    if (usesTeams != FALSE) {
                        e = winningTeamIndex == gRaceMultiConfig->mCurrentEntries[kartIndex].mPlayer.mTeamIndex ? 1 : 0;
                    } else {
                        e = 1;
                    }
                    rres_setBattleResult(kartIndex, 1);
                } else {
                    if (usesTeams != FALSE) {
                        e = winningTeamIndex == gRaceMultiConfig->mCurrentEntries[kartIndex].mPlayer.mTeamIndex ? 1 : 0;
                    } else {
                        e = 0;
                    }
                    rres_setBattleResult(kartIndex, 0);
                    if (gRaceStatus->mUnk_000[kartIndex].mStatus == 0) {
                        gRaceStatus->mUnk_000[kartIndex].mStatus = 2;
                    }
                }
                func_02068640(driver_getById(kartIndex), e);
            }
            func_02110cc8(0);
            break;
        }
    }
    if (usesTeams != FALSE) {
        rres_setTeamsResult(winningTeamIndex);
    }
    gRaceStatus->mRaceDone = 1;
}

void rstat_203D078(void) {
    u32 kartIndex;
    if (mgcnt_hasMgEnded() != 0) {
        for (kartIndex = 0; kartIndex < gRaceMultiConfig->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
            RaceProgressKart *kart = OFFSET_PTR(RaceProgressKart, &gRaceStatus->mKarts[0], kartIndex * 0x8c);
            if (kart->mStatus == 0) {
                if (mgcnt_hasDriverWon(kartIndex) != 0) {
                    kart->mStatus = 1;
                } else {
                    kart->mStatus = 2;
                }
                kart->mFlags |= 2;
            }
        }
        return;
    }
    for (kartIndex = 0; kartIndex < gRaceMultiConfig->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
        if (mgcnt_isDriverDead(kartIndex) != FALSE) {
            RaceProgressKart *kart = OFFSET_PTR(RaceProgressKart, &gRaceStatus->mKarts[0], kartIndex * 0x8c);
            if (kart->mStatus == 0) {
                if (mgcnt_hasDriverWon(kartIndex) != 0) {
                    kart->mStatus = 1;
                } else {
                    kart->mStatus = 2;
                }
                kart->mFlags |= 2;
            }
        }
    }
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

static inline u16 func_0203cd14_inline(s32 v) {
    return (u16) v;
}

// TRUE once no kart is still racing in battle, until the race is marked done.
BOOL rstat_shouldStoreMgResults(void) {
    u32 kartIndex;
    s32 racingCount;
    BOOL noneRacing = TRUE;
    RaceProgress *raceProgress = gRaceStatus;
    if (raceProgress->mRaceDone != 0) {
        return FALSE;
    }
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        racingCount = 0;
        for (kartIndex = 0; kartIndex < gRaceMultiConfig->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
            if (raceProgress->mUnk_000[kartIndex].mStatus == 0) {
                racingCount++;
                if (racingCount > 0) {
                    noneRacing = FALSE;
                    break;
                }
            }
        }
        return noneRacing;
    }
    return FALSE;
}

void rstat_handleMissionMode(void) {
    BOOL endFound = FALSE;
    s32 endKind = 2;
    RaceSetup *raceSetup = gRaceMultiConfig;
    s32 entryIndex = raceSetup->mEntryIndex;
    u16 w;
    u32 kartOffset;
    RaceProgressKart *kart;
    BOOL hasEnded;
    if (entryIndex < 0) {
        return;
    }
    w = entryIndex;
    kartOffset = w * 0x8c;
    kart = OFFSET_PTR(RaceProgressKart, &gRaceStatus->mKarts[0], kartOffset);
    hasEnded = FALSE;
    switch (kart->mStatus) {
        case 1:
        case 2:
        case 3:
            hasEnded = TRUE;
            break;
    }
    if (hasEnded != FALSE) {
        if ((kart->mFlags & 0x10) != 0) {
            gRaceStatus->mFramesSinceFinish++;
            if (gRaceStatus->mFramesSinceFinish <= gRaceMultiConfig->mFinishWaitFrameCount) {
                return;
            }
            func_020688a0(driver_getById((u16) entryIndex));
            func_0207a828(func_0203cd14_inline(entryIndex));
            RequestRaceEndStemSet();
            func_02110cc8(0);
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                mgcnt_forceEnd();
            }
            kart = OFFSET_PTR(RaceProgressKart, &gRaceStatus->mKarts[0], kartOffset);
            kart->mFlags &= ~0x10;
        } else if ((kart->mFlags & 0x20) != 0) {
            if (func_0207a218() != 0) {
                gRaceStatus->mFramesSinceFailure++;
            }
            if (gRaceStatus->mFramesSinceFailure <= 0x3c) {
                return;
            }
            func_020688a0(driver_getById(entryIndex));
            func_0207a828((u16) entryIndex);
            func_02110cc8(0);
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                mgcnt_forceEnd();
            }
            kart = OFFSET_PTR(RaceProgressKart, &gRaceStatus->mKarts[0], kartOffset);
            kart->mFlags &= ~0x20;
        }
        return;
    }
    if ((raceSetup->mUnk_044 & 2) != 0) {
        if (driver_isPlayerHit() != FALSE) {
            endFound = TRUE;
        }
    }
    if (endFound == FALSE) {
        if ((gRaceMultiConfig->mUnk_044 & 4) != 0) {
            if (driver_isPlayerHittingWall() != 0) {
                endKind = 3;
                endFound = TRUE;
            }
        }
    }
    if (endFound == FALSE) {
        if ((gRaceMultiConfig->mUnk_044 & 8) != 0) {
            if (driver_isPlayerRespawning() != 0) {
                endFound = TRUE;
            }
        }
    }
    if (endFound == FALSE) {
        if (area_updateMissionRivalPassAreas() != 0) {
            endKind = 4;
            endFound = TRUE;
        }
    }
    if (endFound == FALSE) {
        return;
    }
    rstat_finishMission((u16) gRaceMultiConfig->mEntryIndex, endKind);
}

void rstat_loseMission(u16 kartIndex) {
    rstat_finishMission(kartIndex, 4);
}

void rstat_update(void) {
    u32 i;
    rstat_updateTime();
    if (gRaceMultiConfig->mMode == 5) {
        for (i = 0; i < gRaceMultiConfig->mKartCount; i = (u16) (i + 1)) {
            RaceProgressKart *kart = OFFSET_PTR(RaceProgressKart, &gRaceStatus->mKarts[0], i * 0x8c);
            if (kart->mFinishRequest != 0) {
                rstat_finishDriver(kart, kart->mFinishRequest == 1 ? 1 : 0);
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
                kart->mFinishRequest = 0;
            }
        }
    }
    if (gMapData->mCheckpoints != NULL) {
        rstat_handleCheckPoints();
    } else {
        BOOL t = FALSE;
        switch (gRaceMultiConfig->mRaceKind) {
            case RACE_KIND_DEMO:
            case 2:
            case RACE_KIND_STAFF_ROLL:
                t = TRUE;
                break;
            case RACE_KIND_NORMAL:
                if (rstat_calcUncontrollableRaceDisplayMode() != 0) {
                    t = TRUE;
                }
                break;
        }
        gRaceStatus->mUnk_4f0 = t;
    }
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        for (i = 0; i < gRaceMultiConfig->mKartCount; i = (u16) (i + 1)) {
            u16 *q;
            u8 standingRank = func_0203ca38_inline(i);
            q = OFFSET_PTR(u16, &gRaceStatus->mUnk_000[0].mUnk_50, i * 0x8c);
            *q = (*q & ~0xf) | (standingRank & 0xf);
        }
        for (i = 0; i < 8; i = (u16) (i + 1)) {
            gRaceStatus->mKartAtRank[i] = -1;
        }
        rstat_203D078();
        if (rstat_shouldStoreMgResults() != 0) {
            rstat_storeRaceResults();
        }
    }
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        rstat_handleMissionMode();
    }
    if (gRaceMultiConfig->mMode == MODE_TIME_ATTACK) {
        BOOL f = FALSE;
        switch (gRaceStatus->mUnk_000[0].mStatus) {
            case 1:
            case 2:
            case 3:
                f = TRUE;
                break;
        }
        if (f == FALSE) {
            return;
        }
        if (gRaceStatus->mRaceDone == 0) {
            gRaceStatus->mRaceDone = 1;
        }
        return;
    }
    if ((u32) gRaceStatus->mUnk_000[0].mFinishedCount < gRaceMultiConfig->mKartCount) {
        return;
    }
    if (gRaceStatus->mRaceDone != 0) {
        return;
    }
    rstat_storeRaceResults();
}
