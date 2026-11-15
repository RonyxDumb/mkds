#pragma once

#include "types.h"
#include "fx_mtx33.h"

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

// Shape that the collision routines test a map object against.
typedef enum { COLLISION_SHAPE_BOX, COLLISION_SHAPE_CYLINDER } CollisionShape;

// Collision-body block at 0xa0 of CollisionMapObject, Bridge, Rotary and MissionRunBox.
typedef struct CollisionData {
    /* 00 */ MtxFx33 mPrevMatrix;
    /* 24 */ MtxFx33 mInitialMatrix;
    /* 48 */ Vec3 mPreviousPos;
    /* 54 */ Vec3 mCenterPos;
    /* 60 */ s32 mHalfSizeX;
    /* 64 */ s32 mHalfSizeY;
    /* 68 */ s32 mPositiveHalfSizeZ;
    /* 6c */ s32 mNegativeHalfSizeZ;
    /* 70 */ BOOL mAxis0Flag;
    // x and y: axisFlag of axes 1 and 2; z: makes a hit in region 8 report hit flags 0x12.
    /* 74 */ Vec3 mHitFlagWords;
    /* 80 */ s32 mFloorThreshold;
    /* 84 */ Vec3 mAngleChangeVector;
    /* 90 */ BOOL mTracksNormal;
    /* 94 */ CollisionShape mShape;
    /* 98 */ s32 mCollisionFlag;
} CollisionData;

typedef struct KoopaBlock KoopaBlock;
typedef struct CollisionMapObject CollisionMapObject;

void UpdateKoopaBlockCruise(void *stateObject);
void EnterKoopaBlockCruise(void *stateObject);
void UpdateKoopaBlockAccelerate(void *stateObject);
