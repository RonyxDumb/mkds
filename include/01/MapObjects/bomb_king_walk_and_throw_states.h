#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;

int SwitchToBounceEffectsOnCollision(MissionRunMapObject *mapObject);
int StartBombKingBounceEffects(MissionRunMapObject *mapObject);
void StartBombKingWalkState(MissionRunMapObject *mapObject);
void StartBombKingRandomState(MissionRunMapObject *mapObject);
void StartBombKingWalkToBombState(MissionRunMapObject *mapObject);
void StartBombKingStoreFoundItemBombState(MissionRunMapObject *mapObject);
void StartItemBombThrow(MissionRunMapObject *mapObject);
void StartBombKingChaseState(MissionRunMapObject *mapObject);
void StoreNewItemBombAndStartThrow(MissionRunMapObject *mapObject);
void StartBombKingThrowBombsState(MissionRunMapObject *mapObject);
void StartBombKingJumpCycle(MissionRunMapObject *mapObject);
void StartBombKingJumpWaitState(MissionRunMapObject *mapObject);
