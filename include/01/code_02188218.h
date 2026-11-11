#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void SetRepeatsRemaining(MissionRunMapObject *mapObject, s32 repeatsRemaining);
unsigned short GetAbsoluteCounter(MissionRunMapObject *mapObject);
