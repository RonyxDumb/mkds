#include "Main/Unknown/code_0203d568.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_0203f334.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0207a32c.h"
#include "Main/Unknown/code_0207a7fc.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204a928.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_0205e2cc.h"
#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_020b1a34.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "code_02147cd8.h"
#include "code_021458c4.h"
#include "Main/Unknown/code_0203ca38.h"

#pragma opt_rebuildconditionals off

static inline s32 func_0203d568_inline(ConnectionWork *p) {
    BOOL r = FALSE;
    if ((p == NULL ? 0 : p->mConnectionMode) != 0 && p->mState != 13) {
        r = TRUE;
    }
    return r;
}

static inline void func_0203d568_b_inline(void) {
    u16 entryIndex;

    if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL && GetNextSceneNumber() != 10 &&
        (GetNextSceneNumber() != 6 || gMenuShared->mWLMenuKind != 2) && func_0203d568_inline(gConnectionWork) != 0) {
        for (entryIndex = 0; entryIndex < (u32) gRaceSetup->mKartCount; entryIndex++) {
            if (gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind == PLAYER_KIND_HUMAN &&
                (gConnectionWork->mParticipantMask & (1 << gConnectionWork->mParticipantIndexByPos[entryIndex])) == 0) {
                ReplaceEntryWithCpu(entryIndex);
            }
        }
    }
}

static inline s32 func_0203d568_c_inline(void) {
    s32 r;
    if (data_0217aa08->mBusy == 0) {
        r = gBackupAccess->mBackupEnabled != 0 ? gBackupAccess->mCommandRunning : 0;
    } else {
        r = 1;
    }
    return r;
}

static inline u16 func_0203df74_inline(u16 checkpoint) {
    u16 routeIndex;
    u16 firstEntry;
    u16 endEntry;
    CourseMapRoute *route;

    for (routeIndex = 0; routeIndex < gCourseMap->mCheckpointRouteCount; routeIndex++) {
        route = &gCourseMap->mCheckpointRoutes[routeIndex];
        firstEntry = route->mFirstEntry;
        endEntry = firstEntry + route->mEntryCount;
        if (checkpoint >= firstEntry && checkpoint < endEntry) {
            return routeIndex;
        }
    }
    return 0;
}

static inline s16 func_0203df74_b_inline(RaceProgressKart *kart, s32 *outProgress, Vec3 *position) {
    u16 routeIndex;
    u16 checkpoint;
    u16 lo;
    u16 hi;
    CourseMapRoute *route;

    for (routeIndex = 0; routeIndex < gCourseMap->mCheckpointRouteCount; routeIndex++) {
        route = &gCourseMap->mCheckpointRoutes[routeIndex];
        lo = route->mFirstEntry;
        hi = lo + route->mEntryCount;
        for (checkpoint = lo; checkpoint < hi; checkpoint++) {
            if (TryGetKartCheckpointProgress(kart, outProgress, position, routeIndex, checkpoint) != 0) {
                return checkpoint;
            }
        }
    }
    return -1;
}

static inline s32 func_0203df74_c_inline(CourseMapRoute *route, u16 checkpoint, s32 progress) {
    s32 x;
    s32 t;

    t = (checkpoint - route->mFirstEntry) << 12;
    if (route->mEntryCount == 0) {
        x = 0;
    } else {
        x = FX_Div(t + progress, route->mEntryCount << 12);
    }
    t = x + (route->mLapProgressBase << 12);
    return MUL_FIXED12_ROUNDED(t, gRaceProgress->mLapProgressScale);
}

static inline void func_0203e550_inline(s32 kartIndex) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        FinishRaceProgressKartWithEndKind(kartIndex, 0);
    }
}

