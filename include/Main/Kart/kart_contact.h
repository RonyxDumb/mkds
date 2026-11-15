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

// Kart.mVelocityLength limits in the wall contact response: above the first the kart bounces off the surface and loses
// its boost; the second makes the contact turn the heading; the third lets a grazing hit turn it; the fourth counts the
// contact for the selected kart.
#define KART_CONTACT_BOUNCE_MIN_SPEED 0x1800
#define KART_CONTACT_HEADING_KICK_MIN_SPEED 0x2000
#define KART_CONTACT_GRAZE_HEADING_MIN_SPEED 0x1800
#define KART_CONTACT_COUNT_MIN_SPEED 0x3000
// Frames the heading swing at the race start lasts (Kart.mRaceStartFrameCount).
#define KART_RACE_START_HEADING_SWING_FRAMES 0x78
