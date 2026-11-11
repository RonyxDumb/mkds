#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/code_0203f334.h"
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

PointLink *GetKeyedPlacementBattlePointLink(u32 key) {
    return &gCourseMap->mBattlePointLinks[gCourseMap->mKeyedPlacements[gCourseMap->mKeyedPlacementIndexByKey[key]]
                                              .mPointIndex];
}

s32 ComputeDotOfPairsRounded(const UnkPair020b502c *first, const UnkPair020b502c *second) {
    return DOT2_FIXED12_ROUNDED(first->mFirst, second->mFirst, first->mSecond, second->mSecond);
}

s64 ComputeDotOfPairsRoundedS64(const UnkPair020b502c *first, const UnkPair020b502c *second) {
    return DOT2_FIXED12_ROUNDED(first->mFirst, second->mFirst, first->mSecond, second->mSecond);
}

static inline s32 IsEntryHumanGhostOrPeer(s8 entryIndex) {
    BOOL isHumanGhostOrPeer = FALSE;
    if (GetCurrentEntry(entryIndex)->mPlayer.mKind <= 3 &&
        ((1 << GetCurrentEntry(entryIndex)->mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
        isHumanGhostOrPeer = TRUE;
    }
    return isHumanGhostOrPeer;
}

BOOL IsEntryRaceEnded(void) {
    BOOL result = FALSE;
    BOOL ended;
    s8 entryIndex = gRaceSetup->mEntryIndex;

    if (entryIndex == -1 || IsEntryHumanGhostOrPeer(entryIndex) == 0) {
        result = TRUE;
    }
    if (result != FALSE) {
        return result;
    }
    switch (gRaceSetup->mMode) {
        case MODE_MISSION_RUN:
            ended = FALSE;
            switch (GetRaceProgressKart(entryIndex)->mStatus) {
                case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
                case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
                case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
                    ended = TRUE;
                    break;
            }
            if (ended == FALSE) {
                if (gRaceProgress->mEntryEndKind != 0) {
                    return result;
                }
            }
            return TRUE;
        case MODE_BATTLE:
            if (gRaceProgress->mRaceDone != 0) {
                result = TRUE;
            }
            return result;
        default:
            ended = FALSE;
            switch (GetRaceProgressKart(entryIndex)->mStatus) {
                case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
                case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
                case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
                    ended = TRUE;
                    break;
            }
            if (ended != FALSE) {
                result = TRUE;
            }
            return result;
    }
}

void ComputeGrandPrixScoreTerms(RaceProgressScoreTerms *scoreTerms, s32 kartIndex) {
    EntryKartCounters *entryKartCounters = GetEntryKartCounters();
    RaceProgress *raceProgress = gRaceProgress;
    RaceProgressKart *raceProgressKart = &raceProgress->mKarts[kartIndex];
    RankTimeGp *rankTimeGpFile = raceProgress->mRankTimeGpFile;

    if (raceProgress->mHeader.mRankTime == 0) {
        scoreTerms->mTimeRemainingScore = 0;
    } else {
        scoreTerms->mTimeRemainingScore =
            (FX_Div(rankTimeGpFile->mTimeRemainingWeight *
                        (raceProgress->mHeader.mRankTime - raceProgress->mHeader.mElapsedFrames),
                    raceProgress->mHeader.mRankTime) +
             0x800) >>
            12;
    }
    scoreTerms->mFirstPlaceScore =
        (rankTimeGpFile->mFirstPlaceWeight *
         FX_Div(raceProgressKart->mFirstPlaceFrames << 12, gRaceProgress->mHeader.mRankTime << 12)) >>
        12;
    if (entryKartCounters->mRaceStartBoosted != 0) {
        scoreTerms->mRaceStartBoostScore = rankTimeGpFile->mRaceStartBoostPoints;
    } else {
        scoreTerms->mRaceStartBoostScore = 0;
    }
    scoreTerms->mMiniTurboScore = rankTimeGpFile->mMiniTurboPoints * entryKartCounters->mMiniTurboCount;
    scoreTerms->mItemHitScore = rankTimeGpFile->mItemHitPoints * entryKartCounters->mUnk_08;
    scoreTerms->mSurfaceScore =
        -((u32) (entryKartCounters->mUnk_0c * FX_Inv(rankTimeGpFile->mSurfaceDivisor << 12)) >> 12);
    scoreTerms->mCourseContactScore = entryKartCounters->mUnk_10 * -rankTimeGpFile->mCourseContactPoints;
    scoreTerms->mMapObjectHitScore = entryKartCounters->mMapObjectHitCount * -rankTimeGpFile->mMapObjectHitPoints;
    scoreTerms->mRespawnScore = entryKartCounters->mRespawnCount * -rankTimeGpFile->mRespawnPoints;
}

// Sum of the nine score terms (also saved in gRaceProgress.mUnk_500), clamped to -9999..9999; 0 unless kart a is the
// local entry in Grand Prix or Mission Run.
s16 ComputeRaceProgressKartScore(s32 kartIndex) {
    RaceProgressScoreTerms scoreTerms;
    EntryKartCounters *entryKartCounters;
    RaceSetup *raceSetup;
    RaceProgress *raceProgress = gRaceProgress;
    RaceProgressScoreTerms *savedScoreTerms = &raceProgress->mScoreTerms;
    s32 score;
    MissionSettings *missionSettings;

    if ((raceProgress->mKarts[kartIndex].mFlags & RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY) == 0) {
        return 0;
    }
    raceSetup = gRaceSetup;
    switch (raceSetup->mMode) {
        case MODE_GRAND_PRIX:
            ComputeGrandPrixScoreTerms(&scoreTerms, kartIndex);
            break;
        case MODE_MISSION_RUN:
            missionSettings = &raceSetup->mUnk_28_view;
            entryKartCounters = GetEntryKartCounters();
            scoreTerms.mTimeRemainingScore =
                FX_Div(missionSettings->mTimeScoreWeight *
                               (missionSettings->mTimeScoreFrameCount - raceProgress->mHeader.mElapsedFrames)
                           << 12,
                       0x3e8000) >>
                12;
            scoreTerms.mFirstPlaceScore = 0;
            scoreTerms.mRaceStartBoostScore = 0;
            scoreTerms.mMiniTurboScore = 0;
            scoreTerms.mItemHitScore = entryKartCounters->mUnk_08 * -5;
            scoreTerms.mSurfaceScore = 0;
            scoreTerms.mCourseContactScore = entryKartCounters->mUnk_10 * -5;
            scoreTerms.mMapObjectHitScore = entryKartCounters->mMapObjectHitCount * -10;
            scoreTerms.mRespawnScore = entryKartCounters->mRespawnCount * -20;
            break;
        default:
            return 0;
    }
    *savedScoreTerms = scoreTerms;
    score = savedScoreTerms->mTimeRemainingScore + savedScoreTerms->mFirstPlaceScore +
            savedScoreTerms->mRaceStartBoostScore + savedScoreTerms->mMiniTurboScore + savedScoreTerms->mItemHitScore +
            savedScoreTerms->mSurfaceScore + savedScoreTerms->mCourseContactScore +
            savedScoreTerms->mMapObjectHitScore + savedScoreTerms->mRespawnScore;
    if (score < -9999) {
        score = -9999;
    }
    if (score > 9999) {
        score = 9999;
    }
    return score;
}

void InitRaceProgressKart(RaceProgressKart *raceProgressKart, s32 kartIndex) {
    s32 lapIndex;
    MinuteSecondMillisecondTime *lapTime;
    CourseMapRoute *route;
    s32 firstEntry;

    if (gCourseMap->mCheckpoints == NULL) {
        raceProgressKart->mRoute = 0;
        raceProgressKart->mCheckpoint = 0;
    } else {
        raceProgressKart->mRoute = gCourseMap->mCheckpointRoutes->mPreviousRoutes[0];
        route = &gCourseMap->mCheckpointRoutes[raceProgressKart->mRoute];
        firstEntry = gCourseMap->mCheckpointRoutes[raceProgressKart->mRoute].mFirstEntry;
        raceProgressKart->mCheckpoint = firstEntry + route->mEntryCount - 1;
    }
    raceProgressKart->mLapFrames = 0;
    raceProgressKart->mUnk_08 = 0;
    raceProgressKart->mFinishTimeMs = 0;
    raceProgressKart->mHighestLap = 1;
    raceProgressKart->mLap = 0;
    raceProgressKart->mStatus = RACE_PROGRESS_KART_STATUS_RACING;
    raceProgressKart->mFlags = 0;
    raceProgressKart->mInOrderCheckpointNumber = gCourseMap->mNumberedCheckpointCount - 1;
    raceProgressKart->mCheckpointNumber = gCourseMap->mNumberedCheckpointCount - 1;
    raceProgressKart->mRankIndexRequestBits =
        (raceProgressKart->mRankIndexRequestBits & ~0xf0) | (((u16) kartIndex & 0xf) << 4);
    raceProgressKart->mRaceProgress = 0;
    raceProgressKart->mLapProgress = 0;
    raceProgressKart->mScore = 0;
    raceProgressKart->mFirstPlaceFrames = 0;
    raceProgressKart->mCheckpointProgress = 0;
    raceProgressKart->mRankIndexRequestBits = raceProgressKart->mRankIndexRequestBits & ~0x300;
    lapTime = raceProgressKart->mLapTimes;
    for (lapIndex = 0; lapIndex < 5; lapIndex++) {
        ComputeRaceTime(&lapTime->mMinute, &lapTime->mSecond, &lapTime->mMillisecond, 0,
                        gRaceProgress->mHeader.mElapsedFrames);
        lapTime++;
    }
    ComputeRaceTime(&raceProgressKart->mLapTimes[5].mMinute, &raceProgressKart->mLapTimes[5].mSecond,
                    &raceProgressKart->mLapTimes[5].mMillisecond, 0, gRaceProgress->mHeader.mElapsedFrames);
    if (kartIndex == gRaceSetup->mEntryIndex) {
        raceProgressKart->mFlags = raceProgressKart->mFlags | RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY;
    }
    raceProgressKart->mRankIndexRequestBits =
        (raceProgressKart->mRankIndexRequestBits & ~0xf) | ((u16) (kartIndex + 1) & 0xf);
}

static inline u32 RaceProgressGetWorkConnectionMode(ConnectionWork *connectionWork) {
    return connectionWork == NULL ? 0 : connectionWork->mConnectionMode;
}

static inline void ResetRaceProgressClock(RaceProgressHeader *raceProgressHeader) {
    raceProgressHeader->mElapsedFrames = 0;
    raceProgressHeader->mClockEnabled = 0;
}

static inline void RaceProgressComputeTimeFromFrames(MinuteSecondMillisecondTime *time, u32 frames) {
    ComputeRaceTime(&time->mMinute, &time->mSecond, &time->mMillisecond, 0, frames);
}

static inline void RaceProgressInitRandomState(RandomState64 *randomState64, u32 seed) {
    randomState64->mValue = seed;
    randomState64->mMultiplier = 0x5d588b656c078965;
    randomState64->mIncrement = 0x269ec3;
}

static inline s32 Fixed12AddOneThenDivideByIntOrZero(s32 value, s32 divisor) {
    return divisor == 0 ? 0 : FX_Div(value + 0x1000, divisor << 12);
}

static inline u32 RaceProgressNextRandomBelow(RandomState64 *randomState64, u32 limit) {
    randomState64->mValue = (s64) randomState64->mMultiplier * (s64) randomState64->mValue + randomState64->mIncrement;
    return ((s64) (randomState64->mValue >> 32) * limit) >> 32;
}

void InitRaceProgress(void) {
    BOOL entryRaceEnded;
    s32 index;
    u32 seed;
    s32 checkpointNumber;
    u64 tickSeed1;
    u64 tickSeed2;
    u64 tickSeed3;
    u16 routeIndex;
    u16 entryInRoute;
    u16 checkpointIndex;
    s32 value;
    ConnectionWork *connectionWork;
    CourseMapRoute *route;
    CourseMapCheckpoint *checkpoint;

    ResetRaceProgressClock(&gRaceProgress->mHeader);
    RaceProgressComputeTimeFromFrames(&gRaceProgress->mHeader.mClockTime, gRaceProgress->mHeader.mElapsedFrames);
    entryRaceEnded = FALSE;
    gRaceProgress->mHeader.mFinishedCount = 0;
    gRaceProgress->mHeader.mRemovedCount = 0;
    gRaceProgress->mRaceDone = 0;
    switch (gRaceSetup->mRaceKind) {
        case RACE_KIND_DEMO:
        case RACE_KIND_REPLAY:
        case RACE_KIND_STAFF_ROLL:
            entryRaceEnded = TRUE;
            break;
        case RACE_KIND_NORMAL:
            if (IsEntryRaceEnded() != 0) {
                entryRaceEnded = TRUE;
            }
            break;
    }
    gRaceProgress->mEntryRaceEnded = entryRaceEnded;
    gRaceProgress->mEntryEndKind = 6;
    gRaceProgress->mTimeCountsDown = FALSE;
    gRaceProgress->mTimeLimitFrameCount = 0;
    switch (gRaceSetup->mMode) {
        case MODE_MISSION_RUN:
            if (gRaceSetup->mMissionKind == 6) {
                gRaceProgress->mTimeCountsDown = FALSE;
            } else {
                gRaceProgress->mTimeCountsDown = TRUE;
            }
            gRaceProgress->mTimeLimitFrameCount = gRaceSetup->mMissionTimeLimitFrameCount;
            break;
        case MODE_BATTLE:
            if (gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
                gRaceProgress->mTimeCountsDown = TRUE;
                gRaceProgress->mTimeLimitFrameCount = gCourseMap->mSettings->mLapCountOrBattleSeconds * 0x3c;
            }
            break;
    }
    for (index = 0; index < 8; index++) {
        InitRaceProgressKart(&gRaceProgress->mKarts[index], index);
        gRaceProgress->mKartAtRank[index] = -1;
    }
    switch (gRaceSetup->mRaceKind) {
        case RACE_KIND_REPLAY:
            seed = gRaceSetup->mSeed;
            break;
        case RACE_KIND_AWARD:
            seed = 0xc240793;
            break;
        case RACE_KIND_STAFF_ROLL:
            seed = 0x71abc95;
            break;
        default:
            switch (gRaceSetup->mMode) {
                case MODE_TIME_ATTACK:
                    seed = 0x34a8f71;
                    break;
                case MODE_MISSION_RUN:
                    seed = 0x158b76f;
                    break;
                case MODE_WIFI:
                    seed = 0x5b12f73;
                    break;
                default:
                    connectionWork = gConnectionWork;
                    value = 0;
                    if (RaceProgressGetWorkConnectionMode(connectionWork) != 0) {
                        if (connectionWork->mState != 0xd) {
                            value = 1;
                        }
                    }
                    if (value != 0) {
                        seed = connectionWork->mRaceSeed;
                    } else {
                        tickSeed1 = OS_GetTick();
                        seed = (tickSeed1 << 16) + OS_GetTick();
                    }
                    break;
            }
            break;
    }
    RaceProgressInitRandomState(&gRaceProgress->mRandom, seed);
    gRaceProgress->mSeed = seed;
    gRaceSetup->mNextHeader.mSeed = seed;
    tickSeed1 = OS_GetTick();
    tickSeed2 = OS_GetTick();
    tickSeed3 = OS_GetTick();
    RaceProgressInitRandomState(&gRaceProgress->mLocalRandom, tickSeed1 + ((tickSeed2 << 24) + (tickSeed3 << 8)));
    RaceProgressInitRandomState(&gRaceProgress->mFixedSeedRandom, 0xa094a2f);
    if (gRaceSetup->mMode == MODE_BATTLE) {
        ShuffleCourseMapRespawnSlots(&gRaceProgress->mRandom);
    }
    gRaceProgress->mCameraChainEnded = 0;
    gRaceProgress->mLapProgressScale = FX_Inv((gCourseMap->mLapProgressBaseMax + 1) << 12);
    gRaceProgress->mRaceProgressScale = FX_Inv(GetLapCount() << 12);
    for (index = 0; index < gCourseMap->mNumberedCheckpointCount + 1; index++) {
        checkpointNumber = index % (gCourseMap->mNumberedCheckpointCount + 1);
        if (checkpointNumber == gCourseMap->mNumberedCheckpointCount) {
            gRaceProgress->mCheckpointLapProgress[index] = 0x1000;
        } else {
            for (routeIndex = 0; routeIndex < gCourseMap->mCheckpointRouteCount; routeIndex++) {
                route = &gCourseMap->mCheckpointRoutes[routeIndex];
                for (entryInRoute = 0; entryInRoute < route->mEntryCount; entryInRoute++) {
                    checkpointIndex = entryInRoute + route->mFirstEntry;
                    checkpoint = &gCourseMap->mCheckpoints[checkpointIndex];
                    if (checkpoint->mNumber == checkpointNumber) {
                        value = Fixed12AddOneThenDivideByIntOrZero((checkpointIndex - route->mFirstEntry) << 12,
                                                                   route->mEntryCount);
                        value += route->mLapProgressBase << 12;
                        gRaceProgress->mCheckpointLapProgress[index] =
                            MUL_FIXED12_ROUNDED(value, gRaceProgress->mLapProgressScale);
                    }
                }
            }
        }
    }
    if (gRaceSetup->mMode != MODE_BATTLE) {
        gRaceProgress->mStartPlacementOffset = 0;
        return;
    }
    gRaceProgress->mStartPlacementOffset = RaceProgressNextRandomBelow(&gRaceProgress->mRandom, 8);
}
