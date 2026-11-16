#pragma once

#include "types.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020e6b58.h"

void bbm_renderTransformedRotatedScaled(NsbmdModel *model, MtxFx43 *matrix, s32 angle, Vec3 *scale, s32 usePosition, u16 maxAlpha);
void bbm_renderTransformedScaled(NsbmdModel *model, MtxFx43 *matrix, Vec3 *scale, s32 usePosition, u16 maxAlpha);
void bbm_render(NsbmdModel *model, Vec3 *position, s32 usePosition, u32 maxAlpha);
void bbm_applyMaterial(NsbmdModel *model);
s32 bbm_calcDistanceAlpha(Vec3 *position);
