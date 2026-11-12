#pragma once
#include "types.h"
#include "01/MapObjects/data_0209bc74.h"

unsigned int SunSetupDrawReturnArgument(unsigned int value);

void CreateSunAndSunLOD(void *mapObjectList);

typedef struct Sun Sun;

void InitSun(Sun *sun); /* creates 30 MAP_OBJECT_KIND_SUN_FIREBALL pool objects */

extern struct MapObjectModel *gSun;
extern struct MapObjectModel *gSunLOD;
