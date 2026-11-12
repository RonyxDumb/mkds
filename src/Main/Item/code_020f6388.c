#include "Main/Item/code_020f6388.h"
#include "Main/Item/item_kinoko.h"
#include "Main/Sound/sound_start.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Item/code_020f73fc.h"
#include "Main/Item/item_f_box.h"
#include "Main/MapObjects/data_02159000.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/data_027e0000.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_in_use.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/code_020f6be8.h"
#include "Main/Item/item_slot_tables.h"
#include "Main/Item/item_object.h"
#include "code_02147cd8.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/code_020e6a74.h"
#include "Main/Course/course_color_blend.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/code_020f9334.h"
#include "Main/Item/held_item.h"
#include "Main/Item/pooled_item_box.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Sound/kart_sound_callbacks.h"
#include "Main/Sound/kart_surface_sound.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Item/item_object_throw.h"
#include "Main/Item/item_koura_r_kart_items.h"
#include "Main/Item/item_object_bouncing.h"
#include "Main/Sound/sound_distance_change_reset.h"
#include "Main/System/state_machine_init.h"
#include "Main/Item/item_link_following.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/rock.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Race/race.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/data_0210b000.h"
#include "code_0212d214.h"
#include "Main/MapObjects/code_020e01f0.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/data_0217d000.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "code_0212df7c.h"
#include "Main/Race/race_clock.h"
#include "Main/Kart/karts.h"
#include "Main/Item/item_teresa_offset.h"

const u8 gItemHitTypes[196] = {2, 2, 2, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 2, 2, 2, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 2, 2, 1, 1, 1, 2, 0, 1, 0, 2, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 2, 2, 2, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 1, 2, 0, 1, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2};
const u16 gItemObjectReleasePendingBit = 0x100;
const u16 gItemObjectFadeOutPendingBit = 0x800;
const u16 gItemObjectReleaseTimerPendingBit = 0x200;
const u16 data_02159b64 = 0x8000;
const u16 gItemObjectNoCallbackFadeOutPendingBit = 0x400;

u8 GetItemObjectHitType(ItemObject *itemParam, ItemObject *otherParam) {
    ItemObject *item = itemParam;
    ItemObject *other = otherParam;

    return (gItemHitTypes + item->mKind * 0xe)[other->mKind];
}

void DeflectItemObjectRandomly(ItemObject *item, Vec3 *otherPos, Vec3 *normal) {
    RandomState64 *random;
    s64 distanceSquared;
    s32 angle;

    if (item->mFlags & 0x2000000) {
        if (LENGTH_SQUARED(*normal) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(normal, normal);
        }
        if (Vec3DotUnrounded(normal, &item->mCoursePointOrParams) > 0x800) {
            item->mVelocity.z = MUL_FIXED12_NO_ROUND(normal->z, 0x14cd);
            item->mVelocity.x = MUL_FIXED12_NO_ROUND(normal->x, 0x14cd);
        }
    }
    distanceSquared = (s64) (item->mPos.x - otherPos->x) * (item->mPos.x - otherPos->x) +
                      (s64) (item->mPos.y - otherPos->y) * (item->mPos.y - otherPos->y) +
                      (s64) (item->mPos.z - otherPos->z) * (item->mPos.z - otherPos->z);
    if (distanceSquared >= (s64) item->mRadius * item->mRadius) {
        return;
    }
    item->mFlags |= 0x4000000;
    if (item->mFlags & 0x2000000) {
        return;
    }
    if (Vec3DotUnrounded(&item->mVelocity, normal) >= 0) {
        return;
    }
    random = &gRaceProgress->mRandom;
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    angle = (u16) ((((u64) (u32) (random->mValue >> 32) * 0x10000) >> 32));
    item->mCoursePointOrParams.z = COS_OF_ANGLE(angle);
    item->mCoursePointOrParams.x = SIN_OF_ANGLE(angle);
    item->mVelocity.z = MUL_FIXED12_NO_ROUND(item->mCoursePointOrParams.z, 0x14cd);
    item->mVelocity.x = MUL_FIXED12_NO_ROUND(item->mCoursePointOrParams.x, 0x14cd);
    item->mFlags |= 0x2000000;
}

