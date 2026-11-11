#include "Main/Unknown/code_02092b3c.h"
#include "Main/Unknown/code_020918a8.h"
#include "Main/Unknown/code_020ac000.h"

#include "Main/Unknown/code_0209219c.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02045874.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_021000d0.h"

void InitBasabasaBurst(u32 mapObject) {
    u32 value = mapObject;
    u32 parkedCount;
    u32 sourceMapObject;
    u32 unused;
    sourceMapObject = value;
    value = MAP_OBJECT_KIND_BASABASA;
    parkedCount = 8u;
    CreateParkedMapObjects(value, parkedCount, (void *) sourceMapObject);
}

static inline u32 BasabasaBurstMapObjectRandomBelow(u32 limit) {
    RandomState64 *mapObjectRandom;

    mapObjectRandom = GetMapObjectRandom();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return ((mapObjectRandom->mValue >> 32) * limit) >> 32;
}

static inline u16 BasabasaBurstMapObjectRandomBelowU16(u32 limit) {
    RandomState64 *mapObjectRandom;

    mapObjectRandom = GetMapObjectRandom();
    mapObjectRandom->mValue = mapObjectRandom->mMultiplier * mapObjectRandom->mValue + mapObjectRandom->mIncrement;
    return (u32) (((mapObjectRandom->mValue >> 32) * limit) >> 32);
}

void InitBasabasaBurstObjects(MapObjectList *mapObjectList) {
    s32 objectIndex;
    BasabasaBurst *burstObject;

    if (mapObjectList == NULL) {
        return;
    }
    for (objectIndex = 0; objectIndex < mapObjectList->mMapObjectCount &&
                          (burstObject = mapObjectList->mMapObjects[objectIndex]) != NULL;
         objectIndex++) {
        if (burstObject->mMapObject.mFlags & 0x800) {
            burstObject->mTimer = (u16) (BasabasaBurstMapObjectRandomBelowU16(25) + 200);
        }
    }
}

static inline s64 BasabasaBurstXzDistanceSquared(const Vec3 *firstPos, const Vec3 *secondPos) {
    s32 deltaX;
    s32 deltaZ;

    deltaX = firstPos->x - secondPos->x;
    deltaZ = firstPos->z - secondPos->z;
    return (s64) deltaX * deltaX + (s64) deltaZ * deltaZ;
}

