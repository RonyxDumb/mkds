#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct MtxFx33 MtxFx33;
typedef struct MtxFx43 MtxFx43;

void AdvanceKartForwardSpeedAndAngles(Kart *kart);
void UpdateKartForwardAndLengthRatio(Kart *kart);
void UpdateKartSpeedLimit(Kart *kart);
void UpdateKartSpeedLimitGoal(Kart *kart);
// Stores the previous collision center: the point mRadius plus 0x400 along the up vector from mUnk_98. Slot 5 of
// Kart.mSlotFunctions for every Kart except the remote Karts of mode 5; also called once from
// ApplyParticipantKartRecord.
void SetKartPrevCollisionCenter(Kart *kart);
// Writes the point mRadius + c along the vector at 0x15c, starting from b plus the move since the last step, to a.
void ComputeKartCollisionCenter(Vec3 *result, const Vec3 *drawPos, s32 extra, Kart *kart);
void ComputeKartPointAlongUp(Vec3 *result, const Vec3 *base, s32 extra, Kart *kart);
void AdvanceKartTurnHeading(Kart *kart, s32 turnApplied);
// One step of a turn in direction c (1 or -1) with e the mDriveFlags bit set for it; always returns 1.
s32 ApplyKartTurn(Kart *kart, s16 baseTurnRate, s16 turnSign, s32 direction, s32 airborne, u32 turnFlag);
s32 ApplyKartTurnInput(Kart *kart, s32 lowSpeedTurn);
// Multiplies *a by 0xe6a / 0x1000 and sets it to 0 once its size is below 0x7b.
void DecayValueToZero(s32 *a);
void SetKartMissionRunInputMask(Kart *kart);
void UpdateKartInputFlags(Kart *kart);
BOOL IsKartNotNormalOrFlagged(Kart *kart);
void AdvanceKartInputAndTurn(Kart *kart);
// Counts mKartCollisionTimer down and starts the collision sound when it reaches 0.
void AdvanceKartCollisionTimer(Kart *kart);
void UpdateKartSoundWrapper(Kart *kart);
// Stores the rank in mRank; returns TRUE when the Kart moved up and the Kart now right behind it is not flagged in
// mEntryFlags.
s32 AdvanceKartRank(Kart *kart);
void AddKartSurfaceSoundRequest(Kart *kart, s32 entryIndex);
void ResetKartTurnAndRadius(Kart *kart);
// First step of UpdateKarts for one Kart: copies the near-Kart mask, the position, mUnk_1d8, mUnk_2e4 and mUnk_2d8 into
// their previous values, clears mTestedKartMask, mNearKartMask and some bits of mMotionFlags and mEffectFlags, then
// runs slot 5 of Kart.mSlotFunctions.
void UpdateKartPrevValuesAndClearFlags(Kart *kart);
// Slot 4 step of one Kart: moves Kart.mCollisionCenter, sweeps it against the course from Kart.mPrevCollisionCenter,
// counts the step and calls the function in mUnk_230.
void AdvanceKartCollision(Kart *kart);
// Slot 3 step of one Kart: speed limits from the physical parameters, the Kart state function, gravity and the velocity
// added to mPos. Does not test collisions.
void AdvanceKartMotion(Kart *kart);
// Writes nine words (a 3x3 rotation matrix with 12 fractional bits) to its first argument from the quaternion at its
// second argument (w in the fourth component); which of the nine words is a row or a column is not claimed.
void Matrix3x3FromQuaternion(MtxFx33 *param_1, void *param_2);
// Like Matrix3x3FromQuaternion but for the whole 4x3 matrix: the translation row is written as zero.
void Matrix4x3FromQuaternion(MtxFx43 *mtx, const Vec4 *quat);
// Writes to c the linear blend of the quaternions a and b with weight d out of 0x1000 (0x1000 gives b); the result is
// not normalized.
void QuaternionBlend(Vec4 *start, const Vec4 *end, Vec4 *result, s32 blend);
// Writes to c the Hamilton product of the quaternions a and b (x, y, z, w with 12 fractional bits, w the scalar part);
// c may be a or b.
void QuaternionMultiply(const Vec4 *left, const Vec4 *right, Vec4 *result);
