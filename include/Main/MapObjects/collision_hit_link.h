#pragma once

#include "types.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/data_02158000.h"

unsigned int KoopaBlockState2ReturnArgument(unsigned int value);

unsigned int KoopaBlockState0ReturnArgument(unsigned int value);

extern const MapObjectList gKoopaBlockUpdateListData;
extern const MapObjectDrawList gKoopaBlockDrawListData;
extern const MapObjectKindData gKoopaBlockKindData;
extern void *gKoopaBlockDrawList;
extern struct MapObjectList *gKoopaBlockUpdateList;
