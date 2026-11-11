#include "code_02146d78.h"

// Scales the rows of the 3x3 matrix at src by x, y and z and writes the result to dst.
void MTX_ScaleApply33(const MtxFx33 *src, MtxFx33 *dst, s32 scaleX, s32 scaleY, s32 scaleZ) {
    dst->mRows[0].x = MUL_FIXED12_NO_ROUND(scaleX, src->mRows[0].x);
    dst->mRows[0].y = MUL_FIXED12_NO_ROUND(scaleX, src->mRows[0].y);
    dst->mRows[0].z = MUL_FIXED12_NO_ROUND(scaleX, src->mRows[0].z);
    dst->mRows[1].x = MUL_FIXED12_NO_ROUND(scaleY, src->mRows[1].x);
    dst->mRows[1].y = MUL_FIXED12_NO_ROUND(scaleY, src->mRows[1].y);
    dst->mRows[1].z = MUL_FIXED12_NO_ROUND(scaleY, src->mRows[1].z);
    dst->mRows[2].x = MUL_FIXED12_NO_ROUND(scaleZ, src->mRows[2].x);
    dst->mRows[2].y = MUL_FIXED12_NO_ROUND(scaleZ, src->mRows[2].y);
    dst->mRows[2].z = MUL_FIXED12_NO_ROUND(scaleZ, src->mRows[2].z);
}

// Sets dst to the rotation by sinVal and cosVal about the axis vec.
void MTX_RotAxis33(MtxFx33 *dst, const Vec3 *vec, s32 sinVal, s32 cosVal) {
    s32 axisX;
    s32 axisY;
    s32 axisZ;
    s32 oneMinusCos;
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
    oneMinusCos = (s64) (0x1000 - cosVal);
    axisX = vecX;
    vecY = vec->y;
    vecZ = (s64) vec->z;
    axisY = vecY;
    axisZ = vecZ;
    xx = (s64) oneMinusCos * ((s64) axisX * axisX);
    dst->mRows[0].x = (s32) (xx >> 24) + cosVal;
    xy = ((s64) oneMinusCos * axisX * axisY) >> 24;
    sinX = MUL_FIXED12_NO_ROUND(sinVal, axisX);
    yy = oneMinusCos * ((s64) axisY * axisY);
    dst->mRows[1].y = (s32) (yy >> 24) + cosVal;
    zz = (s64) oneMinusCos * ((s64) axisZ * axisZ);
    dst->mRows[2].z = (s32) (zz >> 24) + cosVal;
    sinY = MUL_FIXED12_NO_ROUND(sinVal, axisY);
    sinZ = MUL_FIXED12_NO_ROUND(sinVal, axisZ);
    dst->mRows[0].y = xy + sinZ;
    dst->mRows[1].x = xy - sinZ;
    xz = (s32) (((s64) oneMinusCos * axisX * axisZ) >> 24);
    dst->mRows[0].z = xz - sinY;
    dst->mRows[2].x = xz + sinY;
    yz = ((s64) oneMinusCos * axisY * axisZ) >> 24;
    dst->mRows[1].z = yz + sinX;
    dst->mRows[2].y = yz - sinX;
}

// Multiplies the 3x3 matrices a and b and writes the product to ab; ab may be the same as a or b.
void MTX_Concat33(const MtxFx33 *lhs, const MtxFx33 *rhs, MtxFx33 *ab) {
    MtxFx33 resultBuffer;
    MtxFx33 *result;
    s32 rowElement0;
    s32 rowElement1;
    s32 rowElement2;
    s32 columnElement0;
    s32 columnElement1;
    s32 columnElement2;

    result = ab;
    if (result == rhs) {
        result = &resultBuffer;
    }
    rowElement0 = lhs->mRows[0].x;
    rowElement1 = lhs->mRows[0].y;
    rowElement2 = lhs->mRows[0].z;
    result->mRows[0].x =
        DOT3_FIXED12(rowElement0, rhs->mRows[0].x, rowElement1, rhs->mRows[1].x, rowElement2, rhs->mRows[2].x);
    result->mRows[0].y =
        DOT3_FIXED12(rowElement0, rhs->mRows[0].y, rowElement1, rhs->mRows[1].y, rowElement2, rhs->mRows[2].y);
    columnElement0 = rhs->mRows[0].z;
    columnElement1 = rhs->mRows[1].z;
    columnElement2 = rhs->mRows[2].z;
    result->mRows[0].z =
        DOT3_FIXED12(rowElement0, columnElement0, rowElement1, columnElement1, rowElement2, columnElement2);
    rowElement0 = lhs->mRows[1].x;
    rowElement1 = lhs->mRows[1].y;
    rowElement2 = lhs->mRows[1].z;
    result->mRows[1].z =
        DOT3_FIXED12(rowElement0, columnElement0, rowElement1, columnElement1, rowElement2, columnElement2);
    result->mRows[1].y =
        DOT3_FIXED12(rowElement0, rhs->mRows[0].y, rowElement1, rhs->mRows[1].y, rowElement2, rhs->mRows[2].y);
    columnElement0 = rhs->mRows[0].x;
    columnElement1 = rhs->mRows[1].x;
    columnElement2 = rhs->mRows[2].x;
    result->mRows[1].x =
        DOT3_FIXED12(rowElement0, columnElement0, rowElement1, columnElement1, rowElement2, columnElement2);
    rowElement0 = lhs->mRows[2].x;
    rowElement1 = lhs->mRows[2].y;
    rowElement2 = lhs->mRows[2].z;
    result->mRows[2].x =
        DOT3_FIXED12(rowElement0, columnElement0, rowElement1, columnElement1, rowElement2, columnElement2);
    result->mRows[2].y =
        DOT3_FIXED12(rowElement0, rhs->mRows[0].y, rowElement1, rhs->mRows[1].y, rowElement2, rhs->mRows[2].y);
    result->mRows[2].z =
        DOT3_FIXED12(rowElement0, rhs->mRows[0].z, rowElement1, rhs->mRows[1].z, rowElement2, rhs->mRows[2].z);
    if (result == &resultBuffer) {
        *ab = resultBuffer;
    }
}

// Multiplies the vector vec by the 3x3 matrix m and writes the result to dst.
void MTX_MultVec33(const Vec3 *vec, const MtxFx33 *mtx, Vec3 *dst) {
    s32 vecX;
    s32 vecY;
    s32 vecZ;

    vecX = vec->x;
    vecY = vec->y;
    vecZ = vec->z;
    dst->x = DOT3_FIXED12(vecX, mtx->mRows[0].x, vecY, mtx->mRows[1].x, vecZ, mtx->mRows[2].x);
    dst->y = DOT3_FIXED12(vecX, mtx->mRows[0].y, vecY, mtx->mRows[1].y, vecZ, mtx->mRows[2].y);
    dst->z = DOT3_FIXED12(vecX, mtx->mRows[0].z, vecY, mtx->mRows[1].z, vecZ, mtx->mRows[2].z);
}
