#pragma once

#include "types.h"

typedef struct MapObjectModel MapObjectModel;

void StartMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, s32 entryIndex, s32 frameStep, s32 clampLoop);
void AdvanceMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel);
void StartMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel, s32 entryIndex, s32 frameStep, s32 clampLoop);

extern const Vec3 gMapObjectModelShadowScale;
extern const Vec3 gMapObjectModelAnimatedScale;
