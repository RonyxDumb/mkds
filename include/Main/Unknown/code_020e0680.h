#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_0208ab98.h" // CourseColorBlend
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_02087d0c.h" // ModelAnimation
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_0210b000.h" // SoundDistanceSquaredChange
#include "code_02012b30.h"
#include "Main/Unknown/code_020d6dc0.h" // Quaternion
#include "Main/Unknown/code_020e516c.h" // ShadowMatrix

extern const MapObjectList data_02158a54;
extern const MapObjectList data_02158854;
extern const MapObjectList data_02158bbc;
extern const MapObjectList data_02158cc0;

// Block of sixteen words.
typedef struct Unk020e03f8 {
    /* 00 */ u32 mUnk_00[16];
} Unk020e03f8;

extern const u16 data_02158a50;
extern const Unk020e03f8 data_021588a8;
extern const Unk020e03f8 data_02158c3c;
extern const Unk020e03f8 data_02158d18;
extern const Unk020e03f8 data_02158abc;
extern const Unk020e03f8 data_02158afc;
extern const Unk020e03f8 data_02158b3c;

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
    /* 038 */ BOOL mUnk_038;
    /* 03c */ BOOL mUnk_03c;
} VehicleDrawList;

extern const VehicleDrawList data_02158a7c;

typedef struct ItemObject ItemObject;

// Object a pointer at 0x154 of Unk020e1e98 points to.
typedef struct Unk020e1e98_154 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u32 *mUnk_20;
    /* 24 */ u32 *mUnk_24;
    /* 28 */ ModelAnimation **mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
} Unk020e1e98_154;

extern const Quaternion gIdentityQuaternion;

