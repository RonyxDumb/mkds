#pragma once

#include "types.h"
#include "01/MapObjects/mission_run_map_object.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void SetUnusedCallback(MissionRunMapObject *mapObject, MissionRunMapObjectCallback callback);
void SetCourseCollisionCallback(MissionRunMapObject *mapObject, MissionRunMapObjectCallback callback);
void SetStoppedCallback(MissionRunMapObject *mapObject, MissionRunMapObjectCallback callback);
