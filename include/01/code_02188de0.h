#pragma once

#include "types.h"
#include "01/code_02188950.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void SetPointInRangeCallback(MissionRunMapObject *mapObject, s32 pointRadius, s32 pointHalfAngle, Vec3 *point,
                             MapObjectCallback callback);
