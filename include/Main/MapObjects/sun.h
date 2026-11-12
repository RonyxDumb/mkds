#pragma once
#include "types.h"

unsigned int SunSetupDrawReturnArgument(unsigned int value);

void CreateSunAndSunLOD(void *mapObjectList);

typedef struct Sun Sun;

void InitSun(Sun *sun); /* creates 30 MAP_OBJECT_KIND_SUN_FIREBALL pool objects */
