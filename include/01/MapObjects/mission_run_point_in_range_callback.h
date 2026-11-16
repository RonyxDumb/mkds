#pragma once

#include "types.h"
#include "01/MapObjects/mission_run_map_object.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void SetPointInRangeCallback(MissionRunMapObject *mapObject, s32 pointRadius, s32 pointHalfAngle, Vec3 *point,
                             MissionRunMapObjectCallback callback);
