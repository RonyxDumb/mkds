#pragma once

#include "types.h"

typedef struct CollisionHitLink CollisionHitLink;

void CreateCollisionHitLink(CollisionHitLink **slotPointer);

extern const u16 gCylinderOuterRegionFlag;
extern const u16 gCylinderInnerRegionFlag;
extern const Vec3 gCylinderInnerZeroDistanceNormal;
extern const Vec3 gCylinderOuterZeroDistanceNormal;
