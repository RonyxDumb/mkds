#pragma once
#include "types.h"
#include "01/MapObjects/map_object_model.h"

#define SUN_FIRST_FIREBALL_DELAY_FRAMES 5
#define SUN_PAUSE_FRAMES 0x1e
#define SUN_SHOOT_FIREBALL_COUNT 2

#define SUN_PATH_SPEED 0x3c000

void SunSetupDrawNop(void);

void CreateSunAndSunLOD(void *mapObjectList);

typedef struct Sun Sun;

void InitSun(Sun *sun); /* creates 30 MAP_OBJECT_KIND_SUN_FIREBALL pool objects */

extern struct MapObjectModel *gSun;
extern struct MapObjectModel *gSunLOD;
