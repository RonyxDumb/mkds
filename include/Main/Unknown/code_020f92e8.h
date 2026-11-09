#pragma once

#include "types.h"

void BounceItemVelocityOffSurface(Vec3 *velocity, Vec3 *normal);
typedef struct ItemObject ItemObject;

void ClearItemObjectCollisionBits(ItemObject *item, unsigned int clearBits);
