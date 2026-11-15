#pragma once

#include "types.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/data_02158000.h"

#define KOOPA_BLOCK_SOUND_ID 0x17e

void KoopaBlockDecelerateNop(void *stateObject);

void KoopaBlockAccelerateNop(void *stateObject);

extern const MapObjectList gKoopaBlockUpdateListData;
extern const MapObjectDrawList gKoopaBlockDrawListData;
extern const MapObjectKindData gKoopaBlockKindData;
extern MapObjectDrawList *gKoopaBlockDrawList;
extern struct MapObjectList *gKoopaBlockUpdateList;
