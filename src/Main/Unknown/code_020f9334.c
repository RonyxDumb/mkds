#include "Main/Unknown/code_020f9334.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020d6538.h"

#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_02109000.h"
#include "code_02147cd8.h"

BOOL sub_20F9C08(ItemObject *item) {
    if (item->mAgeFrames > 0x12c && (item->mFlags & 0x8000) != 0 &&
        item->mAdvance == (void (*)(ItemObject *)) AdvanceRestingItemObject) {
        return TRUE;
    }
    return FALSE;
}

void sub_20F9BA8(ItemObject *item) {
    if (item->mAgeFrames <= 0x12c) {
        return;
    }
    if ((item->mFlags & 0x8000) == 0) {
        return;
    }
    if (item->mAdvance != (void (*)(ItemObject *)) AdvanceRestingItemObject) {
        return;
    }
    sub_20F7658(item, 1);
}

void func_020f9b0c(ItemObject *item) {
    if ((item->mFlags & 0x8000) != 0) {
        sub_20F7658(item, 1);
        return;
    }
    item->mVelocity.x = ((s64) item->mVelocity.x * 0x99a) >> 12;
    item->mVelocity.y = ((s64) item->mVelocity.y * 0x99a) >> 12;
    item->mVelocity.z = ((s64) item->mVelocity.z * 0x99a) >> 12;
    sub_20F6FC4(item, 1);
}

void it_initInstance(ItemObject *item, s32 kind) {
    void (*reset)(void *);

    reset = it_sItemParams[kind].mReset;
    item->mKind = kind;
    item->mFlags = 0;
    item->field7A = 0;
    item->mScale.x = 0;
    item->mScale.y = 0;
    item->mScale.z = 0;
    item->field100 = 0;
    item->fieldDC = 0x7b;
    item->mRadius = 0x7b;
    item->mAlpha = 0x1f;
    item->mCollisionBits = 0;
    item->field118 = 0;
    item->field114 = 5;
    item->mBounce = NULL;
    item->fieldD0 = &item->mPos;
    item->mCollisionSlotIndex = -1;
    item->field104->field0 = NULL;
    if (gRaceMultiConfig->mMode == 5) {
        item->mFlags |= 0x8000000;
    }
    item->field78 |= data_02159cac;
    light_init(&item->mColorBlend, 1);
    item->field90 = NULL;
    if (reset != NULL) {
        reset(item);
    }
    item->field128 = 0;
}

void it_20F99B8(ItemObject *item, s32 kind, u16 ownerAndFlags, Vec3 *pos) {
    item->mPos = *pos;
    item->field78 = ownerAndFlags;
    it_initInstance(item, kind);
    if ((item->mFlags & 0x8000000) == 0) {
        return;
    }
    item->mId = ComputeItemObjectId(item);
}

void it_destroy(ItemObject *item) {
    enum { K0 } kind;

    if (item->mCollisionSlotIndex != -1) {
        item->mCollisionSlotIndex = col_deleteColEntry(item->mCollisionSlotIndex);
    }
    if ((item->mFlags & 0x400000) != 0) {
        sub_2109054(&item->mSoundSource);
        item->mSoundSource.mTrackParamsFunction = NULL;
        item->mFlags &= ~0x400000;
    }
    item->mFlags |= 4;
    kind = item->mKind;
    if (it_sItemParams[kind].mRelease != NULL) {
        it_sItemParams[kind].mRelease(item);
    }
}

void it_20F98A0(ItemObject *itemParam, Vec3 *prevPos, Vec3 *normal, u16 *colorBlend, s32 param_5) {
    ItemObject *item = itemParam;
    item->mPrevPos = *prevPos;
    if (colorBlend != NULL) {
        item->mColorBlend = *(CourseColorBlend *) colorBlend;
    } else {
        light_init(&item->mColorBlend, 1);
    }
    item->mNormal = *normal;
    item->field116 = param_5 != 0 ? 0 : 5;
}

s32 sub_20F9880(ItemObject *item) {
    return it_sItemParams[item->mKind].field84;
}

BOOL it_20F97E0(ItemObject *item, Kart *kart) {
    Vec3 offset;
    s32 hitRadius;

    if (item->mCollisionSlotIndex == -1 ||
        kart->mIndex == (u16) ((item->field78 & 0x4000) != 0 ? (u16) (item->field78 & ~0xff00) : 8)) {
        return FALSE;
    }
    hitRadius = kart->mRadius + item->mRadius;
    offset.x = item->mPos.x - kart->mPointAlongUp.x;
    offset.y = item->mPos.y - kart->mPointAlongUp.y;
    offset.z = item->mPos.z - kart->mPointAlongUp.z;
    return (s64) offset.x * offset.x + (s64) offset.y * offset.y + (s64) offset.z * offset.z <
           (s64) hitRadius * hitRadius;
}

