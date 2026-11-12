#pragma once

#include "types.h"
#include "01/code_02188950.h"
#include "01/code_0219b250.h"

int UpdateHanachanMoveState(MissionRunMapObject *mapObject);
void StartHanachanMoveAnimation(MissionRunMapObject *mapObject);
void SetHanachanSpeedAndTurnToNextEntry(MissionRunMapObject *mapObject, int speedPercent);
void SetHanachanFollowersTurnTiming(MissionRunMapObject *mapObject, int speedPercent);
void StartHanachanAnimationScaled(MissionRunMapObject *mapObject, int speedPercent);
void StartHanachanFollowerMoveState(MissionRunMapObject *mapObject);
void AdvanceHanachanCounterForAll(MissionRunMapObject *mapObject);
void AdvanceHanachanCounter(MissionRunMapObject *mapObject);
void CopyHanachanFollowerPreviousAngle(MissionRunMapObject *mapObject);
void PlaceHanachanFollowerBehind(MissionRunMapObject *mapObject);
void TurnHanachanFollowerToPrevious(MissionRunMapObject *mapObject);
void PlaceHanachanFollowerBehindXz(MissionRunMapObject *mapObject);

#include "01/Menu/select_ghost.h"
