#pragma once

#include "types.h"
#include "Main/Unknown/code_020ec1fc.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

typedef struct ItemObject ItemObject;
typedef struct Kart Kart;

// Motion words at 0xa0 of the objects the pushed-motion functions work on.
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
extern const Vec3 data_02159588;
extern const Vec3 data_02159594;

void SetPushedMotionFromItemObject(PushedObject *object, const ItemObject *other);
void SetPushedMotionFromKart(PushedObject *object, Kart *other);
BOOL AdvancePushedMotion(PushedObject *object);
void InitPushedMotion(PushedObject *object, s32 lowestY, u32 gravity, u16 angleStep, u32 upwardSpeed, s32 pushSpeed);
