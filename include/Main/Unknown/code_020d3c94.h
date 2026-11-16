#pragma once

#include "types.h"

typedef struct MapObject MapObject;

s32 mobj_getWaterPlaneDistance1(s32 y);
s32 mobj_20D3D10(s32 y);
void mobj_executeAllThunderLogic(void);
s32 mobj_collideAsItem(MapObject *mapObject, s32 itemKind, Vec3 *hitOffset);
