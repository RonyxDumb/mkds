#include "fx_mtx33.h"

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

asm void MTX_Identity33_(MtxFx33 *dst) {
    mov r2, #0x1000
    str r2, [r0, #32]
    mov r3, #0
    stmia r0!, {r2, r3}
    mov r1, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r3}
    bx lr
}

// Copies the nine words at src to dst and clears the three words after them (the translation of the 4x3 matrix).
asm void MTX_Copy33To43_(const MtxFx33 *src, MtxFx43 *dst) {
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    mov r2, #0
    str r2, [r1]
    str r2, [r1, #4]
    str r2, [r1, #8]
    bx lr
}

// Writes the transpose of the 3x3 matrix at src to dst.
asm void MTX_Transpose33_(const void *src, void *dst) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9}
    ldmia r0, {r2, r3, r4, r5, r6, r7, r8, r9, ip}
    stmia r1!, {r2, r5, r8}
    stmia r1!, {r3, r6, r9}
    stmia r1!, {r4, r7, ip}
    ldmfd sp!, {r4, r5, r6, r7, r8, r9}
    bx lr
}

#pragma thumb on

// Sets dst to the rotation about the x axis: rows (0x1000, 0, 0), (0, cosVal, sinVal), (0, -sinVal, cosVal).
asm void MTX_RotX33_(MtxFx33 *dst, s32 sinVal, s32 cosVal) {
    mov r3, #1
    lsl r3, r3, #12
    str r3, [r0]
    mov r3, #0
    str r3, [r0, #4]
    str r3, [r0, #8]
    str r3, [r0, #12]
    str r2, [r0, #16]
    str r1, [r0, #20]
    str r3, [r0, #24]
    neg r1, r1
    str r1, [r0, #28]
    str r2, [r0, #32]
    bx lr
}

// Sets dst to the rotation about the y axis: rows (cosVal, 0, -sinVal), (0, 0x1000, 0), (sinVal, 0, cosVal).
asm void MTX_RotY33_(MtxFx33 *dst, s32 sinVal, s32 cosVal) {
    str r2, [r0]
    str r2, [r0, #32]
    mov r3, #0
    str r3, [r0, #4]
    str r3, [r0, #12]
    str r3, [r0, #20]
    str r3, [r0, #28]
    neg r2, r1
    mov r3, #1
    lsl r3, r3, #12
    str r1, [r0, #24]
    str r2, [r0, #8]
    str r3, [r0, #16]
    bx lr
}

// Sets dst to the rotation about the z axis: rows (cosVal, sinVal, 0), (-sinVal, cosVal, 0), (0, 0, 0x1000).
asm void MTX_RotZ33_(MtxFx33 *dst, s32 sinVal, s32 cosVal) {
    stmia r0!, {r2}
    mov r3, #0
    stmia r0!, {r1, r3}
    neg r1, r1
    stmia r0!, {r1, r2}
    mov r1, #1
    lsl r1, r1, #12
    str r3, [r0]
    str r3, [r0, #4]
    str r3, [r0, #8]
    str r1, [r0, #12]
    bx lr
}

#pragma thumb off
// clang-format on
