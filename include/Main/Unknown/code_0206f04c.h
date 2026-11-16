#pragma once

#include "types.h"

typedef struct Kart Kart;

s32 HandleWalls(Kart *kart, Vec3 *contactNormal, s32 wasTouching, s32 baseSpeedLimitHitFactor, s32 d, s32 e, s32 f);
void driver_handleWallCollision(Kart *kart, u32 collisionFlags, Vec3 *contactNormal);
void func_0206f694(Kart *kart, u32 collisionFlags, Vec3 *b, s32 headingDelta);
void driver_handleFallsWater(Kart *kart, Vec3 *groundNormal, s32 bit100000WasSet);
void driver_handleStartBoost(Kart *kart);
void driver_handleWaterDive(Kart *kart);
void driver_handleOobFallCannonPipe(Kart *kart, u32 collisionFlags);
