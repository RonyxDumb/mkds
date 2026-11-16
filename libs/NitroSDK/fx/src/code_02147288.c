#include "code_02147288.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"

// Scales the first three rows of the 4x3 matrix at src by x, y and z, copies the translation row, and writes the result
// to dst.
void MTX_ScaleApply43(const MtxFx43 *src, MtxFx43 *dst, s32 x, s32 y, s32 z) {
    MTX_ScaleApply33(src, dst, x, y, z);
    dst->field0[3].x = src->field0[3].x;
    dst->field0[3].y = src->field0[3].y;
    dst->field0[3].z = src->field0[3].z;
}

// Sets dst to the rotation by sinVal and cosVal about the axis vec, with a zero translation.
void MTX_RotAxis43(MtxFx43 *dst, const Vec3 *vec, s32 sinVal, s32 cosVal) {
    MTX_RotAxis33(dst, vec, sinVal, cosVal);
    dst->field0[3].x = 0;
    dst->field0[3].y = 0;
    dst->field0[3].z = 0;
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

    src12 = src->field0[1].z;
    src21 = src->field0[2].y;
    if (src == dst) {
        result = &tmp;
    } else {
        result = dst;
    }
    src11 = src->field0[1].y;
    det10 = (s32) (((s64) src->field0[1].x * src->field0[2].z - (s64) src12 * src->field0[2].x + 0x800) >> 12);
    cofactor00 = (s32) (((s64) src11 * src->field0[2].z - (s64) src12 * src21 + 0x800) >> 12);
    det20 = (s32) (((s64) src->field0[1].x * src->field0[2].y - src11 * (s64) src->field0[2].x + 0x800) >> 12);
    determinant = ((s64) src->field0[0].x * cofactor00 - (s64) src->field0[0].y * det10 +
                   (s64) src->field0[0].z * det20 + 0x800) >>
                  12;
    if (determinant == 0) {
        return -1;
    }
    FX_InvAsync(determinant);
    product01 = ((s64) src->field0[0].y * src->field0[2].z - (s64) src->field0[2].y * src->field0[0].z) >> 12;
    tmp02 = ((s64) src->field0[0].y * src->field0[1].z - (s64) src->field0[1].y * src->field0[0].z) >> 12;
    tmp11 = ((s64) src->field0[0].x * src->field0[2].z - (s64) src->field0[2].x * src->field0[0].z) >> 12;
    tmp12 = ((s64) src->field0[0].x * src->field0[1].z - (s64) src->field0[1].x * src->field0[0].z) >> 12;
    invDet = FX_GetDivResult();
    result->field0[0].x = ((s64) invDet * cofactor00) >> 12;
    result->field0[0].y = -(s32) (((s64) invDet * product01) >> 12);
    result->field0[0].z = ((s64) invDet * tmp02) >> 12;
    result->field0[1].x = -(s32) (((s64) invDet * det10) >> 12);
    result->field0[1].y = ((s64) invDet * tmp11) >> 12;
    result->field0[1].z = -(s32) (((s64) invDet * tmp12) >> 12);
    result->field0[2].x = ((s64) invDet * det20) >> 12;
    product21 = ((s64) src->field0[0].x * src->field0[2].y - (s64) src->field0[2].x * src->field0[0].y) >> 12;
    result->field0[2].y = -(s32) (((s64) invDet * product21) >> 12);
    tmp22 = ((s64) src->field0[0].x * src->field0[1].y - (s64) src->field0[1].x * src->field0[0].y) >> 12;
    result->field0[2].z = ((s64) invDet * tmp22) >> 12;
    result->field0[3].x =
        -(s32) (((s64) result->field0[0].x * src->field0[3].x + (s64) result->field0[1].x * src->field0[3].y +
                 (s64) result->field0[2].x * src->field0[3].z) >>
                12);
    result->field0[3].y =
        -(s32) (((s64) result->field0[0].y * src->field0[3].x + (s64) result->field0[1].y * src->field0[3].y +
                 (s64) result->field0[2].y * src->field0[3].z) >>
                12);
    result->field0[3].z =
        -(s32) (((s64) result->field0[0].z * src->field0[3].x + (s64) result->field0[1].z * src->field0[3].y +
                 (s64) result->field0[2].z * src->field0[3].z) >>
                12);
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
    x0 = a->field0[0].x;
    x1 = a->field0[0].y;
    x2 = a->field0[0].z;
    result->field0[0].x = ((s64) x0 * b->field0[0].x + (s64) x1 * b->field0[1].x + (s64) x2 * b->field0[2].x) >> 12;
    result->field0[0].y = ((s64) x0 * b->field0[0].y + (s64) x1 * b->field0[1].y + (s64) x2 * b->field0[2].y) >> 12;
    y0 = b->field0[0].z;
    y1 = b->field0[1].z;
    y2 = b->field0[2].z;
    result->field0[0].z = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12;
    x0 = a->field0[1].x;
    x1 = a->field0[1].y;
    x2 = a->field0[1].z;
    result->field0[1].z = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12;
    result->field0[1].y = ((s64) x0 * b->field0[0].y + (s64) x1 * b->field0[1].y + (s64) x2 * b->field0[2].y) >> 12;
    y0 = b->field0[0].x;
    y1 = b->field0[1].x;
    y2 = b->field0[2].x;
    result->field0[1].x = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12;
    x0 = a->field0[2].x;
    x1 = a->field0[2].y;
    x2 = a->field0[2].z;
    result->field0[2].x = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12;
    result->field0[2].y = ((s64) x0 * b->field0[0].y + (s64) x1 * b->field0[1].y + (s64) x2 * b->field0[2].y) >> 12;
    y0 = b->field0[0].z;
    y1 = b->field0[1].z;
    y2 = b->field0[2].z;
    result->field0[2].z = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12;
    x0 = a->field0[3].x;
    x1 = a->field0[3].y;
    x2 = a->field0[3].z;
    result->field0[3].z = b->field0[3].z + (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    result->field0[3].y =
        b->field0[3].y +
        (((s64) x0 * b->field0[0].y + (s64) x1 * b->field0[1].y + (s64) x2 * b->field0[2].y) >> 12);
    result->field0[3].x =
        b->field0[3].x +
        (((s64) x0 * b->field0[0].x + (s64) x1 * b->field0[1].x + (s64) x2 * b->field0[2].x) >> 12);
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
    dst->x = ((s64) x * m->field0[0].x + (s64) y * m->field0[1].x + (s64) z * m->field0[2].x) >> 12;
    dst->x += m->field0[3].x;
    dst->y = ((s64) x * m->field0[0].y + (s64) y * m->field0[1].y + (s64) z * m->field0[2].y) >> 12;
    dst->y += m->field0[3].y;
    dst->z = ((s64) x * m->field0[0].z + (s64) y * m->field0[1].z + (s64) z * m->field0[2].z) >> 12;
    dst->z += m->field0[3].z;
}
