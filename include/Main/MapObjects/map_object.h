#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"

void StartMapObjectKindSound(MapObject *mapObject, SoundSource *soundSource, s32 value, s32 fraction);
void StartSoundAtPositionIfNear(s32 soundId, Vec3 *position, s32 falloffKind);
void SetMapObjectExtentY(MapObject *mapObject, s32 baseSize);
s32 GetMapObjectCollisionRadius(MapObject *mapObject);
void SetMapObjectDrawDistance(MapObject *mapObject, s32 drawDistance);
