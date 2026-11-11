#include "01/code_0218155c.h"

#include "01/code_02188950.h"
#include "01/code_02188e88.h"
#include "01/unk_021a9000.h"
#include "01/code_02181000.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02108edc.h"
#include "Main/Unknown/code_0214d000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_0210b000.h"
#include "01/code_02182000.h"
#include "01/code_02183000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02108000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"

MissionRunData *gMissionRunData;

void AddMissionRunMapObject(Unk02188950 *mapObject) {
    u8 kartCount;
    u16 entryIndex;

    kartCount = gRaceSetup->mKartCount;
    entryIndex = gMissionRunData->mMapObjectCount + kartCount;
    gMissionRunData->mMapObjects[entryIndex - kartCount] = mapObject;
    ClearStandingEliminationStatus(entryIndex);
    gMissionRunData->mMapObjectCount++;
}

Unk02188950 *GetMissionRunMapObject(int entryIndex) {
    return gMissionRunData->mMapObjects[entryIndex - gRaceSetup->mKartCount];
}

u8 MissionRunGetCurrentKartCount(void) {
    return gRaceSetup->mKartCount;
}

u16 GetMissionRunMapObjectLastIndex(void) {
    return gMissionRunData->mMapObjectCount + gRaceSetup->mKartCount - 1;
}

void AddMissionRunCount(void) {
    MissionRunData *missionRunData;
    u32 countLimit;

    if ((gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) != FALSE) {
        return;
    }
    missionRunData = gMissionRunData;
    countLimit = GetMissionRunCountLimit();
    if (missionRunData->mCount >= countLimit) {
        return;
    }
    missionRunData->mCount = missionRunData->mCount + 1;
    StartMissionRunCountSeq(gMissionRunData->mCount, GetMissionRunCountLimit());
    switch (gRaceSetup->mMissionKind) {
        case 0:
        case 1:
        case 3:
        case 5:
        case 7:
            countLimit = GetMissionRunCountLimit();
            if (gMissionRunData->mCount >= countLimit) {
                FinishMissionRunKartWithEndKind0(gRaceSetup->mEntryIndex);
            }
            break;
    }
}

Vec3 *GetMissionRunKartPos(void) {
    return &gMissionRunData->mKartPos;
}

Vec3 *GetMissionRunPrevKartPos(void) {
    return &gMissionRunData->mPrevKartPos;
}

u16 GetMissionRunKartHeadingAngle(void) {
    return (gMissionRunData->mKartHeadingAngle);
}

u16 GetMissionRunPrevKartHeadingAngle(void) {
    return (gMissionRunData->mPrevKartHeadingAngle);
}

void CreateMissionRunData(void) {
    Kart *kart;
    MissionRunData *missionRunData;

    gMissionRunData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x68);
    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    missionRunData = gMissionRunData;
    missionRunData->mPrevKartPos = kart->mPos;
    missionRunData->mKartPos = missionRunData->mPrevKartPos;
    missionRunData->mPrevKartHeadingAngle = kart->mHeadingAngle;
    missionRunData = gMissionRunData;
    missionRunData->mKartHeadingAngle = missionRunData->mPrevKartHeadingAngle;
}

