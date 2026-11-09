#pragma once

#include "types.h"
#include "code_02146d78.h" // MtxFx33

// Record of 0x54 bytes: four positions, then words at 0x30 and 0x34.
typedef struct Segment {
    /* 00 */ Vec3 mPoints[4];
    /* 30 */ s32 mProgressLength;
    /* 34 */ s32 mInverseProgressLength;
    /* 38 */ s32 mCurveLength;
    /* 3c */ s32 mInverseCurveLength;
    /* 40 */ s32 mStraightLength;
    /* 44 */ s32 mInverseStraightLength;
    /* 48 */ Vec3 mUp;
} Segment;

typedef struct GroupPath {
    /* 00 */ Segment *mSegments;
    /* 04 */ s32 mSegmentCount;
    /* 08 */ s32 mWraps;
} GroupPath;

typedef struct GroupFollower {
    /* 00 */ GroupPath *mPath;
    /* 04 */ s32 mSpeed;
    /* 08 */ u16 mGroupIndex;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ s32 mSegmentIndex;
    /* 10 */ s32 mProgressStep;
    /* 14 */ s32 mProgress;
    /* 18 */ s32 mForward;
    /* 1c */ struct CourseMapGroupEntry *mFromEntry;
    /* 20 */ struct CourseMapGroupEntry *mToEntry;
} GroupFollower;

// Sub-object at 0x80 of Unk020e005c and MapObject: InitStateMachine stores its second, fourth and third arguments at
// 0x00, 0x08 and 0x0c and zeroes 0x04, 0x0e and 0x10.
typedef struct Unk020e005c_080 {
    /* 00 */ UnkFunc *const *mStateTable;
    /* 04 */ u32 mStateFrames;
    /* 08 */ void *mObject;
    /* 0c */ u16 mStateCount;
    /* 0e */ u16 mState;
    /* 10 */ u16 mNextState;
    /* 12 */ u16 mNextStateRequested;
} Unk020e005c_080;

// Shape that the collision routines test a map object against.
typedef enum {
    COLLISION_SHAPE_BOX,
    COLLISION_SHAPE_CYLINDER
} CollisionShape;

// Collision-body block at 0xa0 of Unk020e1d10, Bridge, Unk020e3ef4 and Unk020ff97c. Names carry the offset in the
// object.
typedef struct CollisionData {
    /* 00 */ MtxFx33 mPrevMatrix;
    /* 24 */ MtxFx33 mInitialMatrix;
    /* 48 */ Vec3 mUnk_e8;
    /* 54 */ Vec3 mCenterPos;
    /* 60 */ s32 mUnk_100;
    /* 64 */ s32 mHalfSizeY;
    /* 68 */ s32 mPositiveHalfSizeZ;
    /* 6c */ s32 mNegativeHalfSizeZ;
    /* 70 */ BOOL mUnk_110;
    /* 74 */ Vec3 mUnk_114;
    /* 80 */ s32 mUnk_120;
    /* 84 */ Vec3 mAngleChangeVector;
    /* 90 */ BOOL mUnk_130;
    /* 94 */ CollisionShape mUnk_134;
    /* 98 */ s32 mUnk_138;
} CollisionData;

typedef struct Unk020e005c Unk020e005c;
typedef struct Unk020e1d10 Unk020e1d10;

void UpdateKoopaBlockState1(Unk020e005c *koopaBlock);
void EnterKoopaBlockState1(Unk020e005c *koopaBlock);
void UpdateKoopaBlockState0(Unk020e005c *koopaBlock);