void StartItemObjectSoundOnSource(ItemObject *item, s32 soundId) {
    SoundSource *sourceCopy = &item->mSoundSource;
    s32 soundIdCopy = soundId;
    u32 volume;
    u32 zero;
    s32 soundIdCompared;
    u32 skipId;
    soundIdCompared = soundIdCopy;
    skipId = 1u;
    if (soundIdCompared == skipId) {
    }
    if (soundIdCompared == skipId) {
    }
    if (soundIdCompared == skipId) {
        return;
    }
    volume = 0x7fu;
    zero = 0u;
    StartSound(sourceCopy, soundIdCopy, volume, zero);
}

void ApplyItemObjectHitType(ItemObject *itemParam, s32 hitType, Vec3 *otherPos, Vec3 *otherVelocity,
                            MapObject *mapObject) {
    ItemObject *item = itemParam;
    Vec3 offset;
    Vec3 direction;
    Vec3 push;
    s32 soundId;
    s32 value;
    s32 radius;
    void (*soundCallback)(ItemObject *, s32);

    if (item->mFlags & 0x80000) {
        return;
    }
    soundId = mapObject ? mapObject->mKindData->mCollideItemObjectSoundId : -1;
    switch (hitType) {
        case 1:
            if (item->mFlags & 0x1000) {
                break;
            }
            VEC_Subtract(&item->mPrevPos, otherPos, &offset);
            if (!(item->mFlags & 0x8000) && (item->mFlags & 0x1000000)) {
                DeflectItemObjectRandomly(item, otherPos, &offset);
                break;
            }
            item->mFlags |= 0x4000000;
            if (Vec3DotUnrounded(&item->mVelocity, &offset) <= 0) {
                if (LENGTH_SQUARED(offset) >= 0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&offset, &offset);
                }
                item->mBounce(item, otherVelocity, &offset);
                if (item->mFlags & 0x8000) {
                    break;
                }
                radius = item->mRadius;
                if ((s64) (otherPos->x - item->mPos.x) * (otherPos->x - item->mPos.x) +
                        (s64) (otherPos->y - item->mPos.y) * (otherPos->y - item->mPos.y) +
                        (s64) (otherPos->z - item->mPos.z) * (otherPos->z - item->mPos.z) >=
                    (s64) radius * radius) {
                    break;
                }
                item->mPos.x = otherPos->x + MUL_FIXED12_NO_ROUND(radius, offset.x);
                item->mPos.z = otherPos->z + MUL_FIXED12_NO_ROUND(radius, offset.z);
                break;
            }
            if (item->mFlags & 0x8000) {
                break;
            }
            radius = item->mRadius;
            if ((s64) (otherPos->x - item->mPos.x) * (otherPos->x - item->mPos.x) +
                    (s64) (otherPos->y - item->mPos.y) * (otherPos->y - item->mPos.y) +
                    (s64) (otherPos->z - item->mPos.z) * (otherPos->z - item->mPos.z) >=
                (s64) radius * radius) {
                break;
            }
            if (LENGTH_SQUARED(offset) >= 0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&offset, &offset);
            }
            radius = item->mRadius;
            item->mPos.x = otherPos->x + MUL_FIXED12_NO_ROUND(radius, offset.x);
            item->mPos.z = otherPos->z + MUL_FIXED12_NO_ROUND(radius, offset.z);
            break;
        case 2:
            if (item->mFlags & 0x1000) {
                RemoveItemInUseObject(&GetKartItems(item->mOwnerKartIndexAndFlags & ~0xff00)->mItemInUse, item);
            }
            value = 0;
            if ((s64) otherVelocity->x * otherVelocity->x + (s64) otherVelocity->y * otherVelocity->y +
                    (s64) otherVelocity->z * otherVelocity->z >=
                0x10) {
                value = Vec3NormalizeAndGetLengthUnchecked(otherVelocity, &direction);
            }
            if (value != 0) {
                ApplyItemObjectPush(item, otherPos, otherVelocity, &direction);
            } else {
                VEC_Subtract(&item->mPos, otherPos, &direction);
                if (direction.y < 0) {
                    direction.y = 0;
                }
                if ((s64) direction.x * direction.x + (s64) direction.y * direction.y +
                        (s64) direction.z * direction.z >=
                    0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
                }
                push.x = MUL_FIXED12_NO_ROUND(direction.x, 0x1800);
                push.y = MUL_FIXED12_NO_ROUND(direction.y, 0x1800);
                push.z = MUL_FIXED12_NO_ROUND(direction.z, 0x1800);
                ApplyItemObjectPush(item, otherPos, &push, &direction);
            }
            if (soundId == -1 || (item->mFlags & 0x8000000)) {
                FadeOutUsedUpItemObject(item, 1);
            } else {
                value = item->mKind;
                FadeOutEndedItemObject(item, 1);
                if (value == 5 || value == 9) {
                    soundId = -1;
                }
            }
    }
    if (soundId == -1) {
        return;
    }
    soundCallback = (item->mFlags & 0x400000) ? StartItemObjectSoundOnSource : StartItemObjectSoundIfNear;
    soundCallback(item, soundId);
}

