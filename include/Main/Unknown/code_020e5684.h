#pragma once

#include "types.h"
#include "Main/Unknown/code_020d6dc0.h" // Quaternion
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectList, MapObjectKindData
#include "Main/Unknown/unk_02158000.h" // MapObjectDrawList
#include "Main/Unknown/code_020ec538.h" // PushedObject

// Object InitSecondHand sets up, 0xd0 bytes.
typedef struct SecondHand {
    /* 00 */ MapObject mMapObject;
    /* a0 */ Quaternion mRotationQuaternion;
    /* b0 */ Quaternion mInitialRotationQuaternion;
    /* c0 */ u16 mRampFrameCount;
    /* c2 */ u16 mSteadyFrameCount;
    /* c4 */ u16 mPauseFrameCount;
    /* c6 */ s16 mAnglePerFrame;
    /* c8 */ s32 mSpeedFraction;
    /* cc */ s32 mSpeedFractionPerFrame;
} SecondHand;

// Object InitObPakkunSf sets up.
typedef struct ObPakkunSf {
    /* 00 */ PushedObject mPushedObject;
    /* b8 */ u16 mFramesSinceInit;
} ObPakkunSf;

// Second argument of InitSecondHand: a vector at 0x0c, halfwords from 0x28.
typedef struct Unk020e5684 {
    /* 00 */ u8 mUnk_00[0x0c];
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ u8 mUnk_18[0x10];
    /* 28 */ s16 mUnk_28;
    /* 2a */ s16 mUnk_2a;
    /* 2c */ s16 mUnk_2c;
    /* 2e */ s16 mUnk_2e;
    /* 30 */ s16 mUnk_30;
} Unk020e5684;

void CreateSecondHand(void);

void CreateObPakkunSf(void);

extern MapObjectList *gSecondHandUpdateList;
extern MapObjectDrawList *gSecondHandDrawList;
extern MapObjectList *gObPakkunSfUpdateList;
extern MapObjectDrawList *gObPakkunSfDrawList;
extern MapObjectList *gPendulumUpdateList;
extern MapObjectDrawList *gPendulumDrawList;

void InitSecondHand(SecondHand *secondHand, Unk020e5684 *courseRow);
void ComputeSphereHitOnSecondHand(SecondHand *secondHand, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset);
void UpdateSecondHand(u32 a, SecondHand *secondHand);
void DrawSecondHand(u32 a, SecondHand *secondHand, u32 b, u32 alpha);
MapObjectList *CreateSecondHandUpdateList(void);
MapObjectDrawList *CreateSecondHandDrawList(void);
MapObjectKindData *CreateSecondHandKindData(void);
void InitObPakkunSf(ObPakkunSf *obPakkunSf);
