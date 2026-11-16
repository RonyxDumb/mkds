#pragma once

#include "types.h"

typedef struct Kart Kart;

void driver_handleAcceleration(Kart *p);
void driver_1FFBD9C(Kart *p);
void driver_1FFBE04(Kart *p);
void UpdateKartSpeedLimitGoal(Kart *p);
// Stores the previous collision center: the point mRadius plus 0x400 along the up vector from field98. Slot 5 of
// Kart.mSlotFunctions for every Kart except the remote Karts of mode 5; also called once from func_020653d0.
void SetKartPrevCollisionCenter(Kart *p);
// Writes the point mRadius + c along the vector at 0x15c, starting from b plus the move since the last step, to a.
void ComputeKartCollisionCenter(Vec3 *a, const Vec3 *b, s32 c, Kart *p);
void ComputeKartPointAlongUp(Vec3 *a, const Vec3 *b, s32 c, Kart *p);
void driver_updateYRot(Kart *p, s32 a);
// One step of a turn in direction c (1 or -1) with e the field48 bit set for it; always returns 1.
s32 driver_applySteering(Kart *p, s16 a, s16 b, s32 c, s32 d, u32 e);
s32 driver_handleSteering(Kart *p, s32 a);
// Multiplies *a by 0xe6a / 0x1000 and sets it to 0 once its size is below 0x7b.
void DecayValueToZero(s32 *a);
void driver_handleNoForwardMode(Kart *p);
void driver_handleABButtons(Kart *p);
BOOL func_01ffc67c(Kart *p);
void driver_1FFC6C0(Kart *p);
// Counts mKartCollisionTimer down and starts the collision sound when it reaches 0.
void AdvanceKartCollisionTimer(Kart *p);
void func_01ffc920(Kart *p);
// Stores the rank in mRank; returns TRUE when the Kart moved up and the Kart now right behind it is not flagged in
// field7C.
s32 driver_handlePlaceChanges(Kart *p);
void func_01ffc9e8(Kart *p, s32 a);
void driver_1FFCA50(Kart *p);
// First step of UpdateKarts for one Kart: copies the near-Kart mask, the position, field1D8, field2E4 and field2D8 into
// their previous values, clears mTestedKartMask, mNearKartMask and some bits of field44 and field4C, then runs slot 5
// of Kart.mSlotFunctions.
void driver_1FFCAC0(Kart *p);
// Slot 4 step of one Kart: moves Kart.mCollisionCenter, sweeps it against the course from Kart.mPrevCollisionCenter,
// counts the step and calls the function in field230.
void AdvanceKartCollision(Kart *p);
// Slot 3 step of one Kart: speed limits from the physical parameters, the Kart state function, gravity and the velocity
// added to mPos. Does not test collisions.
void driver_1FFCC50(Kart *p);
// Writes nine words (a 3x3 rotation matrix with 12 fractional bits) to its first argument from the quaternion at its
// second argument (w in the fourth component); which of the nine words is a row or a column is not claimed.
void qtrn_toMtx33(void *param_1, void *param_2);
// Like qtrn_toMtx33 but for the whole 4x3 matrix: the translation row is written as zero.
void qrtn_toMtx43(void *a, const Vec4 *b);
// Writes to c the linear blend of the quaternions a and b with weight d out of 0x1000 (0x1000 gives b); the result is
// not normalized.
void qrtn_lerp(Vec4 *a, const Vec4 *b, Vec4 *c, s32 d);
// Writes to c the Hamilton product of the quaternions a and b (x, y, z, w with 12 fractional bits, w the scalar part);
// c may be a or b.
void qrtn_mult(const Vec4 *a, const Vec4 *b, Vec4 *c);