void CompleteRaceProgressKartLap(RaceProgressKart *kart) {
    BOOL f;
    BOOL missionTestPassed;
    Unk021759c0_28 *missionSettings;
    EntryKartCounters *entryKartCounters;

    if (kart->mLap < 0x7fffffff) {
        kart->mLap = kart->mLap + 1;
    }
    kart->mCheckpointNumber = -1;
    kart->mInOrderCheckpointNumber = -1;
    f = FALSE;
    switch (kart->mStatus) {
        case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
        case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
        case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
            f = TRUE;
            break;
    }
    if (f != FALSE) {
        return;
    }
    if (kart->mLap <= kart->mHighestLap) {
        return;
    }
    if ((kart->mFlags & RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY) != 0) {
        AdvanceSceneSoundLap();
    }
    StoreRaceProgressKartLapTime(kart, kart->mLap > GetLapCount());
    kart->mHighestLap = kart->mLap;
    if ((kart->mFlags & RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY) != 0) {
        StartRaceHudLapTimeDisplay();
    }
    f = FALSE;
    if (gRaceSetup->mMode != MODE_MISSION_RUN) {
        f = TRUE;
    } else {
        switch (gRaceSetup->mMissionKind) {
            case 2:
            case 4:
            case 6:
                f = TRUE;
                break;
        }
    }
    if (f == FALSE) {
        return;
    }
    if (kart->mHighestLap <= GetLapCount()) {
        return;
    }
    kart->mHighestLap = GetLapCount();
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        missionSettings = &gRaceSetup->mUnk_28_view;
        missionTestPassed = TRUE;
        entryKartCounters = GetEntryKartCounters();
        switch (missionSettings->mMissionKind) {
            case 4:
                if (missionSettings->mMissionRunCountLimit > (u32) entryKartCounters->mMiniTurboCount) {
                    missionTestPassed = FALSE;
                }
                break;
            case 6:
                if (kart->mRank != 1) {
                    missionTestPassed = FALSE;
                }
                break;
        }
        if (missionTestPassed != FALSE) {
            func_0203e550_inline(kart->mIndex);
        } else {
            FinishRaceProgressKartWithEndKind(kart->mIndex, 4);
        }
    } else {
        if ((kart->mFlags & RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY) == 0 && gRaceSetup->mMode == MODE_WIFI) {
            return;
        }
        kart->mFlags |= RACE_PROGRESS_KART_FLAG_FINISH_PENDING;
    }
}

void SetRaceProgressKartFinishRequest(u32 kartIndex, u32 b) {
    RaceProgressKart *kart;
    u16 finishRequest;

    kart = &gRaceProgress->mKarts[kartIndex];
    finishRequest = b != 0 ? 1 : 2;
    kart->mUnk_3c = (kart->mUnk_3c & ~0x300) | ((finishRequest & 3) << 8);
    if (gRaceProgress->mHeader.mFinishedCount + gRaceProgress->mHeader.mRemovedCount >= gRaceSetup->mKartCount) {
        FinishRaceProgress();
    }
}

void EnterRaceProgressKartCheckpoint(RaceProgressKart *kart, s32 checkpoint) {
    s16 checkpointNumber;

    checkpointNumber = gCourseMap->mCheckpoints[kart->mCheckpoint].mNumber;
    if (checkpointNumber != -1) {
        kart->mCheckpointNumber = checkpointNumber;
        if (kart->mInOrderCheckpointNumber + 1 >= checkpointNumber) {
            kart->mInOrderCheckpointNumber = checkpointNumber;
        }
    }
    if (checkpoint == 0 && kart->mInOrderCheckpointNumber >= gCourseMap->mNumberedCheckpointCount - 1) {
        CompleteRaceProgressKartLap(kart);
    } else if (kart->mCheckpoint == 0 && checkpoint == gCourseMap->mLastCheckpoint) {
        if (kart->mLap > -100) {
            kart->mLap = kart->mLap - 1;
        }
        kart->mCheckpointNumber = gCourseMap->mNumberedCheckpointCount - 1;
        kart->mInOrderCheckpointNumber = gCourseMap->mNumberedCheckpointCount - 1;
    }
    kart->mCheckpoint = checkpoint;
    kart->mRoute = func_0203df74_inline(checkpoint);
}

