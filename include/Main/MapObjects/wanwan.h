#pragma once

#include "types.h"
#include "Main/MapObjects/attractor.h" // MapObjectList
#include "fx_mtx33.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/code_020d6dc0.h"

typedef struct Wanwan Wanwan;

// Wanwan.mMapObject.mStateMachine states, in the order of gWanwanStateTable. ROAM moves on a curve around the center
// and starts LUNGE when a kart is near; HIT follows a collision; PULL_BACK returns to the center and goes on with
// ROAM; REST does nothing; FOLLOW_PATH moves along the group path (kind 0x1a5).
enum {
    WANWAN_STATE_ROAM,
    WANWAN_STATE_LUNGE,
    WANWAN_STATE_HIT,
    WANWAN_STATE_PULL_BACK,
    WANWAN_STATE_REST,
    WANWAN_STATE_FOLLOW_PATH,
};

// Values of Wanwan.mAngleAroundX (16-bit angles) that the states set: LEVEL is the tilt most states start with, LUNGE
// the tilt of LUNGE, HIT the tilt of HIT; HIT_END is the value that ends the HIT turn (LEVEL after one full turn).
#define WANWAN_ANGLE_AROUND_X_LEVEL 0x555
#define WANWAN_ANGLE_AROUND_X_LUNGE 0x2000
#define WANWAN_ANGLE_AROUND_X_HIT 0xd000
#define WANWAN_ANGLE_AROUND_X_HIT_END (WANWAN_ANGLE_AROUND_X_LEVEL + 0x10000)
// Wanwan.mOrientationBlendAmount (1.12 fixed point) at the start of a state, and the amount it grows per frame in
// the states that follow a path.
#define WANWAN_ORIENTATION_BLEND_AMOUNT_START 0x1c2
#define WANWAN_ORIENTATION_BLEND_AMOUNT_STEP 0x1c

// Object of CreateWanwanDrawList: functions at 0x08 and 0x10, a word at 0x18 and the address of the pointer that holds
// it at 0x28.
typedef struct WanwanDrawList {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ void (*mInit)(void);
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ void (*mForEachObject)(void *, Wanwan *, void *, u32);
    /* 14 */ u8 mUnk_14[4];
    /* 18 */ s32 mPass;
    /* 1c */ u8 mUnk_1c[0xc];
    /* 28 */ struct WanwanDrawList **mListSlot;
} WanwanDrawList;

// Object of CreateWanwanKindData: two functions and words at 0x08, 0x0c, 0x1c, 0x20 and 0x24.
typedef struct WanwanKindData {
    /* 00 */ u8 (*mCollideKartCallback)(Wanwan *, void *, u8 *, u8 *);
    /* 04 */ u8 (*mCollideItemObjectCallback)(Wanwan *, void *, u8 *, u8 *);
    /* 08 */ s32 mShapeKind;
    /* 0c */ s32 mExtentX;
    /* 10 */ u8 mUnk_10[0xc];
    /* 1c */ s32 mCollidable;
    /* 20 */ s32 mPosStepMode;
    /* 24 */ s32 mSoundId;
    /* 28 */ u8 mUnk_28[0x18];
} WanwanKindData;

extern const MapObjectList gWanwanUpdateListData;
extern const WanwanDrawList gWanwanDrawListData;
extern const WanwanKindData gWanwanKindData;
extern MapObjectList *gWanwanUpdateList;
extern WanwanDrawList *gWanwanDrawList;

void EnterWanwanState5(Wanwan *wanwan);
void UpdateWanwanState4Nop(Wanwan *wanwan);
void UpdateWanwanState2(Wanwan *wanwan);
void EnterWanwanState2(Wanwan *wanwan);
void UpdateWanwanState1(Wanwan *wanwan);
void EnterWanwanState1(Wanwan *wanwan);
void UpdateWanwanState0(Wanwan *wanwan);
void EnterWanwanState0(Wanwan *wanwan);
u8 CollideItemObjectWithWanwan(Wanwan *wanwan, void *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr);
u8 CollideKartWithWanwan(Wanwan *wanwan, void *kart, u8 *firstResponsePtr, u8 *secondResponsePtr);
void UpdateWanwan(void *unused, Wanwan *wanwan); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawWanwan(void *unused0, Wanwan *wanwan, void *unused1, u32 maxAlpha);
MapObjectList *CreateWanwanUpdateList(void);
WanwanDrawList *CreateWanwanDrawList(void);
WanwanKindData *CreateWanwanKindData(void);

void EnterWanwanState4(Wanwan *wanwan);

// Object of kinds 0x196 (with chain post kind 0x197) and 0x1a5 (mUnk_fc is 0 or 1) of Wanwan; UpdateWanwanState3,
// UpdateWanwanState2 and the functions after it up to CreateWanwanKindData: vectors at 0x04, 0x10 and 0xa0, ring of
// four vector pointers at 0x160, words at 0xe8, 0xec, 0xf0 and 0x1fc.
typedef struct Wanwan {
    /* 00 */ MapObject mMapObject;
    /* a0 */ Vec3 mCenterPos;
    /* ac */ s32 mBaseY;
    /* b0 */ s32 mUsesCourseCollision;
    /* b4 */ Quaternion mOrientation;
    /* c4 */ Quaternion mSurfaceOrientation;
    /* d4 */ Quaternion mYawQuaternion;
    /* e4 */ s32 mAngleAroundXOffset;
    /* e8 */ s32 mAngleAroundX;
    /* ec */ s32 mOrientationBlendAmount;
    /* f0 */ s32 mScaledLength;
    /* f4 */ s32 mProbeOffsetY;
    /* f8 */ s32 mRadiusLimit;
    /* fc */ s32 mFollowsPath;
    /* 100 */ SegmentProgress mSegmentProgress;
    /* 160 */ Vec3 *mCurvePoints[4];
    /* 170 */ Vec3 mCurvePointValues[4];
    /* 1a0 */ GroupFollowerWithSpeeds mFollower;
    /* 1d8 */ struct WanwanChainObject *mChainObject;
    /* 1dc */ s32 mKartDetectRadius;
    /* 1e0 */ Vec3 mTargetPos;
    /* 1ec */ s32 mMaxRadius;
    /* 1f0 */ Vec3 *mKartPos;
    /* 1f4 */ Vec3 *mKartVelocity;
    /* 1f8 */ u16 mTargetFrame;
    /* 1fa */ s16 mCollisionSlot;
    /* 1fc */ s32 mPullBackRadius;
    /* 200 */ Vec3 mForward;
} Wanwan;

void UpdateWanwanState3(Wanwan *wanwan);

void EnterWanwanState3(Wanwan *wanwan);
