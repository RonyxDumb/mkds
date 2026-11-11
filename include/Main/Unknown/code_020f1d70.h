#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ed5c0.h"

typedef struct ItemInUse ItemInUse;
typedef struct ItemKouraR ItemKouraR;

// Element of gItemPools[0], [1] and [5] up to 0x168: the word and the three vectors from 0x12c and the words
// and halfword from 0x154 that the functions of this file read after the shared part.
typedef struct DirectedItemObject {
    /* 000 */ ItemObject mItemObject;
    /* 12c */ s32 mSpeed;
    /* 130 */ Vec3 mDirection;
    /* 13c */ Vec3 mSurfaceDirection;
    /* 148 */ Vec3 mSideDirection;
    /* 154 */ s32 mHitsRemaining;
    /* 158 */ s32 mUnk_158;
    /* 15c */ BOOL mHasHitLimit;
    /* 160 */ BOOL mUnk_160;
    /* 164 */ u16 mUnk_164;
    /* 166 */ u8 mUnk_166[2];
} DirectedItemObject;

void SetItemObjectDirection(void *objectParam, const Vec3 *direction);
void InitItemObjectMotion(void *objectParam, s32 hitLimit, s32 reverse, s32 d);
void DeflectItemObjectOnHit(DirectedItemObject *object, Vec3 *otherVelocity, Vec3 *awayDirection);
void ApplyItemObjectGravityWithGroundPull(ItemObject *object);
void ApplyItemObjectGravity(void *objectParam);
void AdvanceItemObjectMotion(DirectedItemObject *object, s32 targetSpeed);
void DeflectItemObjectAndStartSound(DirectedItemObject *object, Vec3 *hitNormal, Vec3 *c);
void DeflectItemObjectAlongSurfaceAndStartSound(DirectedItemObject *object, Vec3 *hitNormal);
void SetItemObjectDirectionFromVelocity(ItemKouraR *item);
void ComputeItemSurfaceDirection(Vec3 *direction, Vec3 *normal, Vec3 *result);
void InitItemObjectThrow(void *objectParam, ItemInUse *inUseParam, s32 hitLimit, s32 throwForward, s32 e,
                         s32 baseSpeed);
