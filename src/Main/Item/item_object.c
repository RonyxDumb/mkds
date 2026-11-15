#include "Main/Item/code_020f6388.h"
#include "Main/Item/item_object.h"
#include "Main/MapObjects/rock.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Item/code_020f9334.h"
#include "Main/Course/course_color_blend.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/MapObjects/group_follower.h"
#include "Main/Item/item_f_box.h"
#include "Main/Sound/sound_start.h"
#include "Main/MapObjects/data_02159000.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_kinoko.h"
#include "Main/Item/code_020f6be8.h"
#include "Main/Item/code_020f73fc.h"
#include "Main/Item/item_slot_tables.h"
#include "code_02147cd8.h"
#include "Main/Sound/sound_sources.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/item_object_sound_source_9038.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/choropu_state.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_owner_bit_and_normal.h"

const Vec3 gItemVec3UnitY = {0, 0x1000, 0};
SoundStartParams gSoundStartParamsDefault = {0, NULL, 1, 0};

void FreeItemObjectCollisionSlot(ItemObject *itemObject) {
    if (itemObject->mCollisionSlotIndex == ~0u) {
    }
    if (itemObject->mCollisionSlotIndex == ~0u) {
        return;
    }
    itemObject->mCollisionSlotIndex = FreeCollisionSlot(itemObject->mCollisionSlotIndex);
}

BOOL IsItemObjectOldAndResting(ItemObject *item) {
    if (item->mAgeFrames > ITEM_OBJECT_OLD_FRAMES && (item->mFlags & ITEM_OBJECT_FLAG_RESTING) != 0 &&
        item->mAdvance == AdvanceRestingItemObject) {
        return TRUE;
    }
    return FALSE;
}

void StartItemObjectReleaseIfOldResting(ItemObject *item) {
    if (item->mAgeFrames <= ITEM_OBJECT_OLD_FRAMES) {
        return;
    }
    if ((item->mFlags & ITEM_OBJECT_FLAG_RESTING) == 0) {
        return;
    }
    if (item->mAdvance != AdvanceRestingItemObject) {
        return;
    }
    StartItemObjectReleaseTimerSynced(item, 1);
}

void StartItemObjectReleaseOnTimeout(ItemObject *item) {
    if ((item->mFlags & ITEM_OBJECT_FLAG_RESTING) != 0) {
        StartItemObjectReleaseTimerSynced(item, 1);
        return;
    }
    item->mVelocity.x = MUL_FIXED12_NO_ROUND(item->mVelocity.x, 0x99a);
    item->mVelocity.y = MUL_FIXED12_NO_ROUND(item->mVelocity.y, 0x99a);
    item->mVelocity.z = MUL_FIXED12_NO_ROUND(item->mVelocity.z, 0x99a);
    FadeOutUsedUpItemObject(item, 1);
}

void ResetItemObject(ItemObject *item, s32 kind) {
    void (*reset)(void *);

    reset = gItemKinds[kind].mReset;
    item->mKind = kind;
    item->mFlags = 0;
    item->mPendingUpdateCount = 0;
    item->mScale.x = 0;
    item->mScale.y = 0;
    item->mScale.z = 0;
    item->mScaleTargetOrSpeed = 0;
    item->mCourseRadius = ITEM_OBJECT_INITIAL_RADIUS;
    item->mRadius = ITEM_OBJECT_INITIAL_RADIUS;
    item->mAlpha = MAP_OBJECT_ALPHA_MAX;
    item->mCollisionBits = 0;
    item->mCourseReleaseTimer = 0;
    item->mFramesSinceCourseHit = ITEM_OBJECT_RECENT_HIT_FRAMES;
    item->mBounce = NULL;
    item->mPosPointer = &item->mPos;
    item->mCollisionSlotIndex = -1;
    item->mCollisionHitLink->mObject = NULL;
    if (gRaceSetup->mMode == MODE_WIFI) {
        item->mFlags |= ITEM_OBJECT_FLAG_WIFI_RACE;
    }
    item->mOwnerKartIndexAndFlags |= gItemObjectOwnerExcludedBit;
    InitCourseColorBlend(&item->mColorBlend, 1);
    item->mKartLightColor = NULL;
    if (reset != NULL) {
        reset(item);
    }
    item->mKartSoundMask = 0;
}

