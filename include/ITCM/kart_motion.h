#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct MtxFx33 MtxFx33;
typedef struct MtxFx43 MtxFx43;

// Largest tilt the up and down keys give a kart in the air (either way), and the heading turn a key press sets as the
// goal per frame while the kart is in the air and not drifting.
#define KART_AIR_TILT_LIMIT 0x157c
#define KART_AIR_TURN_HEADING_GOAL 0x32

void AdvanceKartForwardSpeedAndAngles(Kart *kart);
void UpdateKartForwardAndLengthRatio(Kart *kart);
void UpdateKartSpeedLimit(Kart *kart);
void UpdateKartSpeedLimitGoal(Kart *kart);
// Stores the previous collision center: the point mRadius plus 0x400 along row 1 of mDrawBaseMatrix from
// mDrawMatrixPos. Slot 5 of Kart.mSlotFunctions for every Kart except the peer Karts in MODE_WIFI (they use
// SetKartPrevCollisionCenterFromPrevPos); also called once from ApplyParticipantKartRecord.
void SetKartPrevCollisionCenter(Kart *kart);
// Writes the point mRadius + c along the vector at 0x15c, starting from b plus the move since the last step, to a.
void ComputeKartCollisionCenter(Vec3 *result, const Vec3 *drawPos, s32 extra, Kart *kart);
void ComputeKartPointAlongUp(Vec3 *result, const Vec3 *base, s32 extra, Kart *kart);
void AdvanceKartTurnHeading(Kart *kart, s32 turnApplied);
// One step of a turn in direction (1 or -1): sets turnFlag in mDriveFlags; in the air it only sets, outside a drift,
// the turn
// heading goal to KART_AIR_TURN_HEADING_GOAL * direction and returns; otherwise it moves mTurnRatio when on the ground
// and, for a
// moving Kart not in a low-speed turn, sets the heading goal; always returns 1.
s32 ApplyKartTurn(Kart *kart, s16 baseTurnRate, s16 turnSign, s32 direction, s32 airborne, u32 turnFlag);
s32 ApplyKartTurnInput(Kart *kart, s32 lowSpeedTurn);
// Multiplies *a by 0xe6a / 0x1000 and sets it to 0 once its size is below 0x7b.
void DecayValueToZero(s32 *value);
void SetKartMissionRunInputMask(Kart *kart);
void UpdateKartInputFlags(Kart *kart);
BOOL IsKartNotNormalOrFlagged(Kart *kart);
void AdvanceKartInputAndTurn(Kart *kart);
// Counts mKartCollisionTimer down and starts the collision sound when it reaches 0.
void AdvanceKartCollisionTimer(Kart *kart);
void UpdateKartSoundWrapper(Kart *kart);
// Stores the rank in mRank (and, when it changed, tells the scene sound the new rank for the selected Kart); returns
// TRUE when the rank
// number fell, the new rank is below mKartCount, a Kart exists at the next rank number and its mEntryFlags have none of
// KART_ENTRY_GHOST, KART_ENTRY_TERESA, KART_ENTRY_PARKED.
s32 AdvanceKartRank(Kart *kart);
void AddKartSurfaceSoundRequest(Kart *kart, s32 entryIndex);
void ResetKartTurnAndRadius(Kart *kart);
// First step of UpdateKarts for one Kart: copies the near-Kart mask, the position, mPointAlongUp, mPrevHitVelocity and
// mHitVelocity into their previous values, clears mTestedKartMask, mNearKartMask and some bits of mMotionFlags and
// mEffectFlags, then runs slot 5 of Kart.mSlotFunctions.
void UpdateKartPrevValuesAndClearFlags(Kart *kart);
// Slot 4 step of one Kart, except a peer Kart in MODE_WIFI (it runs AdvancePeerKartCollision); returns at once for a
// removed Kart: moves Kart.mCollisionCenter, sweeps it against the course from Kart.mPrevCollisionCenter, counts the
// step and calls the function in mAdvanceOffsetCycle.
void AdvanceKartCollision(Kart *kart);
// Slot 3 step of one Kart, except a peer Kart in MODE_WIFI (it runs AdvancePeerKartMotion): speed limits, CPU steering,
// input and turn, boosts, then AdvanceKartToKeyedPlacement or AdvanceKartByVelocity (the Kart state function, gravity,
// the velocity added to mPos, and the tests against map objects, item objects and other Karts); a removed or scaling-in
// Kart only advances its scale. It does not sweep the course (AdvanceKartCollision does).
void AdvanceKartMotion(Kart *kart);
// Writes nine words (a 3x3 rotation matrix with 12 fractional bits) to its first argument from the quaternion at its
// second argument (w in the fourth component).
void Matrix3x3FromQuaternion(MtxFx33 *mtx, void *quatPtr);
// Like Matrix3x3FromQuaternion but for the whole 4x3 matrix: the translation row is written as zero.
void Matrix4x3FromQuaternion(MtxFx43 *mtx, const Vec4 *quat);
// Writes to result the linear blend of the quaternions start and end with weight blend out of 0x1000 (0x1000 gives
// end); the result is not normalized.
void QuaternionBlend(Vec4 *start, const Vec4 *end, Vec4 *result, s32 blend);
// Writes to result the product of the quaternions left and right (x, y, z, w with 12 fractional bits); result may be
// left or right.
void QuaternionMultiply(const Vec4 *left, const Vec4 *right, Vec4 *result);
