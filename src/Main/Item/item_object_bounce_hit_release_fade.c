#include "Main/Item/item_object_bounce_hit_release_fade.h"
#include "Main/Item/item_kinoko.h"
#include "Main/Sound/sound_start_stop_and_release_wrapper.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Item/item_object_release.h"
#include "Main/Item/item_f_box.h"
#include "Main/MapObjects/attractor_distance_flag.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/kart_items_collision_hits.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Item/item_in_use.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_object_fade_out.h"
#include "Main/Item/item_slot_tables.h"
#include "Main/Item/item_object.h"
#include "fixed_vector_math.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/MapObjects/view_matrix_queue.h"
#include "Main/Course/course_color_blend.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/item_object_reset_collide.h"
#include "Main/Item/held_item.h"
#include "Main/Item/pooled_item_box.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Sound/kart_sound_callbacks.h"
#include "Main/Sound/kart_sound_starts_and_track_params.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Item/item_object_throw.h"
#include "Main/Item/item_koura_r_kart_items.h"
#include "Main/Item/item_object_bouncing.h"
#include "Main/Sound/sound_distance_squared_change_reset.h"
#include "Main/System/state_machine_init.h"
#include "Main/Item/item_link_following.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/rock.h"
#include "Main/Race/race.h"
#include "Main/Sound/sound_handle_accessors_and_mission_count_seq.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "sound_archive_load.h"
#include "Main/MapObjects/koopa_block_hit_link.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "sound_archive_load_result.h"
#include "Main/Race/race_clock.h"
#include "Main/Kart/karts.h"
#include "Main/Item/item_teresa_offset.h"
#include "Main/System/init_after_startup.h"

const u8 gItemHitTypes[196] = {2, 2, 2, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 2, 2, 2, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2,
                               2, 2, 1, 1, 1, 2, 0, 1, 0, 2, 0, 0, 0, 2, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1,
                               1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 2, 2, 2, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 1, 2, 0, 1, 0, 2, 0, 0, 0, 2,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2};
const u16 gItemObjectReleasePendingBit = ITEM_OWNER_RELEASE_PENDING;
const u16 gItemObjectFadeOutPendingBit = ITEM_OWNER_FADE_OUT_PENDING;
const u16 gItemObjectReleaseTimerPendingBit = ITEM_OWNER_RELEASE_TIMER_PENDING;
const u16 gItemObjectLaunchNoOwnerBit = ITEM_OWNER_NO_OWNER;
const u16 gItemObjectNoCallbackFadeOutPendingBit = ITEM_OWNER_NO_CALLBACK_FADE_OUT_PENDING;

u8 GetItemObjectHitType(ItemObject *itemParam, ItemObject *otherParam) {
    ItemObject *item = itemParam;
    ItemObject *other = otherParam;

    return (gItemHitTypes + item->mKind * 0xe)[other->mKind];
}

