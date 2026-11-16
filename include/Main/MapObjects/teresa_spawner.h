#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"

// Object of 0xb0 bytes: the MapObject it starts with, then four words.
// TeresaSpawner.mState: the first spawn, waiting for the entry kart to come near, and spawning on the timer.
#define TERESA_SPAWNER_STATE_FIRST_SPAWN 0
#define TERESA_SPAWNER_STATE_WAIT_KART_NEAR 1
#define TERESA_SPAWNER_STATE_SPAWN_ON_TIMER 2

// A Teresa spawner map object: its kart-near check and spawn timers and its state.
typedef struct TeresaSpawner {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mNearCheckTimer;
    /* a4 */ BOOL mEntryKartNear;
    /* a8 */ s32 mSpawnTimer;
    /* ac */ s32 mState;
} TeresaSpawner;

#include "Main/MapObjects/map_object_park.h"

#define TERESA_NEAR_CHECK_FRAMES 0xf

MapObjectList *CreateTeresaSpawnerUpdateList(void);
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
