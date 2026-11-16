#pragma once

#include "types.h"

typedef struct MissionRunMapObject MissionRunMapObject;

void SetCollisionBoxOffsetAndExtentTarget(MissionRunMapObject *mapObject, int offsetX, u32 offsetY, u32 offsetZ,
                                          u32 offsetPerCall, u32 extentX, u32 extentY, u32 extentZ, u32 extentPerCall);
void SetCollisionBoxOffsetAndExtent(MissionRunMapObject *mapObject, int offsetX, int offsetY, int offsetZ, u32 extentX,
                                    u32 extentY, u32 extentZ);
void SetShadowOffsetAndScaleTarget(MissionRunMapObject *mapObject, int offsetX, u32 offsetY, u32 offsetZ,
                                   u32 offsetPerCall, u32 scaleX, u32 unusedScaleY, u32 scaleZ, u32 scalePerCall);
void SetShadowOffsetAndScale(MissionRunMapObject *mapObject, int offsetX, u32 offsetY, u32 offsetZ, u32 scaleX,
                             u32 unusedScaleY, u32 scaleZ);
void SetCollisionOffsetAndExtentTarget(MissionRunMapObject *mapObject, u32 offsetY, u32 offsetPerCall, u32 extentXZ,
                                       int extentY, u32 extentPerCall);
void SetCollisionOffsetAndExtent(MissionRunMapObject *mapObject, s32 offsetY, s32 extentXZ, s32 extentY);
void SetShadowOffsetYAndScaleTarget(MissionRunMapObject *mapObject, int offsetY, u32 offsetPerCall, u32 scaleXZ,
                                    u32 scalePerCall);
void SetShadowOffsetYAndScale(MissionRunMapObject *mapObject, s32 offsetY, s32 scaleXZ);
