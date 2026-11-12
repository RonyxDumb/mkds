#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"

// Object of 0xb0 bytes: the MapObject it starts with, then four words.
typedef struct TeresaSpawner {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mNearCheckTimer;
    /* a4 */ BOOL mEntryKartNear;
    /* a8 */ s32 mSpawnTimer;
    /* ac */ s32 mState;
} TeresaSpawner;

#include "Main/MapObjects/map_object_park.h"

void CreateTeresaSpawnerUpdateList(void);
MapObjectKindData *CreateTeresaSpawnerKindData(void);
void UpdateTeresaSpawner(void *mapObjectList, TeresaSpawner *spawner);
s16 TeresaSpawnerFX_CosIdx(s32 angle);
s32 TeresaSpawnerMulFixed12NoRound(s32 multiplicand, s32 multiplier);
s16 TeresaSpawnerFX_SinIdx(s32 angle);
u16 NextRandomU16(RandomState64 *randomState64);
RandomState64 *GetRaceLocalRandom(void);
void InitTeresaSpawnerObjects(MapObjectList *mapObjectList);
void StartTeresasAtRandomPositions(TeresaSpawner *spawner, s32 teresaCountLimit, s32 spawnCount, s32 distanceLimit,
                                   s32 timerLimit);
void InitTeresaSpawner(TeresaSpawner *mapObject);
