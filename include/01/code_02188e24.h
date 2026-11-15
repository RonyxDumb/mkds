#pragma once

#include "types.h"
#include "01/code_02188950.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void StartStateFrameCountCallback(MissionRunMapObject *mapObject, s32 frameCount, MapObjectCallback callback);
void SetTwoAnimationFrameCallbacks(MissionRunMapObject *mapObject, s32 firstFrameIndex, MapObjectCallback firstCallback,
                                   s32 secondFrameIndex, MapObjectCallback secondCallback);
void SetAnimationFrameCallback(MissionRunMapObject *mapObject, s32 frameIndex, MapObjectCallback callback);
