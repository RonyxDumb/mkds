#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

void UpdateViewFrustum(MtxFx43 *viewMatrix);
u32 ComputeDistanceViewTest(Vec3 *position, s32 b, s32 c, s32 distanceLimitSquared);
s32 GetHorizontalCameraDistanceSquared(Vec3 *position);
void SetItemObjectSoundByViewRange(ItemObject *itemObject, Vec3 *position, u32 distanceAndFlags);
BOOL IsMapObjectOutOfRange(MapObject *mapObject);
BOOL IsMapObjectOutOfRangeOrMaskedAtDistance(MapObject *mapObject, s32 distanceSquared);
void SetupMapObjectView(MtxFx43 *viewMatrix);
void DrawMapObjectList(MapObjectList *list, MtxFx43 *viewMatrix);
