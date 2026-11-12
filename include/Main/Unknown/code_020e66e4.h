#pragma once

#include "types.h"
#include "Main/MapObjects/pendulum.h"
#include "Main/Unknown/code_020e6b58.h"

void DrawNsbmdModelWithMatrixAndAngle(NsbmdModel *model, MtxFx43 *matrix, s32 angle, Vec3 *scale, s32 usePosition,
                                      u16 maxAlpha);
void DrawNsbmdModelWithMatrixAndMaxAlpha(NsbmdModel *model, MtxFx43 *matrix, Vec3 *scale, s32 usePosition,
                                         u16 maxAlpha);
void DrawNsbmdModelWithMaxAlpha(NsbmdModel *model, Vec3 *position, s32 usePosition, u32 maxAlpha);
void QueueNsbmdModelMaterial(NsbmdModel *model);
s32 ComputeViewDepthAlpha(Vec3 *position);
