#pragma once

#include "types.h"

void *GetWaterEfctNsbmaFile(void);
void *GetWaterEfctNsbcaFile(void);
void *GetWaterEfctNsbmdFile(void);
unsigned int GetMapObjectKindCount(void);

s32 CollideSphereWithMapObjects(Vec3 *position, Vec3 *velocity, s32 radius, s16 collisionSlotIndex, s32 itemKind,
                                Vec3 *hitOffset);

void ClearMapObjectListSlots(void);
