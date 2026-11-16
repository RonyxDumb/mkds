#pragma once

#include "types.h"

struct KartAi;

// CPU kart steering by mTurnAngleDegrees toward the next point: the angle above which the heading is turned by it, the
// angle below which the gesso heading swing runs, and the speed that swing needs.
#define KART_AI_STEER_MIN_TURN_ANGLE 0x2000
#define KART_AI_GESSO_SWING_MAX_TURN_ANGLE 0x46000
#define KART_AI_GESSO_SWING_MIN_SPEED 0x3000

// Writes to b the quaternion a scaled to length 1 (0x1000); no test for a zero quaternion.
void QuaternionNormalize(const Vec4 *input, Vec4 *output);
// Writes the quaternion built from the cross and dot products of b and c to a; returns FALSE (identity written) when
// they point opposite ways.
s32 TryQuaternionFromVectors(Vec4 *result, const Vec3 *source, const Vec3 *target);
// Writes to c the quaternion of a rotation about the axis a by the angle b (0x10000 per turn): a scaled by the sine of
// half the angle in x, y, z and the cosine of half the angle in w.
void QuaternionFromAxisAngle(const Vec3 *axis, u16 angle, Vec4 *result);
// Adds to the heading of the CPU Kart (three ways; returns at once in some states) and sets KART_DRIVE_TURN_LEFT or
// KART_DRIVE_TURN_RIGHT in mDriveFlags.
void AdvanceKartAiHeading(struct KartAi *kartAi, Vec3 *directionA, Vec3 *directionB);
// Squared x and z distance to the camera ORed with the view test bits, checking two frustum planes.
s32 ComputeTwoPlaneViewTest(Vec3 *pos, s32 radius, s32 maxDistance, s32 nearDistSq, u16 level);
// Same as ComputeTwoPlaneViewTest but checks the near plane and four more frustum planes.
s32 ComputeViewTest(Vec3 *pos, s32 radius, s32 maxDistance, s32 nearDistSq, u16 level);
// Lists the slots overlapping slot a whose flags match mask b (at most 0x80) in the result arrays and count.
void FindCollisionSlotsOverlappingSlot(s32 slotId, s32 flagMask);
// Refreshes the bounds of every slot from its position and radius, then re-sorts both end lists.
void UpdateCollisionSlotBounds(void);
