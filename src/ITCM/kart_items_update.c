#include "ITCM/kart_items_update.h"
#include "Main/System/input_slots.h"
#include "Main/Race/race_setup_input.h"
#include "ITCM/kart_motion.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Item/item_in_use.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Item/item_slot_tables.h"
#include "Main/MapObjects/attractor_distance_flag.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "fixed_vector_math.h"

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
    keyWasDown = previousFlags & KART_ITEMS_KEY_DOWN;
    itemKeyBits = gInputSlots[kartItems->mEntryIndex].mBits & ITEM_BITS;
    kart = kartItems->mKart;
    kartItems->mFlags &= ~0xf200;
    if (itemKeyBits) {
        if (!keyWasDown) {
            kartItems->mFlags |= KART_ITEMS_KEY_DOWN | KART_ITEMS_KEY_PRESSED;
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
    if (kartItems->mItemUseFlagsBlocked != FALSE) {
        if (IsKartNotNormalOrFlagged(kart) == FALSE && !(kart->mDriveFlags & KART_DRIVE_KEYED_PLACEMENT) &&
            (kart->mMotionFlags & KART_MOTION_ON_GROUND)) {
            kartItems->mItemUseFlagsBlocked = FALSE;
        }
    } else if (IsKartNotNormalOrFlagged(kart) != FALSE || (kart->mDriveFlags & KART_DRIVE_KEYED_PLACEMENT)) {
        kartItems->mItemUseFlagsBlocked = TRUE;
    } else {
        AddKartItemUseFlags(kartItems);
        kartItems->mFlags |= gKartItemsStartAllowedBit;
    }
    if (itemInUse->mObjectKind != ITEM_OBJECT_KIND_NONE) {
        AdvanceItemInUse(itemInUse);
    }
    if (heldItem->mItemInfoIndex != ITEM_INFO_NONE) {
        if ((kartItems->mFlags & (KART_ITEMS_HELD | KART_ITEMS_START_USE | KART_ITEMS_START_ALLOWED)) ==
                (KART_ITEMS_HELD | KART_ITEMS_START_USE | KART_ITEMS_START_ALLOWED) &&
            heldItem->mItemInfoIndex != ITEM_INFO_NONE && heldItem->mObjectStartFramesLeft == 0 &&
            (kartItems->mFlags & KART_ITEMS_START_ALLOWED) && kart->mState == KART_STATE_NORMAL) {
            StartItemInUse(itemInUse, heldItem);
        }
        UpdateHeldItem(heldItem);
    }
    if (kartItems->mSlotState != KART_ITEMS_SLOT_IDLE && UpdateItemSlot(kartItems, kartItems) != FALSE) {
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
        if (heldItemIndex == ITEM_INFO_NONE || kartItems->mItemInUse.mObjectKind != ITEM_OBJECT_KIND_NONE) {
            heldItemNotInUseKindOneOrTwo = FALSE;
        } else {
            heldItemNotInUseKindOneOrTwo = (u32) (gItemInfos[heldItemIndex].mUseKind - ITEM_USE_KIND_ONE) <=
                                           ITEM_USE_KIND_ONE_WITH_ORIENTATION - ITEM_USE_KIND_ONE;
        }
        if (heldItemNotInUseKindOneOrTwo != FALSE) {
            if ((kartItems->mFlags & KART_ITEMS_KEY_RELEASED) && TryAddKartItemFlags(kartItems) != FALSE) {
                kartItems->mFlags |= gKartItemsStartUseBit;
            }
            goto after;
        }
    }
    if ((kartItems->mFlags & KART_ITEMS_KEY_PRESSED) && TryAddKartItemFlags(kartItems) != FALSE) {
        kartItems->mFlags |= gKartItemsStartUseBit;
    }
after:
    if (!(kartItems->mFlags & KART_ITEMS_IN_USE_ADVANCED)) {
        return;
    }
    kartItems->mFlags &= ~KART_ITEMS_IN_USE_ADVANCED;
    if (gRaceSetup->mMode != MODE_WIFI && (kartItems->mFlags & KART_ITEMS_KEY_DOWN)) {
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
