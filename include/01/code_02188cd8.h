#pragma once

#include "types.h"

typedef struct Unk02188950 Unk02188950;

void SetSpeedTargetAndPerCall(Unk02188950 *mapObject, s32 speedTarget, s32 speedPerCall);
void SetSpeedAndClearTarget(Unk02188950 *mapObject, s32 speed);
void SetScaleTargetAndPerCall(Unk02188950 *mapObject, s32 scaleTarget, s32 scalePerCall);
void SetAlphaLimitTargetAndPerCall(Unk02188950 *mapObject, s32 alphaLimitTarget, s32 alphaLimitPerCall);
void StartAnimationWithEndCallback(Unk02188950 *mapObject, s32 animationEntry, s32 frameStep,
                                   void (*endCallback)(Unk02188950 *));
void StartAnimationNoEndCallback(Unk02188950 *mapObject, s32 animationEntry, s32 frameStep);
void SetPointInRangePoint(Unk02188950 *mapObject, Vec3 *point);