void UpdateRaceProgressKart(Vec3 *position, RaceProgressKart *kart) {
    s32 checkpointProgress;
    u16 checkpoint;
    u16 routeIndex;
    s16 p;
    s32 lapProgress;
    s32 k;
    CourseMapRoute *route;

    checkpoint = kart->mCheckpoint;
    routeIndex = kart->mRoute;
    p = checkpoint;
    checkpointProgress = 0;
    if (IsKartInRespawnWait(kart->mIndex) != 0) {
        return;
    }
    if (TryGetKartCheckpointProgress(kart, &checkpointProgress, position, routeIndex, checkpoint) == 0) {
        if (checkpointProgress >= 0) {
            p = FindKartCheckpointForward(kart, &checkpointProgress, position, routeIndex, checkpoint, 5);
            if (p == -1) {
                p = FindKartCheckpointBackward(kart, &checkpointProgress, position, routeIndex, checkpoint, 5);
            }
        } else {
            p = FindKartCheckpointBackward(kart, &checkpointProgress, position, routeIndex, checkpoint, 5);
            if (p == -1) {
                p = FindKartCheckpointForward(kart, &checkpointProgress, position, routeIndex, checkpoint, 5);
            }
        }
        if (p == -1) {
            p = func_0203df74_b_inline(kart, &checkpointProgress, position);
        }
        if (p == -1) {
            return;
        }
        routeIndex = func_0203df74_inline(p);
    }
    route = &gCourseMap->mCheckpointRoutes[routeIndex];
    lapProgress = func_0203df74_c_inline(route, p, checkpointProgress);
    k = 0;
    if (p != -1) {
        if (gCourseMap->mNumberedCheckpointCount >= 1) {
            k = gRaceProgress->mCheckpointLapProgress[gCourseMap->mNumberedCheckpointCount - 1];
        }
        if (lapProgress <= gRaceProgress->mCheckpointLapProgress[kart->mInOrderCheckpointNumber + 1]) {
            EnterRaceProgressKartCheckpoint(kart, p);
        } else if (kart->mCheckpoint == 0 && lapProgress > k) {
            EnterRaceProgressKartCheckpoint(kart, p);
        } else {
            checkpointProgress = kart->mCheckpointProgress;
            lapProgress = func_0203df74_c_inline(route, kart->mCheckpoint, checkpointProgress);
        }
    }
    kart->mCheckpointProgress = checkpointProgress;
    kart->mLapProgress = lapProgress;
    k = ((kart->mLap - 1) << 12) + kart->mLapProgress;
    kart->mRaceProgress = MUL_FIXED12_ROUNDED(k, gRaceProgress->mRaceProgressScale);
}

