#pragma once

#include "types.h"
#include "Main/MapObjects/woodbox1_kind_data.h"
#include "Main/MapObjects/attractor.h" // MapObject

typedef struct ItemObject ItemObject;
typedef struct Kart Kart;

// The motion of an object that is pushed up and away: lowest height, gravity, angle and speeds.
typedef struct PushedMotion {
    /* 00 */ s32 mLowestY;
    /* 04 */ s32 mGravity;
    /* 08 */ u32 mAngleIncreasing;
    /* 0c */ u16 mAngle;
    /* 0e */ u16 mAngleStep;
    /* 10 */ u32 mUpwardSpeed;
    /* 14 */ s32 mPushSpeed;
} PushedMotion;

// First 0xb8 bytes of the kinds the pushed-motion functions work on; each kind embeds it first.
typedef struct PushedObject {
    /* 00 */ MapObject mMapObject;
    /* a0 */ PushedMotion mMotion;
} PushedObject;

extern const Vec3 gVec3UnitX;
extern const Vec3 gPushedMotionFallbackDirection;
extern const Vec3 gPushedMotionDefaultVelocity;

void SetPushedMotionFromItemObject(PushedObject *object, const ItemObject *other);
void SetPushedMotionFromKart(PushedObject *object, Kart *other);
BOOL AdvancePushedMotion(PushedObject *object);
void InitPushedMotion(PushedObject *object, s32 lowestY, u32 gravity, u16 angleStep, u32 upwardSpeed, s32 pushSpeed);
