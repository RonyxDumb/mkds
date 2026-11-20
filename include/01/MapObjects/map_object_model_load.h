#pragma once

#include "types.h"

// The height range CreateMapObjectKindDataWithSoundIds gives every kind data (9999.0 up and down); an object is out of
// range when the camera height difference is outside it.
#define MISSION_RUN_HEIGHT_RANGE_MAX TO_FIXED12(9999)
#define MISSION_RUN_HEIGHT_RANGE_MIN (-TO_FIXED12(9999))

typedef struct MapObjectModel MapObjectModel;

void StartMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, s32 entryIndex, s32 frameStep, s32 clampLoop);
void AdvanceMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel);
void StartMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel, s32 entryIndex, s32 frameStep, s32 clampLoop);

extern const Vec3 gMapObjectModelShadowScale;
extern const Vec3 gMapObjectModelAnimatedScale;
