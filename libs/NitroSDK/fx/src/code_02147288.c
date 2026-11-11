#include "code_02147288.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"

// Scales the first three rows of the 4x3 matrix at src by x, y and z, copies the translation row, and writes the result
// to dst.
void MTX_ScaleApply43(const MtxFx43 *src, MtxFx43 *dst, s32 x, s32 y, s32 z) {
    MTX_ScaleApply33(&src->mAxes, &dst->mAxes, x, y, z);
    dst->mRows[3].x = src->mRows[3].x;
    dst->mRows[3].y = src->mRows[3].y;
    dst->mRows[3].z = src->mRows[3].z;
}

// Sets dst to the rotation by sinVal and cosVal about the axis vec, with a zero translation.
void MTX_RotAxis43(MtxFx43 *dst, const Vec3 *vec, s32 sinVal, s32 cosVal) {
    MTX_RotAxis33(&dst->mAxes, vec, sinVal, cosVal);
    dst->mRows[3].x = 0;
    dst->mRows[3].y = 0;
    dst->mRows[3].z = 0;
}

// Writes the inverse of the 4x3 matrix at src to dst and returns 0, or returns -1 without writing when the determinant
// is 0.
s32 MTX_Inverse43(const MtxFx43 *src, MtxFx43 *dst) {
    MtxFx43 tmp;
    MtxFx43 *result;
    s64 cofactor00;
    s64 det10;
    s64 det20;
    s32 determinant;
    s32 invDet;
    s32 product01;
    s32 tmp02;
    s32 tmp11;
    s32 tmp12;
    s32 product21;
    s32 tmp22;
    s32 src12;
    s32 src21;
    s32 src11;

    src12 = src->mRows[1].z;
    src21 = src->mRows[2].y;
    if (src == dst) {
        result = &tmp;
    } else {
        result = dst;
    }
    src11 = src->mRows[1].y;
    det10 = (s32) (((s64) src->mRows[1].x * src->mRows[2].z - (s64) src12 * src->mRows[2].x + 0x800) >> 12);
    cofactor00 = (s32) (((s64) src11 * src->mRows[2].z - (s64) src12 * src21 + 0x800) >> 12);
    det20 = (s32) (((s64) src->mRows[1].x * src->mRows[2].y - src11 * (s64) src->mRows[2].x + 0x800) >> 12);
    determinant = ((s64) src->mRows[0].x * cofactor00 - (s64) src->mRows[0].y * det10 +
                   (s64) src->mRows[0].z * det20 + 0x800) >>
                  12;
    if (determinant == 0) {
        return -1;
    }
    FX_InvAsync(determinant);
    product01 = ((s64) src->mRows[0].y * src->mRows[2].z - (s64) src->mRows[2].y * src->mRows[0].z) >> 12;
    tmp02 = ((s64) src->mRows[0].y * src->mRows[1].z - (s64) src->mRows[1].y * src->mRows[0].z) >> 12;
    tmp11 = ((s64) src->mRows[0].x * src->mRows[2].z - (s64) src->mRows[2].x * src->mRows[0].z) >> 12;
    tmp12 = ((s64) src->mRows[0].x * src->mRows[1].z - (s64) src->mRows[1].x * src->mRows[0].z) >> 12;
    invDet = FX_GetDivResult();
    result->mRows[0].x = MUL_FIXED12_NO_ROUND(invDet, cofactor00);
    result->mRows[0].y = -MUL_FIXED12_NO_ROUND(invDet, product01);
    result->mRows[0].z = MUL_FIXED12_NO_ROUND(invDet, tmp02);
    result->mRows[1].x = -MUL_FIXED12_NO_ROUND(invDet, det10);
    result->mRows[1].y = MUL_FIXED12_NO_ROUND(invDet, tmp11);
    result->mRows[1].z = -MUL_FIXED12_NO_ROUND(invDet, tmp12);
    result->mRows[2].x = MUL_FIXED12_NO_ROUND(invDet, det20);
    product21 = CROSS2_FIXED12(src->mRows[0].x, src->mRows[2].y, src->mRows[2].x, src->mRows[0].y);
    result->mRows[2].y = -MUL_FIXED12_NO_ROUND(invDet, product21);
    tmp22 = ((s64) src->mRows[0].x * src->mRows[1].y - (s64) src->mRows[1].x * src->mRows[0].y) >> 12;
    result->mRows[2].z = MUL_FIXED12_NO_ROUND(invDet, tmp22);
    result->mRows[3].x = -(s32) DOT3_FIXED12(result->mRows[0].x, src->mRows[3].x, result->mRows[1].x, src->mRows[3].y,
                                             result->mRows[2].x, src->mRows[3].z);
    result->mRows[3].y = -(s32) DOT3_FIXED12(result->mRows[0].y, src->mRows[3].x, result->mRows[1].y, src->mRows[3].y,
                                             result->mRows[2].y, src->mRows[3].z);
    result->mRows[3].z = -(s32) DOT3_FIXED12(result->mRows[0].z, src->mRows[3].x, result->mRows[1].z, src->mRows[3].y,
                                             result->mRows[2].z, src->mRows[3].z);
    if (result == &tmp) {
        MI_Copy48B(&tmp, dst);
    }
    return 0;
}

