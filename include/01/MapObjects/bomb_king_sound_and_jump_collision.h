#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;
typedef struct Kart Kart;

void BombKingSecondSoundCallback(MissionRunMapObject *mapObject);
void BombKingFirstSoundCallback(MissionRunMapObject *mapObject);
void BombKingJumpKartCollisionCallback(MissionRunMapObject *mapObject, Kart *kart);
u16 GetAbsoluteCounterWrapper(MissionRunMapObject *mapObject);
