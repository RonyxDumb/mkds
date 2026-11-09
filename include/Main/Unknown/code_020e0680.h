#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_0210b000.h" // SoundDistanceSquaredChange
#include "code_02012b30.h"

// Block of ten words.
typedef struct Unk020e0340 {
    /* 00 */ u32 mUnk_00[10];
} Unk020e0340;

extern const Unk020e0340 data_02158a54;
extern const Unk020e0340 data_02158854;
extern const Unk020e0340 data_02158bbc;
extern const Unk020e0340 data_02158cc0;

// Block of sixteen words.
typedef struct Unk020e03f8 {
    /* 00 */ u32 mUnk_00[16];
} Unk020e03f8;

extern const u16 data_02158a50;
extern const Unk020e03f8 data_02158a7c;
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
    /* 000 */ u8 mUnk_000[0x2c];
    /* 02c */ Vec3 mEntryKartLinkDirection;
    /* 038 */ BOOL mUnk_038;
    /* 03c */ BOOL mUnk_03c;
} VehicleDrawList;

// Object with vectors at 0x50 and 0x80.
typedef struct Unk020e246c {
    /* 000 */ u8 mUnk_000[0x50];
    /* 050 */ Vec3 mUnk_050;
    /* 05c */ s32 mUnk_05c;
    /* 060 */ u8 mUnk_060[0x4];
    /* 064 */ s32 mUnk_064;
    /* 068 */ u8 mUnk_068[0xc];
    /* 074 */ u16 mUnk_074;
    /* 076 */ u8 mUnk_076[0xa];
    /* 080 */ Vec3 mUnk_080;
    /* 08c */ u8 mUnk_08c[0x18];
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ u8 mUnk_0a8[0x4];
    /* 0ac */ s32 mUnk_0ac;
} Unk020e246c;

// Object a pointer at 0x12c of Unk020e1e98 points to (also behind gBridgeNsbca).
typedef struct Unk020e1e98_12c {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10[0xa];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ s32 **mUnk_1c;
} Unk020e1e98_12c;

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
    /* 28 */ Unk020e1e98_12c **mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
} Unk020e1e98_154;

// Four words at 0xb4 of Unk020e1e98.
typedef struct Unk020e1e98_0b4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[0x2];
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk020e1e98_0b4;

extern const Unk020e1e98_0b4 gIdentityQuaternion;

// 0x164 bytes.
typedef struct Unk020e1e98 {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ s32 mUnk_0a0;
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ s32 mUnk_0b0;
    /* 0b4 */ Unk020e1e98_0b4 mUnk_0b4;
    /* 0c4 */ s32 mUnk_0c4;
    /* 0c8 */ s32 mUnk_0c8;
    /* 0cc */ s32 mUnk_0cc;
    /* 0d0 */ u8 mUnk_0d0[0x4];
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
    /* 12c */ Unk020e1e98_12c *mUnk_12c;
    /* 130 */ u16 mUnk_130;
    /* 132 */ u16 mUnk_132;
    /* 134 */ u8 mUnk_134[0xc];
    /* 140 */ void *mUnk_140;
    /* 144 */ Vec3 mUnk_144;
    /* 150 */ u16 mUnk_150;
    /* 152 */ u16 mUnk_152;
    /* 154 */ Unk020e1e98_154 *mUnk_154;
    /* 158 */ SoundDistanceSquaredChange *mUnk_158;
    /* 15c */ u32 mUnk_15c;
    /* 160 */ u32 mUnk_160;
} Unk020e1e98;

