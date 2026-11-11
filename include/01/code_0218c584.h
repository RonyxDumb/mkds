#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;

s32 UpdateKurikingTurnToEntryState(MissionRunMapObject *mapObject);
s32 UpdateKurikingWalkState(MissionRunMapObject *mapObject);
s32 UpdateKurikingKartInRangeState(MissionRunMapObject *mapObject);
