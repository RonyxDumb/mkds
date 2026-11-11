#include "Main/Unknown/code_02094e1c.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ac000.h"

#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02093ff0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020918a8.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_021000d0.h"
#include "code_02147cd8.h"

void InitTeresaSpawner(TeresaSpawner *mapObject) {
    CreateParkedMapObjects(MAP_OBJECT_KIND_TERESA, mapObject->mMapObject.mCourseMapRow->mUnk_2a, mapObject);
}

static inline u32 TeresaSpawnerNextRandomBelow(RandomState64 *randomState64, u32 limit) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    if (limit == 0) {
        return randomState64->mValue >> 32;
    }
    return ((randomState64->mValue >> 32) * limit) >> 32;
}

static inline u16 func_020952dc_inline(u32 n) {
    RandomState64 *randomState64;
    u32 t;
    u32 m;
    if (n == 0x10000) {
        randomState64 = &gRaceProgress->mLocalRandom;
        randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
        return (randomState64->mValue >> 32) * 0x10000 >> 32;
    }
    randomState64 = &gRaceProgress->mLocalRandom;
    m = (u16) n;
    if (m == 0) {
        t = 0;
    } else {
        randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
        if (m == 0) {
            t = randomState64->mValue >> 32;
        } else {
            t = ((randomState64->mValue >> 32) * m) >> 32;
        }
    }
    return t;
}

void StartTeresasAtRandomPositions(TeresaSpawner *spawner, s32 teresaCountLimit, s32 spawnCount, s32 distanceLimit,
                                   s32 timerLimit) {
    s32 i;
    s32 k;
    s32 baseX;
    s32 baseY;
    s32 baseZ;
    float maxDistance;
    u32 distance;
    u16 angle;
    Vec3 position;

    if (GetUnparkedTeresaCount() < teresaCountLimit) {
        k = i = 0;
        for (; i < spawnCount; i++) {
            if (distanceLimit > 0) {
                maxDistance = 0.5f + (distanceLimit << 12);
            } else {
                maxDistance = (distanceLimit << 12) - 0.5f;
            }
            baseZ = 0;
            baseY = spawner->mMapObject.mPos.y;
            baseX = 0;
            distance = NextRandomBelow(GetRaceLocalRandom(), (s32) maxDistance);
            angle = NextRandomU16(GetRaceLocalRandom());
            position.x = baseX + TeresaSpawnerMulFixed12NoRound(distance, TeresaSpawnerFX_SinIdx(angle));
            position.y = baseY + NextRandomBelow(GetRaceLocalRandom(), k);
            position.z = baseZ + TeresaSpawnerMulFixed12NoRound(distance, TeresaSpawnerFX_CosIdx(angle));
            StartTeresa(&position);
        }
        spawner->mSpawnTimer = func_020952dc_inline((u16) timerLimit);
    }
}

void InitTeresaSpawnerObjects(MapObjectList *mapObjectList) {
    s32 i;
    TeresaSpawner *spawner;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (spawner = mapObjectList->mMapObjects[i]) != NULL; i++) {
        spawner->mNearCheckTimer = (u16) TeresaSpawnerNextRandomBelow(&gRaceProgress->mLocalRandom, 0xf);
    }
}

RandomState64 *GetRaceLocalRandom(void) {
    return &gRaceProgress->mLocalRandom;
}

u16 NextRandomU16(RandomState64 *randomState64) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    return ((randomState64->mValue >> 32) * 0x10000) >> 32;
}

s16 TeresaSpawnerFX_SinIdx(s32 angle) {
    return FX_SinIdx(angle);
}

s32 TeresaSpawnerMulFixed12NoRound(s32 multiplicand, s32 multiplier) {
    return MUL_FIXED12_NO_ROUND(multiplicand, multiplier);
}

s16 TeresaSpawnerFX_CosIdx(s32 angle) {
    return FX_CosIdx(angle);
}