void ResetItemObjectAtPos(ItemObject *item, s32 kind, u16 ownerAndFlags, Vec3 *pos) {
    item->mPos = *pos;
    item->mOwnerKartIndexAndFlags = ownerAndFlags;
    ResetItemObject(item, kind);
    if ((item->mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) == 0) {
        return;
    }
    item->mId = ComputeItemObjectId(item);
}

void ReleaseItemObject(ItemObject *item) {
    enum { KIND_FIRST } kind;

    if (item->mCollisionSlotIndex != -1) {
        item->mCollisionSlotIndex = FreeCollisionSlot(item->mCollisionSlotIndex);
    }
    if ((item->mFlags & ITEM_OBJECT_FLAG_HAS_SOUND_SOURCE) != 0) {
        ReleaseSoundSourceWrapper(&item->mSoundSource);
        item->mSoundSource.mTrackParamsFunction = NULL;
        item->mFlags &= ~ITEM_OBJECT_FLAG_HAS_SOUND_SOURCE;
    }
    item->mFlags |= ITEM_OBJECT_FLAG_RELEASED;
    kind = item->mKind;
    if (gItemKinds[kind].mRelease != NULL) {
        gItemKinds[kind].mRelease(item);
    }
}

void SetItemObjectPlacement(ItemObject *itemParam, Vec3 *prevPos, const Vec3 *normal, CourseColorBlend *colorBlend,
                            s32 flag) {
    ItemObject *item = itemParam;
    item->mPrevPos = *prevPos;
    if (colorBlend != NULL) {
        item->mColorBlend = *colorBlend;
    } else {
        InitCourseColorBlend(&item->mColorBlend, 1);
    }
    item->mNormal = *normal;
    item->mFramesSinceReset = flag != 0 ? 0 : ITEM_OBJECT_RECENT_HIT_FRAMES;
}

s32 DoesItemObjectHurtKart(ItemObject *item) {
    return gItemKinds[item->mKind].mHurtsKart;
}

BOOL IsItemObjectOverlappingKart(ItemObject *item, Kart *kart) {
    Vec3 offset;
    s32 hitRadius;

    if (item->mCollisionSlotIndex == -1 ||
        kart->mIndex == (u16) ((item->mOwnerKartIndexAndFlags & ITEM_OWNER_EXCLUDED) != 0
                                   ? (u16) (item->mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK)
                                   : 8)) {
        return FALSE;
    }
    hitRadius = kart->mRadius + item->mRadius;
    offset.x = item->mPos.x - kart->mPointAlongUp.x;
    offset.y = item->mPos.y - kart->mPointAlongUp.y;
    offset.z = item->mPos.z - kart->mPointAlongUp.z;
    return LENGTH_SQUARED(offset) < (s64) hitRadius * hitRadius;
}

BOOL IsItemObjectOverlappingSphere(ItemObject *item, Vec3 *center, s32 radius) {
    Vec3 offset;
    s32 sumRadius;

    sumRadius = radius + item->mRadius;
    offset.x = item->mPos.x - center->x;
    offset.y = item->mPos.y - center->y;
    offset.z = item->mPos.z - center->z;
    return LENGTH_SQUARED(offset) < (s64) sumRadius * sumRadius;
}

