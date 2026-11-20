#pragma once

#include "types.h"
#include "Main/MapObjects/attractor.h"

#define TOWN_MONTE_BOUNCE_SPEED_PER_FRAME 0x4000
#define TOWN_MONTE_BOUNCE_OFFSET_MAX 0x16c000

extern void *gTownMonte;
extern struct MapObjectKindData *gCourseMapRowKindData[19];
