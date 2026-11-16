#include "01/code_0218155c.h"

#include "01/code_02188950.h"
#include "01/code_02188e88.h"
#include "01/unk_021a9000.h"
#include "01/code_02181000.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/System/Heap.h"
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

MissionRunData *mrcnt_sMissionRunController;

void AddMissionRunMapObject(Unk02188950 *mapObject) {
    u8 kartCount;
    u16 entryIndex;

    kartCount = gRaceMultiConfig->mKartCount;
    entryIndex = mrcnt_sMissionRunController->mMapObjectCount + kartCount;
    mrcnt_sMissionRunController->mMapObjects[entryIndex - kartCount] = mapObject;
    mgcnt_resetDriverState(entryIndex);
    mrcnt_sMissionRunController->mMapObjectCount++;
}

Unk02188950 *GetMissionRunMapObject(int entryIndex) {
    return mrcnt_sMissionRunController->mMapObjects[entryIndex - gRaceMultiConfig->mKartCount];
}

u8 func_ov001_02181b54(void) {
    return gRaceMultiConfig->mKartCount;
}

u16 GetMissionRunMapObjectLastIndex(void) {
    return mrcnt_sMissionRunController->mMapObjectCount + gRaceMultiConfig->mKartCount - 1;
}

void mrcnt_increaseValue(void) {
    MissionRunData *missionRunData;
    u32 countLimit;

    if ((gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mgcnt_hasWinnerBeenDecided() : 0) != FALSE) {
        return;
    }
    missionRunData = mrcnt_sMissionRunController;
    countLimit = mrcnt_getTargetValue();
    if (missionRunData->mCount >= countLimit) {
        return;
    }
    missionRunData->mCount = missionRunData->mCount + 1;
    sound_handleMissionValueChange(mrcnt_sMissionRunController->mCount, mrcnt_getTargetValue());
    switch (gRaceMultiConfig->mMissionKind) {
        case 0:
        case 1:
        case 3:
        case 5:
        case 7:
            countLimit = mrcnt_getTargetValue();
            if (mrcnt_sMissionRunController->mCount >= countLimit) {
                rstat_winMission(gRaceMultiConfig->mEntryIndex);
            }
            break;
    }
}

Vec3 *mrcnt_getPlayerPosition(void) {
    return &mrcnt_sMissionRunController->mKartPos;
}

Vec3 *mrcnt_getPrevPlayerPosition(void) {
    return &mrcnt_sMissionRunController->mPrevKartPos;
}

u16 mrcnt_getPlayerYRot(void) {
    return (mrcnt_sMissionRunController->mKartHeadingAngle);
}

u16 mrcnt_getPrevPlayerYRot(void) {
    return (mrcnt_sMissionRunController->mPrevKartHeadingAngle);
}

void mrcnt_init(void) {
    Kart *kart;
    MissionRunData *missionRunData;

    mrcnt_sMissionRunController = heap_alloc(proc_getHeap(proc_getCurrent()), 0x68);
    kart = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    missionRunData = mrcnt_sMissionRunController;
    missionRunData->mPrevKartPos = kart->mPos;
    missionRunData->mKartPos = missionRunData->mPrevKartPos;
    missionRunData->mPrevKartHeadingAngle = kart->mHeadingAngle;
    missionRunData = mrcnt_sMissionRunController;
    missionRunData->mKartHeadingAngle = missionRunData->mPrevKartHeadingAngle;
}

