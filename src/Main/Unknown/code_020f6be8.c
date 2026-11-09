#include "Main/Unknown/code_020f6be8.h"

#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f6be4.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9c40.h"
#include "code_02147cd8.h"

s32 StartItemObjectFadeOut(ItemObject *item, s32 variant, s32 skipPending) {
    Vec3 *velocity = &item->mVelocity;
    ItemKind *kindInfo;
    s32 r;
    enum { K0 } kind;

    if (item->mFlags & 0x80000) {
        return 2;
    }
    if (skipPending == 0 && (item->mFlags & 0x8000000) && !(item->mFlags & 0x10000000) &&
        !(item->mFlags & 0x20000000)) {
        if (item->mOwnerKartIndexAndFlags & 0xf00) {
            return 2;
        }
        if (variant == 0) {
            item->mOwnerKartIndexAndFlags |= data_02159b6c;
        } else {
            item->mOwnerKartIndexAndFlags |= data_02159b68;
            FreeItemObjectCollisionSlot(item);
        }
        item->mAdvance = NULL;
        return 1;
    }
    if (variant == 0) {
        kind = item->mKind;
        kindInfo = &gItemKinds[kind];
        if (kindInfo->mUnk_34 != NULL) {
            r = kindInfo->mUnk_34(item);
            if (r == 0) {
                return 2;
            }
            if (r == 1) {
                return 0;
            }
        }
    }
    if (variant != 0) {
        item->mUnk_108.y = 0x266;
    } else {
        item->mUnk_108.y = 0x333;
        if (!(item->mFlags & 0x8000)) {
            item->mUnk_108.y += MUL_FIXED12_NO_ROUND(VEC_Mag(velocity), 0x15c);
            if (item->mUnk_108.y > 0x5c3) {
                item->mUnk_108.y = 0x5c3;
            }
        }
    }
    kind = item->mKind;
    kindInfo = &gItemKinds[kind];
    if (kindInfo->mKeepsAdvanceAtEnd == 0) {
        item->mAdvance = AdvanceItemObjectFadeOut;
    }
    item->mBounce = (void (*)(ItemObject *, Vec3 *, Vec3 *)) ItemObjectBounceReturnArgument;
    if (item->mNormal.y != 0) {
        Vec3 *normal = &item->mNormal;

        r = Vec3DotUnrounded(velocity, normal);
        if (r < 0x3000) {
            VEC_MultAdd(0x3000 - r, normal, velocity, velocity);
        }
    }
    item->mFlags |= 0x80001;
    FreeItemObjectCollisionSlot(item);
    r = Vec3DotUnrounded(velocity, GetViewTransposeMatrixAxis0());
    if (r > 1) {
        item->mUnk_108.x = 1;
    } else {
        item->mUnk_108.x = 0;
    }
    return 0;
}

void func_020f7104(ItemObject *item, s32 sendEvent) {
    s32 result;

    if (!(item->mFlags & 0x8000000)) {
        StartItemObjectFadeOut(item, 0, 0);
        return;
    }
    result = StartItemObjectFadeOut(item, 0, 0);
    if (result != 0) {
        return;
    }
    if (sendEvent == 0) {
        return;
    }
    AddItemDataItemIdAndParts(item->mKind, 0, 8, item->mId);
}

void func_020f70f0(ItemObject *item) {
    StartItemObjectFadeOut(item, 0, 1);
}

void func_020f7070(ItemObject *item, s32 sendEvent) {
    s32 result;

    if (!(item->mFlags & 0x8000000)) {
        StartItemObjectFadeOut(item, 1, 0);
        return;
    }
    result = StartItemObjectFadeOut(item, 1, 0);
    if (result != 0) {
        return;
    }
    if (sendEvent == 0) {
        return;
    }
    AddItemDataItemIdAndParts(item->mKind, 1, 8, item->mId);
}

void func_020f705c(ItemObject *item) {
    StartItemObjectFadeOut(item, 1, 1);
}

