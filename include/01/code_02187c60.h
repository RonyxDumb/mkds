#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void ReleaseAndSetItemBomb(MissionRunMapObject *mapObject, void *itemBomb);
void SetNodePositionSourceAndBombOffset(MissionRunMapObject *mapObject, s32 matchValue, const Vec3 *offset);
