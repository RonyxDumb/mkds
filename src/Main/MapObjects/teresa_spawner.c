#include "Main/MapObjects/teresa_spawner.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/Race/data_020f36d8.h"

#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/teresa.h"
#include "Main/Kart/kart_drift.h"
#include "Main/MapObjects/cow.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/bound.h"
#include "Main/Kart/karts.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "code_02147cd8.h"

MapObjectKindDescriptor gTeresaSpawnerKindDescriptor = {0,
                                                        {0, 0},
                                                        0xb0,
                                                        (void (*)(void *, CourseMapRow *, void *)) InitTeresaSpawner,
                                                        CreateTeresaSpawnerKindData,
                                                        0,
                                                        0,
                                                        0,
                                                        CreateTeresaSpawnerUpdateList};

void InitTeresaSpawner(TeresaSpawner *mapObject) {
    CreateParkedMapObjects(MAP_OBJECT_KIND_TERESA, mapObject->mMapObject.mCourseMapRow->mSettings[1], mapObject);
}

static inline u32 TeresaSpawnerNextRandomBelow(RandomState64 *randomState64, u32 limit) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    if (limit == 0) {
        return randomState64->mValue >> 32;
    }
    return ((randomState64->mValue >> 32) * limit) >> 32;
}

static inline u16 TeresaSpawnerLocalRandomBelowU16(u32 limit) {
    RandomState64 *randomState64;
    u32 value;
    u32 limitU16;
    if (limit == 0x10000) {
        randomState64 = &gRaceProgress->mLocalRandom;
        randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
        return (randomState64->mValue >> 32) * 0x10000 >> 32;
    }
    randomState64 = &gRaceProgress->mLocalRandom;
    limitU16 = (u16) limit;
    if (limitU16 == 0) {
        value = 0;
    } else {
        randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
        if (limitU16 == 0) {
            value = randomState64->mValue >> 32;
        } else {
            value = ((randomState64->mValue >> 32) * limitU16) >> 32;
        }
    }
    return value;
}

void StartTeresasAtRandomPositions(TeresaSpawner *spawner, s32 teresaCountLimit, s32 spawnCount, s32 distanceLimit,
                                   s32 timerLimit) {
    s32 spawnIndex;
    s32 randomRange;
    s32 baseX;
    s32 baseY;
    s32 baseZ;
    float maxDistance;
    u32 distance;
    u16 angle;
    Vec3 position;

    if (GetUnparkedTeresaCount() < teresaCountLimit) {
        randomRange = spawnIndex = 0;
        for (; spawnIndex < spawnCount; spawnIndex++) {
            if (distanceLimit > 0) {
                maxDistance = 0.5f + TO_FIXED12(distanceLimit);
            } else {
                maxDistance = TO_FIXED12(distanceLimit) - 0.5f;
            }
            baseZ = 0;
            baseY = spawner->mMapObject.mPos.y;
            baseX = 0;
            distance = NextRandomBelow(GetRaceLocalRandom(), (s32) maxDistance);
            angle = NextRandomU16(GetRaceLocalRandom());
            position.x = baseX + TeresaSpawnerMulFixed12NoRound(distance, TeresaSpawnerFX_SinIdx(angle));
            position.y = baseY + NextRandomBelow(GetRaceLocalRandom(), randomRange);
            position.z = baseZ + TeresaSpawnerMulFixed12NoRound(distance, TeresaSpawnerFX_CosIdx(angle));
            StartTeresa(&position);
        }
        spawner->mSpawnTimer = TeresaSpawnerLocalRandomBelowU16((u16) timerLimit);
    }
}

void InitTeresaSpawnerObjects(MapObjectList *mapObjectList) {
    s32 mapObjectIndex;
    TeresaSpawner *spawner;

    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (spawner = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
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
    s32 timer;
    s32 radius;
    s32 radiusFixed;
    s32 deltaX;
    s32 deltaZ;
    s32 spawnIndex;
    BOOL randomRange;
    s32 baseX;
    s32 baseY;
    s32 baseZ;
    float maxDistance;
    u32 distance;
    u16 angle;
    Kart *kart;
    Vec3 position;
    Vec3 *kartPos;

    timer = spawner->mNearCheckTimer;
    spawner->mNearCheckTimer = timer - 1;
    if (timer <= 0) {
        spawner->mNearCheckTimer = 0xf;
        radius = spawner->mMapObject.mCourseMapRow->mSettings[0];
        kart = GetKart((u16) gRaceSetup->mEntryIndex);
        radiusFixed = TO_FIXED12(radius);
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
            randomRange = FALSE;
            if (GetCurrentCameraKind() == 2) {
                for (spawnIndex = 0; spawnIndex < spawner->mMapObject.mCourseMapRow->mSettings[1]; spawnIndex++) {
                    if (spawner->mMapObject.mCourseMapRow->mSettings[0] > 0) {
                        maxDistance = 0.5f + TO_FIXED12(spawner->mMapObject.mCourseMapRow->mSettings[0]);
                    } else {
                        maxDistance = TO_FIXED12(spawner->mMapObject.mCourseMapRow->mSettings[0]) - 0.5f;
                    }
                    baseZ = spawner->mMapObject.mPos.z;
                    baseY = spawner->mMapObject.mPos.y;
                    baseX = spawner->mMapObject.mPos.x;
                    distance = NextRandomBelow(GetRaceLocalRandom(), (s32) maxDistance);
                    angle = NextRandomU16(GetRaceLocalRandom());
                    position.x = baseX + TeresaSpawnerMulFixed12NoRound(distance, TeresaSpawnerFX_SinIdx(angle));
                    position.y = baseY + NextRandomBelow(GetRaceLocalRandom(), randomRange);
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
            timer = spawner->mSpawnTimer;
            spawner->mSpawnTimer = timer - 1;
            if (timer > 0) {
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

MapObjectList *CreateTeresaSpawnerUpdateList(void) {
    return CreateMapObjectUpdateList(InitTeresaSpawnerObjects, UpdateTeresaSpawner, NULL);
}
