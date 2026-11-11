#pragma once

#include "types.h"

typedef struct Kart Kart;

s32 ApplyKartContact(Kart *kart, Vec3 *contactNormal, s32 wasTouching, s32 baseSpeedLimitHitFactor, s32 surfaceKind,
                     s32 surfaceVariant, s32 value);
void ApplyKartCourseContact(Kart *kart, u32 collisionFlags, Vec3 *contactNormal);
void AdvanceKartPointMotion(Kart *kart, u32 collisionFlags, Vec3 *targetPointMotion, s32 headingDelta);
void ApplyKartAttractorPull(Kart *kart, Vec3 *groundNormal, s32 bit100000WasSet);
void AdvanceKartRaceStartBoost(Kart *kart);
void ApplyKartWaterDepth(Kart *kart);
void StartKartRespawnWait(Kart *kart, u32 collisionFlags);
