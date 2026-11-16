#pragma once

#include "types.h"
#include "model_material_set.h" // MtxFx43
#include "matrix44_concat.h" // MtxFx44

void MTX_Identity43_(MtxFx43 *dst);
void MTX_Copy43To44_(const MtxFx43 *src, MtxFx44 *dst);
void MTX_Scale43__from_thumb(MtxFx43 *dst, s32 scaleX, s32 scaleY, s32 scaleZ);
void MTX_RotX43__from_thumb(MtxFx43 *dst, s32 sinVal, s32 cosVal);
void MTX_RotY43__from_thumb(MtxFx43 *dst, s32 sinVal, s32 cosVal);
void MTX_RotZ43__from_thumb(MtxFx43 *dst, s32 sinVal, s32 cosVal);

void MTX_MultVec43(const Vec3 *vec, const MtxFx43 *mtx, Vec3 *dst);
void MTX_Concat43(const MtxFx43 *lhs, const MtxFx43 *rhs, MtxFx43 *ab);
s32 MTX_Inverse43(const MtxFx43 *src, MtxFx43 *dst);
void MTX_RotAxis43(MtxFx43 *dst, const Vec3 *vec, s32 sinVal, s32 cosVal);
void MTX_ScaleApply43(const MtxFx43 *src, MtxFx43 *dst, s32 scaleX, s32 scaleY, s32 scaleZ);
