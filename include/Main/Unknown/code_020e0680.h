#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_0208ab98.h" // CourseColorBlend
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_02087d0c.h" // ModelAnimation
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_0210b000.h" // SoundDistanceSquaredChange
#include "Main/Unknown/code_021000d0.h" // MAP_OBJECT_KIND_ROTARY_GEAR
#include "code_02012b30.h"
#include "Main/Unknown/code_020d6dc0.h" // Quaternion
#include "Main/Unknown/code_020e516c.h" // ShadowMatrix

extern const MapObjectList data_02158a54;
extern const MapObjectList data_02158854;
extern const MapObjectList data_02158bbc;
extern const MapObjectList data_02158cc0;

// Vehicle.mHitReactionTimer: set to the first value on a hit, counted down; above the second the vehicle is thrown.
#define VEHICLE_HIT_TIMER_START 0x14
#define VEHICLE_HIT_TIMER_AIRBORNE 0xf
// Vehicle.mRotationBlendRate values after a bounce, after landing and on a hit.
#define VEHICLE_BLEND_RATE_BOUNCE 0x320
#define VEHICLE_BLEND_RATE_LANDING 0x258
#define VEHICLE_BLEND_RATE_HIT 0x384
#define VEHICLE_TIRE_ANGLE_STEP 0x600
#define VEHICLE_GRAVITY_PER_FRAME 0x59a
#define VEHICLE_HIT_UPWARD_SPEED 0x7000

// Rotary.mModelIndex: the model the object draws.
#define ROTARY_MODEL_TEST_CYLINDER 0
#define ROTARY_MODEL_GEAR_BLACK 1
#define ROTARY_MODEL_GEAR_WHITE 2
#define ROTARY_MODEL_ROOM 3
#define ROTARY_MODEL_BRIDGE 4
#define ROTARY_MODEL_COUNT 5

// Rotary state machine states, in the order of gRotaryStateTable.
#define ROTARY_STATE_RAMP_UP 0
#define ROTARY_STATE_STEADY 1
#define ROTARY_STATE_SLOW_DOWN 2
#define ROTARY_STATE_PAUSE 3

extern const u16 data_02158a50;
extern const MapObjectKindData data_021588a8;
extern const MapObjectKindData data_02158c3c;
extern const MapObjectKindData data_02158d18;
extern const MapObjectKindData data_02158abc;
extern const MapObjectKindData data_02158afc;
extern const MapObjectKindData data_02158b3c;

// Object ComputeSphereHitOnCollisionBox and ComputeSphereHitOnCollisionCylinder compare against: two vectors, a word
// and a vector.
typedef struct CollisionHitRecord {
    /* 00 */ Vec3 mMaxOffset;
    /* 0c */ Vec3 mMinOffset;
    /* 18 */ s32 mDeepestDepth;
    /* 1c */ Vec3 mDeepestNormal;
} CollisionHitRecord;

// Object with a vector at 0x2c and words at 0x38 and 0x3c.
typedef struct VehicleDrawList {
    /* 000 */ MapObjectList mMapObjectList;
    /* 028 */ u8 mUnk_028[0x4];
    /* 02c */ Vec3 mEntryKartLinkDirection;
    /* 038 */ BOOL mLinkCullEnabled;
    /* 03c */ BOOL mLinkCullActive;
} VehicleDrawList;

extern const VehicleDrawList data_02158a7c;

typedef struct ItemObject ItemObject;

// Object a pointer at 0x154 of Vehicle points to.
typedef struct VehicleKindInfo {
    /* 00 */ s32 mExtentX;
    /* 04 */ s32 mExtentY;
    /* 08 */ s32 mExtentZ;
    /* 0c */ s32 mExtentNegativeZ;
    /* 10 */ s32 mTireOffsetX;
    /* 14 */ s32 mTireOffsetY;
    /* 18 */ s32 mTireOffsetZ;
    /* 1c */ s32 mTireRadius;
    /* 20 */ u32 *mModelSlot;
    /* 24 */ u32 *mShadowModelSlot;
    /* 28 */ ModelAnimation **mAnimationSlot;
    /* 2c */ s32 mRunSoundId;
    /* 30 */ s32 mBounceSoundId;
} VehicleKindInfo;

