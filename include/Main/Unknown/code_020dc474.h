#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_020d6dc0.h"

// Object of kinds 0x196 (with chain post kind 0x197) and 0x1a5 (mUnk_fc is 0 or 1) of Wanwan; UpdateWanwanState3,
// UpdateWanwanState2 and the functions after it up to CreateWanwanKindData: vectors at 0x04, 0x10 and 0xa0, ring of
// four vector pointers at 0x160, words at 0xe8, 0xec, 0xf0 and 0x1fc.
typedef struct Wanwan {
    /* 00 */ MapObject mMapObject;
    /* a0 */ Vec3 mCenterPos;
    /* ac */ s32 mUnk_ac;
    /* b0 */ s32 mUnk_b0;
    /* b4 */ Quaternion mOrientation;
    /* c4 */ Quaternion mSurfaceOrientation;
    /* d4 */ Quaternion mYawQuaternion;
    /* e4 */ s32 mUnk_e4;
    /* e8 */ s32 mUnk_e8;
    /* ec */ s32 mOrientationBlendAmount;
    /* f0 */ s32 mUnk_f0;
    /* f4 */ s32 mUnk_f4;
    /* f8 */ s32 mUnk_f8;
    /* fc */ s32 mFollowsPath;
    /* 100 */ SegmentProgress mSegmentProgress;
    /* 160 */ Vec3 *mCurvePoints[4];
    /* 170 */ Vec3 mCurvePointValues[4];
    /* 1a0 */ GroupFollowerWithSpeeds mFollower;
    /* 1d8 */ struct WanwanChainObject *mChainObject;
    /* 1dc */ s32 mUnk_1dc;
    /* 1e0 */ Vec3 mUnk_1e0;
    /* 1ec */ s32 mMaxRadius;
    /* 1f0 */ Vec3 *mKartPos;
    /* 1f4 */ Vec3 *mKartVelocity;
    /* 1f8 */ u16 mUnk_1f8;
    /* 1fa */ s16 mCollisionSlot;
    /* 1fc */ s32 mUnk_1fc;
    /* 200 */ Vec3 mUnk_200;
} Wanwan;

void UpdateWanwanState3(Wanwan *wanwan);
