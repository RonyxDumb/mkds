#pragma once

#include "types.h"

void *GetExplosionSplashWaveNsbma_from_thumb(void);
void *GetExplosionSplashWaveNsbca_from_thumb(void);
void *GetExplosionSplashWaveNsbmd_from_thumb(void);
unsigned int GetMapObjectKindCount(void);

s32 CollideSphereWithMapObjects(Vec3 *position, Vec3 *velocity, s32 radius, s16 collisionSlotIndex, s32 itemKind,
                                Vec3 *hitOffset);

void ClearMapObjectListSlots(void);