void UpdateTeresaSpawner(void *mapObjectList, TeresaSpawner *spawner) {
    s32 t;
    s32 radius;
    s32 radiusFixed;
    s32 deltaX;
    s32 deltaZ;
    s32 i;
    BOOL k;
    s32 baseX;
    s32 baseY;
    s32 baseZ;
    float maxDistance;
    u32 distance;
    u16 angle;
    Kart *kart;
    Vec3 position;
    Vec3 *kartPos;

    t = spawner->mNearCheckTimer;
    spawner->mNearCheckTimer = t - 1;
    if (t <= 0) {
        spawner->mNearCheckTimer = 0xf;
        radius = spawner->mMapObject.mCourseMapRow->mUnk_28;
        kart = GetKart((u16) gRaceSetup->mEntryIndex);
        radiusFixed = radius << 12;
        kartPos = &kart->mPos;
        deltaX = kartPos->x - spawner->mMapObject.mPos.x;
        deltaZ = kartPos->z - spawner->mMapObject.mPos.z;
        if ((s64) deltaX * deltaX + (s64) deltaZ * deltaZ < (s64) radiusFixed * radiusFixed) {
            spawner->mEntryKartNear = TRUE;
        } else {
            spawner->mEntryKartNear = FALSE;
        }
    }
    switch (spawner->mState) {
        case 0:
            k = FALSE;
            if (GetCurrentCameraKind() == 2) {
                for (i = 0; i < spawner->mMapObject.mCourseMapRow->mUnk_2a; i++) {
                    if (spawner->mMapObject.mCourseMapRow->mUnk_28 > 0) {
                        maxDistance = 0.5f + (spawner->mMapObject.mCourseMapRow->mUnk_28 << 12);
                    } else {
                        maxDistance = (spawner->mMapObject.mCourseMapRow->mUnk_28 << 12) - 0.5f;
                    }
                    baseZ = spawner->mMapObject.mPos.z;
                    baseY = spawner->mMapObject.mPos.y;
                    baseX = spawner->mMapObject.mPos.x;
                    distance = NextRandomBelow(GetRaceLocalRandom(), (s32) maxDistance);
                    angle = NextRandomU16(GetRaceLocalRandom());
                    position.x = baseX + TeresaSpawnerMulFixed12NoRound(distance, TeresaSpawnerFX_SinIdx(angle));
                    position.y = baseY + NextRandomBelow(GetRaceLocalRandom(), k);
                    position.z = baseZ + TeresaSpawnerMulFixed12NoRound(distance, TeresaSpawnerFX_CosIdx(angle));
                    StartTeresa(&position);
                }
            }
            spawner->mState = 1;
        case 1:
            if (GetCurrentCameraKind() == 2) {
                break;
            }
            if (spawner->mEntryKartNear == FALSE) {
                break;
            }
            if (GetCurrentCameraKind() != 0) {
                StartTeresasAtRandomPositions(spawner, 0x1e, 0x14, 0x1f4, 4);
            } else {
                StartTeresasAtRandomPositions(spawner, 6, 4, 0xa, 0x14);
            }
            spawner->mState = 2;
            break;
        case 2:
            t = spawner->mSpawnTimer;
            spawner->mSpawnTimer = t - 1;
            if (t > 0) {
                break;
            }
            if (spawner->mEntryKartNear != FALSE) {
                if (GetCurrentCameraKind() != 0) {
                    StartTeresasAtRandomPositions(spawner, 0x1e, 1, 0x1f4, 4);
                } else {
                    StartTeresasAtRandomPositions(spawner, 6, 1, 0xa, 0x14);
                }
            } else {
                ClearTeresaTimers();
                spawner->mState = 1;
            }
            break;
    }
    if (GetUnparkedTeresaCount() > 0) {
        StartWhileRequestedFullVolumeWrapper(&GetKart((u16) gRaceSetup->mEntryIndex)->mSoundSource, 0x11e);
    }
}

MapObjectKindData *CreateTeresaSpawnerKindData(void) {
    s32 mode;

    mode = gRaceSetup->mMode;
    if (mode == MODE_VS || mode == MODE_WIFI) {
        if (GetCurrentCameraKind() == 0) {
            return 0;
        }
    }
    return CreateEmptyMapObjectKindData();
}

void CreateTeresaSpawnerUpdateList(void) {
    CreateMapObjectUpdateList(InitTeresaSpawnerObjects, UpdateTeresaSpawner, NULL);
}
