#pragma once

#include "types.h"

typedef struct MapObject MapObject;

s32 GetHeightAboveWaterOrEfct(s32 y);
s32 IsFarBelowWaterEfct(s32 y);
void RunMapObjectListCallbacks(void);
s32 GetMapObjectHitResponse(MapObject *mapObject, s32 itemKind, Vec3 *hitOffset);
