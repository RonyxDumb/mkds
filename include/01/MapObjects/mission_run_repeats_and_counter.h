#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void SetRepeatsRemaining(MissionRunMapObject *mapObject, u16 repeatsRemaining);
unsigned short GetAbsoluteCounter(MissionRunMapObject *mapObject);