void DeflectItemObjectRandomly(ItemObject *item, Vec3 *otherPos, Vec3 *normal) {
    RandomState64 *random;
    s64 distanceSquared;
    s32 angle;

    if (item->mFlags & ITEM_OBJECT_FLAG_DEFLECTED) {
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
    item->mFlags |= ITEM_OBJECT_FLAG_HIT_THIS_STEP;
    if (item->mFlags & ITEM_OBJECT_FLAG_DEFLECTED) {
        return;
    }
    if (Vec3DotUnrounded(&item->mVelocity, normal) >= 0) {
        return;
    }
    random = &gRaceProgress->mRandom;
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    angle = (u16) ((((u64) (u32) (random->mValue >> 32) * ANGLE_FULL_TURN) >> 32));
    item->mCoursePointOrParams.z = COS_OF_ANGLE(angle);
    item->mCoursePointOrParams.x = SIN_OF_ANGLE(angle);
    item->mVelocity.z = MUL_FIXED12_NO_ROUND(item->mCoursePointOrParams.z, 0x14cd);
    item->mVelocity.x = MUL_FIXED12_NO_ROUND(item->mCoursePointOrParams.x, 0x14cd);
    item->mFlags |= ITEM_OBJECT_FLAG_DEFLECTED;
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

    if (item->mFlags & ITEM_OBJECT_FLAG_FADING_OUT) {
        return;
    }
    soundId = mapObject ? mapObject->mKindData->mCollideItemObjectSoundId : -1;
    switch (hitType) {
        case ITEM_HIT_TYPE_BOUNCE:
            if (item->mFlags & ITEM_OBJECT_FLAG_IN_USE) {
                break;
            }
            VEC_Subtract(&item->mPrevPos, otherPos, &offset);
            if (!(item->mFlags & ITEM_OBJECT_FLAG_RESTING) && (item->mFlags & ITEM_OBJECT_FLAG_BOUNCED_BEFORE)) {
                DeflectItemObjectRandomly(item, otherPos, &offset);
                break;
            }
            item->mFlags |= ITEM_OBJECT_FLAG_HIT_THIS_STEP;
            if (Vec3DotUnrounded(&item->mVelocity, &offset) <= 0) {
                if (LENGTH_SQUARED(offset) >= 0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&offset, &offset);
                }
                item->mBounce(item, otherVelocity, &offset);
                if (item->mFlags & ITEM_OBJECT_FLAG_RESTING) {
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
            if (item->mFlags & ITEM_OBJECT_FLAG_RESTING) {
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
        case ITEM_HIT_TYPE_FADE_OUT:
            if (item->mFlags & ITEM_OBJECT_FLAG_IN_USE) {
                RemoveItemInUseObject(&GetKartItems(item->mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK)->mItemInUse,
                                      item);
            }
            value = 0;
            if (SQUARE_SUM3(otherVelocity->x, otherVelocity->y, otherVelocity->z) >=
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
                if (SQUARE_SUM3(direction.x, direction.y, direction.z) >=
                    0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
                }
                push.x = MUL_FIXED12_NO_ROUND(direction.x, 0x1800);
                push.y = MUL_FIXED12_NO_ROUND(direction.y, 0x1800);
                push.z = MUL_FIXED12_NO_ROUND(direction.z, 0x1800);
                ApplyItemObjectPush(item, otherPos, &push, &direction);
            }
            if (soundId == -1 || (item->mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
                FadeOutUsedUpItemObject(item, 1);
            } else {
                value = item->mKind;
                FadeOutEndedItemObject(item, 1);
                if (value == ITEM_OBJECT_KIND_KOURA_W || value == ITEM_OBJECT_KIND_BOMB) {
                    soundId = -1;
                }
            }
    }
    if (soundId == -1) {
        return;
    }
    soundCallback =
        (item->mFlags & ITEM_OBJECT_FLAG_HAS_SOUND_SOURCE) ? StartItemObjectSoundOnSource : StartItemObjectSoundIfNear;
    soundCallback(item, soundId);
}

void StartItemObjectReleaseTimerSynced(ItemObject *item, s32 sendEvent) {
    BOOL started;
    enum { KIND_FIRST } kind;

    if (!(item->mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
        if ((item->mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) && !(item->mFlags & ITEM_OBJECT_FLAG_FROM_DATA) &&
            !(item->mFlags & ITEM_OBJECT_FLAG_DATA_SET_UP)) {
            if (item->mOwnerKartIndexAndFlags & ITEM_OWNER_PENDING_MASK) {
                return;
            }
            item->mOwnerKartIndexAndFlags |= gItemObjectReleaseTimerPendingBit;
            item->mAdvance = NULL;
            return;
        }
        if (item->mFlags & ITEM_OBJECT_FLAGS_ENDING) {
            return;
        }
        kind = item->mKind;
        if (gItemKinds[kind].mKeepsAdvanceAtEnd == 0 && !(item->mFlags & ITEM_OBJECT_FLAGS_ENDING)) {
            item->mAdvance = AdvanceItemObjectReleaseTimer;
        }
        item->mFlags |= ITEM_OBJECT_FLAG_RELEASE_STARTED | ITEM_OBJECT_FLAG_RELEASING;
        return;
    }
    if ((item->mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) && !(item->mFlags & ITEM_OBJECT_FLAG_FROM_DATA) &&
        !(item->mFlags & ITEM_OBJECT_FLAG_DATA_SET_UP)) {
        if (item->mOwnerKartIndexAndFlags & ITEM_OWNER_PENDING_MASK) {
            started = FALSE;
        } else {
            item->mOwnerKartIndexAndFlags |= gItemObjectReleaseTimerPendingBit;
            item->mAdvance = NULL;
            started = TRUE;
        }
    } else {
        if (item->mFlags & ITEM_OBJECT_FLAGS_ENDING) {
            started = FALSE;
        } else {
            kind = item->mKind;
            if (gItemKinds[kind].mKeepsAdvanceAtEnd == 0 && !(item->mFlags & ITEM_OBJECT_FLAGS_ENDING)) {
                item->mAdvance = AdvanceItemObjectReleaseTimer;
            }
            item->mFlags |= ITEM_OBJECT_FLAG_RELEASE_STARTED | ITEM_OBJECT_FLAG_RELEASING;
            started = TRUE;
        }
    }
    if (started == FALSE) {
        return;
    }
    if (sendEvent == 0) {
        return;
    }
    AddItemDataItemIdAndParts(item->mKind, ITEM_EVENT_RELEASE_TIMER, 8, item->mId);
}

void StartItemObjectReleaseTimer(ItemObject *item) {
    enum { KIND_FIRST } kind;

    if (item->mFlags & ITEM_OBJECT_FLAGS_ENDING) {
        return;
    }
    kind = item->mKind;
    if (gItemKinds[kind].mKeepsAdvanceAtEnd == 0 && !(item->mFlags & ITEM_OBJECT_FLAGS_ENDING)) {
        item->mAdvance = AdvanceItemObjectReleaseTimer;
    }
    item->mFlags |= ITEM_OBJECT_FLAG_RELEASE_STARTED | ITEM_OBJECT_FLAG_RELEASING;
}

void AdvanceItemObjectReleaseTimer(ItemObject *item) {
    if (item->mFlags & ITEM_OBJECT_FLAG_RESTING) {
        AdvanceRestingItemObject(item);
    }
    item->mAlpha--;
    if (item->mAlpha <= 0) {
        ReleaseItemPoolObject(&gItemPools[item->mKind], item);
    } else {
        if (item->mAlpha < ITEM_OBJECT_RELEASE_ALPHA_NO_COLLISION) {
            FreeItemObjectCollisionSlot(item);
        }
    }
}

void StartItemObjectReleaseSynced(ItemObject *item, s32 sendEvent) {
    BOOL started;

    if (!(item->mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
        if ((item->mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) && !(item->mFlags & ITEM_OBJECT_FLAG_FROM_DATA) &&
            !(item->mFlags & ITEM_OBJECT_FLAG_DATA_SET_UP)) {
            if (item->mOwnerKartIndexAndFlags & ITEM_OWNER_PENDING_MASK) {
                return;
            }
            item->mOwnerKartIndexAndFlags |= gItemObjectReleasePendingBit;
            item->mAdvance = NULL;
            return;
        }
        if (item->mFlags & ITEM_OBJECT_FLAGS_ENDING) {
            return;
        }
        if (!(item->mFlags & ITEM_OBJECT_FLAGS_ENDING)) {
            item->mAdvance = ReleaseItemObjectToItsPool;
        }
        item->mFlags |= ITEM_OBJECT_FLAG_RELEASE_STARTED | ITEM_OBJECT_FLAG_RELEASING;
        return;
    }
    if ((item->mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) && !(item->mFlags & ITEM_OBJECT_FLAG_FROM_DATA) &&
        !(item->mFlags & ITEM_OBJECT_FLAG_DATA_SET_UP)) {
        if (item->mOwnerKartIndexAndFlags & ITEM_OWNER_PENDING_MASK) {
            started = FALSE;
        } else {
            item->mOwnerKartIndexAndFlags |= gItemObjectReleasePendingBit;
            item->mAdvance = NULL;
            started = TRUE;
        }
    } else {
        if (item->mFlags & ITEM_OBJECT_FLAGS_ENDING) {
            started = FALSE;
        } else {
            if (!(item->mFlags & ITEM_OBJECT_FLAGS_ENDING)) {
                item->mAdvance = ReleaseItemObjectToItsPool;
            }
            item->mFlags |= ITEM_OBJECT_FLAG_RELEASE_STARTED | ITEM_OBJECT_FLAG_RELEASING;
            started = TRUE;
        }
    }
    if (started == FALSE) {
        return;
    }
    if (sendEvent == 0) {
        return;
    }
    AddItemDataItemIdAndParts(item->mKind, ITEM_EVENT_RELEASE, 8, item->mId);
}

void StartItemObjectRelease(ItemObject *item) {
    if (item->mFlags & ITEM_OBJECT_FLAGS_ENDING) {
        return;
    }
    if (!(item->mFlags & ITEM_OBJECT_FLAGS_ENDING)) {
        item->mAdvance = ReleaseItemObjectToItsPool;
    }
    item->mFlags |= ITEM_OBJECT_FLAG_RELEASE_STARTED | ITEM_OBJECT_FLAG_RELEASING;
}

void ReleaseItemObjectToItsPool(ItemObject *item) {
    ReleaseItemPoolObject(&gItemPools[item->mKind], item);
}

Vec3 *CreateItemPushVector(void) {
    void *heap = GetHeap(GetCurrentHeapCall());
    gItemPushVector = HeapAlloc(heap, sizeof(Vec3));
    return gItemPushVector;
}

s32 StartItemObjectFadeOut(ItemObject *item, s32 variant, s32 skipPending) {
    Vec3 *velocity = &item->mVelocity;
    ItemKind *kindInfo;
    s32 value;
    enum { KIND_FIRST } kind;

    if (item->mFlags & ITEM_OBJECT_FLAG_FADING_OUT) {
        return 2;
    }
    if (skipPending == 0 && (item->mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) &&
        !(item->mFlags & ITEM_OBJECT_FLAG_FROM_DATA) && !(item->mFlags & ITEM_OBJECT_FLAG_DATA_SET_UP)) {
        if (item->mOwnerKartIndexAndFlags & ITEM_OWNER_PENDING_MASK) {
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
        if (!(item->mFlags & ITEM_OBJECT_FLAG_RESTING)) {
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
    item->mBounce = ItemObjectBounceNop;
    if (item->mNormal.y != 0) {
        Vec3 *normal = &item->mNormal;

        value = Vec3DotUnrounded(velocity, normal);
        if (value < 0x3000) {
            VEC_MultAdd(0x3000 - value, normal, velocity, velocity);
        }
    }
    item->mFlags |= ITEM_OBJECT_FLAG_FADE_OUT_STARTED | ITEM_OBJECT_FLAG_FADING_OUT;
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

    if (!(item->mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
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
    AddItemDataItemIdAndParts(item->mKind, ITEM_EVENT_FADE_OUT_ENDED, 8, item->mId);
}

void ReplayPendingFadeOut(ItemObject *item) {
    StartItemObjectFadeOut(item, 0, 1);
}

void FadeOutItemObjectNoCallback(ItemObject *item, s32 sendEvent) {
    s32 result;

    if (!(item->mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
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
    AddItemDataItemIdAndParts(item->mKind, ITEM_EVENT_FADE_OUT_NO_CALLBACK, 8, item->mId);
}

void ReplayPendingNoCallbackFadeOut(ItemObject *item) {
    StartItemObjectFadeOut(item, 1, 1);
}

void FadeOutUsedUpItemObject(ItemObject *item, s32 sendEvent) {
    s32 result;
    enum { KIND_FIRST } kind;

    result = StartItemObjectFadeOut(item, 0, 0);
    if (result <= 1) {
        kind = item->mKind;
        StartItemObjectSoundIfNear(item, gItemKinds[kind].mUsedUpSoundId);
    }
    if (result != 0) {
        return;
    }
    if (!(item->mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
        return;
    }
    if (sendEvent == 0) {
        return;
    }
    if (item->mKind == ITEM_OBJECT_KIND_KOURA_W) {
        return;
    }
    AddItemDataItemIdAndParts(item->mKind, ITEM_EVENT_FADE_OUT_USED_UP, 8, item->mId);
}

void FadeOutItemObjectHitByKart(ItemObject *item, s32 sendEvent, s32 highPart) {
    s32 result;
    enum { KIND_FIRST } kind;

    result = StartItemObjectFadeOut(item, 0, 0);
    if (result <= 1) {
        kind = item->mKind;
        StartItemObjectSoundIfNear(item, gItemKinds[kind].mKartHitSoundId);
    }
    if (result != 0) {
        return;
    }
    if (!(item->mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
        return;
    }
    if (sendEvent == 0) {
        return;
    }
    if (item->mKind == ITEM_OBJECT_KIND_KOURA_W) {
        return;
    }
    AddItemDataItemIdAndParts(item->mKind, ITEM_EVENT_FADE_OUT_HIT_BY_KART, highPart, item->mId);
}

void AdvanceItemObjectFadeOut(ItemObject *item) {
    Vec3 direction;

    Vec3CrossUnrounded(&item->mNormal, GetViewTransposeMatrixAxis2(), &direction);
    VEC_MultAdd(item->mCoursePointOrParams.x != 0 ? item->mCoursePointOrParams.y : -item->mCoursePointOrParams.y,
                &direction, &item->mNormal, &item->mNormal);
    item->mFlags |= ITEM_OBJECT_FLAG_KEEP_NORMAL;
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
    if (item->mFlags & ITEM_OBJECT_FLAG_RESTING) {
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

void ItemObjectBounceNop(ItemObject *item, Vec3 *otherVelocity, Vec3 *normal) {}

void StartRestingItemObject(ItemObject *item, void *collisionHitLink) {
    s32 fallSpeed;
    enum { KIND_FIRST } kind;
    s32 bounceFactor;

    VEC_MultAdd(-item->mCourseRadius, &item->mNormal, &item->mPos, &item->mCoursePointOrParams);
    UpdateCollisionHitLink(collisionHitLink, item->mCollisionBits, item->mCollisionHitLink, &item->mCoursePointOrParams,
                           &item->mNormal);
    if (item->mCollisionHitLink->mObject != NULL && IsHitLinkOutsideGearRadiusOrFlagged(item->mCollisionHitLink) != 0) {
        item->mHitLinkTimer = ITEM_OBJECT_HIT_LINK_TIMER_FRAMES;
    } else {
        item->mHitLinkTimer = 0;
    }
    item->mFlags |= ITEM_OBJECT_FLAG_RESTING;
    kind = item->mKind;
    if (gItemKinds[kind].mKeepsAdvanceWhenResting == 0) {
        if (!(item->mFlags & ITEM_OBJECT_FLAGS_ENDING)) {
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
    AddRestingItemPoolObject(&gItemPools[item->mKind], item);
    kind = item->mKind;
    StartItemObjectSoundIfNear(item, gItemKinds[kind].mRestSoundId);
}

void AdvanceRestingItemObject(ItemObject *item) {
    u32 collisionHitLink;

    if (item->mCollisionHitLink->mObject != NULL) {
        if (GetCollisionHitLinkPosAndNormal(item->mCollisionHitLink, &item->mCoursePointOrParams, &item->mNormal) !=
            FALSE) {
            StartFallingItemObject(item);
        }
        if (item->mCollisionHitLink->mObject->mCollisionData.mTracksNormal != FALSE) {
            if (item->mNormal.y < 0xff4) {
                item->mFlags |= ITEM_OBJECT_FLAG_KEEP_NORMAL;
            }
        }
        VEC_MultAdd(item->mCourseRadius, &item->mNormal, &item->mCoursePointOrParams, &item->mPos);
        if (item->mHitLinkTimer > 0) {
            item->mHitLinkTimer -= 1;
            if ((item->mCreationNumber & ITEM_OBJECT_CREATION_PHASE_MASK) != GetRaceUpdateFramesMod8()) {
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
            if (!(item->mCollisionBits & COURSE_HIT_FADES_ITEMS)) {
                return;
            }
            FadeOutItemObjectNoCallback(item, 1);
        } else {
            VEC_Subtract(&item->mPos, &item->mPrevPos, &item->mVelocity);
        }
    } else {
        if (!(item->mFlags & ITEM_OBJECT_FLAG_SCALE_CHANGED)) {
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

void LaunchItemObjectFromPos(ItemObject *itemParam, s32 pushStrength, Vec3 *fromPos, Vec3 *fromVelocity,
                             const Vec3 *normal) {
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
    if (gRaceSetup->mMode == MODE_TIME_ATTACK || (item->mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
        startsFalling = 0;
    }
    item->mFlags |= ITEM_OBJECT_FLAG_LAUNCHED;
    item->mOwnerKartIndexAndFlags |= gItemObjectLaunchNoOwnerBit;
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
        if (!(item->mFlags & ITEM_OBJECT_FLAGS_ENDING)) {
            item->mAdvance = AdvanceFallingItemObject;
        }
        item->mBounce = FallingBounceItemObject;
        item->mFlags &=
            ~(ITEM_OBJECT_FLAG_BOUNCED_BEFORE | ITEM_OBJECT_FLAG_DEFLECTED | ITEM_OBJECT_FLAG_HIT_THIS_STEP);
    } else {
        item->mFlags &= ~ITEM_OBJECT_FLAG_LAUNCHED;
        FadeOutItemObjectNoCallback(item, 1);
    }
}

void StartFallingItemObject(ItemObject *item) {
    u32 kind;

    item->mFlags &= ~ITEM_OBJECT_FLAG_RESTING;
    item->mFlags |= ITEM_OBJECT_FLAG_LAUNCHED;
    kind = *(vs32 *) &item->mKind;
    if (gItemKinds[kind].mKeepsAdvanceWhenResting == 0) {
        if (!(item->mFlags & ITEM_OBJECT_FLAGS_ENDING)) {
            item->mAdvance = AdvanceFallingItemObject;
        }
    }
    item->mBounce = FallingBounceItemObject;
    item->mFlags &= ~(ITEM_OBJECT_FLAG_BOUNCED_BEFORE | ITEM_OBJECT_FLAG_DEFLECTED | ITEM_OBJECT_FLAG_HIT_THIS_STEP);
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
        if (item->mCollisionBits & COURSE_HIT_GROUND) {
            LandItemObjectIfOnGround(item, pos, velocity, 0x385, &groundNormal);
        }
        if (item->mCollisionBits & COURSE_HIT_WALL) {
            item->mFlags |= ITEM_OBJECT_FLAG_HIT_WALL;
            BounceItemVelocityOffSurface(velocity, &bounceNormal);
            if (TryFadeOutDeflectedItemObject(item, &bounceNormal) != FALSE) {
                return;
            }
        }
        if (item->mCollisionBits & COURSE_HIT_FADES_ITEMS) {
            FadeOutItemObjectNoCallback(item, 1);
            return;
        }
    }
    item->mFlags &= ~ITEM_OBJECT_FLAG_HIT_THIS_STEP;
    if (!(item->mCollisionBits & COURSE_HIT_GROUND)) {
        velocity->y -= 0x385;
        if (velocity->y < -0xa000) {
            velocity->y = -0xa000;
        }
    }
    if (!(item->mFlags & ITEM_OBJECT_FLAG_LANDED)) {
        return;
    }
    if (item->mFlags & (ITEM_OBJECT_FLAG_FADE_OUT_STARTED | ITEM_OBJECT_FLAG_RELEASE_STARTED)) {
        return;
    }
    StartRestingItemObject(item, &collisionHitLink);
}

void FallingBounceItemObject(ItemObject *item, Vec3 *otherVelocity, Vec3 *normal) {
    BounceItemVelocityOffSurface(&item->mVelocity, normal);
    if (item->mFlags & ITEM_OBJECT_FLAG_BOUNCED_BEFORE) {
        return;
    }
    item->mFlags |= ITEM_OBJECT_FLAG_BOUNCED_BEFORE;
    item->mCoursePointOrParams.x = 0;
    item->mCoursePointOrParams.y = 0;
    item->mCoursePointOrParams.z = 0;
}
