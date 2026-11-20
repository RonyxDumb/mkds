#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;
typedef struct Kart Kart;

void ShowKingTeresaWithEffects(MissionRunMapObject *mapObject);
void KingTeresaKartCollisionCallback(MissionRunMapObject *mapObject, Kart *kart);
u16 IsIwanteHandShapeWalkB(MissionRunMapObject *mapObject);