void UpdateRaceProgressKarts(void) {
    IntPair forwardPair;
    s32 progressByKart[8];
    s32 progressByRank[8];
    s32 lapByRank[8];
    u16 kartByRank[8];
    Vec3 position;
    Vec3 forward;
    u16 kartOrRankIndex;
    s32 testedBitsIndex;
    RaceProgressKart *kart;
    BOOL flag;
    RaceProgress *raceProgress;
    IntPair *checkpointDirection;
    u16 m;
    s32 finishedCount;
    s32 notRemovedCount;
    s32 insertPos;
    s32 rankIndex;
    s32 progressKey;
    s32 lapKey;
    s32 kartKey;
    u16 rankSlot;
    RaceProgressKart *statusKart;

    for (kartOrRankIndex = 0; kartOrRankIndex < (u32) gRaceSetup->mKartCount; kartOrRankIndex++) {
        kart = &gRaceProgress->mKarts[kartOrRankIndex];
        if (kart->mStatus != RACE_PROGRESS_KART_STATUS_REMOVED && gRaceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
            for (testedBitsIndex = 0; testedBitsIndex < 16; testedBitsIndex++) {
                kart->mCheckpointTestedBits[testedBitsIndex] = 0;
            }
            GetKartPos(&position, kartOrRankIndex);
            GetKartForward(GetKart(kartOrRankIndex), &forward);
            UpdateRaceProgressKart(&position, kart);
            flag = FALSE;
            if (IsKartOnBoostSurface(kart->mIndex) == 0) {
                checkpointDirection = &gCourseMap->mCheckpoints[kart->mCheckpoint].mDirection;
                forwardPair.mFirst = forward.x;
                forwardPair.mSecond = forward.z;
                if (ComputeDotOfPairsRounded(&forwardPair, checkpointDirection) < -1394) {
                    flag = TRUE;
                }
            }
            if (flag != FALSE) {
                kart->mFlags |= RACE_PROGRESS_KART_FLAG_AGAINST_CHECKPOINT;
            } else {
                kart->mFlags &= ~RACE_PROGRESS_KART_FLAG_AGAINST_CHECKPOINT;
            }
            progressByKart[kartOrRankIndex] = kart->mRaceProgress;
        }
    }
    if (gRaceSetup->mKartCount > 1) {
        raceProgress = gRaceProgress;
        notRemovedCount = gRaceSetup->mKartCount - raceProgress->mHeader.mRemovedCount;
        finishedCount = raceProgress->mHeader.mFinishedCount;
        for (kartOrRankIndex = 0; kartOrRankIndex < (u32) gRaceSetup->mKartCount; kartOrRankIndex++) {
            rankIndex = raceProgress->mKarts[kartOrRankIndex].mRank - 1;
            progressByRank[rankIndex] = progressByKart[kartOrRankIndex];
            kartByRank[rankIndex] = kartOrRankIndex;
            lapByRank[rankIndex] = raceProgress->mKarts[kartOrRankIndex].mLap;
        }
        for (kartOrRankIndex = finishedCount + 1; kartOrRankIndex < notRemovedCount; kartOrRankIndex++) {
            progressKey = progressByRank[kartOrRankIndex];
            kartKey = kartByRank[kartOrRankIndex];
            lapKey = lapByRank[kartOrRankIndex];
            for (insertPos = kartOrRankIndex;
                 insertPos > finishedCount &&
                 (lapByRank[insertPos - 1] < lapKey ||
                  (lapKey == lapByRank[insertPos - 1] && progressByRank[insertPos - 1] < progressKey));
                 insertPos--) {
                lapByRank[insertPos] = lapByRank[insertPos - 1];
                progressByRank[insertPos] = progressByRank[insertPos - 1];
                kartByRank[insertPos] = kartByRank[insertPos - 1];
            }
            progressByRank[insertPos] = progressKey;
            kartByRank[insertPos] = kartKey;
        }
        for (kartOrRankIndex = 0; kartOrRankIndex < (u32) gRaceSetup->mKartCount; kartOrRankIndex++) {
            if (kartByRank[kartOrRankIndex] < 8) {
                gRaceProgress->mKarts[kartByRank[kartOrRankIndex]].mRank = kartOrRankIndex + 1;
            }
        }
        gRaceProgress->mKarts[kartByRank[0]].mFirstPlaceFrames++;
        for (rankSlot = 0; rankSlot < (u32) gRaceSetup->mKartCount; rankSlot++) {
            gRaceProgress->mKartAtRank[rankSlot] = kartByRank[rankSlot];
        }
        for (; rankSlot < 8; rankSlot++) {
            gRaceProgress->mKartAtRank[rankSlot] = -1;
        }
    } else {
        gRaceProgress->mKarts[0].mRank = 1;
        gRaceProgress->mKarts[0].mFirstPlaceFrames++;
        gRaceProgress->mKartAtRank[0] = 0;
        for (rankSlot = 1; rankSlot < 8; rankSlot++) {
            gRaceProgress->mKartAtRank[rankSlot] = -1;
        }
    }
    flag = FALSE;
    switch (gRaceSetup->mRaceKind) {
        case RACE_KIND_DEMO:
        case RACE_KIND_REPLAY:
        case RACE_KIND_STAFF_ROLL:
            flag = TRUE;
            break;
        case RACE_KIND_NORMAL:
            if (IsEntryRaceEnded() != 0) {
                flag = TRUE;
            }
            break;
    }
    gRaceProgress->mEntryRaceEnded = flag;
    for (kartOrRankIndex = 0; kartOrRankIndex < (u32) gRaceSetup->mKartCount; kartOrRankIndex++) {
        statusKart = &gRaceProgress->mKarts[kartOrRankIndex];
        flag = FALSE;
        switch (statusKart->mStatus) {
            case RACE_PROGRESS_KART_STATUS_GOAL_REACHED:
            case RACE_PROGRESS_KART_STATUS_BATTLE_LOSER:
            case RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL:
                flag = TRUE;
                break;
        }
        if (flag == FALSE && (statusKart->mFlags & RACE_PROGRESS_KART_FLAG_FINISH_PENDING) != 0) {
            FinishRaceProgressKart(statusKart, 1);
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
            statusKart->mFlags &= ~RACE_PROGRESS_KART_FLAG_FINISH_PENDING;
        }
        if ((statusKart->mFlags & RACE_PROGRESS_KART_FLAG_FINISH_JUST_HAPPENED) != 0) {
            statusKart->mFlags &= ~RACE_PROGRESS_KART_FLAG_FINISH_JUST_HAPPENED;
            if (gRaceSetup->mMode != MODE_MISSION_RUN) {
                StartKartRaceEndWrapper(statusKart->mIndex);
                if ((statusKart->mFlags & RACE_PROGRESS_KART_FLAG_LOCAL_ENTRY) != 0) {
                    StartRaceEndSeq(0);
                }
            }
        }
    }
}