extern const Quaternion gIdentityQuaternion;

// Choropu record: the shared part of the map objects, then its own words and the shadow.
typedef struct Choropu {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ s32 mStartDelayFrameCount;
    /* 0a4 */ s32 mRepeatDelayFrameCount;
    /* 0a8 */ s32 mInitialY;
    /* 0ac */ s32 mBottomY;
    /* 0b0 */ s32 mLowestY;
    /* 0b4 */ s32 mSpinDirection;
    /* 0b8 */ u16 mSpinAngle;
    /* 0ba */ u8 mUnk_0ba[0x2];
    /* 0bc */ ShadowMatrix mShadowMatrix;
} Choropu;

// 0x164 bytes.
typedef struct Vehicle {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ s32 mStartEntryY;
    /* 0a4 */ Quaternion mRotation;
    /* 0b4 */ Quaternion mGroundRotation;
    /* 0c4 */ Quaternion mHitRotation;
    /* 0d4 */ s32 mUpdateIndex;
    /* 0d8 */ GroupFollower mFollower;
    /* 0fc */ u16 mStartEntryIndex;
    /* 0fe */ s16 mHitReactionTimer;
    /* 100 */ s32 mTireOffset[3];
    /* 10c */ u16 mTireAngle;
    /* 10e */ u8 mUnk_10e[0x2];
    /* 110 */ s32 mTireRadius;
    /* 114 */ Vec3 mExtentPositive;
    /* 120 */ s32 mExtentNegativeZ;
    /* 124 */ u32 mModel;
    /* 128 */ u32 mShadowModel;
    /* 12c */ ModelAnimation *mModelAnimation;
    /* 130 */ u16 mAnimationFrame;
    /* 132 */ CourseColorBlend mCourseColorBlend;
    /* 144 */ Vec3 mFollowerPosition;
    /* 150 */ u16 mDefaultBlendRate;
    /* 152 */ u16 mRotationBlendRate;
    /* 154 */ VehicleKindInfo *mKindInfo;
    /* 158 */ SoundDistanceSquaredChange *mSoundDistanceChange;
    /* 15c */ u32 mRunSoundId;
    /* 160 */ u32 mBounceSoundId;
} Vehicle;

// Map object with a collision block: the part that the collision routines read, which Koopa blocks and the kinds 0xcb,
// 0xcc, 0xce, 0xd0 and 0xd1 share.
typedef struct CollisionMapObject {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ CollisionData mCollisionData;
    /* 13c */ s32 mSkipsFlaggedQueries;
    /* 140 */ struct Nsbmd *mModel; // set by SetMapObjectsModel, drawn by DrawMapObjectModelAtPos
} CollisionMapObject;

// Koopa block: the shared part, then the path follower.
typedef struct KoopaBlock {
    /* 000 */ CollisionMapObject mCollisionMapObject;
    /* 144 */ GroupFollower mFollower;
    /* 168 */ s32 mFollowSpeed;
    /* 16c */ u16 mPauseTimer;
} KoopaBlock;

// Kind record InitRotary reads: the course map rows of the rotary kinds point at it.
typedef struct RotaryKindInfo {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mRadius;
    /* 08 */ s32 mHeight;
    /* 0c */ s32 mModelIndex;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mCollisionFlag;
    /* 18 */ s32 mSoundId;
} RotaryKindInfo;

// Object InitRotary fills.
typedef struct Rotary {
    /* 000 */ CollisionMapObject mCollisionMapObject;
    /* 144 */ u16 mRampFrameCount;
    /* 146 */ u16 mSteadyFrameCount;
    /* 148 */ u16 mPauseFrameCount;
    /* 14a */ s16 mAnglePerFrame;
    /* 14c */ s32 mSpeedFraction;
    /* 150 */ s32 mSpeedFractionPerFrame;
    /* 154 */ s32 mGearRadius;
    /* 158 */ s32 mModelIndex;
    /* 15c */ s32 mSoundId;
} Rotary;

