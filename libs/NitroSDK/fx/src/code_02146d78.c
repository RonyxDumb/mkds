#include "code_02146d78.h"

// Scales the rows of the 3x3 matrix at src by x, y and z and writes the result to dst.
void MTX_ScaleApply33(const MtxFx33 *src, MtxFx33 *dst, s32 x, s32 y, s32 z) {
    dst->mUnk_00[0].x = ((s64) x * src->mUnk_00[0].x) >> 12;
    dst->mUnk_00[0].y = ((s64) x * src->mUnk_00[0].y) >> 12;
    dst->mUnk_00[0].z = ((s64) x * src->mUnk_00[0].z) >> 12;
    dst->mUnk_00[1].x = ((s64) y * src->mUnk_00[1].x) >> 12;
    dst->mUnk_00[1].y = ((s64) y * src->mUnk_00[1].y) >> 12;
    dst->mUnk_00[1].z = ((s64) y * src->mUnk_00[1].z) >> 12;
    dst->mUnk_00[2].x = ((s64) z * src->mUnk_00[2].x) >> 12;
    dst->mUnk_00[2].y = ((s64) z * src->mUnk_00[2].y) >> 12;
    dst->mUnk_00[2].z = ((s64) z * src->mUnk_00[2].z) >> 12;
}

// Sets dst to the rotation by sinVal and cosVal about the axis vec.
void MTX_RotAxis33(MtxFx33 *dst, const Vec3 *vec, s32 sinVal, s32 cosVal) {
    s32 x;
    s32 y;
    s32 z;
    s32 t;
    s64 xx;
    s64 yy;
    s64 zz;
    s32 xy;
    u32 xz;
    s32 yz;
    s32 sinX;
    s32 sinY;
    s32 sinZ;
    u32 vecX;
    s32 vecZ;
    s32 vecY;

    vecX = vec->x;
    t = (s64) (0x1000 - cosVal);
    x = vecX;
    vecY = vec->y;
    vecZ = (s64) vec->z;
    y = vecY;
    z = vecZ;
    xx = (s64) t * ((s64) x * x);
    dst->mUnk_00[0].x = (s32) (xx >> 24) + cosVal;
    xy = ((s64) t * x * y) >> 24;
    sinX = ((s64) sinVal * x) >> 12;
    yy = t * ((s64) y * y);
    dst->mUnk_00[1].y = (s32) (yy >> 24) + cosVal;
    zz = (s64) t * ((s64) z * z);
    dst->mUnk_00[2].z = (s32) (zz >> 24) + cosVal;
    sinY = ((s64) sinVal * y) >> 12;
    sinZ = ((s64) sinVal * z) >> 12;
    dst->mUnk_00[0].y = xy + sinZ;
    dst->mUnk_00[1].x = xy - sinZ;
    xz = (s32) (((s64) t * x * z) >> 24);
    dst->mUnk_00[0].z = xz - sinY;
    dst->mUnk_00[2].x = xz + sinY;
    yz = ((s64) t * y * z) >> 24;
    dst->mUnk_00[1].z = yz + sinX;
    dst->mUnk_00[2].y = yz - sinX;
}

// Multiplies the 3x3 matrices a and b and writes the product to ab; ab may be the same as a or b.
void MTX_Concat33(const MtxFx33 *a, const MtxFx33 *b, MtxFx33 *ab) {
    MtxFx33 tmp;
    MtxFx33 *result;
    s32 x0;
    s32 x1;
    s32 x2;
    s32 y0;
    s32 y1;
    s32 y2;

    result = ab;
    if (result == b) {
        result = &tmp;
    }
    x0 = a->mUnk_00[0].x;
    x1 = a->mUnk_00[0].y;
    x2 = a->mUnk_00[0].z;
    result->mUnk_00[0].x = ((s64) x0 * b->mUnk_00[0].x + (s64) x1 * b->mUnk_00[1].x + (s64) x2 * b->mUnk_00[2].x) >> 12;
    result->mUnk_00[0].y = ((s64) x0 * b->mUnk_00[0].y + (s64) x1 * b->mUnk_00[1].y + (s64) x2 * b->mUnk_00[2].y) >> 12;
    y0 = b->mUnk_00[0].z;
    y1 = b->mUnk_00[1].z;
    y2 = b->mUnk_00[2].z;
    result->mUnk_00[0].z = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12;
    x0 = a->mUnk_00[1].x;
    x1 = a->mUnk_00[1].y;
    x2 = a->mUnk_00[1].z;
    result->mUnk_00[1].z = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12;
    result->mUnk_00[1].y = ((s64) x0 * b->mUnk_00[0].y + (s64) x1 * b->mUnk_00[1].y + (s64) x2 * b->mUnk_00[2].y) >> 12;
    y0 = b->mUnk_00[0].x;
    y1 = b->mUnk_00[1].x;
    y2 = b->mUnk_00[2].x;
    result->mUnk_00[1].x = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12;
    x0 = a->mUnk_00[2].x;
    x1 = a->mUnk_00[2].y;
    x2 = a->mUnk_00[2].z;
    result->mUnk_00[2].x = ((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12;
    result->mUnk_00[2].y = ((s64) x0 * b->mUnk_00[0].y + (s64) x1 * b->mUnk_00[1].y + (s64) x2 * b->mUnk_00[2].y) >> 12;
    result->mUnk_00[2].z = ((s64) x0 * b->mUnk_00[0].z + (s64) x1 * b->mUnk_00[1].z + (s64) x2 * b->mUnk_00[2].z) >> 12;
    if (result == &tmp) {
        *ab = tmp;
    }
}

// Multiplies the vector vec by the 3x3 matrix m and writes the result to dst.
void MTX_MultVec33(const Vec3 *vec, const MtxFx33 *m, Vec3 *dst) {
    s32 x;
    s32 y;
    s32 z;

    x = vec->x;
    y = vec->y;
    z = vec->z;
    dst->x = ((s64) x * m->mUnk_00[0].x + (s64) y * m->mUnk_00[1].x + (s64) z * m->mUnk_00[2].x) >> 12;
    dst->y = ((s64) x * m->mUnk_00[0].y + (s64) y * m->mUnk_00[1].y + (s64) z * m->mUnk_00[2].y) >> 12;
    dst->z = ((s64) x * m->mUnk_00[0].z + (s64) y * m->mUnk_00[1].z + (s64) z * m->mUnk_00[2].z) >> 12;
}
