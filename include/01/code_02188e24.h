#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void StartStateFrameCountCallback(MissionRunMapObject *mapObject, s32 frameCount,
                                  void (*callback)(MissionRunMapObject *));
void SetTwoAnimationFrameCallbacks(MissionRunMapObject *mapObject, s32 firstFrameIndex,
                                   void (*firstCallback)(MissionRunMapObject *), s32 secondFrameIndex,
                                   void (*secondCallback)(MissionRunMapObject *));
void SetAnimationFrameCallback(MissionRunMapObject *mapObject, s32 frameIndex, UnkFunc *callback);