void CollideItemObjectWithItemObject(ItemObject *item, ItemObject *other) {
    Vec3 itemVelocity;
    s32 hitType;
    s32 otherHitType;

    if (other->mCollisionSlotIndex == -1) {
        return;
    }
    if ((other->mFlags & ITEM_OBJECT_FLAG_IN_USE) != 0) {
        return;
    }
    if ((other->mFlags & ITEM_OBJECT_FLAG_RESTING) == 0) {
        if (item->mCreationNumber > other->mCreationNumber) {
            return;
        }
    }
    if ((item->mFlags & ITEM_OBJECT_FLAG_FROM_DATA) != 0 && (other->mFlags & ITEM_OBJECT_FLAG_FROM_DATA) != 0) {
        if (GetItemObjectHitType(item, other) != ITEM_HIT_TYPE_BOUNCE &&
            GetItemObjectHitType(other, item) != ITEM_HIT_TYPE_BOUNCE) {
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
    ApplyItemObjectHitType(item, hitType, &other->mPos, &other->mVelocity, NULL);
    ApplyItemObjectHitType(other, otherHitType, &item->mPos, &itemVelocity, NULL);
    if (item->mKind == ITEM_OBJECT_KIND_KOURA_R) {
        StartTargetKartSoundOnOwnItemHit(item, hitType, other);
    }
    if (other->mKind != ITEM_OBJECT_KIND_KOURA_R) {
        return;
    }
    StartTargetKartSoundOnOwnItemHit(other, otherHitType, item);
}

void ApplyMapObjectHitToItemObject(ItemObject *itemParam, MapObject *mapObjectParam) {
    Vec3 pushOut;
    Vec3 otherPos;
    s32 firstResponse;
    MapObject *reportedMapObject;
    ItemObject *item = itemParam;
    MapObject *mapObject = mapObjectParam;

    if (IsSphereHittingMapObject(&item->mPos, item->mRadius, mapObject, &pushOut) == FALSE) {
        return;
    }
    if ((mapObject->mFlags & MAP_OBJECT_FLAG_NO_PUSH_OUT) == 0 && (item->mFlags & ITEM_OBJECT_FLAG_FADING_OUT) == 0 &&
        DoesItemObjectRespondToMapObject(item->mKind, mapObject) != 0) {
        VEC_Add(&item->mPos, &pushOut, &item->mPos);
    }
    switch (CollideItemObjectWithMapObject(item, mapObject, &firstResponse)) {
        case ITEM_HIT_TYPE_BOUNCE:
            otherPos.x = mapObject->mPos.x;
            otherPos.y = item->mPos.y;
            otherPos.z = mapObject->mPos.z;
            pushOut = otherPos;
            if (firstResponse == 1 ||
                (mapObject->mDistanceSquaredAndFlags & MAP_OBJECT_DISTANCE_FLAG_REPORT_HIT) != 0) {
                mapObject->mDistanceSquaredAndFlags &= ~MAP_OBJECT_DISTANCE_FLAG_REPORT_HIT;
                reportedMapObject = mapObject;
            } else {
                mapObject->mDistanceSquaredAndFlags &= ~MAP_OBJECT_DISTANCE_FLAG_REPORT_HIT;
                reportedMapObject = NULL;
            }
            ApplyItemObjectHitType(item, ITEM_HIT_TYPE_BOUNCE, &pushOut, &mapObject->mPosStep, reportedMapObject);
            item->mOwnerKartIndexAndFlags &= ~ITEM_OWNER_EXCLUDED;
            return;
        case ITEM_HIT_TYPE_FADE_OUT:
            if (firstResponse == 1 ||
                (mapObject->mDistanceSquaredAndFlags & MAP_OBJECT_DISTANCE_FLAG_REPORT_HIT) != 0) {
                mapObject->mDistanceSquaredAndFlags &= ~MAP_OBJECT_DISTANCE_FLAG_REPORT_HIT;
                reportedMapObject = mapObject;
            } else {
                mapObject->mDistanceSquaredAndFlags &= ~MAP_OBJECT_DISTANCE_FLAG_REPORT_HIT;
                reportedMapObject = NULL;
            }
            ApplyItemObjectHitType(item, ITEM_HIT_TYPE_FADE_OUT, &mapObject->mPos, &mapObject->mPosStep,
                                   reportedMapObject);
            return;
    }
}

void LandItemObjectIfOnGround(ItemObject *item, Vec3 *pos, Vec3 *velocity, s32 minFallSpeed, Vec3 *normal) {
    Vec3 lowerPos;
    u32 collisionBits;
    s32 lowerX;
    s32 lowerY;
    s32 lowerZ;

    collisionBits = 0;
    lowerZ = pos->z;
    lowerY = pos->y - item->mCourseRadius;
    lowerX = pos->x;
    lowerPos.x = lowerX;
    lowerPos.y = lowerY;
    lowerPos.z = lowerZ;

    CollideSphereWithCourse(&lowerPos, pos, 0, item->mCourseRadius >> 1, 0x24, item->mCollisionSlotIndex, NULL, NULL,
                            NULL, &collisionBits, NULL, NULL, NULL, NULL);
    if ((collisionBits & COURSE_HIT_GROUND) != 0 || (item->mCollisionBits & COURSE_HIT_BOOST_SURFACE) != 0) {
        if ((item->mFlags & ITEM_OBJECT_FLAG_HIT_THIS_STEP) != 0) {
            return;
        }
        item->mFlags |= ITEM_OBJECT_FLAG_LANDED;
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

void ClearItemObjectCollisionBits(ItemObject *item, u32 clearBits) {
    item->mCollisionBits = (((item->mCollisionBits)) & ((~(clearBits))));
}

void BounceItemVelocityOffSurface(Vec3 *velocity, Vec3 *normal) {
    BounceVelocityOffSurface(velocity, normal, 0xb33, 0x733, 0xacd, velocity);
}

BOOL TryFadeOutDeflectedItemObject(ItemObject *item, Vec3 *normal) {
    if ((item->mFlags & ITEM_OBJECT_FLAG_DEFLECTED) != 0 && Vec3DotUnrounded(normal, &item->mCoursePointOrParams) < 0 &&
        (item->mFlags & ITEM_OBJECT_FLAG_LANDED) == 0) {
        FadeOutUsedUpItemObject(item, 1);
        return TRUE;
    }
    return FALSE;
}

void StartItemObjectSoundIfNear(ItemObject *item, s32 soundId) {
    SoundStartParams request;

    if (soundId == 1) {
        return;
    }
    if ((s32) (item->mDistanceSquaredAndFlags & ~0xc000001f) >= gSoundFalloffs[1].mFarDistanceSquared) {
        return;
    }
    if (soundId == 1) {
        return;
    }
    request = gSoundStartParamsDefault;
    request.mPositionSource = &item->mPos;
    request.mSoundId = soundId;
    request.mDistanceSquared = item->mDistanceSquaredAndFlags & ~0xc000001f;
    StartSoundFromParams(&request);
}

BOOL IsItemObjectScaleAtSetupSize(ItemObject *itemParam) {
    ItemObject *item = itemParam;

    return item->mScale.z >= 0xccd;
}

BOOL IsItemObjectFartherFromCameraThan(ItemObject *item, s32 distance) {
    return (s32) (item->mDistanceSquaredAndFlags & ~0xc000001f) > distance * distance;
}

BOOL IsItemObjectTooFarForEffects(ItemObject *itemObject) {
    BOOL isVisible;
    BOOL isVisibleAndNear;

    isVisible = FALSE;
    if ((itemObject->mFlags & ITEM_OBJECT_FLAG_OUT_OF_VIEW) == 0) {
        isVisible = TRUE;
    }
    if (isVisible != FALSE && (s32) (itemObject->mDistanceSquaredAndFlags & ~0xc000001f) <= 0x3d0900) {
        isVisibleAndNear = TRUE;
    } else {
        isVisibleAndNear = FALSE;
    }
    if (isVisibleAndNear == FALSE && (s32) (itemObject->mDistanceSquaredAndFlags & ~0xc000001f) > 0x3d090) {
        return TRUE;
    }
    return FALSE;
}

void StartItemObjectSoundSource(ItemObject *item) {
    enum { KIND_FIRST } kind = item->mKind;

    ItemObjectInitSoundSource(&item->mSoundSource, gItemKinds[kind].mFalloffIndex, &item->mPos);
    SetSoundSourceEnabled(&item->mSoundSource, 1);
    item->mFlags |= ITEM_OBJECT_FLAG_HAS_SOUND_SOURCE;
}

void StopItemObjectSoundSource(ItemObject *itemParam) {
    ItemObject *item = itemParam;
    if ((item->mFlags & ITEM_OBJECT_FLAG_HAS_SOUND_SOURCE) == 0) {
        return;
    }
    ReleaseSoundSourceWrapper(&item->mSoundSource);
    item->mSoundSource.mTrackParamsFunction = NULL;
    item->mFlags &= ~ITEM_OBJECT_FLAG_HAS_SOUND_SOURCE;
}

void UpdateItemObjectSoundSource(ItemObject *itemParam) {
    ItemObject *item = itemParam;

    item->mSoundSource.mDistanceSquared = item->mDistanceSquaredAndFlags & ~0xc000001f;
    SetItemObjectSoundByViewRange(item, &item->mPos, item->mDistanceSquaredAndFlags);
}

void ResetItemObjectFromData(ItemObject *itemParam, s32 kind, void *buffer, s32 useGenericCopy) {
    ItemObject *item = itemParam;
    void *(*copyData)(void *, void *, s32);

    copyData = useGenericCopy != 0 ? CopyItemObjectDataAndAdd : gItemKinds[kind].mCopyData;
    ResetItemObject(item, kind);
    copyData(buffer, item, 0);
    item->mFlags &= ~ITEM_OBJECT_FLAG_HAS_SOUND_SOURCE;
    item->mFlags |= ITEM_OBJECT_FLAG_FROM_DATA;
}

void SetupItemObjectFromData(ItemObject *item) {
    ItemKind *kindInfo;
    BOOL hasCollisionSlot;
    s32 kindRadius;
    enum { KIND_FIRST } kind;
    void (*advance)(struct ItemObject *);

    item->mScale.z = 0xccd;
    kind = item->mKind;
    item->mFlags |= ITEM_OBJECT_FLAG_SCALE_CHANGED;
    item->mScale.y = item->mScale.z;
    item->mScale.x = item->mScale.y;
    kindInfo = &gItemKinds[kind];
    kindRadius = kindInfo->mRadius;
    item->mCourseRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, kindInfo->mCourseRadius);
    item->mRadius = MUL_FIXED12_NO_ROUND(item->mScale.y, kindRadius);
    SetCollisionSlotRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
    InitCourseColorBlend(&item->mColorBlend, 1);
    item->mKartLightColor = NULL;
    item->mNormal = gItemVec3UnitY;
    item->mCollisionBits = 0;
    item->mScaleTargetOrSpeed = 0;
    item->mCollisionHitLink->mObject = NULL;
    item->mCoursePointOrParams.x = 0;
    item->mCoursePointOrParams.y = 0;
    item->mCoursePointOrParams.z = 0;
    item->mFramesSinceCourseHit = ITEM_OBJECT_RECENT_HIT_FRAMES;
    item->mFramesSinceReset = 0;
    item->mCourseReleaseTimer = 0;
    item->mHitLinkTimer = 0;
    item->mAgeFrames = 1;
    if ((item->mFlags & ITEM_OBJECT_FLAG_HAS_SOUND_SOURCE) == 0) {
        kind = item->mKind;
        ItemObjectInitSoundSource(&item->mSoundSource, gItemKinds[kind].mFalloffIndex, &item->mPos);
        SetSoundSourceEnabled(&item->mSoundSource, 1);
        item->mFlags |= ITEM_OBJECT_FLAG_HAS_SOUND_SOURCE;
    }
    kind = item->mKind;
    advance = gItemKinds[kind].mAdvance;
    if ((item->mFlags & ITEM_OBJECT_FLAGS_ENDING) == 0) {
        item->mAdvance = advance;
    }
    if ((item->mOwnerKartIndexAndFlags & ITEM_OWNER_PENDING_MASK) != 0) {
        return;
    }
    kind = item->mKind;
    if (gItemKinds[kind].mSkipsStartCollisionSlot != 0) {
        return;
    }
    hasCollisionSlot = item->mCollisionSlotIndex != -1;
    if (hasCollisionSlot != FALSE) {
        return;
    }
    if (hasCollisionSlot != FALSE) {
        return;
    }
    item->mCollisionSlotIndex =
        CreateCollisionSlot(&item->mPos, item->mRadius + 0xa000, COLLISION_SLOT_FLAG_ITEM_OBJECT, item);
}