// Object behind gVehicleDrawList and the argument of InitVehicleUpdateList.
typedef struct Unk0217b79c {
    /* 00 */ Unk020e1e98 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk0217b79c;

// Object func_020e3ef4 fills.
typedef struct Unk020e3ef4 {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ CollisionData mCollisionData;
    /* 13c */ u8 mUnk_13c[0x4];
    /* 140 */ struct Nsbmd *mModel;
    /* 144 */ u16 mUnk_144;
    /* 146 */ u16 mUnk_146;
    /* 148 */ u16 mUnk_148;
    /* 14a */ s16 mUnk_14a;
    /* 14c */ s32 mUnk_14c;
    /* 150 */ s32 mUnk_150;
    /* 154 */ s32 mUnk_154;
    /* 158 */ s32 mUnk_158;
    /* 15c */ s32 mUnk_15c;
} Unk020e3ef4;

// Object behind data_0217b7c4.
typedef struct BridgeDrawList {
    /* 00 */ Unk020e3ef4 **mMapObjects;
    /* 04 */ u16 mMapObjectCount;
    /* 06 */ u8 mUnk_06[0x26];
    /* 2c */ s32 mAnimationFrameCount;
} BridgeDrawList;

void InitChoropu(Unk020e1e98 *choropu, struct CourseMapRow *courseRow);
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
u8 CollideItemObjectWithVehicle(Unk020e1e98 *vehicle, Unk020e246c *itemObject, u8 *c, u8 *d);
void ComputeSphereHitOnVehicle(Unk020e1e98 *vehicle, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset);
void InitVehicleUpdateList(Unk0217b79c *updateList);
void InitVehicleDrawList(VehicleDrawList *drawList);
void InitVehicle(Unk020e1e98 *vehicle, struct CourseMapRow *courseRow, Unk020e1e98_154 *kindInfo);
void ResetVehicleToStartEntry(Unk020e1e98 *vehicle);
void DrawVisibleMapObjects(BridgeDrawList *list, void *viewMatrix, void (*drawObject)(Unk020e3ef4 *, void *, u32));
void DrawMapObjectModelAtPos(Unk020e3ef4 *mapObject, void *viewMatrix, u32 alpha);
void SetMapObjectsModel(BridgeDrawList *list, void *model);
s32 ComputeSphereHitOnCollisionData(Unk020e005c *object, Vec3 *sphereCenter, s32 sphereRadius, u16 queryFlags,
                                    CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord,
                                    Vec3 *lowestOffset, u16 *outFlags, Vec3 *pointMotion, u16 *angleChange);
void AddCollisionHitOneAxis(s32 sphereRadius, s32 signedDepth, s32 depth, u32 regionFlags, u16 positiveSideBit,
                            u16 *outFlags, s32 axisFlag, Unk020e005c *object, Vec3 *sphereCenter, Vec3 *normal,
                            CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord, Vec3 *lowestOffset,
                            Vec3 *pointMotion, u16 *angleChange);
BOOL AddCollisionHitTwoAxes(s32 sphereRadius, s32 firstOffset, s32 c, u32 regionFlags, u16 firstPositiveSideBit,
                            u16 secondPositiveSideBit, u16 *outFlags, u16 queryFlags, s32 firstAxisFlag,
                            s32 secondAxisFlag, Unk020e005c *object, Vec3 *sphereCenter, Vec3 *firstNormal,
                            Vec3 *secondNormal, CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord,
                            Vec3 *lowestOffset, Vec3 *pointMotion, u16 *angleChange);
BOOL ComputeSphereHitOnCollisionBox(Unk020e005c *object, Vec3 *sphereCenter, s32 sphereRadius, u16 queryFlags,
                                    CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord,
                                    Vec3 *lowestOffset, u16 *outFlags, Vec3 *pointMotion, u16 *angleChange);
BOOL ComputeSphereHitOnCollisionCylinder(Unk020e005c *object, Vec3 *sphereCenter, s32 sphereRadius, u16 queryFlags,
                                         CollisionHitRecord *firstHitRecord, CollisionHitRecord *secondHitRecord,
                                         Vec3 *lowestOffset, u16 *outFlags, Vec3 *pointMotion, u16 *angleChange);
void ComputeCollisionPointMotion(Unk020e005c *object, Vec3 *position, Vec3 *contactNormal, Vec3 *pointMotion,
                                 u16 *angleChange);
