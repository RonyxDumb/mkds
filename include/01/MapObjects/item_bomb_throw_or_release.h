#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void ThrowOrReleaseStoredItemBomb(MissionRunMapObject *mapObject, Vec3 *velocity, s32 timer);
