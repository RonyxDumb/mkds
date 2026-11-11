#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void SetUnusedCallback(MissionRunMapObject *mapObject, UnkFunc *callback);
void SetCourseCollisionCallback(MissionRunMapObject *mapObject, void (*callback)(MissionRunMapObject *));
void SetStoppedCallback(MissionRunMapObject *mapObject, UnkFunc *callback);
