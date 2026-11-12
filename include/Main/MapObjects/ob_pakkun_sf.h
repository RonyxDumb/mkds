#pragma once

#include "types.h"
#include "Main/Unknown/code_020d6dc0.h" // Quaternion
#include "Main/MapObjects/attractor.h" // MapObject, MapObjectList, MapObjectKindData
#include "Main/Unknown/unk_02158000.h" // MapObjectDrawList
#include "Main/MapObjects/pushed_motion.h" // PushedObject

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

typedef struct CourseMapRow CourseMapRow;

void CreateSecondHand(void);

void CreateObPakkunSf(void);

extern MapObjectList *gSecondHandUpdateList;
extern MapObjectDrawList *gSecondHandDrawList;
extern MapObjectList *gObPakkunSfUpdateList;
extern MapObjectDrawList *gObPakkunSfDrawList;
extern MapObjectList *gPendulumUpdateList;
extern MapObjectDrawList *gPendulumDrawList;

void InitSecondHand(SecondHand *secondHand, CourseMapRow *courseRow);
void ComputeSphereHitOnSecondHand(SecondHand *secondHand, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset);
void UpdateSecondHand(u32 unused, SecondHand *secondHand);
void DrawSecondHand(u32 unused, SecondHand *secondHand, u32 unusedArg, u32 alpha);
MapObjectList *CreateSecondHandUpdateList(void);
MapObjectDrawList *CreateSecondHandDrawList(void);
MapObjectKindData *CreateSecondHandKindData(void);
void InitObPakkunSf(ObPakkunSf *obPakkunSf);