void mrcnt_update(void) {
    Kart *kart;
    MissionRunData *missionRunData;

    kart = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
    if ((kart->field48 & 0x200) == 0) {
        missionRunData = mrcnt_sMissionRunController;
        missionRunData->mPrevKartPos = missionRunData->mKartPos;
        missionRunData->mPrevKartHeadingAngle = missionRunData->mKartHeadingAngle;
        missionRunData = mrcnt_sMissionRunController;
        missionRunData->mKartPos = kart->mPos;
        missionRunData->mKartHeadingAngle = kart->mHeadingAngle;
    }
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mgcnt_hasWinnerBeenDecided() : 0) {
        if (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mgcnt_isDriverDead((u16) gRaceMultiConfig->mEntryIndex) : 0) {
            if (mgcnt_getDriverBalloonShineCount(gRaceMultiConfig->mEntryIndex)) {
                mrcnt_sMissionRunController->mSinceHitCallbackFrames += 1;
                if (mrcnt_sMissionRunController->mSinceHitCallbackFrames > 0xf) {
                    mrcnt_sMissionRunController->mSinceHitCallbackFrames = 0;
                    mgcnt_20A1748(gRaceMultiConfig->mEntryIndex);
                    return;
                }
            }
        }
        return;
    }
    {
        u32 missionKind = gRaceMultiConfig->mMissionKind;
        if (missionKind == 1 || missionKind == 5) {
            if (race_getFrameCounterModulo8() == 0) {
                missionRunData = mrcnt_sMissionRunController;
                if (missionRunData->mPendingBossTransfer != 0) {
                    missionRunData->mPendingBossTransfer -= 1;
                    missionRunData = mrcnt_sMissionRunController;
                    if (missionRunData->mCount != 0) {
                        missionRunData->mCount -= 1;
                        mrcnt_sMissionRunController->mBossCount += 1;
                    }
                    if (mrcnt_sMissionRunController->mBossTransferCallback != NULL) {
                        mrcnt_sMissionRunController->mBossTransferCallback();
                    }
                    mrcnt_sMissionRunController->mTimer = 0;
                } else if (missionRunData->mPendingDrop != 0) {
                    missionRunData->mPendingDrop -= 1;
                    missionRunData = mrcnt_sMissionRunController;
                    if (missionRunData->mCount != 0) {
                        missionRunData->mCount -= 1;
                    }
                    if (mrcnt_sMissionRunController->mDropCallback != NULL) {
                        mrcnt_sMissionRunController->mDropCallback();
                    }
                    mrcnt_sMissionRunController->mTimer = 0;
                } else if (missionRunData->mPendingCountUp != 0) {
                    missionRunData->mPendingCountUp -= 1;
                    mrcnt_increaseValue();
                    if (mrcnt_sMissionRunController->mCountUpCallback != NULL) {
                        mrcnt_sMissionRunController->mCountUpCallback();
                    }
                }
            }
            missionRunData = mrcnt_sMissionRunController;
            if (missionRunData->mTimer != 0) {
                missionRunData->mTimer -= 1;
                missionRunData = mrcnt_sMissionRunController;
                if (missionRunData->mTimer == 0) {
                    if (missionRunData->mTimerEndCallback != NULL) {
                        missionRunData->mTimerEndCallback();
                    }
                }
            }
        }
    }
}

void func_ov001_02181844(u16 a, u16 b, u16 c, u16 d) {
    mrcnt_sMissionRunController->field10 = a;
    mrcnt_sMissionRunController->field12 = b;
    mrcnt_sMissionRunController->field14 = c;
    mrcnt_sMissionRunController->field16 = d;
}

s32 GetMissionRunTimer(void) {
    return (mrcnt_sMissionRunController->mTimer);
}

void SetMissionRunTimer(u32 timer) {
    mrcnt_sMissionRunController->mTimer = timer;
}

u32 mrcnt_getCurrentValue(void) {
    return (mrcnt_sMissionRunController->mCount);
}

u32 mrcnt_getTargetValue(void) {
    u32 countLimit = gRaceMultiConfig->mMissionRunCountLimit;
    if (countLimit == 0) {
        countLimit = 1;
    }
    return countLimit;
}

s32 mrcnt_getStolenCoinCount(void) {
    return (mrcnt_sMissionRunController->mBossCount);
}

void mrcnt_notifyBossDamage(void) {
    if (gRaceMultiConfig->mMissionKind == '\a') {
        mrcnt_increaseValue();
    }
}

void mrcnt_notifyMObjDamage(s32 b) {
    RaceSetup *raceSetup = gRaceMultiConfig;
    u32 missionKind = raceSetup->mMissionKind;
    if (missionKind == 3 || missionKind == 7 || missionKind == 0) {
        u32 a = raceSetup->field3C;
        if (a == 0 && raceSetup->field3E == 0 && raceSetup->field40 == 0 && raceSetup->field42 == 0 && b > 400 &&
            b < 500) {
            mrcnt_increaseValue();
            return;
        }
        if (b == a || b == raceSetup->field3E || b == raceSetup->field40 || b == raceSetup->field42) {
            mrcnt_increaseValue();
        }
    }
}

