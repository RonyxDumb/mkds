#pragma once

#include "types.h"
#include "01/MapObjects/mission_run_range_and_collision_callbacks.h"
#include "01/MapObjects/mission_run_state_callbacks.h"

void StartBombKingBounceStateAfterHits(MissionRunMapObject *mapObject);
void StartBombKingStoppedStateAfterHits(MissionRunMapObject *mapObject);
void StartBombKingBounceState(MissionRunMapObject *mapObject);
void StartBombKingStoppedState(MissionRunMapObject *mapObject);
