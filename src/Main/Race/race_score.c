#include "Main/Race/race_score.h"
#include "Main/Race/race_end_condition.h"
#include "Main/Race/race_checkpoint_progress.h"
#include "Main/Course/course_map_sections.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Kart/kart_drift.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "fixed_vector_math.h"
#include "tick_counter.h"
#include "Main/Kart/karts.h"
#include "Main/System/init_after_startup.h"

PointLink *GetKeyedPlacementBattlePointLink(u32 key) {
    return &g_GlobalPE->mBattlePointLinks[g_GlobalPE->mKeyedPlacements[g_GlobalPE->mKeyedPlacementIndexByKey[key]]
                                              .mPointIndex];
}

s32 ComputeDotOfPairsRounded(const IntPair *first, const IntPair *second) {
    return DOT2_FIXED12_ROUNDED(first->mFirst, second->mFirst, first->mSecond, second->mSecond);
}

s64 ComputeDotOfPairsRoundedS64(const IntPair *first, const IntPair *second) {
    return DOT2_FIXED12_ROUNDED(first->mFirst, second->mFirst, first->mSecond, second->mSecond);
}

static inline s32 IsEntryHumanGhostOrPeer(s8 entryIndex) {
    BOOL isHumanGhostOrPeer = FALSE;
    if (GetCurrentEntry(entryIndex)->mPlayer.mKind <= PLAYER_KIND_PEER &&
        ((1 << GetCurrentEntry(entryIndex)->mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
        isHumanGhostOrPeer = TRUE;
    }
    return isHumanGhostOrPeer;
}

BOOL IsEntryRaceEnded(void) {
    BOOL result = FALSE;
    BOOL ended;
    s8 entryIndex = g_GlobalCO->mEntryIndex;

    if (entryIndex == -1 || IsEntryHumanGhostOrPeer(entryIndex) == 0) {
        result = TRUE;
    }
    if (result != FALSE) {
        return result;
    }
    switch (g_GlobalCO->mMode) {
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
                if (g_GlobalMV->mEntryEndKind != 0) {
                    return result;
                }
            }
            return TRUE;
        case MODE_BATTLE:
            if (g_GlobalMV->mRaceDone != 0) {
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

void MaybeComputeGPScore(RaceProgressScoreTerms *scoreTerms, s32 kartIndex) {
    EntryKartCounters *entryKartCounters = GetGlobalRK();
    RaceProgress *raceProgress = g_GlobalMV;
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
         FX_Div(TO_FIXED12(raceProgressKart->mFirstPlaceFrames), TO_FIXED12(g_GlobalMV->mHeader.mRankTime))) >>
        12;
    if (entryKartCounters->mRaceStartBoosted != 0) {
        scoreTerms->mRaceStartBoostScore = rankTimeGpFile->mRaceStartBoostPoints;
    } else {
        scoreTerms->mRaceStartBoostScore = 0;
    }
    scoreTerms->mMiniTurboScore = rankTimeGpFile->mMiniTurboPoints * entryKartCounters->mMiniTurboCount;
    scoreTerms->mItemHitScore = rankTimeGpFile->mItemHitPoints * entryKartCounters->mItemHitCount;
    scoreTerms->mSurfaceScore =
        -((u32) (entryKartCounters->mSurfaceCount * FX_Inv(TO_FIXED12(rankTimeGpFile->mSurfaceDivisor))) >> 12);
    scoreTerms->mCourseContactScore = entryKartCounters->mCourseContactCount * -rankTimeGpFile->mCourseContactPoints;
    scoreTerms->mMapObjectHitScore = entryKartCounters->mMapObjectHitCount * -rankTimeGpFile->mMapObjectHitPoints;
    scoreTerms->mRespawnScore = entryKartCounters->mRespawnCount * -rankTimeGpFile->mRespawnPoints;
}

// Sum of the nine score terms (also saved in g_GlobalMV.mScoreTerms), clamped to -9999..9999; 0 unless kart a is the
// local entry in Grand Prix or Mission Run.
s16 MaybeComputeRacerScore(s32 kartIndex) {
    RaceProgressScoreTerms scoreTerms;
    EntryKartCounters *entryKartCounters;
    RaceSetup *raceSetup;
    RaceProgress *raceProgress = g_GlobalMV;
    RaceProgressScoreTerms *savedScoreTerms = &raceProgress->mScoreTerms;
    s32 score;
    MissionSettings *missionSettings;

    if ((raceProgress->mKarts[kartIndex].mFlags & RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY) == 0) {
        return 0;
    }
    raceSetup = g_GlobalCO;
    switch (raceSetup->mMode) {
        case MODE_GRAND_PRIX:
            MaybeComputeGPScore(&scoreTerms, kartIndex);
            break;
        case MODE_MISSION_RUN:
            missionSettings = &raceSetup->mMissionSettings;
            entryKartCounters = GetGlobalRK();
            scoreTerms.mTimeRemainingScore =
                FX_Div(missionSettings->mTimeScoreWeight *
                               (missionSettings->mTimeScoreFrameCount - raceProgress->mHeader.mElapsedFrames)
                           << 12,
                       0x3e8000) >>
                12;
            scoreTerms.mFirstPlaceScore = 0;
            scoreTerms.mRaceStartBoostScore = 0;
            scoreTerms.mMiniTurboScore = 0;
            scoreTerms.mItemHitScore = entryKartCounters->mItemHitCount * -5;
            scoreTerms.mSurfaceScore = 0;
            scoreTerms.mCourseContactScore = entryKartCounters->mCourseContactCount * -5;
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

void StructRC_SomeFn_2(RaceProgressKart *raceProgressKart, s32 kartIndex) {
    s32 lapIndex;
    MinuteSecondMillisecondTime *lapTime;
    CourseMapRoute *route;
    s32 firstEntry;

    if (g_GlobalPE->mCheckpoints == NULL) {
        raceProgressKart->mRoute = 0;
        raceProgressKart->mCheckpoint = 0;
    } else {
        raceProgressKart->mRoute = g_GlobalPE->mCheckpointRoutes->mPreviousRoutes[0];
        route = &g_GlobalPE->mCheckpointRoutes[raceProgressKart->mRoute];
        firstEntry = g_GlobalPE->mCheckpointRoutes[raceProgressKart->mRoute].mFirstEntry;
        raceProgressKart->mCheckpoint = firstEntry + route->mEntryCount - 1;
    }
    raceProgressKart->mLapFrames = 0;
    raceProgressKart->mUnk_08 = 0;
    raceProgressKart->mFinishTimeMs = 0;
    raceProgressKart->mHighestLap = 1;
    raceProgressKart->mLap = 0;
    raceProgressKart->mStatus = RACE_PROGRESS_KART_STATUS_RACING;
    raceProgressKart->mFlags = 0;
    raceProgressKart->mInOrderCheckpointNumber = g_GlobalPE->mNumberedCheckpointCount - 1;
    raceProgressKart->mCheckpointNumber = g_GlobalPE->mNumberedCheckpointCount - 1;
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
        MaybeConvertElapsedTime(&lapTime->mMinute, &lapTime->mSecond, &lapTime->mMillisecond, 0,
                        g_GlobalMV->mHeader.mElapsedFrames);
        lapTime++;
    }
    MaybeConvertElapsedTime(&raceProgressKart->mLapTimes[5].mMinute, &raceProgressKart->mLapTimes[5].mSecond,
                    &raceProgressKart->mLapTimes[5].mMillisecond, 0, g_GlobalMV->mHeader.mElapsedFrames);
    if (kartIndex == g_GlobalCO->mEntryIndex) {
        raceProgressKart->mFlags = raceProgressKart->mFlags | RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY;
    }
    raceProgressKart->mRankIndexRequestBits =
        (raceProgressKart->mRankIndexRequestBits & ~0xf) | ((u16) (kartIndex + 1) & 0xf);
}

static inline u32 RaceProgressGetWorkConnectionMode(ConnectionWork *connectionWork) {
    return connectionWork == NULL ? CONNECTION_MODE_NONE : connectionWork->mConnectionMode;
}

static inline void ResetRaceProgressClock(RaceProgressHeader *raceProgressHeader) {
    raceProgressHeader->mElapsedFrames = 0;
    raceProgressHeader->mClockEnabled = 0;
}

static inline void RaceProgressComputeTimeFromFrames(MinuteSecondMillisecondTime *time, u32 frames) {
    MaybeConvertElapsedTime(&time->mMinute, &time->mSecond, &time->mMillisecond, 0, frames);
}

static inline void RaceProgressInitRandomState(RandomState64 *randomState64, u32 seed) {
    randomState64->mValue = seed;
    randomState64->mMultiplier = RANDOM_STATE64_MULTIPLIER;
    randomState64->mIncrement = RANDOM_STATE64_INCREMENT;
}

static inline s32 Fixed12AddOneThenDivideByIntOrZero(s32 value, s32 divisor) {
    return divisor == 0 ? 0 : FX_Div(value + 0x1000, TO_FIXED12(divisor));
}

static inline u32 RaceProgressNextRandomBelow(RandomState64 *randomState64, u32 limit) {
    randomState64->mValue = (s64) randomState64->mMultiplier * (s64) randomState64->mValue + randomState64->mIncrement;
    return ((s64) (randomState64->mValue >> 32) * limit) >> 32;
}

void CreateGlobalMV(void) {
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

    ResetRaceProgressClock(&g_GlobalMV->mHeader);
    RaceProgressComputeTimeFromFrames(&g_GlobalMV->mHeader.mClockTime, g_GlobalMV->mHeader.mElapsedFrames);
    entryRaceEnded = FALSE;
    g_GlobalMV->mHeader.mFinishedCount = 0;
    g_GlobalMV->mHeader.mRemovedCount = 0;
    g_GlobalMV->mRaceDone = 0;
    switch (g_GlobalCO->mRaceKind) {
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
    g_GlobalMV->mEntryRaceEnded = entryRaceEnded;
    g_GlobalMV->mEntryEndKind = RACE_END_KIND_NOT_ENDED;
    g_GlobalMV->mTimeCountsDown = FALSE;
    g_GlobalMV->mTimeLimitFrameCount = 0;
    switch (g_GlobalCO->mMode) {
        case MODE_MISSION_RUN:
            if (g_GlobalCO->mMissionKind == MISSION_KIND_LAPS_FIRST_PLACE) {
                g_GlobalMV->mTimeCountsDown = FALSE;
            } else {
                g_GlobalMV->mTimeCountsDown = TRUE;
            }
            g_GlobalMV->mTimeLimitFrameCount = g_GlobalCO->mMissionTimeLimitFrameCount;
            break;
        case MODE_BATTLE:
            if (g_GlobalCO->mBattleKind == BATTLE_KIND_SHINE) {
                g_GlobalMV->mTimeCountsDown = TRUE;
                g_GlobalMV->mTimeLimitFrameCount = g_GlobalPE->mSettings->mLapCountOrBattleSeconds * 0x3c;
            }
            break;
    }
    for (index = 0; index < 8; index++) {
        StructRC_SomeFn_2(&g_GlobalMV->mKarts[index], index);
        g_GlobalMV->mKartAtRank[index] = -1;
    }
    switch (g_GlobalCO->mRaceKind) {
        case RACE_KIND_REPLAY:
            seed = g_GlobalCO->mSeed;
            break;
        case RACE_KIND_AWARD:
            seed = 0xc240793;
            break;
        case RACE_KIND_STAFF_ROLL:
            seed = 0x71abc95;
            break;
        default:
            switch (g_GlobalCO->mMode) {
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
                    connectionWork = g_GlobalZE;
                    value = 0;
                    if (RaceProgressGetWorkConnectionMode(connectionWork) != 0) {
                        if (connectionWork->mState != CONNECTION_STATE_ENDED) {
                            value = 1;
                        }
                    }
                    if (value != 0) {
                        seed = connectionWork->mRaceSeed;
                    } else {
                        tickSeed1 = Os_GetTick();
                        seed = (tickSeed1 << 16) + Os_GetTick();
                    }
                    break;
            }
            break;
    }
    RaceProgressInitRandomState(&g_GlobalMV->mRandom, seed);
    g_GlobalMV->mSeed = seed;
    g_GlobalCO->mNextHeader.mSeed = seed;
    tickSeed1 = Os_GetTick();
    tickSeed2 = Os_GetTick();
    tickSeed3 = Os_GetTick();
    RaceProgressInitRandomState(&g_GlobalMV->mLocalRandom, tickSeed1 + ((tickSeed2 << 24) + (tickSeed3 << 8)));
    RaceProgressInitRandomState(&g_GlobalMV->mFixedSeedRandom, 0xa094a2f);
    if (g_GlobalCO->mMode == MODE_BATTLE) {
        ShuffleCourseMapRespawnSlots(&g_GlobalMV->mRandom);
    }
    g_GlobalMV->mCameraChainEnded = 0;
    g_GlobalMV->mLapProgressScale = FX_Inv(TO_FIXED12(g_GlobalPE->mLapProgressBaseMax + 1));
    g_GlobalMV->mRaceProgressScale = FX_Inv(TO_FIXED12(GetCurrentLapCount()));
    for (index = 0; index < g_GlobalPE->mNumberedCheckpointCount + 1; index++) {
        checkpointNumber = index % (g_GlobalPE->mNumberedCheckpointCount + 1);
        if (checkpointNumber == g_GlobalPE->mNumberedCheckpointCount) {
            g_GlobalMV->mCheckpointLapProgress[index] = TO_FIXED12(1);
        } else {
            for (routeIndex = 0; routeIndex < g_GlobalPE->mCheckpointRouteCount; routeIndex++) {
                route = &g_GlobalPE->mCheckpointRoutes[routeIndex];
                for (entryInRoute = 0; entryInRoute < route->mEntryCount; entryInRoute++) {
                    checkpointIndex = entryInRoute + route->mFirstEntry;
                    checkpoint = &g_GlobalPE->mCheckpoints[checkpointIndex];
                    if (checkpoint->mNumber == checkpointNumber) {
                        value = Fixed12AddOneThenDivideByIntOrZero(TO_FIXED12(checkpointIndex - route->mFirstEntry),
                                                                   route->mEntryCount);
                        value += TO_FIXED12(route->mLapProgressBase);
                        g_GlobalMV->mCheckpointLapProgress[index] =
                            MUL_FIXED12_ROUNDED(value, g_GlobalMV->mLapProgressScale);
                    }
                }
            }
        }
    }
    if (g_GlobalCO->mMode != MODE_BATTLE) {
        g_GlobalMV->mStartPlacementOffset = 0;
        return;
    }
    g_GlobalMV->mStartPlacementOffset = RaceProgressNextRandomBelow(&g_GlobalMV->mRandom, 8);
}
