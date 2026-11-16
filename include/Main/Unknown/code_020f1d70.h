#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Item/ItemInUse.h"

typedef struct ItemInUse ItemInUse;
typedef struct ItemKouraR ItemKouraR;

// Element of it_sItemsets[0], [1] and [5] up to 0x168: the word and the three vectors from 0x12c and the words
// and halfword from 0x154 that the functions of this file read after the shared part.
typedef struct DirectedItemObject {
    /* 000 */ ItemObject field0;
    /* 12c */ s32 mSpeed;
    /* 130 */ Vec3 mDirection;
    /* 13c */ Vec3 mSurfaceDirection;
    /* 148 */ Vec3 mSideDirection;
    /* 154 */ s32 mHitsRemaining;
    /* 158 */ s32 field158;
    /* 15c */ BOOL mHasHitLimit;
    /* 160 */ BOOL field160;
    /* 164 */ u16 field164;
    /* 166 */ u8 field166[2];
} DirectedItemObject;

void SetItemObjectDirection(void *objectParam, const Vec3 *direction);
void InitItemObjectMotion(void *objectParam, s32 hitLimit, s32 reverse, s32 d);
void DeflectItemObjectOnHit(DirectedItemObject *object, Vec3 *otherVelocity, Vec3 *awayDirection);
void sub_20F2028(ItemObject *object);
void ApplyItemObjectGravity(void *objectParam);
void AdvanceItemObjectMotion(DirectedItemObject *object, s32 targetSpeed);
void DeflectItemObjectAndStartSound(DirectedItemObject *object, Vec3 *hitNormal, Vec3 *c);
void sub_20F288C(DirectedItemObject *object, Vec3 *hitNormal);
void sub_20F29E8(ItemKouraR *item);
void sub_20F2A6C(Vec3 *direction, Vec3 *normal, Vec3 *result);
void InitItemObjectThrow(void *objectParam, ItemInUse *inUseParam, s32 hitLimit, s32 throwForward, s32 e,
                         s32 baseSpeed);