// Object behind gBridgeDrawList, and the list of the kinds 0xcb, 0xce, 0xd0 and 0xd1.
typedef struct BridgeDrawList {
    /* 00 */ MapObjectList mMapObjectList;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mAnimationFrameCount;
} BridgeDrawList;

void InitChoropu(Choropu *choropu, struct CourseMapRow *courseRow);
void *CreateCarAKindData(void);
void *CreateTruckAKindData(void);
void *CreateBusAKindData(void);
void *CreateVehicleDrawList(void);
void *CreateVehicleUpdateList(void);
void SetVehicleLinkDirection(VehicleDrawList *drawList);
void DrawVehicle(VehicleDrawList *drawList, Vehicle *vehicle, u32 unusedArg, u32 alpha);
void UpdateVehicle(u32 unused, Vehicle *vehicle);
void StartVehicleHitReaction(Vehicle *vehicle, Vec3 *hitterPosition);
u8 CollideKartWithVehicle(Vehicle *vehicle, Kart *kart, u8 *firstResponse, u8 *response);
u8 CollideItemObjectWithVehicle(Vehicle *vehicle, ItemObject *itemObject, u8 *firstResponse, u8 *response);
void ComputeSphereHitOnVehicle(Vehicle *vehicle, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset);
void InitVehicleUpdateList(MapObjectList *updateList);
void InitVehicleDrawList(VehicleDrawList *drawList);
void InitVehicle(Vehicle *vehicle, struct CourseMapRow *courseRow, VehicleKindInfo *kindInfo);
void ResetVehicleToStartEntry(Vehicle *vehicle);
void DrawVisibleMapObjects(MapObjectList *list, void *viewMatrix,
                           void (*drawObject)(CollisionMapObject *, void *, u32));
void DrawMapObjectModelAtPos(CollisionMapObject *mapObject, void *viewMatrix, u32 alpha);
void SetMapObjectsModel(MapObjectList *list, void *model);
s32 ComputeSphereHitOnCollisionData(CollisionMapObject *object, Vec3 *sphereCenter, s32 sphereRadius, u16 queryFlags,
                                    CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord,
                                    Vec3 *lowestOffset, u16 *outFlags, Vec3 *pointMotion, u16 *angleChange);
void AddCollisionHitOneAxis(s32 sphereRadius, s32 signedDepth, s32 depth, u32 regionFlags, u16 positiveSideBit,
                            u16 *outFlags, s32 axisFlag, CollisionMapObject *object, Vec3 *sphereCenter, Vec3 *normal,
                            CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord, Vec3 *lowestOffset,
                            Vec3 *pointMotion, u16 *angleChange);
BOOL AddCollisionHitTwoAxes(s32 sphereRadius, s32 firstOffset, s32 secondOffset, u32 regionFlags,
                            u16 firstPositiveSideBit, u16 secondPositiveSideBit, u16 *outFlags, u16 queryFlags,
                            s32 firstAxisFlag, s32 secondAxisFlag, CollisionMapObject *object, Vec3 *sphereCenter,
                            Vec3 *firstNormal, Vec3 *secondNormal, CollisionHitRecord *firstHitRecord,
                            CollisionHitRecord *secondHitRecord, Vec3 *lowestOffset, Vec3 *pointMotion,
                            u16 *angleChange);
BOOL ComputeSphereHitOnCollisionBox(CollisionMapObject *object, Vec3 *sphereCenter, s32 sphereRadius, u16 queryFlags,
                                    CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord,
                                    Vec3 *lowestOffset, u16 *outFlags, Vec3 *pointMotion, u16 *angleChange);
BOOL ComputeSphereHitOnCollisionCylinder(CollisionMapObject *object, Vec3 *sphereCenter, s32 sphereRadius,
                                         u16 queryFlags, CollisionHitRecord *firstHitRecord,
                                         CollisionHitRecord *secondHitRecord, Vec3 *lowestOffset, u16 *outFlags,
                                         Vec3 *pointMotion, u16 *angleChange);
void ComputeCollisionPointMotion(CollisionMapObject *object, Vec3 *position, Vec3 *contactNormal, Vec3 *pointMotion,
                                 u16 *angleChange);