// Multiplies the 4x3 matrices a and b and writes the product to ab; ab may be the same as a or b.
void MTX_Concat43(const MtxFx43 *a, const MtxFx43 *b, MtxFx43 *ab) {
    MtxFx43 tmp;
    MtxFx43 *result;
    s32 x0, x1, x2;
    s32 y0, y1, y2;

    result = ab;
    if (result == b) {
        result = &tmp;
    }
    x0 = a->mRows[0].x;
    x1 = a->mRows[0].y;
    x2 = a->mRows[0].z;
    result->mRows[0].x = ((s64) x0 * b->mRows[0].x + (s64) x1 * b->mRows[1].x + (s64) x2 * b->mRows[2].x) >> 12;
    result->mRows[0].y = ((s64) x0 * b->mRows[0].y + (s64) x1 * b->mRows[1].y + (s64) x2 * b->mRows[2].y) >> 12;
    y0 = b->mRows[0].z;
    y1 = b->mRows[1].z;
    y2 = b->mRows[2].z;
    result->mRows[0].z = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12;
    x0 = a->mRows[1].x;
    x1 = a->mRows[1].y;
    x2 = a->mRows[1].z;
    result->mRows[1].z = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12;
    result->mRows[1].y = ((s64) x0 * b->mRows[0].y + (s64) x1 * b->mRows[1].y + (s64) x2 * b->mRows[2].y) >> 12;
    y0 = b->mRows[0].x;
    y1 = b->mRows[1].x;
    y2 = b->mRows[2].x;
    result->mRows[1].x = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12;
    x0 = a->mRows[2].x;
    x1 = a->mRows[2].y;
    x2 = a->mRows[2].z;
    result->mRows[2].x = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12;
    result->mRows[2].y = ((s64) x0 * b->mRows[0].y + (s64) x1 * b->mRows[1].y + (s64) x2 * b->mRows[2].y) >> 12;
    y0 = b->mRows[0].z;
    y1 = b->mRows[1].z;
    y2 = b->mRows[2].z;
    result->mRows[2].z = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12;
    x0 = a->mRows[3].x;
    x1 = a->mRows[3].y;
    x2 = a->mRows[3].z;
    result->mRows[3].z = b->mRows[3].z + (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    result->mRows[3].y =
        b->mRows[3].y +
        (((s64) x0 * b->mRows[0].y + (s64) x1 * b->mRows[1].y + (s64) x2 * b->mRows[2].y) >> 12);
    result->mRows[3].x =
        b->mRows[3].x +
        (((s64) x0 * b->mRows[0].x + (s64) x1 * b->mRows[1].x + (s64) x2 * b->mRows[2].x) >> 12);
    if (result == &tmp) {
        *ab = tmp;
    }
}

// Multiplies the vector vec by the 4x3 matrix m, translation included, and writes the result to dst.
void MTX_MultVec43(const Vec3 *vec, const MtxFx43 *m, Vec3 *dst) {
    s32 x;
    s32 y;
    s32 z;

    x = vec->x;
    y = vec->y;
    z = vec->z;
    dst->x = ((s64) x * m->mRows[0].x + (s64) y * m->mRows[1].x + (s64) z * m->mRows[2].x) >> 12;
    dst->x += m->mRows[3].x;
    dst->y = ((s64) x * m->mRows[0].y + (s64) y * m->mRows[1].y + (s64) z * m->mRows[2].y) >> 12;
    dst->y += m->mRows[3].y;
    dst->z = ((s64) x * m->mRows[0].z + (s64) y * m->mRows[1].z + (s64) z * m->mRows[2].z) >> 12;
    dst->z += m->mRows[3].z;
}