void StartItemObjectReleaseTimerSynced(ItemObject *item, s32 sendEvent) {
    BOOL started;
    enum { K0 } kind;

    if (!(item->mFlags & 0x8000000)) {
        if ((item->mFlags & 0x8000000) && !(item->mFlags & 0x10000000) && !(item->mFlags & 0x20000000)) {
            if (item->mOwnerKartIndexAndFlags & 0xf00) {
                return;
            }
            item->mOwnerKartIndexAndFlags |= gItemObjectReleaseTimerPendingBit;
            item->mAdvance = NULL;
            return;
        }
        if (item->mFlags & 0x180000) {
            return;
        }
        kind = item->mKind;
        if (gItemKinds[kind].mKeepsAdvanceAtEnd == 0 && !(item->mFlags & 0x180000)) {
            item->mAdvance = AdvanceItemObjectReleaseTimer;
        }
        item->mFlags |= 0x100002;
        return;
    }
    if ((item->mFlags & 0x8000000) && !(item->mFlags & 0x10000000) && !(item->mFlags & 0x20000000)) {
        if (item->mOwnerKartIndexAndFlags & 0xf00) {
            started = FALSE;
        } else {
            item->mOwnerKartIndexAndFlags |= gItemObjectReleaseTimerPendingBit;
            item->mAdvance = NULL;
            started = TRUE;
        }
    } else {
        if (item->mFlags & 0x180000) {
            started = FALSE;
        } else {
            kind = item->mKind;
            if (gItemKinds[kind].mKeepsAdvanceAtEnd == 0 && !(item->mFlags & 0x180000)) {
                item->mAdvance = AdvanceItemObjectReleaseTimer;
            }
            item->mFlags |= 0x100002;
            started = TRUE;
        }
    }
    if (started == FALSE) {
        return;
    }
    if (sendEvent == 0) {
        return;
    }
    AddItemDataItemIdAndParts(item->mKind, 4, 8, item->mId);
}

void StartItemObjectReleaseTimer(ItemObject *item) {
    enum { K0 } kind;

    if (item->mFlags & 0x180000) {
        return;
    }
    kind = item->mKind;
    if (gItemKinds[kind].mKeepsAdvanceAtEnd == 0 && !(item->mFlags & 0x180000)) {
        item->mAdvance = AdvanceItemObjectReleaseTimer;
    }
    item->mFlags |= 0x100002;
}

