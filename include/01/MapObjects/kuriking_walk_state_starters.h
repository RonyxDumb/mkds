#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void ThrowBombsAndKinoko(MissionRunMapObject *mapObject);
void StartKurikingWalkState(MissionRunMapObject *mapObject);
void SetKurikingWalkByCounter(MissionRunMapObject *mapObject);
void StartKurikingKartInRangeState(MissionRunMapObject *mapObject);
