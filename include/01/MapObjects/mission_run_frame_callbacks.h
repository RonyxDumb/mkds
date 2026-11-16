#pragma once

#include "types.h"
#include "01/MapObjects/mission_run_map_object.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void StartStateFrameCountCallback(MissionRunMapObject *mapObject, s32 frameCount, MissionRunMapObjectCallback callback);
void SetTwoAnimationFrameCallbacks(MissionRunMapObject *mapObject, s32 firstFrameIndex, MissionRunMapObjectCallback firstCallback,
                                   s32 secondFrameIndex, MissionRunMapObjectCallback secondCallback);
void SetAnimationFrameCallback(MissionRunMapObject *mapObject, s32 frameIndex, MissionRunMapObjectCallback callback);
