#include "code_02147288.h"
#include "fx_mtx33.h"
#include "code_02147cd8.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"

// Scales the first three rows of the 4x3 matrix at src by x, y and z, copies the translation row, and writes the result
// to dst.
void MTX_ScaleApply43(const MtxFx43 *src, MtxFx43 *dst, s32 scaleX, s32 scaleY, s32 scaleZ) {
    MTX_ScaleApply33(&src->mAxes, &dst->mAxes, scaleX, scaleY, scaleZ);
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
    MtxFx43 resultBuffer;
    MtxFx43 *result;
    s64 cofactor00;
    s64 det10;
    s64 det20;
    s32 determinant;
    s32 invDet;
    s32 product01;
    s32 cofactor02;
    s32 cofactor11;
    s32 cofactor12;
    s32 product21;
    s32 cofactor22;
    s32 src12;
    s32 src21;
    s32 src11;

    src12 = src->mRows[1].z;
    src21 = src->mRows[2].y;
    if (src == dst) {
        result = &resultBuffer;
    } else {
        result = dst;
    }
    src11 = src->mRows[1].y;
    det10 = (s32) (((s64) src->mRows[1].x * src->mRows[2].z - (s64) src12 * src->mRows[2].x + 0x800) >> 12);
    cofactor00 = (s32) (((s64) src11 * src->mRows[2].z - (s64) src12 * src21 + 0x800) >> 12);
    det20 = (s32) (((s64) src->mRows[1].x * src->mRows[2].y - src11 * (s64) src->mRows[2].x + 0x800) >> 12);
    determinant =
        ((s64) src->mRows[0].x * cofactor00 - (s64) src->mRows[0].y * det10 + (s64) src->mRows[0].z * det20 + 0x800) >>
        12;
    if (determinant == 0) {
        return -1;
    }
    FX_InvAsync(determinant);
    product01 = CROSS2_FIXED12(src->mRows[0].y, src->mRows[2].z, src->mRows[2].y, src->mRows[0].z);
    cofactor02 = CROSS2_FIXED12(src->mRows[0].y, src->mRows[1].z, src->mRows[1].y, src->mRows[0].z);
    cofactor11 = CROSS2_FIXED12(src->mRows[0].x, src->mRows[2].z, src->mRows[2].x, src->mRows[0].z);
    cofactor12 = CROSS2_FIXED12(src->mRows[0].x, src->mRows[1].z, src->mRows[1].x, src->mRows[0].z);
    invDet = FX_GetDivResult();
    result->mRows[0].x = MUL_FIXED12_NO_ROUND(invDet, cofactor00);
    result->mRows[0].y = -MUL_FIXED12_NO_ROUND(invDet, product01);
    result->mRows[0].z = MUL_FIXED12_NO_ROUND(invDet, cofactor02);
    result->mRows[1].x = -MUL_FIXED12_NO_ROUND(invDet, det10);
    result->mRows[1].y = MUL_FIXED12_NO_ROUND(invDet, cofactor11);
    result->mRows[1].z = -MUL_FIXED12_NO_ROUND(invDet, cofactor12);
    result->mRows[2].x = MUL_FIXED12_NO_ROUND(invDet, det20);
    product21 = CROSS2_FIXED12(src->mRows[0].x, src->mRows[2].y, src->mRows[2].x, src->mRows[0].y);
    result->mRows[2].y = -MUL_FIXED12_NO_ROUND(invDet, product21);
    cofactor22 = CROSS2_FIXED12(src->mRows[0].x, src->mRows[1].y, src->mRows[1].x, src->mRows[0].y);
    result->mRows[2].z = MUL_FIXED12_NO_ROUND(invDet, cofactor22);
    result->mRows[3].x = -(s32) DOT3_FIXED12(result->mRows[0].x, src->mRows[3].x, result->mRows[1].x, src->mRows[3].y,
                                             result->mRows[2].x, src->mRows[3].z);
    result->mRows[3].y = -(s32) DOT3_FIXED12(result->mRows[0].y, src->mRows[3].x, result->mRows[1].y, src->mRows[3].y,
                                             result->mRows[2].y, src->mRows[3].z);
    result->mRows[3].z = -(s32) DOT3_FIXED12(result->mRows[0].z, src->mRows[3].x, result->mRows[1].z, src->mRows[3].y,
                                             result->mRows[2].z, src->mRows[3].z);
    if (result == &resultBuffer) {
        MI_Copy48B(&resultBuffer, dst);
    }
    return 0;
}

// Multiplies the 4x3 matrices a and b and writes the product to ab; ab may be the same as a or b.
void MTX_Concat43(const MtxFx43 *lhs, const MtxFx43 *rhs, MtxFx43 *ab) {
    MtxFx43 resultBuffer;
    MtxFx43 *result;
    s32 rowElement0, rowElement1, rowElement2;
    s32 columnElement0, columnElement1, columnElement2;

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
    columnElement0 = rhs->mRows[0].z;
    columnElement1 = rhs->mRows[1].z;
    columnElement2 = rhs->mRows[2].z;
    result->mRows[2].z =
        DOT3_FIXED12(rowElement0, columnElement0, rowElement1, columnElement1, rowElement2, columnElement2);
    rowElement0 = lhs->mRows[3].x;
    rowElement1 = lhs->mRows[3].y;
    rowElement2 = lhs->mRows[3].z;
    result->mRows[3].z = rhs->mRows[3].z + DOT3_FIXED12(rowElement0, columnElement0, rowElement1, columnElement1,
                                                        rowElement2, columnElement2);
    result->mRows[3].y = rhs->mRows[3].y + DOT3_FIXED12(rowElement0, rhs->mRows[0].y, rowElement1, rhs->mRows[1].y,
                                                        rowElement2, rhs->mRows[2].y);
    result->mRows[3].x = rhs->mRows[3].x + DOT3_FIXED12(rowElement0, rhs->mRows[0].x, rowElement1, rhs->mRows[1].x,
                                                        rowElement2, rhs->mRows[2].x);
    if (result == &resultBuffer) {
        *ab = resultBuffer;
    }
}

// Multiplies the vector vec by the 4x3 matrix m, translation included, and writes the result to dst.
void MTX_MultVec43(const Vec3 *vec, const MtxFx43 *mtx, Vec3 *dst) {
    s32 vecX;
    s32 vecY;
    s32 vecZ;

    vecX = vec->x;
    vecY = vec->y;
    vecZ = vec->z;
    dst->x = DOT3_FIXED12(vecX, mtx->mRows[0].x, vecY, mtx->mRows[1].x, vecZ, mtx->mRows[2].x);
    dst->x += mtx->mRows[3].x;
    dst->y = DOT3_FIXED12(vecX, mtx->mRows[0].y, vecY, mtx->mRows[1].y, vecZ, mtx->mRows[2].y);
    dst->y += mtx->mRows[3].y;
    dst->z = DOT3_FIXED12(vecX, mtx->mRows[0].z, vecY, mtx->mRows[1].z, vecZ, mtx->mRows[2].z);
    dst->z += mtx->mRows[3].z;
}