void func_020f6fc4(ItemObject *item, s32 sendEvent) {
    s32 result;
    enum { K0 } kind;

    result = StartItemObjectFadeOut(item, 0, 0);
    if (result <= 1) {
        kind = item->mKind;
        StartItemObjectSoundIfNear(item, gItemKinds[kind].mUnk_94);
    }
    if (result != 0) {
        return;
    }
    if (!(item->mFlags & 0x8000000)) {
        return;
    }
    if (sendEvent == 0) {
        return;
    }
    if (item->mKind == 5) {
        return;
    }
    AddItemDataItemIdAndParts(item->mKind, 2, 8, item->mId);
}

void func_020f6f10(ItemObject *item, s32 sendEvent, s32 highPart) {
    s32 result;
    enum { K0 } kind;

    result = StartItemObjectFadeOut(item, 0, 0);
    if (result <= 1) {
        kind = item->mKind;
        StartItemObjectSoundIfNear(item, gItemKinds[kind].mUnk_98);
    }
    if (result != 0) {
        return;
    }
    if (!(item->mFlags & 0x8000000)) {
        return;
    }
    if (sendEvent == 0) {
        return;
    }
    if (item->mKind == 5) {
        return;
    }
    AddItemDataItemIdAndParts(item->mKind, 3, highPart, item->mId);
}

void AdvanceItemObjectFadeOut(ItemObject *item) {
    Vec3 direction;

    Vec3CrossUnrounded(&item->mNormal, GetViewTransposeMatrixAxis2(), &direction);
    VEC_MultAdd(item->mUnk_108.x != 0 ? item->mUnk_108.y : -item->mUnk_108.y, &direction, &item->mNormal,
                &item->mNormal);
    item->mFlags |= 0x80;
    item->mVelocity.y -= 0x400;
    VEC_Add(&item->mPos, &item->mVelocity, &item->mPos);
    item->mAlpha--;
    if (item->mAlpha > 0) {
        return;
    }
    ReleaseItemPoolObject(&gItemPools[item->mKind], item);
}

void ApplyItemObjectPush(ItemObject *item, Vec3 *otherPos, Vec3 *otherVelocity, Vec3 *normal) {
    Vec3 away;
    Vec3 relativeVelocity;
    Vec3 *push;
    s32 dot;
    s64 lengthSquared;

    VEC_Subtract(otherVelocity, &item->mVelocity, &relativeVelocity);
    VEC_Subtract(&item->mPos, otherPos, &away);
    dot = VEC_DotProduct(normal, &away);
    away.x -= MUL_FIXED12_NO_ROUND(normal->x, dot);
    away.y -= MUL_FIXED12_NO_ROUND(normal->y, dot);
    away.z -= MUL_FIXED12_NO_ROUND(normal->z, dot);
    lengthSquared = LENGTH_SQUARED(away);
    if (lengthSquared >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&away, &away);
    }
    if (item->mFlags & 0x8000) {
        VEC_MultAdd(0x666, &relativeVelocity, &item->mVelocity, &item->mVelocity);
        push = gItemPushVector;
        push->x = MUL_FIXED12_NO_ROUND(away.x, 0xccd);
        push->y = MUL_FIXED12_NO_ROUND(away.y, 0xccd);
        push->z = MUL_FIXED12_NO_ROUND(away.z, 0xccd);
        VEC_Add(&item->mVelocity, gItemPushVector, &item->mVelocity);
    } else {
        item->mVelocity.x = MUL_FIXED12_NO_ROUND(otherVelocity->x, 0x8cd);
        item->mVelocity.y = MUL_FIXED12_NO_ROUND(otherVelocity->y, 0x8cd);
        item->mVelocity.z = MUL_FIXED12_NO_ROUND(otherVelocity->z, 0x8cd);
        push = gItemPushVector;
        push->x = MUL_FIXED12_NO_ROUND(away.x, 0x1800);
        push->y = MUL_FIXED12_NO_ROUND(away.y, 0x1800);
        push->z = MUL_FIXED12_NO_ROUND(away.z, 0x1800);
        VEC_Add(&item->mVelocity, gItemPushVector, &item->mVelocity);
    }
}
