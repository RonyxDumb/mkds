#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/Course/course_color_blend.h" // CourseColorBlend
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/Graphics/model_animation.h" // ModelAnimation
#include "Main/MapObjects/segment_group_collision.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "Main/Sound/sound_distance_squared_change.h" // SoundDistanceSquaredChange
#include "Main/MapObjects/map_object_kind_update_list.h" // MAP_OBJECT_KIND_ROTARY_GEAR
#include "model_material_set.h"
#include "Main/MapObjects/quaternion_math.h" // Quaternion
#include "Main/MapObjects/send_obj_shadow.h" // ShadowMatrix
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Kart/shadow_model.h"

enum {
    CHOROPU_STATE_WAIT_START,
    CHOROPU_STATE_RISE,
    CHOROPU_STATE_HOLD_TOP,
    CHOROPU_STATE_SINK,
    CHOROPU_STATE_LEAP,
    CHOROPU_STATE_WAIT_REPEAT,
    CHOROPU_STATE_LAUNCHED_SPIN,
    CHOROPU_STATE_FALL_SPIN,
};

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
    /* 20 */ struct Nsbmd **mModelSlot;
    /* 24 */ struct ShadowModel **mShadowModelSlot;
    /* 28 */ ModelAnimation **mAnimationSlot;
    /* 2c */ s32 mRunSoundId;
    /* 30 */ s32 mBounceSoundId;
    /* 34 */ const char *mName;
} VehicleKindInfo;

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
    /* 124 */ struct Nsbmd *mModel;
    /* 128 */ struct ShadowModel *mShadowModel;
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
    /* 00 */ s32 mUsesAxis1;
    /* 04 */ s32 mRadius;
    /* 08 */ s32 mHeight;
    /* 0c */ s32 mModelIndex;
    /* 10 */ s32 mSignedNormalYLimit;
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
MapObjectKindData *CreateCarAKindData(void);
MapObjectKindData *CreateTruckAKindData(void);
MapObjectKindData *CreateBusAKindData(void);
MapObjectList *CreateVehicleDrawList(void);
MapObjectList *CreateVehicleUpdateList(void);
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

extern const MapObjectKindData gBusAKindData;
extern const MapObjectKindData gTruckAKindData;
extern const MapObjectKindData gCarAKindData;
extern Quaternion gIdentityQuaternion;
extern const MapObjectList gVehicleUpdateListData;
extern const u16 gVehicleHitFlag;
extern const VehicleDrawList gVehicleDrawListData;
extern struct Nsbmd *gCarA;
extern ModelAnimation *gCarANsbtp;
extern struct Nsbmd *gTruckA;
extern struct ShadowModel *gBusAShadow;
extern struct Nsbmd *gCarTire;
extern struct Nsbmd *gBusA;
extern struct ShadowModel *gCarAShadow;
extern struct ShadowModel *gTruckAShadow;
extern struct VehicleDrawList *gVehicleDrawList;
extern struct MapObjectList *gVehicleUpdateList;
extern ModelAnimation *gTruckANsbtp;
