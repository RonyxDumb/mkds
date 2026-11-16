#pragma once

#include "types.h"

typedef struct Kart Kart;

// Sets mUnk_100_q to the quaternion from the up vector to a (y = 0, w keeps its sign) and normalizes it; when there is
// none, multiplies it by the quaternion from field244 to a first.
void driver_1FFAD14(Kart *p, Vec3 *a);
void driver_multiplyDeltaPos(Kart *p, s32 a);
s32 driver_1FFAF18(Kart *p);
void driver_1FFB0CC(Kart *p);