void UpdateMissionRunData(void) {
    Kart *kart;
    MissionRunData *missionRunData;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    if ((kart->mUnk_48 & KART_48_OBJECTS_SKIP) == 0) {
        missionRunData = gMissionRunData;
        missionRunData->mPrevKartPos = missionRunData->mKartPos;
        missionRunData->mPrevKartHeadingAngle = missionRunData->mKartHeadingAngle;
        missionRunData = gMissionRunData;
        missionRunData->mKartPos = kart->mPos;
        missionRunData->mKartHeadingAngle = kart->mHeadingAngle;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) {
        if (gRaceSetup->mMode == MODE_MISSION_RUN ? IsKartEliminated((u16) gRaceSetup->mEntryIndex) : 0) {
            if (GetBalloonOrShineCount(gRaceSetup->mEntryIndex)) {
                gMissionRunData->mSinceHitCallbackFrames += 1;
                if (gMissionRunData->mSinceHitCallbackFrames > 0xf) {
                    gMissionRunData->mSinceHitCallbackFrames = 0;
                    CallKartHitCallbackForSelf(gRaceSetup->mEntryIndex);
                    return;
                }
            }
        }
        return;
    }
    {
        u32 missionKind = gRaceSetup->mMissionKind;
        if (missionKind == 1 || missionKind == 5) {
            if (GetRaceUpdateFramesMod8() == 0) {
                missionRunData = gMissionRunData;
                if (missionRunData->mPendingBossTransfer != 0) {
                    missionRunData->mPendingBossTransfer -= 1;
                    missionRunData = gMissionRunData;
                    if (missionRunData->mCount != 0) {
                        missionRunData->mCount -= 1;
                        gMissionRunData->mBossCount += 1;
                    }
                    if (gMissionRunData->mBossTransferCallback != NULL) {
                        gMissionRunData->mBossTransferCallback();
                    }
                    gMissionRunData->mTimer = 0;
                } else if (missionRunData->mPendingDrop != 0) {
                    missionRunData->mPendingDrop -= 1;
                    missionRunData = gMissionRunData;
                    if (missionRunData->mCount != 0) {
                        missionRunData->mCount -= 1;
                    }
                    if (gMissionRunData->mDropCallback != NULL) {
                        gMissionRunData->mDropCallback();
                    }
                    gMissionRunData->mTimer = 0;
                } else if (missionRunData->mPendingCountUp != 0) {
                    missionRunData->mPendingCountUp -= 1;
                    AddMissionRunCount();
                    if (gMissionRunData->mCountUpCallback != NULL) {
                        gMissionRunData->mCountUpCallback();
                    }
                }
            }
            missionRunData = gMissionRunData;
            if (missionRunData->mTimer != 0) {
                missionRunData->mTimer -= 1;
                missionRunData = gMissionRunData;
                if (missionRunData->mTimer == 0) {
                    if (missionRunData->mTimerEndCallback != NULL) {
                        missionRunData->mTimerEndCallback();
                    }
                }
            }
        }
    }
}

void SetMissionRunTimerValues(u16 startTimer, u16 maxTimer, u16 countUpTimerAdd, u16 bossTransferTimerAdd) {
    gMissionRunData->mUnk_10 = startTimer;
    gMissionRunData->mUnk_12 = maxTimer;
    gMissionRunData->mUnk_14 = countUpTimerAdd;
    gMissionRunData->mUnk_16 = bossTransferTimerAdd;
}

s32 GetMissionRunTimer(void) {
    return (gMissionRunData->mTimer);
}

void SetMissionRunTimer(u32 timer) {
    gMissionRunData->mTimer = timer;
}

u32 GetMissionRunCount(void) {
    return (gMissionRunData->mCount);
}

u32 GetMissionRunCountLimit(void) {
    u32 countLimit = gRaceSetup->mMissionRunCountLimit;
    if (countLimit == 0) {
        countLimit = 1;
    }
    return countLimit;
}

s32 GetMissionRunBossCount(void) {
    return (gMissionRunData->mBossCount);
}

void AddMissionRunCountForKind7(void) {
    if (gRaceSetup->mMissionKind == '\a') {
        AddMissionRunCount();
    }
}

void AddMissionRunCountForMapObjectKind(s32 mapObjectKind) {
    RaceSetup *raceSetup = gRaceSetup;
    u32 missionKind = raceSetup->mMissionKind;
    if (missionKind == 3 || missionKind == 7 || missionKind == 0) {
        u32 missionObjectKind0 = raceSetup->mMissionMapObjectKind0;
        if (missionObjectKind0 == 0 && raceSetup->mMissionMapObjectKind1 == 0 &&
            raceSetup->mMissionMapObjectKind2 == 0 && raceSetup->mMissionMapObjectKind3 == 0 && mapObjectKind > 400 &&
            mapObjectKind < 500) {
            AddMissionRunCount();
            return;
        }
        if (mapObjectKind == missionObjectKind0 || mapObjectKind == raceSetup->mMissionMapObjectKind1 ||
            mapObjectKind == raceSetup->mMissionMapObjectKind2 || mapObjectKind == raceSetup->mMissionMapObjectKind3) {
            AddMissionRunCount();
        }
    }
}

