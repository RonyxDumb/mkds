#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50ec.h"

#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210c000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f9334.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02109038.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_020e337c.h"

BOOL TryFadeOutDeflectedItemObject(ItemObject *item, Vec3 *normal) {
    if ((item->mFlags & 0x2000000) != 0 && Vec3DotUnrounded(normal, &item->mUnk_108) < 0 && (item->mFlags & 8) == 0) {
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
    if ((s32) (item->mDistanceSquaredAndFlags & ~0xc000001f) >= gSoundFalloffs[1].mUnk_20) {
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
    if ((itemObject->mFlags & 0x10000) == 0) {
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
    enum { K0 } kind = item->mKind;

    func_02109038(&item->mSoundSource, gItemKinds[kind].mFalloffIndex, &item->mPos);
    SetSoundSourceEnabled(&item->mSoundSource, 1);
    item->mFlags |= 0x400000;
}

void StopItemObjectSoundSource(ItemObject *itemParam) {
    ItemObject *item = itemParam;
    if ((item->mFlags & 0x400000) == 0) {
        return;
    }
    ReleaseSoundSourceWrapper(&item->mSoundSource);
    item->mSoundSource.mTrackParamsFunction = NULL;
    item->mFlags &= ~0x400000;
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
    item->mFlags &= ~0x400000;
    item->mFlags |= 0x10000000;
}

void SetupItemObjectFromData(ItemObject *item) {
    ItemKind *kindInfo;
    BOOL hasCollisionSlot;
    s32 kindRadius;
    enum { K0 } kind;
    void (*advance)(struct ItemObject *);

    item->mScale.z = 0xccd;
    kind = item->mKind;
    item->mFlags |= 0x40;
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
    item->mUnk_100 = 0;
    item->mCollisionHitLink->mObject = NULL;
    item->mUnk_108.x = 0;
    item->mUnk_108.y = 0;
    item->mUnk_108.z = 0;
    item->mFramesSinceCourseHit = 5;
    item->mUnk_116 = 0;
    item->mCourseReleaseTimer = 0;
    item->mUnk_11a = 0;
    item->mAgeFrames = 1;
    if ((item->mFlags & 0x400000) == 0) {
        kind = item->mKind;
        func_02109038(&item->mSoundSource, gItemKinds[kind].mFalloffIndex, &item->mPos);
        SetSoundSourceEnabled(&item->mSoundSource, 1);
        item->mFlags |= 0x400000;
    }
    kind = item->mKind;
    advance = gItemKinds[kind].mAdvance;
    if ((item->mFlags & 0x180000) == 0) {
        item->mAdvance = advance;
    }
    if ((item->mOwnerKartIndexAndFlags & 0xf00) != 0) {
        return;
    }
    kind = item->mKind;
    if (gItemKinds[kind].mUnk_54 != 0) {
        return;
    }
    hasCollisionSlot = item->mCollisionSlotIndex != -1;
    if (hasCollisionSlot != FALSE) {
        return;
    }
    if (hasCollisionSlot != FALSE) {
        return;
    }
    item->mCollisionSlotIndex = CreateCollisionSlot(&item->mPos, item->mRadius + 0xa000, 0x4000, item);
}
