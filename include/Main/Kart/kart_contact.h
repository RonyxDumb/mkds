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

// Kart.mVelocityLength limits at the first contact of ApplyKartContact (all tests are "above"): BOUNCE gates the bounce
// off the surface (no boost, a non-zero normal velocity, hit factor not 1) and, once mCourseHitTimer is 0 or less, the
// surface sound and the model bump; HEADING_ANGLE lets the contact set mHeadingAnglePerFrame (hit factor not 1);
// GRAZE_HEADING is the extra limit of the second branch; COUNT counts the contact of the selected kart when value is 2.
#define KART_CONTACT_BOUNCE_MIN_SPEED 0x1800
#define KART_CONTACT_HEADING_ANGLE_MIN_SPEED 0x2000
#define KART_CONTACT_GRAZE_HEADING_MIN_SPEED 0x1800
#define KART_CONTACT_COUNT_MIN_SPEED 0x3000
// Value stored in Kart.mRaceStartFrameCount when the race start heading swing begins; nothing reads it (the swing ends
// when mHeadingAngleOffset crosses 0).
#define KART_RACE_START_HEADING_SWING_FRAMES 0x78
