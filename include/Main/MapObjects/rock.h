#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/code_020e01f0.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/map_object_kind_update_list.h" // MapObjectKindDescriptor

// 0x1c-byte element of the table behind gCollisionSlots.
typedef struct CollisionSlot {
    /* 00 */ s16 mHighEndIndex;
    /* 02 */ s16 mLowEndIndex;
    /* 04 */ s32 mHighZ;
    /* 08 */ s32 mLowZ;
    /* 0c */ Vec3 *mCenterPos;
    /* 10 */ s32 mRadius;
    /* 14 */ u16 mFlags;
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ void *mObject;
} CollisionSlot;

static inline CollisionSlot *GetCollisionSlot(s16 slotId) {
    return &gCollisionSlots[slotId];
}

// Four-byte element of the tables behind gCollisionSlotHighEnds and gCollisionSlotLowEnds.
typedef struct CollisionSlotEnd {
    /* 00 */ u32 mOtherEndIndex : 8;
// Low-end list: the slot index. High-end list: the lowest low-end index the search scans down to.
    /* 01 */ u32 mSlotIndexOrScanLimit : 8;
    /* 02 */ s32 mEndX : 16;
} CollisionSlotEnd;

u32 FreeCollisionSlot(s32 slotIndex);
s32 CreateCollisionSlot(Vec3 *centerPos, s32 radius, s32 flags, void *object);
// Object behind the pointer IsCollisionHitLinkOutdated and UpdateCollisionHitLink read: a pointer at 0x00 and a word at
// 0x04.
typedef struct CollisionFirstHit {
    /* 00 */ CollisionMapObject *mObject;
    /* 04 */ s32 mLinkBlocked;
} CollisionFirstHit;

// Element object of InitRock: MapObject and the words and halfword used after it.
typedef struct RockObject {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ s32 mStartY;
    /* 0a4 */ GroupFollowerWithSpeeds mFollower;
    /* 0dc */ s32 mDelayFrames;
    /* 0e0 */ s32 mDelayFramesLeft;
    /* 0e4 */ Vec3 mBasePos;
    /* 0f0 */ Vec3 *mSideVectors;
    /* 0f4 */ BOOL mBounceSide;
    /* 0f8 */ s32 mOffsetVelocityX;
    /* 0fc */ s32 mOffsetVelocityZ;
    /* 100 */ s32 mOffsetX;
    /* 104 */ s32 mOffsetZ;
    /* 108 */ u16 mSinceGroundFrames;
    /* 10a */ u8 mUnk_10a[2];
    /* 10c */ s32 mStartScale;
    /* 110 */ s32 mScalePerFrame;
    /* 114 */ s32 mScaleLimit;
    /* 118 */ s32 mBottomOffsetReciprocal;
    /* 11c */ s32 mBottomOffset;
    /* 120 */ s32 mBounceRatio;
} RockObject;

// Twelve bytes ResetRockWithEffects fills: a word and three halfwords.
typedef struct EmitterParams {
    /* 00 */ s32 mRadius;
    /* 04 */ s16 mDirectionSpeed;
    /* 06 */ s16 mAxisSpeed;
    /* 08 */ s16 mSizeScale;
    /* 0a */ u8 mUnk_0a[2];
} EmitterParams;

void UpdateRock(void *mapObjectList, RockObject *rock);
void ResetRockWithEffects(RockObject *rock, s32 wasHit);
u8 CollideKartWithRock(RockObject *rock, s32 unused, u8 *firstResponsePtr, u8 *secondResponsePtr);
u8 CollideItemObjectWithRock(RockObject *rock, s32 unused, u8 *firstResponsePtr, u8 *secondResponsePtr);
void ResetRock(RockObject *rock);
void InitRock(RockObject *rock, struct CourseMapRow *courseRow);
void CreateNsbmdAndShadowNsbmd(void *mapObjectList, const char *name, const char *shadowName);
void CreateRock(void *mapObjectList);
void CreateRock2(void *mapObjectList);
void LoadCourseCollisionData(CourseCollision *collision, CourseCollision *file);
void InitCourseCollision(void);
void UpdateCollisionHitLink(void *hitListPtr, u32 collisionBits, CollisionHitLink *link, Vec3 *position, Vec3 *normal);
BOOL IsCollisionHitLinkOutdated(void *hitListPtr, u32 collisionBits, CollisionHitLink *link);
u16 PickCollisionHitValue(u32 mask);
void InitCollisionSlots(void);
void FindCollisionSlotsAroundPos(Vec3 *position, s32 radius, s32 flagMask);
void SetCollisionSlotRadius(s16 slotIndex, s32 radius);
void DisableCollisionSlot(s16 slotIndex);
void EnableCollisionSlot(s16 slotIndex);

extern const u16 gRockSecondFlag;
extern const u16 gRockThirdFlag;
extern const u16 gRockFirstFlag;
extern const s16 gRockFirstEffectRows08[4];
extern const s16 gRockSecondEffectRows04[4];
extern const s16 gRockSecondEffectRows06[4];
extern const s16 gRockSecondEffectRows08[4];
extern const s16 gRockFirstEffectRows04[4];
extern const s16 gRockFirstEffectRows06[4];
extern const s32 gRockSecondEffectRows00[4];
extern const s32 gRockFirstEffectRows00[4];
extern const MapObjectKindDescriptor gRockKindDescriptor;
extern const MapObjectKindDescriptor gRock2KindDescriptor;
