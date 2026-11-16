#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43

typedef struct GroupFollowerWithSpeeds GroupFollowerWithSpeeds;
typedef struct SegmentProgress SegmentProgress;

struct CourseMapRow;

// Four words: qrtn_fromForwardVec writes them.
typedef struct Quaternion {
    /* 00 */ s32 mComponents[4];
} Quaternion;

void pwex_initFromObject(GroupFollowerWithSpeeds *m, struct CourseMapRow *courseRow, s32 speed, s32 d);
void func_020d7d18(SegmentProgress *segmentProgress, s32 a, Vec3 **points, s32 rate);
BOOL func_020d7c84(SegmentProgress *segmentProgress, s32 a, Vec3 **points);
// Stores in gViewYawQuaternion the rotation about Y by the angle of the matrix a.
void SetViewYawQuaternion(MtxFx43 *viewMatrix);
void qrtn_fromForwardVec(Vec3 *p, void *output);
void qrtn_fromYAngle(s32 angle, Quaternion *quaternion);
// Writes to q the quaternion qrtn_fromForwardVec gives for p combined with the Y rotation
// qrtn_fromYAngle gives for b.
void qrtn_20D7A3C(void *directionPtr, s32 angle, void *outputPtr);
void func_020d79b0(void *quaternionPtr, u32 angle, void *outputPtr);
void qrtn_20D7938(Quaternion *first, Quaternion *second, Quaternion *result);
void Quaternion_Rotate_20D788C(Quaternion *quaternion, s32 angle, Quaternion *result);
void Quaternion_Rotate_20D77E0(void *quaternionPtr, s32 angle, void *resultPtr);
void Quaternion_Rotate_20D7734(void *quaternionPtr, s32 angle, void *resultPtr);
void Quaternion_Rotate_20D76A8(Quaternion *quaternion, s32 angle, Quaternion *result);
// Blends p toward q by d, toward the negated q when their dot product is negative.
void qrtn_slerp(void *fromPtr, void *toPtr, void *resultPtr, s32 amount);
void qtrn_normalize(Quaternion *input, Quaternion *output);
void qtrn_fromEulerAngles(Vec3 *degrees, u32 *resultWords);
s32 vec_normalizeFast(Vec3 *vector, Vec3 *result);
s32 vec_normalizeXZFast(Vec3 *vector, Vec3 *result);
// Writes to c the vector a rotated about the Y axis by the angle b (0x10000 per turn).
void vec_rotate(Vec3 *vector, s32 angle, Vec3 *result);
// Writes to b (a 3x3 matrix, nine words with 12 fractional bits) the rotation given by the three angles of a in degrees
// with 12 fractional bits: the X rotation, then the Y rotation, then the Z rotation multiplied on.
void mtx_eulerAnglesToMtx33(Vec3 *degrees, s32 *matrix);
u32 mobj_getDriverHitResponse(s32 flagBit, s32 itemEffect, s32 kindHundreds, s32 kindRemainder);
