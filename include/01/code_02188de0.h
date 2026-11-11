#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void SetPointInRangeCallback(MissionRunMapObject *mapObject, s32 pointRadius, s32 pointHalfAngle, Vec3 *point,
                             UnkFunc *callback);