void AdvanceItemObjectReleaseTimer(ItemObject *item) {
    if (item->mFlags & 0x8000) {
        AdvanceRestingItemObject(item);
    }
    item->mAlpha--;
    if (item->mAlpha <= 0) {
        ReleaseItemPoolObject(&gItemPools[item->mKind], item);
    } else {
        if (item->mAlpha < 0xa) {
            FreeItemObjectCollisionSlot(item);
        }
    }
}

void StartItemObjectReleaseSynced(ItemObject *item, s32 sendEvent) {
    BOOL started;

    if (!(item->mFlags & 0x8000000)) {
        if ((item->mFlags & 0x8000000) && !(item->mFlags & 0x10000000) && !(item->mFlags & 0x20000000)) {
            if (item->mOwnerKartIndexAndFlags & 0xf00) {
                return;
            }
            item->mOwnerKartIndexAndFlags |= gItemObjectReleasePendingBit;
            item->mAdvance = NULL;
            return;
        }
        if (item->mFlags & 0x180000) {
            return;
        }
        if (!(item->mFlags & 0x180000)) {
            item->mAdvance = ReleaseItemObjectToItsPool;
        }
        item->mFlags |= 0x100002;
        return;
    }
    if ((item->mFlags & 0x8000000) && !(item->mFlags & 0x10000000) && !(item->mFlags & 0x20000000)) {
        if (item->mOwnerKartIndexAndFlags & 0xf00) {
            started = FALSE;
        } else {
            item->mOwnerKartIndexAndFlags |= gItemObjectReleasePendingBit;
            item->mAdvance = NULL;
            started = TRUE;
        }
    } else {
        if (item->mFlags & 0x180000) {
            started = FALSE;
        } else {
            if (!(item->mFlags & 0x180000)) {
                item->mAdvance = ReleaseItemObjectToItsPool;
            }
            item->mFlags |= 0x100002;
            started = TRUE;
        }
    }
    if (started == FALSE) {
        return;
    }
    if (sendEvent == 0) {
        return;
    }
    AddItemDataItemIdAndParts(item->mKind, 5, 8, item->mId);
}

void StartItemObjectRelease(ItemObject *item) {
    if (item->mFlags & 0x180000) {
        return;
    }
    if (!(item->mFlags & 0x180000)) {
        item->mAdvance = ReleaseItemObjectToItsPool;
    }
    item->mFlags |= 0x100002;
}

void ReleaseItemObjectToItsPool(ItemObject *item) {
    ReleaseItemPoolObject(&gItemPools[item->mKind], item);
}

Vec3 *CreateItemPushVector(void) {
    void *heap = GetHeap(GetCurrentHeapCall());
    gItemPushVector = HeapAlloc(heap, 0xc);
    return gItemPushVector;
}

