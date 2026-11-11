#pragma once

#include "types.h"

// Three halfword components.
typedef struct Vec3s16 {
    /* 00 */ s16 x;
    /* 02 */ s16 y;
    /* 04 */ s16 z;
} Vec3s16;

// Sine and cosine pairs: 4096 entries of (sin, cos) in 1.12 fixed point, indexed by angle >> 4.
extern const s16 FX_SinCosTable_[];

static inline s16 FX_SinIdx(int idx) {
    return SIN_OF_ANGLE(idx);
}

static inline s16 FX_CosIdx(int idx) {
    return COS_OF_ANGLE(idx);
}

s32 FX_ModS32(s32 numer, s32 denom);
s32 FX_DivS32(s32 numer, s32 denom);
void FX_DivAsync(s32 numer, s32 denom);
s32 FX_GetSqrtResult(void);
void FX_InvAsync(s32 denom);
s32 FX_GetDivResult(void);
s64 FX_GetDivResultFx64c(void);
s32 FX_Sqrt(s32 value);
s64 FX_InvFx64c(s32 denom);
s32 FX_Inv(s32 denom);
s32 FX_Div(s32 numer, s32 denom);
s32 VEC_Distance(const Vec3 *firstVec, const Vec3 *secondVec);
// Argument order: scale, vector, base, result: result = base + vector * scale (scale with 12 fractional bits).
void VEC_MultAdd(s32 scale, const Vec3 *vector, const Vec3 *base, Vec3 *result);
void VEC_Fx16Normalize(const Vec3s16 *src, Vec3s16 *dst);
void VEC_Normalize(const Vec3 *src, Vec3 *dst);
s32 VEC_Mag(const Vec3 *vec);
void VEC_Fx16CrossProduct(const Vec3s16 *firstVec, const Vec3s16 *secondVec, Vec3s16 *result);
void VEC_CrossProduct(const Vec3 *firstVec, const Vec3 *secondVec, Vec3 *result);
s32 VEC_Fx16DotProduct(const Vec3s16 *firstVec, const Vec3s16 *secondVec);
s32 VEC_DotProduct(const Vec3 *firstVec, const Vec3 *secondVec);
void VEC_Subtract(const Vec3 *firstVec, const Vec3 *secondVec, Vec3 *difference);
void VEC_Add(const Vec3 *firstVec, const Vec3 *secondVec, Vec3 *sum);
