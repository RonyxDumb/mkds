#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;
typedef struct ItemBomb ItemBomb;

ItemBomb *FindItemBombInRange(MissionRunMapObject *mapObject, u32 radius, u32 halfAngle);
BOOL IsPointInRange(MissionRunMapObject *mapObject, Vec3 *point, s32 radius, s32 halfAngle);
void SetItemCollisionCallback(MissionRunMapObject *mapObject, UnkFunc *itemCollisionCallback);
void SetKartCollisionCallback(MissionRunMapObject *mapObject, UnkFunc *kartCollisionCallback);