s32 StartItemObjectFadeOut(ItemObject *item, s32 variant, s32 skipPending) {
    Vec3 *velocity = &item->mVelocity;
    ItemKind *kindInfo;
    s32 value;
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
            item->mOwnerKartIndexAndFlags |= gItemObjectFadeOutPendingBit;
        } else {
            item->mOwnerKartIndexAndFlags |= gItemObjectNoCallbackFadeOutPendingBit;
            FreeItemObjectCollisionSlot(item);
        }
        item->mAdvance = NULL;
        return 1;
    }
    if (variant == 0) {
        kind = item->mKind;
        kindInfo = &gItemKinds[kind];
        if (kindInfo->mFadeOutCallback != NULL) {
            value = kindInfo->mFadeOutCallback(item);
            if (value == 0) {
                return 2;
            }
            if (value == 1) {
                return 0;
            }
        }
    }
    if (variant != 0) {
        item->mCoursePointOrParams.y = 0x266;
    } else {
        item->mCoursePointOrParams.y = 0x333;
        if (!(item->mFlags & 0x8000)) {
            item->mCoursePointOrParams.y += MUL_FIXED12_NO_ROUND(VEC_Mag(velocity), 0x15c);
            if (item->mCoursePointOrParams.y > 0x5c3) {
                item->mCoursePointOrParams.y = 0x5c3;
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

        value = Vec3DotUnrounded(velocity, normal);
        if (value < 0x3000) {
            VEC_MultAdd(0x3000 - value, normal, velocity, velocity);
        }
    }
    item->mFlags |= 0x80001;
    FreeItemObjectCollisionSlot(item);
    value = Vec3DotUnrounded(velocity, GetViewTransposeMatrixAxis0());
    if (value > 1) {
        item->mCoursePointOrParams.x = 1;
    } else {
        item->mCoursePointOrParams.x = 0;
    }
    return 0;
}

void FadeOutEndedItemObject(ItemObject *item, s32 sendEvent) {
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

void ReplayPendingFadeOut(ItemObject *item) {
    StartItemObjectFadeOut(item, 0, 1);
}

void FadeOutItemObjectNoCallback(ItemObject *item, s32 sendEvent) {
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

void ReplayPendingNoCallbackFadeOut(ItemObject *item) {
    StartItemObjectFadeOut(item, 1, 1);
}

void FadeOutUsedUpItemObject(ItemObject *item, s32 sendEvent) {
    s32 result;
    enum { K0 } kind;

    result = StartItemObjectFadeOut(item, 0, 0);
    if (result <= 1) {
        kind = item->mKind;
        StartItemObjectSoundIfNear(item, gItemKinds[kind].mUsedUpSoundId);
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

void FadeOutItemObjectHitByKart(ItemObject *item, s32 sendEvent, s32 highPart) {
    s32 result;
    enum { K0 } kind;

    result = StartItemObjectFadeOut(item, 0, 0);
    if (result <= 1) {
        kind = item->mKind;
        StartItemObjectSoundIfNear(item, gItemKinds[kind].mKartHitSoundId);
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
    VEC_MultAdd(item->mCoursePointOrParams.x != 0 ? item->mCoursePointOrParams.y : -item->mCoursePointOrParams.y,
                &direction, &item->mNormal, &item->mNormal);
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

u32 ItemObjectBounceReturnArgument(u32 value) {
    return value;
}

void StartRestingItemObject(ItemObject *item, void *collisionHitLink) {
    s32 fallSpeed;
    enum { K0 } kind;
    s32 bounceFactor;

    VEC_MultAdd(-item->mCourseRadius, &item->mNormal, &item->mPos, &item->mCoursePointOrParams);
    UpdateCollisionHitLink(collisionHitLink, item->mCollisionBits, item->mCollisionHitLink, &item->mCoursePointOrParams,
                           &item->mNormal);
    if (item->mCollisionHitLink->mObject != NULL && IsHitLinkOutsideGearRadiusOrFlagged(item->mCollisionHitLink) != 0) {
        item->mHitLinkTimer = ITEM_OBJECT_HIT_LINK_TIMER_FRAMES;
    } else {
        item->mHitLinkTimer = 0;
    }
    item->mFlags |= 0x8000;
    kind = *(vs32 *) &item->mKind;
    if (gItemKinds[kind].mKeepsAdvanceWhenResting == 0) {
        if (!(item->mFlags & 0x180000)) {
            item->mAdvance = AdvanceRestingItemObject;
        }
    }
    item->mBounce = BounceRestingItemObject;
    kind = item->mKind;
    bounceFactor = gItemKinds[kind].mBounceFactor;
    fallSpeed = item->mVelocity.y;
    if (fallSpeed <= 0) {
        fallSpeed = -fallSpeed;
    }
    item->mScaleTargetOrSpeed = -MUL_FIXED12_NO_ROUND(fallSpeed, bounceFactor);
    if (item->mScaleTargetOrSpeed < -0x5c3) {
        item->mScaleTargetOrSpeed = -0x5c3;
    }
    item->mVelocity.x = 0;
    item->mVelocity.y = 0;
    item->mVelocity.z = 0;
    StopItemObjectSoundSource(item);
    AddRestingItemPoolObject(&gItemPools[*(vs32 *) &item->mKind], item);
    kind = *(vs32 *) &item->mKind;
    StartItemObjectSoundIfNear(item, gItemKinds[kind].mRestSoundId);
}

void AdvanceRestingItemObject(ItemObject *item) {
    u32 collisionHitLink;

    if (item->mCollisionHitLink->mObject != NULL) {
        if (GetCollisionHitLinkPosAndVelocity(item->mCollisionHitLink, &item->mCoursePointOrParams, &item->mNormal) !=
            FALSE) {
            StartFallingItemObject(item);
        }
        if (item->mCollisionHitLink->mObject->mCollisionData.mUnk_130 != FALSE) {
            if (item->mNormal.y < 0xff4) {
                item->mFlags |= 0x80;
            }
        }
        VEC_MultAdd(item->mCourseRadius, &item->mNormal, &item->mCoursePointOrParams, &item->mPos);
        if (item->mHitLinkTimer > 0) {
            item->mHitLinkTimer -= 1;
            if ((item->mCreationNumber & 7) != GetRaceUpdateFramesMod8()) {
                return;
            }
            if (CollideSphereWithCourse(&item->mPos, NULL, 0, item->mCourseRadius, 0x44, item->mCollisionSlotIndex,
                                        NULL, NULL, NULL, &item->mCollisionBits, NULL, NULL, NULL,
                                        &collisionHitLink) == 0) {
                return;
            }
            if (IsCollisionHitLinkOutdated(&collisionHitLink, item->mCollisionBits, item->mCollisionHitLink) != FALSE) {
                item->mVelocity.x = 0;
                item->mVelocity.y = 0;
                item->mVelocity.z = 0;
                FadeOutUsedUpItemObject(item, 1);
            }
            if (!(item->mCollisionBits & 0x8000)) {
                return;
            }
            FadeOutItemObjectNoCallback(item, 1);
        } else {
            VEC_Subtract(&item->mPos, &item->mPrevPos, &item->mVelocity);
        }
    } else {
        if (!(item->mFlags & 0x40)) {
            return;
        }
        VEC_MultAdd(item->mCourseRadius, &item->mNormal, &item->mCoursePointOrParams, &item->mPos);
    }
}

void BounceRestingItemObject(ItemObject *item, Vec3 *otherVelocity, Vec3 *normal) {
    s32 scaleDifference;
    s32 dot;
    u32 kind;

    scaleDifference = item->mScale.z - item->mScale.y;
    if (scaleDifference * scaleDifference >= 0x68be1) {
        return;
    }
    dot = Vec3DotUnrounded(otherVelocity, normal);
    if (dot <= 0) {
        dot = -dot;
    }
    kind = *(vs32 *) &item->mKind;
    item->mScaleTargetOrSpeed = MUL_FIXED12_NO_ROUND(dot, gItemKinds[kind].mBounceFactor);
    item->mScaleTargetOrSpeed = item->mScaleTargetOrSpeed >> 1;
}

void LaunchItemObjectFromPos(ItemObject *itemParam, s32 pushStrength, Vec3 *fromPos, Vec3 *fromVelocity, Vec3 *normal) {
    ItemObject *item;
    Vec3 away;
    Vec3 *velocity;
    s32 startsFalling;
    s32 dot;
    u32 kind;

    item = itemParam;
    velocity = &item->mVelocity;
    kind = *(vs32 *) &item->mKind;
    startsFalling = gItemKinds[kind].mStartsFalling;
    if (gRaceSetup->mMode == MODE_TIME_ATTACK || (item->mFlags & 0x8000000)) {
        startsFalling = 0;
    }
    item->mFlags |= 0x4000;
    item->mOwnerKartIndexAndFlags |= data_02159b64;
    dot = VEC_DotProduct(normal, velocity);
    velocity->x -= MUL_FIXED12_NO_ROUND(normal->x, dot);
    velocity->y -= MUL_FIXED12_NO_ROUND(normal->y, dot);
    velocity->z -= MUL_FIXED12_NO_ROUND(normal->z, dot);
    dot = Vec3DotUnrounded(fromVelocity, normal);
    if (dot < 0) {
        dot = 0;
    } else if (dot > 0x1333) {
        dot = 0x1333;
    }
    VEC_MultAdd(dot + (startsFalling != 0 ? 0x2800 : 0x3800), normal, velocity, velocity);
    if (pushStrength != 0) {
        VEC_Subtract(&item->mPos, fromPos, &away);
        if (LENGTH_SQUARED(away) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&away, &away);
        }
        VEC_MultAdd(pushStrength * 0x14cd, &away, velocity, velocity);
    }
    if (startsFalling != 0) {
        if (!(item->mFlags & 0x180000)) {
            item->mAdvance = AdvanceFallingItemObject;
        }
        item->mBounce = FallingBounceItemObject;
        item->mFlags &= ~0x7000000;
    } else {
        item->mFlags &= ~0x4000;
        FadeOutItemObjectNoCallback(item, 1);
    }
}

void StartFallingItemObject(ItemObject *item) {
    u32 kind;

    item->mFlags &= ~0x8000;
    item->mFlags |= 0x4000;
    kind = *(vs32 *) &item->mKind;
    if (gItemKinds[kind].mKeepsAdvanceWhenResting == 0) {
        if (!(item->mFlags & 0x180000)) {
            item->mAdvance = AdvanceFallingItemObject;
        }
    }
    item->mBounce = FallingBounceItemObject;
    item->mFlags &= ~0x7000000;
}

void AdvanceFallingItemObject(ItemObject *item) {
    u32 collisionHitLink;
    Vec3 pushOut;
    Vec3 groundNormal;
    Vec3 bounceNormal;
    Vec3 *pos;
    Vec3 *velocity;

    pos = &item->mPos;
    velocity = &item->mVelocity;

    VEC_Add(velocity, pos, pos);
    item->mVelocity.x = MUL_FIXED12_NO_ROUND(item->mVelocity.x, 0xfec);
    velocity->z = MUL_FIXED12_NO_ROUND(velocity->z, 0xfec);
    if (CollideSphereWithCourse(pos, &item->mPrevPos, 0, item->mCourseRadius, 0x44, item->mCollisionSlotIndex, &pushOut,
                                &groundNormal, &bounceNormal, &item->mCollisionBits, NULL, NULL, NULL,
                                &collisionHitLink) != 0) {
        VEC_Add(&pushOut, pos, pos);
        if (item->mCollisionBits & 0x1e34ef) {
            LandItemObjectIfOnGround(item, pos, velocity, 0x385, &groundNormal);
        }
        if (item->mCollisionBits & 0x214300) {
            item->mFlags |= 0x20;
            BounceItemVelocityOffSurface(velocity, &bounceNormal);
            if (TryFadeOutDeflectedItemObject(item, &bounceNormal) != FALSE) {
                return;
            }
        }
        if (item->mCollisionBits & 0x8000) {
            FadeOutItemObjectNoCallback(item, 1);
            return;
        }
    }
    item->mFlags &= ~0x4000000;
    if (!(item->mCollisionBits & 0x1e34ef)) {
        velocity->y -= 0x385;
        if (velocity->y < -0xa000) {
            velocity->y = -0xa000;
        }
    }
    if (!(item->mFlags & 8)) {
        return;
    }
    if (item->mFlags & 3) {
        return;
    }
    StartRestingItemObject(item, &collisionHitLink);
}

void FallingBounceItemObject(ItemObject *item, Vec3 *otherVelocity, Vec3 *normal) {
    BounceItemVelocityOffSurface(&item->mVelocity, normal);
    if (item->mFlags & 0x1000000) {
        return;
    }
    item->mFlags |= 0x1000000;
    item->mCoursePointOrParams.x = 0;
    item->mCoursePointOrParams.y = 0;
    item->mCoursePointOrParams.z = 0;
}
