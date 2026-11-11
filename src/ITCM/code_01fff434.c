#include "ITCM/code_01fff434.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020435c4.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"

void UpdateKartItems(KartItems *kartItems) {
    HeldItem *heldItem = &kartItems->mHeldItem;
    ItemInUse *itemInUse = &kartItems->mItemInUse;
    Kart *kart;
    ItemPointLinkRef *itemLink;
    Vec3 *drawMatrixPos;
    s64 distanceSquared;
    s32 slotResult;
    u16 previousFlags;
    u16 itemKeyBits;
    u32 keyWasDown;
    previousFlags = kartItems->mFlags;
    keyWasDown = previousFlags & 0x1000;
    itemKeyBits = gInputSlots[kartItems->mEntryIndex].mBits & ITEM_BITS;
    kart = kartItems->mKart;
    kartItems->mFlags &= ~0xf200;
    if (itemKeyBits) {
        if (!keyWasDown) {
            kartItems->mFlags |= 0x3000;
        } else {
            kartItems->mFlags |= gKartItemsKeyDownBit;
        }
    } else if (keyWasDown) {
        kartItems->mFlags |= gKartItemsKeyReleasedBit;
    }
    if (IsKartRemoved(kart) != FALSE) {
        kartItems->mKinokoBoostStarted = FALSE;
        kartItems->mTargetedByKouraR = FALSE;
        return;
    }
    kartItems->mKinokoBoostStarted = FALSE;
    if (kartItems->mUnk_20c != FALSE) {
        if (IsKartNotNormalOrFlagged(kart) == FALSE && !(kart->mUnk_48 & 0x10000) &&
            (kart->mUnk_44 & KART_44_ON_GROUND)) {
            kartItems->mUnk_20c = FALSE;
        }
    } else if (IsKartNotNormalOrFlagged(kart) != FALSE || (kart->mUnk_48 & 0x10000)) {
        kartItems->mUnk_20c = TRUE;
    } else {
        AddKartItemUseFlags(kartItems);
        kartItems->mFlags |= data_usa_021595d4;
    }
    if (itemInUse->mObjectKind != 0xf) {
        AdvanceItemInUse(itemInUse);
    }
    if (heldItem->mItemInfoIndex != 0x13) {
        if ((kartItems->mFlags & 0x242) == 0x242 && heldItem->mItemInfoIndex != 0x13 &&
            heldItem->mObjectStartFramesLeft == 0 && (kartItems->mFlags & 0x200) && kart->mState == KART_STATE_NORMAL) {
            StartItemInUse(itemInUse, heldItem);
        }
        UpdateHeldItem(heldItem);
    }
    if (kartItems->mSlotState != 0 && UpdateItemSlot(kartItems, kartItems) != FALSE) {
        slotResult = kartItems->mSlotResult;
        FinishItemSlot(kartItems);
        if (gItemInfos[slotResult].mEnabled != FALSE) {
            SetHeldItem(heldItem, slotResult);
        }
    }
    if (kartItems->mKartIndex == GetRaceUpdateFramesMod8() && (itemLink = &kartItems->mItemLink)->mLink != NULL) {
        kart = kartItems->mKart;
        drawMatrixPos = &kart->mDrawMatrixPos;
        PickNearestNearbyItemPointLink(itemLink, itemLink, drawMatrixPos);
        distanceSquared = (s64) (itemLink->mLink->mPointPos->x - drawMatrixPos->x) *
                          (itemLink->mLink->mPointPos->x - drawMatrixPos->x);
        distanceSquared += (s64) (itemLink->mLink->mPointPos->z - drawMatrixPos->z) *
                           (itemLink->mLink->mPointPos->z - drawMatrixPos->z);
        if (distanceSquared >= ((s64) 0x15f9 << 32)) {
            FollowItemPointLinksToPos(itemLink, itemLink, drawMatrixPos);
        }
    }
    kartItems->mTargetedByKouraR = FALSE;
}

void AddKartItemUseFlags(KartItems *kartItems) {
    BOOL heldItemNotInUseKindOneOrTwo;
    s32 heldItemIndex;
    kartItems->mFlags &= ~0xff;
    if (gRaceSetup->mMode == MODE_WIFI) {
        heldItemIndex = kartItems->mHeldItem.mItemInfoIndex;
        if (heldItemIndex == 0x13 || kartItems->mItemInUse.mObjectKind != 0xf) {
            heldItemNotInUseKindOneOrTwo = FALSE;
        } else {
            heldItemNotInUseKindOneOrTwo = (u32) (gItemInfos[heldItemIndex].mUseKind - 1) <= 1;
        }
        if (heldItemNotInUseKindOneOrTwo != FALSE) {
            if ((kartItems->mFlags & 0x4000) && TryAddKartItemFlags(kartItems) != FALSE) {
                kartItems->mFlags |= gKartItemsStartUseBit;
            }
            goto after;
        }
    }
    if ((kartItems->mFlags & 0x2000) && TryAddKartItemFlags(kartItems) != FALSE) {
        kartItems->mFlags |= gKartItemsStartUseBit;
    }
after:
    if (!(kartItems->mFlags & KART_ITEMS_IN_USE_ADVANCED)) {
        return;
    }
    kartItems->mFlags &= ~KART_ITEMS_IN_USE_ADVANCED;
    if (gRaceSetup->mMode != MODE_WIFI && (kartItems->mFlags & 0x1000)) {
        return;
    }
    if (TryAddKartItemFlags(kartItems) == FALSE) {
        return;
    }
    kartItems->mFlags |= gKartItemsEndUseBit;
}

void ComputeVec3FromDotProducts(s32 normalsDot, s32 secondDot, s32 firstDot, Vec3 *result, const Vec3 *firstVector,
                                const Vec3 *secondVector, s64 *lengthSquared) {
    s32 firstWeight;
    s32 secondWeight;
    firstWeight = FX_Div(MUL_FIXED12_NO_ROUND(normalsDot, secondDot) - firstDot,
                         MUL_FIXED12_NO_ROUND(normalsDot, normalsDot) - 0x1000);
    secondWeight = secondDot - MUL_FIXED12_NO_ROUND(firstWeight, normalsDot);
    result->x = MUL_FIXED12_NO_ROUND(firstWeight, firstVector->x) + MUL_FIXED12_NO_ROUND(secondWeight, secondVector->x);
    result->y = MUL_FIXED12_NO_ROUND(firstWeight, firstVector->y) + MUL_FIXED12_NO_ROUND(secondWeight, secondVector->y);
    result->z = MUL_FIXED12_NO_ROUND(firstWeight, firstVector->z) + MUL_FIXED12_NO_ROUND(secondWeight, secondVector->z);
    *lengthSquared = LENGTH_SQUARED(*result);
}
