#pragma once

#include "types.h"

typedef struct Kart Kart;

// Sets mAirTiltQuaternion to the quaternion from the up vector to a (y = 0, w keeps its sign) and normalizes it; when
// there is none, multiplies it by the quaternion from mGroundNormal to a first.
void AdvanceKartQuaternionFromVector(Kart *kart, Vec3 *target);
void ScaleKartVelocityAndSetCappedLengthAndDirection(Kart *kart, s32 scale);
s32 LimitKartForwardSpeedAndGetScaled(Kart *kart);
void AdvanceKartOffsetCycleIndex(Kart *kart);
