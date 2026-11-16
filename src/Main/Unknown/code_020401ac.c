#include "Main/Unknown/code_020401ac.h"
#include "Main/Race/RaceProgress.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_02042064.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"
#include "code_0200f5ac.h"
#include "Main/Unknown/code_02077bc0.h"

PointLink *mdat_getNextMgEnemyPointForWarpPipe(u32 key) {
    return &gMapData
                ->mBattlePointLinks[gMapData->mKeyedPlacements[gMapData->mKeyedPlacementIndexByKey[key]].field18];
}

s32 rstat_rotCompare(const UnkPair020b502c *first, const UnkPair020b502c *second) {
    return ((s64) first->field0 * second->field0 + (s64) first->field4 * second->field4 + 0x800) >> 12;
}

s64 rstat_getProgressByTrigPos(const UnkPair020b502c *first, const UnkPair020b502c *second) {
    return ((s64) first->field0 * second->field0 + (s64) first->field4 * second->field4 + 0x800) >> 12;
}

static inline s32 func_02040bc0_inline(s8 entryIndex) {
    BOOL f = FALSE;
    if (gRaceMultiConfig->mCurrentEntries[(u16) entryIndex].mPlayer.mKind <= 3 &&
        ((1 << gRaceMultiConfig->mCurrentEntries[(u16) entryIndex].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
        f = TRUE;
    }
    return f;
}

BOOL rstat_calcUncontrollableRaceDisplayMode(void) {
    BOOL result = FALSE;
    BOOL ended;
    s8 entryIndex = gRaceMultiConfig->mEntryIndex;

    if (entryIndex == -1 || func_02040bc0_inline(entryIndex) == 0) {
        result = TRUE;
    }
    if (result != FALSE) {
        return result;
    }
    switch (gRaceMultiConfig->mMode) {
        case MODE_MISSION_RUN:
            ended = FALSE;
            switch (gRaceStatus->field0[(u16) entryIndex].mStatus) {
                case 1:
                case 2:
                case 3:
                    ended = TRUE;
                    break;
            }
            if (ended == FALSE) {
                if (gRaceStatus->mEntryEndKind != 0) {
                    return result;
                }
            }
            return TRUE;
        case MODE_BATTLE:
            if (gRaceStatus->mRaceDone != 0) {
                result = TRUE;
            }
            return result;
        default:
            ended = FALSE;
            switch (gRaceStatus->field0[(u16) entryIndex].mStatus) {
                case 1:
                case 2:
                case 3:
                    ended = TRUE;
                    break;
            }
            if (ended != FALSE) {
                result = TRUE;
            }
            return result;
    }
}

void rstat_calculateSkillRankPointsGp(RaceProgressScoreTerms *scoreTerms, s32 kartIndex) {
    EntryKartCounters *entryKartCounters = driver_getPlayerStatistics();
    RaceProgress *raceProgress = gRaceStatus;
    RaceProgressKart *raceProgressKart = &raceProgress->mKarts[kartIndex];
    RankTimeGp *rankTimeGpFile = raceProgress->mRankTimeGpFile;

    if (raceProgress->field0[0].mRankTime == 0) {
        scoreTerms->field0 = 0;
    } else {
        scoreTerms->field0 = (FX_Div(rankTimeGpFile->fieldA * (raceProgress->field0[0].mRankTime -
                                                                 raceProgress->field0[0].mElapsedFrames),
                                      raceProgress->field0[0].mRankTime) +
                               0x800) >>
                              12;
    }
    scoreTerms->field4 = (rankTimeGpFile->fieldC * FX_Div(raceProgressKart->mFirstPlaceFrames << 12,
                                                            gRaceStatus->field0[0].mRankTime << 12)) >>
                          12;
    if (entryKartCounters->field0 != 0) {
        scoreTerms->field8 = rankTimeGpFile->fieldE;
    } else {
        scoreTerms->field8 = 0;
    }
    scoreTerms->fieldC = rankTimeGpFile->field10 * entryKartCounters->field4;
    scoreTerms->field10 = rankTimeGpFile->field12 * entryKartCounters->field8;
    scoreTerms->field14 = -((u32) (entryKartCounters->fieldC * FX_Inv(rankTimeGpFile->field14 << 12)) >> 12);
    scoreTerms->field18 = entryKartCounters->field10 * -rankTimeGpFile->field16;
    scoreTerms->field1C = entryKartCounters->field14 * -rankTimeGpFile->field18;
    scoreTerms->field20 = entryKartCounters->field18 * -rankTimeGpFile->field1A;
}

// Sum of the nine score terms (also saved in gRaceStatus->field500), clamped to -9999..9999; 0 unless kart a is the
// local entry in Grand Prix or Mission Run.
s16 rstat_calculateSkillRankPoints(s32 kartIndex) {
    RaceProgressScoreTerms scoreTerms;
    EntryKartCounters *entryKartCounters;
    RaceSetup *raceSetup;
    RaceProgress *raceProgress = gRaceStatus;
    RaceProgressScoreTerms *savedScoreTerms = &raceProgress->mScoreTerms;
    s32 score;
    u8 *missionSettings;

    if ((raceProgress->field0[kartIndex].mFlags & 1) == 0) {
        return 0;
    }
    raceSetup = gRaceMultiConfig;
    switch (raceSetup->mMode) {
        case MODE_GRAND_PRIX:
            rstat_calculateSkillRankPointsGp(&scoreTerms, kartIndex);
            break;
        case MODE_MISSION_RUN:
            missionSettings = (u8 *) raceSetup + 0x28;
            entryKartCounters = driver_getPlayerStatistics();
            scoreTerms.field0 = FX_Div(*(s16 *) (missionSettings + 4) * (*(u16 *) (missionSettings + 2) -
                                                                          raceProgress->field0[0].mElapsedFrames)
                                            << 12,
                                        0x3e8000) >>
                                 12;
            scoreTerms.field4 = 0;
            scoreTerms.field8 = 0;
            scoreTerms.fieldC = 0;
            scoreTerms.field10 = entryKartCounters->field8 * -5;
            scoreTerms.field14 = 0;
            scoreTerms.field18 = entryKartCounters->field10 * -5;
            scoreTerms.field1C = entryKartCounters->field14 * -10;
            scoreTerms.field20 = entryKartCounters->field18 * -20;
            break;
        default:
            return 0;
    }
    *savedScoreTerms = scoreTerms;
    score = savedScoreTerms->field0 + savedScoreTerms->field4 + savedScoreTerms->field8 + savedScoreTerms->fieldC +
            savedScoreTerms->field10 + savedScoreTerms->field14 + savedScoreTerms->field18 + savedScoreTerms->field1C +
            savedScoreTerms->field20;
    if (score < -9999) {
        score = -9999;
    }
    if (score > 9999) {
        score = 9999;
    }
    return score;
}

void rstat_initDriverStatus(RaceProgressKart *raceProgressKart, s32 kartIndex) {
    s32 i;
    Unk0217aa1c_144_00 *lapTime;
    CourseMapRoute *route;
    s32 firstEntry;

    if (gMapData->mCheckpoints == NULL) {
        raceProgressKart->mRoute = 0;
        raceProgressKart->mCheckpoint = 0;
    } else {
        raceProgressKart->mRoute = gMapData->mCheckpointRoutes->mPreviousRoutes[0];
        route = &gMapData->mCheckpointRoutes[raceProgressKart->mRoute];
        firstEntry = gMapData->mCheckpointRoutes[raceProgressKart->mRoute].mFirstEntry;
        raceProgressKart->mCheckpoint = firstEntry + route->mEntryCount - 1;
    }
    raceProgressKart->mLapFrames = 0;
    raceProgressKart->field8 = 0;
    raceProgressKart->mFinishTimeMs = 0;
    raceProgressKart->mHighestLap = 1;
    raceProgressKart->mLap = 0;
    raceProgressKart->mStatus = 0;
    raceProgressKart->mFlags = 0;
    raceProgressKart->mInOrderCheckpointNumber = gMapData->mNumberedCheckpointCount - 1;
    raceProgressKart->mCheckpointNumber = gMapData->mNumberedCheckpointCount - 1;
    raceProgressKart->field3C = (raceProgressKart->field3C & ~0xf0) | (((u16) kartIndex & 0xf) << 4);
    raceProgressKart->mRaceProgress = 0;
    raceProgressKart->mLapProgress = 0;
    raceProgressKart->mScore = 0;
    raceProgressKart->mFirstPlaceFrames = 0;
    raceProgressKart->mCheckpointProgress = 0;
    raceProgressKart->field3C = raceProgressKart->field3C & ~0x300;
    lapTime = raceProgressKart->mLapTimes;
    for (i = 0; i < 5; i++) {
        rstat_calculateTime(&lapTime->field2, &lapTime->field3, &lapTime->field0, 0,
                        gRaceStatus->field0[0].mElapsedFrames);
        lapTime++;
    }
    rstat_calculateTime(&raceProgressKart->mLapTimes[5].field2, &raceProgressKart->mLapTimes[5].field3,
                    &raceProgressKart->mLapTimes[5].field0, 0, gRaceStatus->field0[0].mElapsedFrames);
    if (kartIndex == gRaceMultiConfig->mEntryIndex) {
        raceProgressKart->mFlags = raceProgressKart->mFlags | 1;
    }
    raceProgressKart->field3C = (raceProgressKart->field3C & ~0xf) | ((u16) (kartIndex + 1) & 0xf);
}

static inline u32 func_020401ac_inline(ConnectionWork *p) {
    return p == NULL ? 0 : p->field0;
}

static inline void func_020401ac_inline2(Unk0217561c_000 *q) {
    q->mElapsedFrames = 0;
    q->mClockEnabled = 0;
}

static inline void func_020401ac_inline3(Unk0217aa1c_144_00 *time, u32 frames) {
    rstat_calculateTime(&time->field2, &time->field3, &time->field0, 0, frames);
}

static inline void func_020401ac_inline4(RandomState64 *randomState64, u32 seed) {
    randomState64->mValue = seed;
    randomState64->mMultiplier = 0x5d588b656c078965;
    randomState64->mIncrement = 0x269ec3;
}

static inline s32 func_020401ac_inline5(s32 a, s32 b) {
    return b == 0 ? 0 : FX_Div(a + 0x1000, b << 12);
}

static inline u32 func_020401ac_inline6(RandomState64 *randomState64, u32 limit) {
    randomState64->mValue = (s64) randomState64->mMultiplier * (s64) randomState64->mValue + randomState64->mIncrement;
    return ((s64) (randomState64->mValue >> 32) * limit) >> 32;
}

void rstat_init2(void) {
    BOOL f;
    s32 i;
    u32 seed;
    s32 checkpointNumber;
    u64 a;
    u64 c;
    u64 d;
    u16 routeIndex;
    u16 entryInRoute;
    u16 checkpointIndex;
    s32 v;
    ConnectionWork *p;
    CourseMapRoute *route;
    CourseMapCheckpoint *checkpoint;

    func_020401ac_inline2(&gRaceStatus->field0[0]);
    func_020401ac_inline3(&gRaceStatus->field0[0].mUnk_08_view, gRaceStatus->field0[0].mElapsedFrames);
    f = FALSE;
    gRaceStatus->field0[0].mFinishedCount = 0;
    gRaceStatus->field0[0].mRemovedCount = 0;
    gRaceStatus->mRaceDone = 0;
    switch (gRaceMultiConfig->mRaceKind) {
        case RACE_KIND_DEMO:
        case 2:
        case RACE_KIND_STAFF_ROLL:
            f = TRUE;
            break;
        case RACE_KIND_NORMAL:
            if (rstat_calcUncontrollableRaceDisplayMode() != 0) {
                f = TRUE;
            }
            break;
    }
    gRaceStatus->field4F0 = f;
    gRaceStatus->mEntryEndKind = 6;
    gRaceStatus->mTimeCountsDown = FALSE;
    gRaceStatus->mTimeLimitFrameCount = 0;
    switch (gRaceMultiConfig->mMode) {
        case MODE_MISSION_RUN:
            if (gRaceMultiConfig->mMissionKind == 6) {
                gRaceStatus->mTimeCountsDown = FALSE;
            } else {
                gRaceStatus->mTimeCountsDown = TRUE;
            }
            gRaceStatus->mTimeLimitFrameCount = gRaceMultiConfig->mMissionTimeLimitFrameCount;
            break;
        case MODE_BATTLE:
            if (gRaceMultiConfig->mBattleKind == BATTLE_KIND_SHINE) {
                gRaceStatus->mTimeCountsDown = TRUE;
                gRaceStatus->mTimeLimitFrameCount = gMapData->mSettings->mLapCountOrBattleSeconds * 0x3c;
            }
            break;
    }
    for (i = 0; i < 8; i++) {
        rstat_initDriverStatus(&gRaceStatus->mKarts[i], i);
        gRaceStatus->mKartAtRank[i] = -1;
    }
    switch (gRaceMultiConfig->mRaceKind) {
        case 2:
            seed = gRaceMultiConfig->field5C;
            break;
        case RACE_KIND_AWARD:
            seed = 0xc240793;
            break;
        case RACE_KIND_STAFF_ROLL:
            seed = 0x71abc95;
            break;
        default:
            switch (gRaceMultiConfig->mMode) {
                case MODE_TIME_ATTACK:
                    seed = 0x34a8f71;
                    break;
                case MODE_MISSION_RUN:
                    seed = 0x158b76f;
                    break;
                case 5:
                    seed = 0x5b12f73;
                    break;
                default:
                    p = gStruct217AA00;
                    v = 0;
                    if (func_020401ac_inline(p) != 0) {
                        if (p->field4 != 0xd) {
                            v = 1;
                        }
                    }
                    if (v != 0) {
                        seed = p->field1EB0;
                    } else {
                        a = OS_GetTick();
                        seed = (a << 16) + OS_GetTick();
                    }
                    break;
            }
            break;
    }
    func_020401ac_inline4(&gRaceStatus->mRandom, seed);
    gRaceStatus->mSeed = seed;
    gRaceMultiConfig->mNextHeader.field5C = seed;
    a = OS_GetTick();
    c = OS_GetTick();
    d = OS_GetTick();
    func_020401ac_inline4(&gRaceStatus->mLocalRandom, a + ((c << 24) + (d << 8)));
    func_020401ac_inline4(&gRaceStatus->mFixedSeedRandom, 0xa094a2f);
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        mdat_shuffleRespawns(&gRaceStatus->mRandom);
    }
    gRaceStatus->mCameraChainEnded = 0;
    gRaceStatus->mLapProgressScale = FX_Inv((gMapData->mLapProgressBaseMax + 1) << 12);
    gRaceStatus->mRaceProgressScale = FX_Inv(rconf_getLapCount() << 12);
    for (i = 0; i < gMapData->mNumberedCheckpointCount + 1; i++) {
        checkpointNumber = i % (gMapData->mNumberedCheckpointCount + 1);
        if (checkpointNumber == gMapData->mNumberedCheckpointCount) {
            gRaceStatus->mCheckpointLapProgress[i] = 0x1000;
        } else {
            for (routeIndex = 0; routeIndex < gMapData->mCheckpointRouteCount; routeIndex++) {
                route = &gMapData->mCheckpointRoutes[routeIndex];
                for (entryInRoute = 0; entryInRoute < route->mEntryCount; entryInRoute++) {
                    checkpointIndex = entryInRoute + route->mFirstEntry;
                    checkpoint = &gMapData->mCheckpoints[checkpointIndex];
                    if (checkpoint->mNumber == checkpointNumber) {
                        v = func_020401ac_inline5((checkpointIndex - route->mFirstEntry) << 12, route->mEntryCount);
                        v += route->mLapProgressBase << 12;
                        gRaceStatus->mCheckpointLapProgress[i] =
                            ((s64) v * gRaceStatus->mLapProgressScale + 0x800) >> 12;
                    }
                }
            }
        }
    }
    if (gRaceMultiConfig->mMode != MODE_BATTLE) {
        gRaceStatus->mStartPlacementOffset = 0;
        return;
    }
    gRaceStatus->mStartPlacementOffset = func_020401ac_inline6(&gRaceStatus->mRandom, 8);
}
