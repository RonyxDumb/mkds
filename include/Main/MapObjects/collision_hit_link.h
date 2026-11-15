#pragma once

#include "types.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/data_02158000.h"

void KoopaBlockState2Nop(KoopaBlock *koopaBlock);

void KoopaBlockState0Nop(KoopaBlock *koopaBlock);

extern const MapObjectList gKoopaBlockUpdateListData;
extern const MapObjectDrawList gKoopaBlockDrawListData;
extern const MapObjectKindData gKoopaBlockKindData;
extern MapObjectDrawList *gKoopaBlockDrawList;
extern struct MapObjectList *gKoopaBlockUpdateList;
