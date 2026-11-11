#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void BombKingSecondSoundCallback(MissionRunMapObject *mapObject);
void BombKingFirstSoundCallback(MissionRunMapObject *mapObject);
void BombKingJumpKartCollisionCallback(MissionRunMapObject *mapObject);
u16 GetAbsoluteCounterWrapper(MissionRunMapObject *mapObject);