static inline BOOL BasabasaBurstIsKartNearInAngle(BasabasaBurst *burst, s32 burstAngle) {
    s32 kartIndex;
    BOOL isHumanGhostOrPeer;
    s32 angleDifference;
    Kart *kart;

    for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex++) {
        isHumanGhostOrPeer = FALSE;
        if (gRaceSetup->mCurrentEntries[(u16) kartIndex].mPlayer.mKind <= 3 &&
            ((1 << gRaceSetup->mCurrentEntries[(u16) kartIndex].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
            isHumanGhostOrPeer = TRUE;
        }
        if (isHumanGhostOrPeer == FALSE && kartIndex != gRaceSetup->mEntryIndex) {
            continue;
        }
        kart = GetKart((u16) kartIndex);
        if (BasabasaBurstXzDistanceSquared(&kart->mPos, &burst->mMapObject.mPos) >= 0x15f900000000LL) {
            continue;
        }
        angleDifference =
            FX_Atan2Idx(kart->mPos.x - burst->mMapObject.mPos.x, kart->mPos.z - burst->mMapObject.mPos.z) - burstAngle;
        if (angleDifference < -0x1f40) {
            continue;
        }
        if (angleDifference <= 0x1f40) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline void BasabasaBurstSetRandomPos(Vec3 *outPos, s32 baseX, s32 baseY, s32 baseZ) {
    outPos->x = baseX - 0x5000 + BasabasaBurstMapObjectRandomBelow(0xa000);
    outPos->y = baseY - 0x5000 + BasabasaBurstMapObjectRandomBelow(0xa000);
    outPos->z = baseZ - 0x28000 + BasabasaBurstMapObjectRandomBelow(0x50000);
}

s16 BasabasaBurstFX_SinIdx(s32 angle) {
    return FX_SinIdx(angle);
}

s32 BasabasaBurstMulFixed12NoRound(s32 multiplicand, s32 multiplier) {
    return MUL_FIXED12_NO_ROUND(multiplicand, multiplier);
}

s16 BasabasaBurstFX_CosIdx(s32 angle) {
    return FX_CosIdx(angle);
}

void UpdateBasabasaBurst(void *mapObjectList, BasabasaBurst *burstObject) {
    s32 spawnIndex;
    s32 horizontalSpeed;
    u16 angle;
    s32 nextCycleFrames;
    Vec3 basabasaPos;
    Vec3 basabasaVelocity;

    switch (burstObject->mState) {
        case 0:
            if (GetCurrentCameraKind() == 2) {
                burstObject->mState = 1;
                return;
            }
            if (burstObject->mMapObject.mFlags & 0x800) {
                if (burstObject->mTimer-- <= 0) {
                    burstObject->mTimer = 4;
                    burstObject->mState = 1;
                }
                return;
            }
            if (BasabasaBurstIsKartNearInAngle(burstObject, burstObject->mMapObject.mAngle) != FALSE) {
                burstObject->mTimer = 4;
                burstObject->mState = 1;
            }
            return;
        case 1:
            break;
        default:
            return;
    }
    if (burstObject->mCycleFrames == 0x14) {
        for (spawnIndex = 0; spawnIndex < 2; spawnIndex++) {
            BasabasaBurstSetRandomPos(&basabasaPos, burstObject->mMapObject.mPos.x,
                                      burstObject->mMapObject.mPos.y + 0x23000, burstObject->mMapObject.mPos.z);
            angle = burstObject->mMapObject.mAngle;
            horizontalSpeed = NextRandomBelow(GetMapObjectRandom(), 0x1000) + 0x2000;
            angle = angle - 0xbb8 + NextRandomBelowU16(GetMapObjectRandom(), 0x1770);
            basabasaVelocity.x = BasabasaBurstMulFixed12NoRound(horizontalSpeed, BasabasaBurstFX_SinIdx(angle));
            basabasaVelocity.y = NextRandomBelow(GetMapObjectRandom(), 0x400) - 0xa00;
            basabasaVelocity.z = BasabasaBurstMulFixed12NoRound(horizontalSpeed, BasabasaBurstFX_CosIdx(angle));
            if (spawnIndex == 0 && burstObject->mBurstCount == 0) {
                StartBasabasa(0x8c, &basabasaPos, &basabasaVelocity, 0xf, 1, spawnIndex == 0 ? 2 : 0);
            } else {
                StartBasabasa(0x8c, &basabasaPos, &basabasaVelocity, 0xf, 0, spawnIndex == 0 ? 2 : 0);
            }
        }
        burstObject->mBurstCount += 1;
        if (burstObject->mBurstCount >= 3) {
            burstObject->mBurstCount = 0;
        }
    }
    nextCycleFrames = burstObject->mCycleFrames + 1;
    if (nextCycleFrames >= 0x32) {
        nextCycleFrames = 0;
    }
    burstObject->mCycleFrames = nextCycleFrames;
    if (burstObject->mCycleFrames != 0) {
        return;
    }
    if (burstObject->mTimer-- > 0) {
        return;
    }
    burstObject->mBurstCount = 0;
    burstObject->mState = 0;
    if (burstObject->mMapObject.mFlags & 0x800) {
        burstObject->mTimer = (u16) (BasabasaBurstMapObjectRandomBelowU16(25) + 200);
    }
}

void CreateBasabasaBurstUpdateList(void) {
    CreateMapObjectUpdateList(InitBasabasaBurstObjects, UpdateBasabasaBurst, NULL);
}
