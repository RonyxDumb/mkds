#include "Main/MapObjects/basabasa_burst.h"
#include "Main/MapObjects/cow.h"

#include "Main/MapObjects/basabasa.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Kart/karts.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/bound.h"

MapObjectKindDescriptor gBasabasaBurstKindDescriptor = {0,
                                                        {0, 0},
                                                        0xb0,
                                                        InitBasabasaBurst,
                                                        CreateEmptyMapObjectKindData,
                                                        0,
                                                        0,
                                                        0,
                                                        CreateBasabasaBurstUpdateList};

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
        if (burstObject->mMapObject.mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI) {
            burstObject->mTimer = (u16) (BasabasaBurstMapObjectRandomBelowU16(25) + 200);
        }
    }
}

static inline s64 BasabasaBurstXzDistanceSquared(const Vec3 *firstPos, const Vec3 *secondPos) {
    s32 deltaX;
    s32 deltaZ;

    deltaX = firstPos->x - secondPos->x;
    deltaZ = firstPos->z - secondPos->z;
    return SQUARE_SUM2(deltaX, deltaZ);
}

static inline BOOL BasabasaBurstIsKartNearInAngle(BasabasaBurst *burst, s32 burstAngle) {
    s32 kartIndex;
    BOOL isHumanGhostOrPeer;
    s32 angleDifference;
    Kart *kart;

    for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex++) {
        isHumanGhostOrPeer = FALSE;
        if (gRaceSetup->mCurrentEntries[(u16) kartIndex].mPlayer.mKind <= PLAYER_KIND_PEER &&
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
            if (burstObject->mMapObject.mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI) {
                if (burstObject->mTimer-- <= 0) {
                    burstObject->mTimer = BASABASA_BURST_TIMER_FRAMES;
                    burstObject->mState = 1;
                }
                return;
            }
            if (BasabasaBurstIsKartNearInAngle(burstObject, burstObject->mMapObject.mAngle) != FALSE) {
                burstObject->mTimer = BASABASA_BURST_TIMER_FRAMES;
                burstObject->mState = 1;
            }
            return;
        case 1:
            break;
        default:
            return;
    }
    if (burstObject->mCycleFrames == BASABASA_BURST_CYCLE_FRAMES) {
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
    if (burstObject->mMapObject.mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI) {
        burstObject->mTimer = (u16) (BasabasaBurstMapObjectRandomBelowU16(25) + 200);
    }
}

MapObjectList *CreateBasabasaBurstUpdateList(void) {
    return CreateMapObjectUpdateList(InitBasabasaBurstObjects, UpdateBasabasaBurst, NULL);
}
