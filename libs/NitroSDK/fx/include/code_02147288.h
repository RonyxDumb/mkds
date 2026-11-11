#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43

void MTX_MultVec43(const Vec3 *vec, const MtxFx43 *mtx, Vec3 *dst);
void MTX_Concat43(const MtxFx43 *lhs, const MtxFx43 *rhs, MtxFx43 *ab);
s32 MTX_Inverse43(const MtxFx43 *src, MtxFx43 *dst);
void MTX_RotAxis43(MtxFx43 *dst, const Vec3 *vec, s32 sinVal, s32 cosVal);
void MTX_ScaleApply43(const MtxFx43 *src, MtxFx43 *dst, s32 scaleX, s32 scaleY, s32 scaleZ);