// Choropu record: the shared part of the map objects, then its own words and the shadow.
typedef struct Choropu {
    /* 000 */ MapObject mUnk_000;
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
typedef struct Unk020e1e98 {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ s32 mUnk_0a0;
    /* 0a4 */ Quaternion mUnk_0a4;
    /* 0b4 */ Quaternion mUnk_0b4;
    /* 0c4 */ Quaternion mUnk_0c4;
    /* 0d4 */ s32 mUnk_0d4;
    /* 0d8 */ GroupFollower mUnk_0d8;
    /* 0fc */ u16 mUnk_0fc;
    /* 0fe */ s16 mUnk_0fe;
    /* 100 */ s32 mUnk_100[3];
    /* 10c */ u16 mUnk_10c;
    /* 10e */ u8 mUnk_10e[0x2];
    /* 110 */ s32 mUnk_110;
    /* 114 */ Vec3 mUnk_114;
    /* 120 */ s32 mUnk_120;
    /* 124 */ u32 mUnk_124;
    /* 128 */ u32 mUnk_128;
    /* 12c */ ModelAnimation *mUnk_12c;
    /* 130 */ u16 mUnk_130;
    /* 132 */ CourseColorBlend mCourseColorBlend;
    /* 144 */ Vec3 mUnk_144;
    /* 150 */ u16 mUnk_150;
    /* 152 */ u16 mUnk_152;
    /* 154 */ Unk020e1e98_154 *mUnk_154;
    /* 158 */ SoundDistanceSquaredChange *mUnk_158;
    /* 15c */ u32 mUnk_15c;
    /* 160 */ u32 mUnk_160;
} Unk020e1e98;

// Map object with a collision block: the part that the collision routines read, which Koopa blocks and the kinds 0xcb,
// 0xcc, 0xce, 0xd0 and 0xd1 share.
typedef struct Unk020e1d10 {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ CollisionData mCollisionData;
    /* 13c */ s32 mUnk_13c;
    /* 140 */ struct Nsbmd *mModel; // set by SetMapObjectsModel, drawn by DrawMapObjectModelAtPos
} Unk020e1d10;

// Koopa block: the shared part, then the path follower.
typedef struct Unk020e005c {
    /* 000 */ Unk020e1d10 mUnk_000;
    /* 144 */ GroupFollower mUnk_144;
    /* 168 */ s32 mUnk_168;
    /* 16c */ u16 mUnk_16c;
} Unk020e005c;

// Object InitRotary fills.
typedef struct Unk020e3ef4 {
    /* 000 */ Unk020e1d10 mUnk_000;
    /* 144 */ u16 mRampFrameCount;
    /* 146 */ u16 mSteadyFrameCount;
    /* 148 */ u16 mPauseFrameCount;
    /* 14a */ s16 mAnglePerFrame;
    /* 14c */ s32 mSpeedFraction;
    /* 150 */ s32 mSpeedFractionPerFrame;
    /* 154 */ s32 mUnk_154;
    /* 158 */ s32 mModelIndex;
    /* 15c */ s32 mSoundId;
} Unk020e3ef4;

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
void DrawVehicle(VehicleDrawList *drawList, Unk020e1e98 *vehicle, u32 c, u32 alpha);
void UpdateVehicle(u32 a, Unk020e1e98 *vehicle);
void StartVehicleHitReaction(Unk020e1e98 *vehicle, Vec3 *hitterPosition);
u8 CollideKartWithVehicle(Unk020e1e98 *vehicle, Kart *kart, u8 *c, u8 *d);
u8 CollideItemObjectWithVehicle(Unk020e1e98 *vehicle, ItemObject *itemObject, u8 *c, u8 *d);
void ComputeSphereHitOnVehicle(Unk020e1e98 *vehicle, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset);
void InitVehicleUpdateList(MapObjectList *updateList);
void InitVehicleDrawList(VehicleDrawList *drawList);
void InitVehicle(Unk020e1e98 *vehicle, struct CourseMapRow *courseRow, Unk020e1e98_154 *kindInfo);
void ResetVehicleToStartEntry(Unk020e1e98 *vehicle);
void DrawVisibleMapObjects(MapObjectList *list, void *viewMatrix, void (*drawObject)(Unk020e1d10 *, void *, u32));
void DrawMapObjectModelAtPos(Unk020e1d10 *mapObject, void *viewMatrix, u32 alpha);
void SetMapObjectsModel(MapObjectList *list, void *model);
s32 ComputeSphereHitOnCollisionData(Unk020e1d10 *object, Vec3 *sphereCenter, s32 sphereRadius, u16 queryFlags,
                                    CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord,
                                    Vec3 *lowestOffset, u16 *outFlags, Vec3 *pointMotion, u16 *angleChange);
void AddCollisionHitOneAxis(s32 sphereRadius, s32 signedDepth, s32 depth, u32 regionFlags, u16 positiveSideBit,
                            u16 *outFlags, s32 axisFlag, Unk020e1d10 *object, Vec3 *sphereCenter, Vec3 *normal,
                            CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord, Vec3 *lowestOffset,
                            Vec3 *pointMotion, u16 *angleChange);
BOOL AddCollisionHitTwoAxes(s32 sphereRadius, s32 firstOffset, s32 c, u32 regionFlags, u16 firstPositiveSideBit,
                            u16 secondPositiveSideBit, u16 *outFlags, u16 queryFlags, s32 firstAxisFlag,
                            s32 secondAxisFlag, Unk020e1d10 *object, Vec3 *sphereCenter, Vec3 *firstNormal,
                            Vec3 *secondNormal, CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord,
                            Vec3 *lowestOffset, Vec3 *pointMotion, u16 *angleChange);
BOOL ComputeSphereHitOnCollisionBox(Unk020e1d10 *object, Vec3 *sphereCenter, s32 sphereRadius, u16 queryFlags,
                                    CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord,
                                    Vec3 *lowestOffset, u16 *outFlags, Vec3 *pointMotion, u16 *angleChange);
BOOL ComputeSphereHitOnCollisionCylinder(Unk020e1d10 *object, Vec3 *sphereCenter, s32 sphereRadius, u16 queryFlags,
                                         CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord,
                                         Vec3 *lowestOffset, u16 *outFlags, Vec3 *pointMotion, u16 *angleChange);
void ComputeCollisionPointMotion(Unk020e1d10 *object, Vec3 *position, Vec3 *contactNormal, Vec3 *pointMotion,
                                 u16 *angleChange);
