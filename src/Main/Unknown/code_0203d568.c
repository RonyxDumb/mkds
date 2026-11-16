#include "Main/Unknown/code_0203d568.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203e74c.h"
#include "Main/Race/RaceProgress.h"
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
    if ((p == NULL ? 0 : p->field0) != 0 && p->field4 != 13) {
        r = TRUE;
    }
    return r;
}

static inline void func_0203d568_b_inline(void) {
    u16 entryIndex;

    if (gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL && scproc_getNextScene() != 10 &&
        (scproc_getNextScene() != 6 || gStruct217B488->field74 != 2) && func_0203d568_inline(gStruct217AA00) != 0) {
        for (entryIndex = 0; entryIndex < (u32) gRaceMultiConfig->mKartCount; entryIndex++) {
            if (gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mKind == PLAYER_KIND_HUMAN &&
                (gStruct217AA00->mParticipantMask & (1 << gStruct217AA00->field1E8C[entryIndex])) == 0) {
                func_0204451c(entryIndex);
            }
        }
    }
}

static inline s32 func_0203d568_c_inline(void) {
    s32 r;
    if (gSaveData->mBusy == 0) {
        r = gSaveCore->mBackupEnabled != 0 ? gSaveCore->mCommandRunning : 0;
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

    for (routeIndex = 0; routeIndex < gMapData->mCheckpointRouteCount; routeIndex++) {
        route = &gMapData->mCheckpointRoutes[routeIndex];
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

    for (routeIndex = 0; routeIndex < gMapData->mCheckpointRouteCount; routeIndex++) {
        route = &gMapData->mCheckpointRoutes[routeIndex];
        lo = route->mFirstEntry;
        hi = lo + route->mEntryCount;
        for (checkpoint = lo; checkpoint < hi; checkpoint++) {
            if (rstat_isLeavingCpoiQuad(kart, outProgress, position, routeIndex, checkpoint) != 0) {
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
    return ((s64) t * gRaceStatus->mLapProgressScale + 0x800) >> 12;
}

static inline void func_0203e550_inline(s32 kartIndex) {
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        rstat_finishMission(kartIndex, 0);
    }
}

void rstat_handleLapChange(RaceProgressKart *kart) {
    BOOL f;
    BOOL missionTestPassed;
    Unk021759c0_28 *s;
    EntryKartCounters *entryKartCounters;

    if (kart->mLap < 0x7fffffff) {
        kart->mLap = kart->mLap + 1;
    }
    kart->mCheckpointNumber = -1;
    kart->mInOrderCheckpointNumber = -1;
    f = FALSE;
    switch (kart->mStatus) {
        case 1:
        case 2:
        case 3:
            f = TRUE;
            break;
    }
    if (f != FALSE) {
        return;
    }
    if (kart->mLap <= kart->mHighestLap) {
        return;
    }
    if ((kart->mFlags & 1) != 0) {
        snd_handleLapChange();
    }
    rstat_handleLapTime(kart, kart->mLap > rconf_getLapCount());
    kart->mHighestLap = kart->mLap;
    if ((kart->mFlags & 1) != 0) {
        func_020b1a34();
    }
    f = FALSE;
    if (gRaceMultiConfig->mMode != MODE_MISSION_RUN) {
        f = TRUE;
    } else {
        switch (gRaceMultiConfig->mMissionKind) {
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
    if (kart->mHighestLap <= rconf_getLapCount()) {
        return;
    }
    kart->mHighestLap = rconf_getLapCount();
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        s = &gRaceMultiConfig->mUnk_28_view;
        missionTestPassed = TRUE;
        entryKartCounters = driver_getPlayerStatistics();
        switch (s->mMissionKind) {
            case 4:
                if (s->fieldF > (u32) entryKartCounters->field4) {
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
            rstat_finishMission(kart->mIndex, 4);
        }
    } else {
        if ((kart->mFlags & 1) == 0 && gRaceMultiConfig->mMode == 5) {
            return;
        }
        kart->mFlags |= 0x40;
    }
}

void rstat_203E4C4(u32 kartIndex, u32 b) {
    RaceProgressKart *kart;
    u16 finishRequest;

    kart = &gRaceStatus->mKarts[kartIndex];
    finishRequest = b != 0 ? 1 : 2;
    kart->field3C = (kart->field3C & ~0x300) | ((finishRequest & 3) << 8);
    if (gRaceStatus->field0[0].mFinishedCount + gRaceStatus->field0[0].mRemovedCount >=
        gRaceMultiConfig->mKartCount) {
        rstat_storeRaceResults();
    }
}

void rstat_setCurrentCpoi(RaceProgressKart *kart, s32 checkpoint) {
    s16 checkpointNumber;

    checkpointNumber = gMapData->mCheckpoints[kart->mCheckpoint].mNumber;
    if (checkpointNumber != -1) {
        kart->mCheckpointNumber = checkpointNumber;
        if (kart->mInOrderCheckpointNumber + 1 >= checkpointNumber) {
            kart->mInOrderCheckpointNumber = checkpointNumber;
        }
    }
    if (checkpoint == 0 && kart->mInOrderCheckpointNumber >= gMapData->mNumberedCheckpointCount - 1) {
        rstat_handleLapChange(kart);
    } else if (kart->mCheckpoint == 0 && checkpoint == gMapData->mLastCheckpoint) {
        if (kart->mLap > -100) {
            kart->mLap = kart->mLap - 1;
        }
        kart->mCheckpointNumber = gMapData->mNumberedCheckpointCount - 1;
        kart->mInOrderCheckpointNumber = gMapData->mNumberedCheckpointCount - 1;
    }
    kart->mCheckpoint = checkpoint;
    kart->mRoute = func_0203df74_inline(checkpoint);
}

void rstat_updateDriverProgress(Vec3 *position, RaceProgressKart *kart) {
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
    if (driver_isFalling(kart->mIndex) != 0) {
        return;
    }
    if (rstat_isLeavingCpoiQuad(kart, &checkpointProgress, position, routeIndex, checkpoint) == 0) {
        if (checkpointProgress >= 0) {
            p = rstat_getNextCpoiId(kart, &checkpointProgress, position, routeIndex, checkpoint, 5);
            if (p == -1) {
                p = rstat_getPrevCpoiId(kart, &checkpointProgress, position, routeIndex, checkpoint, 5);
            }
        } else {
            p = rstat_getPrevCpoiId(kart, &checkpointProgress, position, routeIndex, checkpoint, 5);
            if (p == -1) {
                p = rstat_getNextCpoiId(kart, &checkpointProgress, position, routeIndex, checkpoint, 5);
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
    route = &gMapData->mCheckpointRoutes[routeIndex];
    lapProgress = func_0203df74_c_inline(route, p, checkpointProgress);
    k = 0;
    if (p != -1) {
        if (gMapData->mNumberedCheckpointCount >= 1) {
            k = gRaceStatus->mCheckpointLapProgress[gMapData->mNumberedCheckpointCount - 1];
        }
        if (lapProgress <= gRaceStatus->mCheckpointLapProgress[kart->mInOrderCheckpointNumber + 1]) {
            rstat_setCurrentCpoi(kart, p);
        } else if (kart->mCheckpoint == 0 && lapProgress > k) {
            rstat_setCurrentCpoi(kart, p);
        } else {
            checkpointProgress = kart->mCheckpointProgress;
            lapProgress = func_0203df74_c_inline(route, kart->mCheckpoint, checkpointProgress);
        }
    }
    kart->mCheckpointProgress = checkpointProgress;
    kart->mLapProgress = lapProgress;
    k = ((kart->mLap - 1) << 12) + kart->mLapProgress;
    kart->mRaceProgress = ((s64) k * gRaceStatus->mRaceProgressScale + 0x800) >> 12;
}

void rstat_handleCheckPoints(void) {
    Unk0217b498_0c t;
    s32 progressByKart[8];
    s32 progressByRank[8];
    s32 lapByRank[8];
    u16 kartByRank[8];
    Vec3 position;
    Vec3 forward;
    u16 i;
    s32 k;
    RaceProgressKart *kart;
    BOOL f;
    RaceProgress *raceProgress;
    Unk0217b498_0c *checkpointDirection;
    u16 m;
    s32 finishedCount;
    s32 notRemovedCount;
    s32 insertPos;
    s32 rankIndex;
    s32 progressKey;
    s32 lapKey;
    s32 kartKey;
    u16 g;
    RaceProgressKart *s;

    for (i = 0; i < (u32) gRaceMultiConfig->mKartCount; i++) {
        kart = &gRaceStatus->mKarts[i];
        if (kart->mStatus != 4 && gRaceMultiConfig->mRaceKind != RACE_KIND_STAFF_ROLL) {
            for (k = 0; k < 16; k++) {
                kart->mCheckpointTestedBits[k] = 0;
            }
            driver_getPosition(&position, i);
            driver_getShadowZDirection(driver_getById(i), &forward);
            rstat_updateDriverProgress(&position, kart);
            f = FALSE;
            if (driver_getIsOnAntigravity(kart->mIndex) == 0) {
                checkpointDirection = &gMapData->mCheckpoints[kart->mCheckpoint].mDirection;
                t.field0 = forward.x;
                t.field4 = forward.z;
                if (rstat_rotCompare(&t, checkpointDirection) < -1394) {
                    f = TRUE;
                }
            }
            if (f != FALSE) {
                kart->mFlags |= 4;
            } else {
                kart->mFlags &= ~4;
            }
            progressByKart[i] = kart->mRaceProgress;
        }
    }
    if (gRaceMultiConfig->mKartCount > 1) {
        raceProgress = gRaceStatus;
        notRemovedCount = gRaceMultiConfig->mKartCount - raceProgress->field0[0].mRemovedCount;
        finishedCount = raceProgress->field0[0].mFinishedCount;
        for (i = 0; i < (u32) gRaceMultiConfig->mKartCount; i++) {
            rankIndex = raceProgress->field0[i].field50_0 - 1;
            progressByRank[rankIndex] = progressByKart[i];
            kartByRank[rankIndex] = i;
            lapByRank[rankIndex] = raceProgress->field0[(u32) i].mLap;
        }
        for (i = finishedCount + 1; i < notRemovedCount; i++) {
            progressKey = progressByRank[i];
            kartKey = kartByRank[i];
            lapKey = lapByRank[i];
            for (insertPos = i; insertPos > finishedCount &&
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
        for (i = 0; i < (u32) gRaceMultiConfig->mKartCount; i++) {
            if (kartByRank[i] < 8) {
                gRaceStatus->mKarts[kartByRank[i]].mRank = i + 1;
            }
        }
        gRaceStatus->field0[kartByRank[0]].mFirstPlaceFrames++;
        for (g = 0; g < (u32) gRaceMultiConfig->mKartCount; g++) {
            gRaceStatus->mKartAtRank[g] = kartByRank[g];
        }
        for (; g < 8; g++) {
            gRaceStatus->mKartAtRank[g] = -1;
        }
    } else {
        gRaceStatus->field0[0].field50_0 = 1;
        gRaceStatus->field0[0].mFirstPlaceFrames++;
        gRaceStatus->mKartAtRank[0] = 0;
        for (g = 1; g < 8; g++) {
            gRaceStatus->mKartAtRank[g] = -1;
        }
    }
    f = FALSE;
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
    for (i = 0; i < (u32) gRaceMultiConfig->mKartCount; i++) {
        s = &gRaceStatus->mKarts[i];
        f = FALSE;
        switch (s->mStatus) {
            case 1:
            case 2:
            case 3:
                f = TRUE;
                break;
        }
        if (f == FALSE && (s->mFlags & 0x40) != 0) {
            rstat_finishDriver(s, 1);
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
            s->mFlags &= ~0x40;
        }
        if ((s->mFlags & 8) != 0) {
            s->mFlags &= ~8;
            if (gRaceMultiConfig->mMode != MODE_MISSION_RUN) {
                func_0207a828(s->mIndex);
                if ((s->mFlags & 1) != 0) {
                    func_02110cc8(0);
                }
            }
        }
    }
}

void rstat_loadRankTimeGp(RankTimeGp *rankTimeGp) {
    s32 entryIndex;
    RankTimeGpEntry *entry;

    gRaceStatus->field0[0].mRankTime = 0;
    for (entryIndex = 0; entryIndex < rankTimeGp->mEntryCount; entryIndex++) {
        entry = &rankTimeGp->field1C[entryIndex];
        if (entry->mCourseId == gRaceMultiConfig->mCourseId) {
            switch (gRaceMultiConfig->mEngineIndex) {
                case 0:
                    gRaceStatus->field0[0].mRankTime = entry->field2;
                    return;
                case 1:
                    gRaceStatus->field0[0].mRankTime = entry->field4;
                    return;
                case 2:
                    gRaceStatus->field0[0].mRankTime = entry->field6;
                    break;
            }
            return;
        }
    }
}

void rstat_init(void *heap) {
    gRaceStatus = heap_alloc(heap, 0x524);
    gRaceStatus->mCheckpointLapProgress = heap_alloc(heap, (gMapData->mNumberedCheckpointCount + 1) << 2);
    gRaceStatus->mRankPointFile = arc_getMainRaceMainEffectArcFile(aRankpoint_rpt);
    gRaceStatus->mRankTimeGpFile = arc_getMainRaceMainEffectArcFile(aRanktimegp_rtt);
    rstat_loadRankTimeGp(gRaceStatus->mRankTimeGpFile);
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        area_initMissionRivalPassAreas(heap);
    }
    rstat_init2();
}

void rstat_finalize(void) {
    u16 entryIndex;
    enum { K0 } inputSlotIndex;

    input_setFlagsBit1(0);
    if (func_0203d568_c_inline() != 0) {
        bgwkr_waitForCompletion();
        if (gSaveCore->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    switch (gRaceMultiConfig->mMode) {
        case MODE_VS:
            func_0203d568_b_inline();
            break;
        case MODE_MISSION_RUN:
            area_finalizeMissionRivalPassAreas();
            break;
        case MODE_BATTLE:
            func_0203d568_b_inline();
            break;
    }
    for (entryIndex = 0; entryIndex < (u32) gRaceMultiConfig->mKartCount; entryIndex++) {
        inputSlotIndex = gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mIndex;
        irec_stopRecording(&gInputUnits[inputSlotIndex].field28);
    }
}
