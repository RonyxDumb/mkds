#pragma once

#include "types.h"

typedef struct MapObject MapObject;

BOOL mobj_sphereCollide(Vec3 *position, s32 radius, MapObject *mapObject, Vec3 *overlapOffset);
BOOL mobj_getHasWater(void);
s32 mobj_getWaterPlaneDistance2(s32 y);
s32 mobj_getWaterTideProgress(void);
u32 mobj_getWaterTidePhase(void);