BOOL IsItemObjectOverlappingSphere(ItemObject *item, Vec3 *center, s32 radius) {
    Vec3 offset;
    s32 sumRadius;

    sumRadius = radius + item->mRadius;
    offset.x = item->mPos.x - center->x;
    offset.y = item->mPos.y - center->y;
    offset.z = item->mPos.z - center->z;
    return (s64) offset.x * offset.x + (s64) offset.y * offset.y + (s64) offset.z * offset.z <
           (s64) sumRadius * sumRadius;
}

void func_020f95d4(ItemObject *item, ItemObject *other) {
    Vec3 itemVelocity;
    s32 hitType;
    s32 otherHitType;

    if (other->mCollisionSlotIndex == -1) {
        return;
    }
    if ((other->mFlags & 0x1000) != 0) {
        return;
    }
    if ((other->mFlags & 0x8000) == 0) {
        if (item->field48 > other->field48) {
            return;
        }
    }
    if ((item->mFlags & 0x10000000) != 0 && (other->mFlags & 0x10000000) != 0) {
        if (GetItemObjectHitType(item, other) != 1 && GetItemObjectHitType(other, item) != 1) {
            return;
        }
    }
    if (IsItemObjectOverlappingSphere(item, &other->mPos, other->mRadius) == FALSE) {
        if (IsItemObjectOverlappingSphere(item, &other->mPrevPos, other->mRadius) == FALSE) {
            return;
        }
        if (IsItemObjectOverlappingSphere(other, &item->mPrevPos, item->mRadius) == FALSE) {
            return;
        }
    }
    itemVelocity = item->mVelocity;
    hitType = GetItemObjectHitType(item, other);
    otherHitType = GetItemObjectHitType(other, item);
    it_20F77F8(item, hitType, &other->mPos, &other->mVelocity, NULL);
    it_20F77F8(other, otherHitType, &item->mPos, &itemVelocity, NULL);
    if (item->mKind == 1) {
        sub_20F5614(item, hitType, other);
    }
    if (other->mKind != 1) {
        return;
    }
    sub_20F5614(other, otherHitType, item);
}

void it_20F944C(ItemObject *itemParam, MapObject *mapObjectParam) {
    Vec3 a;
    Vec3 otherPos;
    s32 b;
    MapObject *reportedMapObject;
    ItemObject *item = itemParam;
    MapObject *mapObject = mapObjectParam;

    if (mobj_sphereCollide(&item->mPos, item->mRadius, mapObject, &a) == FALSE) {
        return;
    }
    if ((mapObject->mFlags & 0x40) == 0 && (item->mFlags & 0x80000) == 0 &&
        mobj_getCollidesWithItem(item->mKind, mapObject) != 0) {
        VEC_Add(&item->mPos, &a, &item->mPos);
    }
    switch (mobj_handleItemCollision(item, mapObject, &b)) {
        case 1:
            otherPos.x = mapObject->mPos.x;
            otherPos.y = item->mPos.y;
            otherPos.z = mapObject->mPos.z;
            a = otherPos;
            if (b == 1 || (mapObject->mDistanceSquaredAndFlags & 0x80000000) != 0) {
                mapObject->mDistanceSquaredAndFlags &= ~0x80000000;
                reportedMapObject = mapObject;
            } else {
                mapObject->mDistanceSquaredAndFlags &= ~0x80000000;
                reportedMapObject = NULL;
            }
            it_20F77F8(item, 1, &a, &mapObject->field10, reportedMapObject);
            item->field78 &= ~0x4000;
            return;
        case 2:
            if (b == 1 || (mapObject->mDistanceSquaredAndFlags & 0x80000000) != 0) {
                mapObject->mDistanceSquaredAndFlags &= ~0x80000000;
                reportedMapObject = mapObject;
            } else {
                mapObject->mDistanceSquaredAndFlags &= ~0x80000000;
                reportedMapObject = NULL;
            }
            it_20F77F8(item, 2, &mapObject->mPos, &mapObject->field10, reportedMapObject);
            return;
    }
}

void sub_20F9334(void *itemParam, Vec3 *pos, Vec3 *velocity, s32 minFallSpeed, Vec3 *normal) {
    ItemObject *item = itemParam;
    Vec3 lowerPos;
    u32 collisionBits;
    s32 x;
    s32 y;
    s32 z;

    collisionBits = 0;
    z = pos->z;
    y = pos->y - item->fieldDC;
    x = pos->x;
    lowerPos.x = x;
    lowerPos.y = y;
    lowerPos.z = z;

    col_collide(&lowerPos, pos, 0, item->fieldDC >> 1, 0x24, item->mCollisionSlotIndex, NULL, NULL, NULL,
                  &collisionBits, NULL, NULL, NULL, NULL);
    if ((collisionBits & 0x1e34ef) != 0 || (item->mCollisionBits & 0x80000) != 0) {
        if ((item->mFlags & 0x4000000) != 0) {
            return;
        }
        item->mFlags |= 8;
        item->mNormal = *normal;
        return;
    }
    velocity->z = 0;
    velocity->x = velocity->z;
    if (velocity->y > 0) {
        velocity->y = 0;
        return;
    }
    if (velocity->y > -minFallSpeed) {
        velocity->y = -minFallSpeed;
    }
}
