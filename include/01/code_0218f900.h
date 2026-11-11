#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void ShowKingTeresaWithEffects(MissionRunMapObject *mapObject);
void KingTeresaKartCollisionCallback(MissionRunMapObject *mapObject);
u16 IsIwanteWalkB(MissionRunMapObject *mapObject);
