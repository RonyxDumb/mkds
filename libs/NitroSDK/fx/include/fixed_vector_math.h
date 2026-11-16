#pragma once

#include "types.h"

// Three halfword components.
typedef struct Vec3s16 {
    /* 00 */ s16 x;
    /* 02 */ s16 y;
    /* 04 */ s16 z;
} Vec3s16;

// Sine and cosine pairs: 4096 entries of (sin, cos) in 1.12 fixed point, indexed by angle >> 4.
extern const s16 g_SinFx16Table_AndCos[8192];

static inline s16 FX_SinIdx(int idx) {
    return SIN_OF_ANGLE(idx);
}

static inline s16 FX_CosIdx(int idx) {
    return COS_OF_ANGLE(idx);
}

s32 FX_ModS32(s32 numer, s32 denom);
s32 Fx_DivS32(s32 numer, s32 denom);
void FX_DivAsync(s32 numer, s32 denom);
s32 FX_GetSqrtResult(void);
void FX_InvAsync(s32 denom);
s32 FX_GetDivResult(void);
s64 FX_GetDivResultFx64c(void);
s32 FX_Sqrt(s32 value);
s64 FX_Inv64(s32 denom);
s32 FX_Inv(s32 denom);
s32 FX_Div(s32 numer, s32 denom);
s32 VecFx32_Distance(const Vec3 *firstVec, const Vec3 *secondVec);
// Argument order: scale, vector, base, result: result = base + vector * scale (scale with 12 fractional bits).
void VecFx32_AddScale1(s32 scale, const Vec3 *vector, const Vec3 *base, Vec3 *result);
void VecFx16_Normalize(const Vec3s16 *src, Vec3s16 *dst);
void VecFx32_Normalize(const Vec3 *src, Vec3 *dst);
s32 VecFx32_Norm(const Vec3 *vec);
void VecFx16_CrossProduct(const Vec3s16 *firstVec, const Vec3s16 *secondVec, Vec3s16 *result);
void VecFx32_CrossProduct(const Vec3 *firstVec, const Vec3 *secondVec, Vec3 *result);
s32 VecFx16_DotProduct(const Vec3s16 *firstVec, const Vec3s16 *secondVec);
s32 Vector3_DotProduct(const Vec3 *firstVec, const Vec3 *secondVec);
void VecFx32_Subtract(const Vec3 *firstVec, const Vec3 *secondVec, Vec3 *difference);
void VecFx32_Add(const Vec3 *firstVec, const Vec3 *secondVec, Vec3 *sum);
