#pragma once

#include "types.h"
#include "Main/MapObjects/attractor.h" // MapObjectList
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/map_object_response_and_quaternion_math.h"

#define WANWAN_HIT_FRAMES 0x78
#define WANWAN_ROAM_START_FRAMES 0x40
#define WANWAN_FOLLOW_PATH_FRAMES 0x40
#define WANWAN_LUNGE_FRAMES 0xb4
#define WANWAN_HIT_SHAKE_FRAMES 0x40
#define WANWAN_HIT_PHASE_END_FRAMES 0x28
#define WANWAN_PULL_BACK_FRAMES 0xb4

#define WANWAN_PATH_BASE_LAND_SOUND_ID 0x1a1
#define WANWAN_PATH_COURSE_LAND_SOUND_ID 0x1df
#define WANWAN_LUNGE_SOUND_ID 0x12c

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

// The draw list of the Wanwan map objects: init and per-object draw functions, the pass and the slot that holds it.
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

// The data of one Wanwan kind: its collision callbacks, shape, extent, sound and how it steps.
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

void EnterWanwanFollowPath(void *stateObject);
void UpdateWanwanRestNop(void *stateObject);
void UpdateWanwanHit(void *stateObject);
void EnterWanwanHit(void *stateObject);
void UpdateWanwanLunge(void *stateObject);
void EnterWanwanLunge(void *stateObject);
void UpdateWanwanRoam(void *stateObject);
void EnterWanwanRoam(void *stateObject);
u8 CollideItemObjectWithWanwan(Wanwan *wanwan, void *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr);
u8 CollideKartWithWanwan(Wanwan *wanwan, void *kart, u8 *firstResponsePtr, u8 *secondResponsePtr);
void UpdateWanwan(void *unused, Wanwan *wanwan); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawWanwan(void *unused0, Wanwan *wanwan, void *unused1, u32 maxAlpha);
MapObjectList *CreateWanwanUpdateList(void);
WanwanDrawList *CreateWanwanDrawList(void);
WanwanKindData *CreateWanwanKindData(void);

void EnterWanwanRest(void *stateObject);

// A Wanwan map object: its center, orientation, roam curve points, path follower, chain object and kart target.
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

void UpdateWanwanPullBack(void *stateObject);

void EnterWanwanPullBack(void *stateObject);
