#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx33, MtxFx43

void MTX_MultVec33(const Vec3 *vec, const MtxFx33 *m, Vec3 *dst);
void MTX_Concat33(const MtxFx33 *a, const MtxFx33 *b, MtxFx33 *ab);
void MTX_RotAxis33(MtxFx33 *dst, const Vec3 *vec, s32 sinVal, s32 cosVal);
void MTX_ScaleApply33(const MtxFx33 *src, MtxFx33 *dst, s32 x, s32 y, s32 z);