void mrcnt_notifyPlayerDamage(void) {
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        mrcnt_loseCoins(5);
    }
}

void mrcnt_notifyPowerSlide(void) {
    if (gRaceMultiConfig->mMissionKind == 4) {
        mrcnt_increaseValue();
    }
}

void mrcnt_notifyMissionEndWinAreaReached(void) {
    if (gRaceMultiConfig->mMissionKind == 0) {
        mrcnt_increaseValue();
    }
}

BOOL func_ov001_021816b4(void) {
    BalloonList *list;
    Balloon *balloon;
    s32 i;

    list = mobj_getLogicPartForObjectId(MAP_OBJECT_KIND_BALLOON);
    if (list != NULL) {
        for (i = 0; i < list->mObjectCount && (balloon = list->mObjects[i]) != NULL; i++) {
            if ((balloon->field0.mFlags & 0x100) == 0) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

void mrcnt_setCoinCollectFunc(UnkFunc *callback) {
    mrcnt_sMissionRunController->mCountUpCallback = callback;
}

void mrcnt_setCoinLoseFunc(UnkFunc *callback) {
    mrcnt_sMissionRunController->mDropCallback = callback;
}

void mrcnt_setCoinStealFunc(UnkFunc *callback) {
    mrcnt_sMissionRunController->mBossTransferCallback = callback;
}

void mrcnt_loseCoins(u32 amount) {
    MissionRunData *missionRunData = mrcnt_sMissionRunController;
    u16 count = missionRunData->mCount;
    if (amount >= count) {
        amount = count;
    }
    missionRunData->mPendingDrop += amount;
}

void mrcnt_stealCoins(u16 amount) {
    MissionRunData *missionRunData = mrcnt_sMissionRunController;
    u16 count = missionRunData->mCount;
    if (amount >= count) {
        amount = count;
    }
    missionRunData->mPendingBossTransfer += amount;
}

void mrcnt_updateStolenCoinCount(short amount) {
    mrcnt_sMissionRunController->mBossCount += amount;
    if (mrcnt_sMissionRunController->mBossCount > mrcnt_getTargetValue()) {
        mrcnt_sMissionRunController->mBossCount = mrcnt_getTargetValue();
    }
}

void mrcnt_collectCoins(s32 stepCount) {
    s32 i;

    for (i = 0; i < stepCount; i++) {
        if (++mrcnt_sMissionRunController->mPendingCountUp > mrcnt_getTargetValue()) {
            mrcnt_sMissionRunController->mPendingCountUp = mrcnt_getTargetValue();
            return;
        }
        if (mrcnt_sMissionRunController->mTimer == 0) {
            mrcnt_sMissionRunController->mTimer = mrcnt_sMissionRunController->field10;
        } else {
            mrcnt_sMissionRunController->mTimer += mrcnt_sMissionRunController->field14;
            if (mrcnt_sMissionRunController->mTimer > mrcnt_sMissionRunController->field12) {
                mrcnt_sMissionRunController->mTimer = mrcnt_sMissionRunController->field12;
            }
        }
    }
}

void mrcnt_regainStolenCoins(s32 stepCount) {
    s32 i;

    if ((u32) stepCount >= mrcnt_sMissionRunController->mBossCount) {
        stepCount = mrcnt_sMissionRunController->mBossCount;
    }
    for (i = 0; i < stepCount; i++) {
        mrcnt_sMissionRunController->mBossCount--;
        if (++mrcnt_sMissionRunController->mPendingCountUp > mrcnt_getTargetValue()) {
            mrcnt_sMissionRunController->mPendingCountUp = mrcnt_getTargetValue();
            return;
        }
        if (mrcnt_sMissionRunController->mTimer == 0) {
            mrcnt_sMissionRunController->mTimer = mrcnt_sMissionRunController->field10;
        } else {
            mrcnt_sMissionRunController->mTimer += mrcnt_sMissionRunController->field16;
            if (mrcnt_sMissionRunController->mTimer > mrcnt_sMissionRunController->field12) {
                mrcnt_sMissionRunController->mTimer = mrcnt_sMissionRunController->field12;
            }
        }
    }
}
