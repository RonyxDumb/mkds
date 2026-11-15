#pragma once

#include "types.h"
#include "01/MapObjects/mission_run_map_object.h"

typedef struct MissionRunMapObject MissionRunMapObject;
typedef struct ItemBomb ItemBomb;

ItemBomb *FindItemBombInRange(MissionRunMapObject *mapObject, u32 radius, u32 halfAngle);
BOOL IsPointInRange(MissionRunMapObject *mapObject, Vec3 *point, s32 radius, s32 halfAngle);
void SetItemCollisionCallback(MissionRunMapObject *mapObject, MapObjectItemCollisionCallback itemCollisionCallback);
void SetKartCollisionCallback(MissionRunMapObject *mapObject, MapObjectKartCollisionCallback kartCollisionCallback);