void SetRankTimeFromRankTimeGp(RankTimeGp *rankTimeGp) {
    s32 entryIndex;
    RankTimeGpEntry *entry;

    gRaceProgress->mHeader.mRankTime = 0;
    for (entryIndex = 0; entryIndex < rankTimeGp->mEntryCount; entryIndex++) {
        entry = &rankTimeGp->mEntries[entryIndex];
        if (entry->mCourseId == gRaceSetup->mCourseId) {
            switch (gRaceSetup->mEngineIndex) {
                case 0:
                    gRaceProgress->mHeader.mRankTime = entry->mRankTimeEngine0;
                    return;
                case 1:
                    gRaceProgress->mHeader.mRankTime = entry->mRankTimeEngine1;
                    return;
                case 2:
                    gRaceProgress->mHeader.mRankTime = entry->mRankTimeEngine2;
                    break;
            }
            return;
        }
    }
}

void CreateRaceProgress(void *heap) {
    gRaceProgress = HeapAlloc(heap, 0x524);
    gRaceProgress->mCheckpointLapProgress = HeapAlloc(heap, (gCourseMap->mNumberedCheckpointCount + 1) << 2);
    gRaceProgress->mRankPointFile = FindMainRaceOrMainEffectFile(gRankPointRptName);
    gRaceProgress->mRankTimeGpFile = FindMainRaceOrMainEffectFile(gRankTimeGpRttName);
    SetRankTimeFromRankTimeGp(gRaceProgress->mRankTimeGpFile);
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        CreateShapeMapObjectCountList(heap);
    }
    InitRaceProgress();
}

void StopRaceInput(void) {
    u16 entryIndex;
    enum { K0 } inputSlotIndex;

    SetReadRaceKeys(0);
    if (func_0203d568_c_inline() != 0) {
        WaitThreadFunctionsDone();
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    switch (gRaceSetup->mMode) {
        case MODE_VS:
            func_0203d568_b_inline();
            break;
        case MODE_MISSION_RUN:
            ClearShapeMapObjectCountListPointer();
            break;
        case MODE_BATTLE:
            func_0203d568_b_inline();
            break;
    }
    for (entryIndex = 0; entryIndex < (u32) gRaceSetup->mKartCount; entryIndex++) {
        inputSlotIndex = gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mIndex;
        FinishKeyRecording(&gInputSlots[inputSlotIndex].mUnk_28);
    }
}
