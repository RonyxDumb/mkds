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

// Kart.mVelocityLength limits at the first contact of ApplyKartContact (all tests are "above"): the BOUNCE one bounces
// the velocity off the surface unless a boost runs and plays the surface sound; the HEADING_ANGLE one lets the contact
// set mHeadingAnglePerFrame (both branches); the GRAZE_HEADING one is the extra limit of the second branch; the COUNT
// one counts the contact for the selected kart on surface kind 2.
#define KART_CONTACT_BOUNCE_MIN_SPEED 0x1800
#define KART_CONTACT_HEADING_ANGLE_MIN_SPEED 0x2000
#define KART_CONTACT_GRAZE_HEADING_MIN_SPEED 0x1800
#define KART_CONTACT_COUNT_MIN_SPEED 0x3000
// Value stored in Kart.mRaceStartFrameCount when the race start heading swing begins; nothing reads it (the swing ends
// when mHeadingAngleOffset crosses 0).
#define KART_RACE_START_HEADING_SWING_FRAMES 0x78
