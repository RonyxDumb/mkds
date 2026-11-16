#pragma once

#include "types.h"
#include "model_material_set.h" // MtxFx43

MtxFx43 *SetTranslationMatrixPos(Vec3 *position);
MtxFx43 *SetViewAxis2MatrixPos(Vec3 *position);
MtxFx43 *SetYAxisMatrixPos(Vec3 *position);
void ResetViewRotatedMatrixAxis1(void);
MtxFx43 *TiltViewRotatedMatrix(Vec3 *position, s32 horizontalFactor, s32 yOffset);
MtxFx43 *MaybeGetBBMtxAtPosition(Vec3 *position);
MtxFx43 *SetViewTransposeMatrixPos(Vec3 *position);
s32 BuildMatrixFromYAxis(Vec3 *yAxis, MtxFx43 *matrix);
s32 BuildYAxisMatrix(Vec3 *yAxis);
void SetViewMatrices(MtxFx43 *viewMatrix);
