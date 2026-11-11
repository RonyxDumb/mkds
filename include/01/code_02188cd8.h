#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void SetSpeedTargetAndPerCall(MissionRunMapObject *mapObject, s32 speedTarget, s32 speedPerCall);
void SetSpeedAndClearTarget(MissionRunMapObject *mapObject, s32 speed);
void SetScaleTargetAndPerCall(MissionRunMapObject *mapObject, s32 scaleTarget, s32 scalePerCall);
void SetAlphaLimitTargetAndPerCall(MissionRunMapObject *mapObject, s32 alphaLimitTarget, s32 alphaLimitPerCall);
void StartAnimationWithEndCallback(MissionRunMapObject *mapObject, s32 animationEntry, s32 frameStep,
                                   void (*endCallback)(MissionRunMapObject *));
void StartAnimationNoEndCallback(MissionRunMapObject *mapObject, s32 animationEntry, s32 frameStep);
void SetPointInRangePoint(MissionRunMapObject *mapObject, Vec3 *point);
