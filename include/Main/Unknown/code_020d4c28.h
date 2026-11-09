#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

void UpdateViewFrustum(MtxFx43 *viewMatrix);
u32 func_020d4f34(Vec3 *position, s32 b, s32 c, s32 distanceLimitSquared);
s32 GetHorizontalCameraDistanceSquared(Vec3 *position);
void func_020d4e28(ItemObject *itemObject, Vec3 *position, u32 distanceAndFlags);
BOOL func_020d4ddc(MapObject *mapObject);
BOOL func_020d4d60(MapObject *mapObject, s32 distanceSquared);
void func_020d4d44(MtxFx43 *viewMatrix);
void DrawMapObjectList(MapObjectList *list, MtxFx43 *viewMatrix);