void AddMissionRunPendingDropOnKartHit(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunPendingDrop(5);
    }
}

void AddMissionRunCountForKind4(void) {
    if (gRaceSetup->mMissionKind == 4) {
        AddMissionRunCount();
    }
}

void AddMissionRunCountForKind0(void) {
    if (gRaceSetup->mMissionKind == 0) {
        AddMissionRunCount();
    }
}

BOOL IsAnyBalloonUnparked(void) {
    MapObjectList *list;
    Balloon *balloon;
    s32 balloonIndex;

    list = FindMapObjectKindUpdateList(MAP_OBJECT_KIND_BALLOON);
    if (list != NULL) {
        for (balloonIndex = 0;
             balloonIndex < list->mMapObjectCount && (balloon = list->mMapObjects[balloonIndex]) != NULL;
             balloonIndex++) {
            if ((balloon->mMapObject.mFlags & 0x100) == 0) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

void SetMissionRunCountUpCallback(UnkFunc *callback) {
    gMissionRunData->mCountUpCallback = callback;
}

void SetMissionRunDropCallback(UnkFunc *callback) {
    gMissionRunData->mDropCallback = callback;
}

void SetMissionRunBossTransferCallback(UnkFunc *callback) {
    gMissionRunData->mBossTransferCallback = callback;
}

void AddMissionRunPendingDrop(u32 amount) {
    MissionRunData *missionRunData = gMissionRunData;
    u16 count = missionRunData->mCount;
    if (amount >= count) {
        amount = count;
    }
    missionRunData->mPendingDrop += amount;
}

void AddMissionRunPendingBossTransfer(u16 amount) {
    MissionRunData *missionRunData = gMissionRunData;
    u16 count = missionRunData->mCount;
    if (amount >= count) {
        amount = count;
    }
    missionRunData->mPendingBossTransfer += amount;
}

void AddMissionRunBossCount(short amount) {
    gMissionRunData->mBossCount += amount;
    if (gMissionRunData->mBossCount > GetMissionRunCountLimit()) {
        gMissionRunData->mBossCount = GetMissionRunCountLimit();
    }
}

void AddMissionRunPendingCountUp(s32 stepCount) {
    s32 stepIndex;

    for (stepIndex = 0; stepIndex < stepCount; stepIndex++) {
        if (++gMissionRunData->mPendingCountUp > GetMissionRunCountLimit()) {
            gMissionRunData->mPendingCountUp = GetMissionRunCountLimit();
            return;
        }
        if (gMissionRunData->mTimer == 0) {
            gMissionRunData->mTimer = gMissionRunData->mUnk_10;
        } else {
            gMissionRunData->mTimer += gMissionRunData->mUnk_14;
            if (gMissionRunData->mTimer > gMissionRunData->mUnk_12) {
                gMissionRunData->mTimer = gMissionRunData->mUnk_12;
            }
        }
    }
}

void AddMissionRunPendingCountUpFromBoss(s32 stepCount) {
    s32 stepIndex;

    if ((u32) stepCount >= gMissionRunData->mBossCount) {
        stepCount = gMissionRunData->mBossCount;
    }
    for (stepIndex = 0; stepIndex < stepCount; stepIndex++) {
        gMissionRunData->mBossCount--;
        if (++gMissionRunData->mPendingCountUp > GetMissionRunCountLimit()) {
            gMissionRunData->mPendingCountUp = GetMissionRunCountLimit();
            return;
        }
        if (gMissionRunData->mTimer == 0) {
            gMissionRunData->mTimer = gMissionRunData->mUnk_10;
        } else {
            gMissionRunData->mTimer += gMissionRunData->mUnk_16;
            if (gMissionRunData->mTimer > gMissionRunData->mUnk_12) {
                gMissionRunData->mTimer = gMissionRunData->mUnk_12;
            }
        }
    }
}
