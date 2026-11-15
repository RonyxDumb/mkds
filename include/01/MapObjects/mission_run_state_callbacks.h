#pragma once

#include "types.h"
#include "01/MapObjects/mission_run_map_object.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void SetUnusedCallback(MissionRunMapObject *mapObject, MapObjectCallback callback);
void SetCourseCollisionCallback(MissionRunMapObject *mapObject, MapObjectCallback callback);
void SetStoppedCallback(MissionRunMapObject *mapObject, MapObjectCallback callback);
