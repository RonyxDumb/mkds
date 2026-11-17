#include "Main/Item/item_kinoko.h"
#include "Main/Sound/sound_handle_start_and_distance_change.h"
#include "Main/Sound/sound_start_stop_and_release_wrapper.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Item/item_object_bounce_hit_release_fade.h"
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
#include "ITCM/collision_slots.h"
#include "Main/Item/item_koura_r.h"
#include "Main/System/init_after_startup.h"

const u16 gItemBananaUntilCourseHitBit = ITEM_OWNER_EXCLUDED_UNTIL_COURSE_HIT;

StateCallbacks gItemKouraRStateTable[7] = {{NULL, UpdateItemKouraRStraight},
                                           {NULL, UpdateItemKouraRStraight},
                                           {NULL, UpdateItemKouraRSeekAfterThrow},
                                           {EnterItemKouraRFollowLink, UpdateItemKouraRFollowLink},
                                           {EnterItemKouraRSteerToKart, UpdateItemKouraRSteerToKart},
                                           {NULL, UpdateItemKouraRCloseIn},
                                           {NULL, UpdateItemKouraRGlide}};

const ItemInfo gItemInfoKouraR = {1, 1, 1, 1, 0, 1, NULL};

const ItemKind gItemKindKouraR = {0x274,
                                  8,
                                  4,
                                  -1,
                                  -1,
                                  {0},
                                  NULL,
                                  NULL,
                                  NULL,
                                  (s32(*)(void *, void *)) InitItemKouraR,
                                  (void (*)(ItemObject *)) AdvanceItemKouraR,
                                  NULL,
                                  ComputeViewTest,
                                  NULL,
                                  NULL,
                                  NULL,
                                  0,
                                  0,
                                  (void *(*) (void *, void *, s32)) CopyItemKouraRData,
                                  0,
                                  (void (*)(void *)) InitItemKouraRFromData,
                                  0,
                                  0,
                                  0x4b0000,
                                  2,
                                  0x319a,
                                  0x6000,
                                  0x2e66,
                                  0x1000,
                                  0x1ccd,
                                  0x29,
                                  0xa4,
                                  1,
                                  1,
                                  1,
                                  {0},
                                  3,
                                  0xd6,
                                  0xd9,
                                  1,
                                  1,
                                  0};

void StartItemKouraRSound(void *kouraParam, s32 unused) {
    ItemKouraR *kouraR;

    kouraR = kouraParam;
    if (!(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags &
          ITEM_OBJECT_FLAG_HAS_SOUND_SOURCE)) {
        return;
    }
    AdvanceSoundDistanceSquaredChange(
        &kouraR->mSoundDistanceSquaredChange,
        kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f);
    StartSoundWhileRequested(&kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource, 0xd8, SOUND_VOLUME_MAX,
                             0);
}

void DeflectItemKouraROnHit(ItemKouraR *kouraR, Vec3 *otherVelocity, Vec3 *normal) {
    SetItemObjectDirectionFromVelocity(kouraR);
    DeflectItemObjectOnHit(&kouraR->mLinkFollowingItemObject.mDirectedItemObject, otherVelocity, normal);
    kouraR->mStateMachine.mNextState = ITEM_KOURA_R_STATE_STRAIGHT;
    kouraR->mStateMachine.mNextStateRequested = 1;
}

// Called when an object is taken off the kart item list: sets up its state machine and first state.
s32 InitItemKouraR(ItemInUse *itemInUse, ItemKouraR *kouraR) {
    u16 ownerKartIndex;
    u16 targetKartIndex;
    u16 rankAhead;

    StartItemObjectSoundSource(&kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    ResetSoundDistanceSquaredChange(&kouraR->mSoundDistanceSquaredChange);
    kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource.mTrackParamsFunction =
        (void (*)(void *, void *, void *)) SetItemKouraSoundTrackParams;
    InitStateMachine(&kouraR->mStateMachine, gItemKouraRStateTable, 7, kouraR);
    if (itemInUse->mKartItems->mFlags & KART_ITEMS_DOWN) {
        kouraR->mThrowForward = 0;
        InitItemObjectThrow(kouraR, itemInUse, 0, 0, 0, 0x5000);
        kouraR->mStateMachine.mNextState = ITEM_KOURA_R_STATE_STRAIGHT;
        kouraR->mStateMachine.mNextStateRequested = 1;
        kouraR->mLinkFollowingItemObject.mPreviousLink.mLink = NULL;
        kouraR->mLinkFollowingItemObject.mPreviousLink.mNextLinksUsed = 1;
    } else {
        kouraR->mThrowForward = 1;
        if (gRaceSetup->mMode != MODE_BATTLE && itemInUse->mKartItems->mItemLink.mLink != NULL) {
            ownerKartIndex =
                !(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags &
                  ITEM_OWNER_NO_OWNER)
                    ? (u16) (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags &
                             ~ITEM_OWNER_FLAGS_MASK)
                    : ITEM_NO_KART_INDEX;
            if (ownerKartIndex >= ITEM_NO_KART_INDEX) {
                targetKartIndex = ITEM_NO_KART_INDEX;
            } else {
                rankAhead = GetKartRank(ownerKartIndex) - 1;
                if (rankAhead < 1) {
                    rankAhead = gRaceSetup->mKartCount;
                }
                targetKartIndex = GetRaceProgressKartIndexAtRank(rankAhead);
            }
            InitLinkFollowingItemFromInUse(&kouraR->mLinkFollowingItemObject, itemInUse, 0x2d, 0x5b, 1, 0, 1, 0x5000,
                                           targetKartIndex, 0);
            kouraR->mStateMachine.mNextState = ITEM_KOURA_R_STATE_FOLLOW_LINK;
            kouraR->mStateMachine.mNextStateRequested = 1;
        } else {
            InitItemObjectThrow(kouraR, itemInUse, 0, 1, 0, 0x5000);
            kouraR->mStateMachine.mNextState = ITEM_KOURA_R_STATE_SEEK_AFTER_THROW;
            kouraR->mStateMachine.mNextStateRequested = 1;
            kouraR->mLinkFollowingItemObject.mPreviousLink.mLink = NULL;
            kouraR->mLinkFollowingItemObject.mPreviousLink.mNextLinksUsed = 1;
        }
        kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags |= ITEM_OBJECT_FLAG_HITS_FAR_KARTS;
    }
    ResetItemKouraRKartItems(kouraR);
    if (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE) {
        kouraR->mStateMachine.mNextState = ITEM_KOURA_R_STATE_STRAIGHT_WIFI_RACE;
        kouraR->mStateMachine.mNextStateRequested = 1;
    }
    return kouraR->mThrowForward;
}

void AdvanceItemKouraR(ItemKouraR *kouraR) {
    AdvanceStateMachine(&kouraR->mStateMachine);
}

void UpdateItemKouraRStraight(void *stateObject) {
    ItemKouraR *kouraR = stateObject;
    AdvanceItemObjectMotion(&kouraR->mLinkFollowingItemObject.mDirectedItemObject, 0x8800);
    if (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADE_OUT_STARTED) {
        return;
    }
    AddSoundRequest(&gSoundRequestQueues[5],
                    kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags &
                        ~0xc000001f,
                    StartItemKouraRSound, kouraR, 0);
}

void RequestItemKouraRSteerToKart(ItemKouraR *kouraR, u32 kartIndex) {
    u32 value = kartIndex;
    u32 minusOne;
    u32 collisionSlotIndex;
    u32 collisionSlotCompared;
    u32 minusOneCompared;
    collisionSlotIndex = kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCollisionSlotIndex;
    minusOne = ~(0u);
    collisionSlotCompared = collisionSlotIndex;
    minusOneCompared = minusOne;
    if (collisionSlotCompared == minusOneCompared) {
    }
    if (collisionSlotCompared == minusOneCompared) {
        return;
    }
    SetItemKouraRKartItemsAndClearTowardKartVelocity(kouraR, value);
    value = ITEM_KOURA_R_STATE_HOMING;
    kouraR->mStateMachine.mNextState = value;
    value = 1u;
    kouraR->mStateMachine.mNextStateRequested = value;
}

void UpdateItemKouraRSeekAfterThrow(void *stateObject) {
    ItemKouraR *kouraR = stateObject;
    AdvanceItemObjectMotion(&kouraR->mLinkFollowingItemObject.mDirectedItemObject, 0x8800);
    if (!(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags &
          ITEM_OBJECT_FLAG_FADE_OUT_STARTED)) {
        AddSoundRequest(&gSoundRequestQueues[5],
                        kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags &
                            ~0xc000001f,
                        StartItemKouraRSound, kouraR, 0);
    }
    if (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADE_OUT_STARTED) {
        return;
    }
    if (kouraR->mStateMachine.mStateFrames > ITEM_KOURA_R_SINGLE_KART_TEST_FRAMES) {
        if (TrySetItemKouraRKartItemsByFrame(kouraR, 0) == 0) {
            return;
        }
        kouraR->mStateMachine.mNextState = ITEM_KOURA_R_STATE_HOMING;
        kouraR->mStateMachine.mNextStateRequested = 1;
        if (!(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
            return;
        }
        AddItemDataItemIdAndKart(ITEM_OBJECT_KIND_KOURA_R, kouraR->mKartItems->mKartIndex,
                                 kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
        return;
    }
    if (kouraR->mStateMachine.mStateFrames > ITEM_KOURA_R_NEAREST_TARGET_FRAMES) {
        if (TrySetItemKouraRNearestKartItems(kouraR, 0) == FALSE) {
            return;
        }
        kouraR->mStateMachine.mNextState = ITEM_KOURA_R_STATE_HOMING;
        kouraR->mStateMachine.mNextStateRequested = 1;
        if (!(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
            return;
        }
        AddItemDataItemIdAndKart(ITEM_OBJECT_KIND_KOURA_R, kouraR->mKartItems->mKartIndex,
                                 kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
    }
}

void EnterItemKouraRFollowLink(void *stateObject) {
    ItemKouraR *kouraR = stateObject;
    kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mBounce =
        (void (*)(ItemObject *, Vec3 *, Vec3 *)) DeflectItemKouraROnHit;
}

void UpdateItemKouraRFollowLink(void *stateObject) {
    ItemKouraR *kouraR = stateObject;
    u16 ownerKartIndex;
    u16 targetKartIndex;
    u16 targetRank;

    ownerKartIndex =
        !(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags &
          ITEM_OWNER_NO_OWNER)
            ? (u16) (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags &
                     ~ITEM_OWNER_FLAGS_MASK)
            : ITEM_NO_KART_INDEX;
    if (ownerKartIndex >= ITEM_NO_KART_INDEX) {
        targetKartIndex = ITEM_NO_KART_INDEX;
    } else {
        targetRank = GetKartRank(ownerKartIndex) - 1;
        if (targetRank < 1) {
            targetRank = gRaceSetup->mKartCount;
        }
        targetKartIndex = GetRaceProgressKartIndexAtRank(targetRank);
    }
    AdvanceLinkFollowingItem(&kouraR->mLinkFollowingItemObject, 0xd000, 0x29, targetKartIndex, 0);
    if (!(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags &
          ITEM_OBJECT_FLAG_FADE_OUT_STARTED)) {
        AddSoundRequest(&gSoundRequestQueues[5],
                        kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags &
                            ~0xc000001f,
                        StartItemKouraRSound, kouraR, 0);
    }
    if (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADE_OUT_STARTED) {
        return;
    }
    if (kouraR->mStateMachine.mStateFrames > ITEM_KOURA_R_FOLLOW_LINK_LIMIT_FRAMES) {
        SetItemObjectDirectionFromVelocity(kouraR);
        kouraR->mStateMachine.mNextState = ITEM_KOURA_R_STATE_STRAIGHT;
        kouraR->mStateMachine.mNextStateRequested = 1;
        return;
    }
    if (kouraR->mStateMachine.mStateFrames > ITEM_KOURA_R_SINGLE_KART_TEST_FRAMES) {
        if (TrySetItemKouraRKartItemsByFrame(kouraR, 1) == 0) {
            return;
        }
        kouraR->mStateMachine.mNextState = ITEM_KOURA_R_STATE_HOMING;
        kouraR->mStateMachine.mNextStateRequested = 1;
        if (!(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
            return;
        }
        AddItemDataItemIdAndKart(ITEM_OBJECT_KIND_KOURA_R, kouraR->mKartItems->mKartIndex,
                                 kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
        return;
    }
    if (kouraR->mStateMachine.mStateFrames > ITEM_KOURA_R_NEAREST_TARGET_FRAMES) {
        if (TrySetItemKouraRNearestKartItems(kouraR, 1) == FALSE) {
            return;
        }
        kouraR->mStateMachine.mNextState = ITEM_KOURA_R_STATE_HOMING;
        kouraR->mStateMachine.mNextStateRequested = 1;
        if (!(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_WIFI_RACE)) {
            return;
        }
        AddItemDataItemIdAndKart(ITEM_OBJECT_KIND_KOURA_R, kouraR->mKartItems->mKartIndex,
                                 kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
    }
}

void EnterItemKouraRSteerToKart(void *stateObject) {
    ItemKouraR *kouraR = stateObject;
    kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mBounce =
        (void (*)(ItemObject *, Vec3 *, Vec3 *)) DeflectItemKouraROnHit;
}

// Homing state: if the kart is removed, parked, a Teresa or dropping to respawn, glide toward the kart's velocity;
// otherwise steer toward the kart, and when the steer call returns non-zero go to the seek-after-throw state. Requests
// the shell sound unless a fade-out has started.
void UpdateItemKouraRSteerToKart(void *stateObject) {
    ItemKouraR *kouraR = stateObject;
    KartItems *kartItems;
    Kart *kart;
    BOOL kartFlagged;
    u32 kartBits;
    s32 value;

    kartItems = kouraR->mKartItems;
    kart = kartItems->mKart;
    kartBits = kart->mEntryFlags;
    kartFlagged = TRUE;
    if ((kartBits & KART_ENTRY_REMOVED_PARKED_OR_TERESA) == 0) {
        if ((kart->mEffectFlags & KART_EFFECT_RESPAWN_DROP) == 0) {
            kartFlagged = FALSE;
        }
    }
    if (kartFlagged != FALSE) {
        AddItemKouraRTowardKartToVelocity(kouraR);
        kouraR->mStateMachine.mNextState = ITEM_KOURA_R_STATE_GLIDE_TO_KART_VELOCITY;
        kouraR->mStateMachine.mNextStateRequested = 1;
    } else {
        value = kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags;
        if (value & ITEM_OBJECT_FLAG_FROM_DATA) {
            if (kartBits & KART_ENTRY_SELECTED) {
                value = SteerItemKouraRToKart(kouraR, 0x5333, 0x19a, 1);
            } else {
                value = SteerItemKouraRToKart(kouraR, 0x4b33, 0x19a, 0);
            }
        } else {
            value = SteerItemKouraRToKart(kouraR, 0x4800, 0x19a, (value & ITEM_OBJECT_FLAG_WIFI_RACE) == 0);
        }
        if (value != 0) {
            AddItemKouraRTowardKartToVelocity(kouraR);
            kouraR->mStateMachine.mNextState = ITEM_KOURA_R_STATE_SEEK_AFTER_THROW;
            kouraR->mStateMachine.mNextStateRequested = 1;
            kouraR->mLinkFollowingItemObject.mPreviousLink.mLink = NULL;
            kouraR->mLinkFollowingItemObject.mPreviousLink.mNextLinksUsed = 1;
        }
    }
    if (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADE_OUT_STARTED) {
        return;
    }
    AddSoundRequest(&gSoundRequestQueues[5],
                    kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags &
                        ~0xc000001f,
                    StartItemKouraRSound, kouraR, 0);
}

// Close-in state: fades the shell out as a hit if IsKartNotNormal, else steers at the kart; requests the shell sound
// unless a fade-out has started; the shell fades out as a hit when it is within the hit radius of the kart in x and z,
// or once mStateFrames passes ITEM_KOURA_R_CLOSE_IN_HIT_FRAMES.
void UpdateItemKouraRCloseIn(void *stateObject) {
    ItemKouraR *kouraR = stateObject;
    KartItems *kartItems;
    Kart *kart;
    s32 deltaZ;
    s32 hitRadius;
    s32 deltaX;

    kartItems = kouraR->mKartItems;
    kart = kartItems->mKart;
    if (IsKartNotNormal(kart) != FALSE) {
        FadeOutItemObjectHitByKart(&kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, 0, 8);
    } else {
        SteerItemKouraRToKart(kouraR, 0x10000, 0x333, 0);
    }
    if ((kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADE_OUT_STARTED) ==
        0) {
        AddSoundRequest(&gSoundRequestQueues[5],
                        kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags &
                            ~0xc000001f,
                        StartItemKouraRSound, kouraR, 0);
    }
    if (kouraR->mStateMachine.mStateFrames <= ITEM_KOURA_R_CLOSE_IN_HIT_FRAMES) {
        hitRadius =
            kart->mRadius + ((kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mRadius * 3) >> 1);
        deltaZ = kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.z - kart->mPointAlongUp.z;
        deltaX = kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.x - kart->mPointAlongUp.x;
        if (SQUARE_SUM2(deltaX, deltaZ) >= (s64) hitRadius * hitRadius) {
            return;
        }
    }
    FadeOutItemObjectHitByKart(&kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, 0, 8);
}

// Advances the shell's motion; unless a fade-out has started, requests the shell sound.
void UpdateItemKouraRGlide(void *stateObject) {
    ItemKouraR *kouraR = stateObject;
    AdvanceItemObjectMotion(&kouraR->mLinkFollowingItemObject.mDirectedItemObject, 0xc000);
    if (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADE_OUT_STARTED) {
        return;
    }
    AddSoundRequest(&gSoundRequestQueues[5],
                    kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags &
                        ~0xc000001f,
                    StartItemKouraRSound, kouraR, 0);
}

// Plays the sound at the kart held in mKartItems when hitType is 1 or 2 and the other object is owned by that kart; an
// object not in use must also be active, flagged ITEM_OWNER_KART_TARGETED_BY_KOURA_R and younger than
// ITEM_KOURA_R_TARGET_SOUND_AGE_FRAMES.
void StartTargetKartSoundOnOwnItemHit(void *kouraParam, s32 hitType, ItemObject *otherParam) {
    ItemKouraR *kouraR;
    ItemObject *other;
    KartItems *kartItems;
    Kart *kart;
    u16 otherOwnerIndex;
    u32 otherFlags;

    kouraR = kouraParam;
    other = otherParam;
    if ((u32) (hitType - ITEM_HIT_TYPE_BOUNCE) > ITEM_HIT_TYPE_FADE_OUT - ITEM_HIT_TYPE_BOUNCE) {
        return;
    }
    kartItems = kouraR->mKartItems;
    otherOwnerIndex = !(other->mOwnerKartIndexAndFlags & ITEM_OWNER_NO_OWNER)
                          ? (u16) (other->mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK)
                          : ITEM_NO_KART_INDEX;
    if (kartItems == NULL) {
        return;
    }
    kart = kartItems->mKart;
    if (otherOwnerIndex != kart->mIndex) {
        return;
    }
    otherFlags = other->mFlags;
    if ((otherFlags & ITEM_OBJECT_FLAG_IN_USE) == 0) {
        if ((otherFlags & ITEM_OBJECT_FLAG_ACTIVE) == 0) {
            return;
        }
        if ((other->mOwnerKartIndexAndFlags & ITEM_OWNER_KART_TARGETED_BY_KOURA_R) == 0) {
            return;
        }
        if (other->mAgeFrames >= ITEM_KOURA_R_TARGET_SOUND_AGE_FRAMES) {
            return;
        }
    }
    StartKartSeqArcSoundOffset8(kart, kart->mSoundIndex);
}

// Copies the shell's item data to or from the buffer: the object data and previous link index, plus two flag bits
// carried in velocity.y (mReverse) and pos.y (mThrowForward); when writing it also adds the item data record for the
// kind and returns its buffer.
void *CopyItemKouraRData(void *buffer, ItemKouraR *kouraR, void *toBuffer) {
    s32 dot;
    void *result;

    if (kouraR != NULL && toBuffer != NULL) {
        dot = Vec3DotUnrounded(&kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity,
                               &kouraR->mLinkFollowingItemObject.mDirectedItemObject.mDirection);
        StoreItemDataFlagBit(dot < 0, &kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.y);
        StoreItemDataFlagBit(kouraR->mThrowForward,
                             &kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.y);
    }
    result = CopyItemObjectData(buffer, kouraR, toBuffer);
    result =
        CopyItemPointLinkIndex(result, kouraR != NULL ? &kouraR->mLinkFollowingItemObject.mPreviousLink : 0, toBuffer);
    if (kouraR != NULL && toBuffer == NULL) {
        LoadItemDataFlagBit(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.y,
                            &kouraR->mReverse);
        LoadItemDataFlagBit(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.y,
                            &kouraR->mThrowForward);
    }
    if (kouraR != NULL && toBuffer != NULL) {
        return AddItemDataSizedByKind(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mKind);
    }
    return result;
}

// Sets the shell up from received item data: resets the sound change, sets the sound track function, starts the state
// machine with gItemKouraRStateTable, then picks the follow-link, seek-after-throw or straight state from mThrowForward
// and the previous link.
void InitItemKouraRFromData(ItemKouraR *kouraR) {
    u16 ownerKartIndex;
    u32 rank;
    u16 targetKartIndex;
    u16 rankAhead;

    SetupItemObjectFromData(&kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    ResetSoundDistanceSquaredChange(&kouraR->mSoundDistanceSquaredChange);
    kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource.mTrackParamsFunction =
        (void (*)(void *, void *, void *)) SetItemKouraSoundTrackParams;
    InitStateMachine(&kouraR->mStateMachine, gItemKouraRStateTable, 7, kouraR);
    if (kouraR->mThrowForward != 0) {
        if (kouraR->mLinkFollowingItemObject.mPreviousLink.mLink != NULL) {
            kouraR->mStateMachine.mNextState = ITEM_KOURA_R_STATE_FOLLOW_LINK;
            kouraR->mStateMachine.mNextStateRequested = 1;
            ownerKartIndex =
                !(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags &
                  ITEM_OWNER_NO_OWNER)
                    ? (u16) (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags &
                             ~ITEM_OWNER_FLAGS_MASK)
                    : ITEM_NO_KART_INDEX;
            if (ownerKartIndex >= ITEM_NO_KART_INDEX) {
                targetKartIndex = ITEM_NO_KART_INDEX;
            } else {
                rank = GetKartRank(ownerKartIndex);
                rankAhead = rank - 1;
                if (rankAhead < 1) {
                    rankAhead = gRaceSetup->mKartCount;
                }
                targetKartIndex = gRaceProgress->mKartAtRank[(rankAhead & 0xff) - 1];
            }
            InitLinkFollowingItem(&kouraR->mLinkFollowingItemObject, 0x2d, 0x5b, 0, 1, kouraR->mReverse,
                                  targetKartIndex, 0);
        } else {
            kouraR->mStateMachine.mNextState = ITEM_KOURA_R_STATE_SEEK_AFTER_THROW;
            kouraR->mStateMachine.mNextStateRequested = 1;
            InitItemObjectMotion(kouraR, 0, kouraR->mReverse, 0);
        }
        kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags |= ITEM_OBJECT_FLAG_HITS_FAR_KARTS;
    } else {
        kouraR->mStateMachine.mNextState = ITEM_KOURA_R_STATE_STRAIGHT;
        kouraR->mStateMachine.mNextStateRequested = 1;
        InitItemObjectMotion(kouraR, 0, kouraR->mReverse, 0);
    }
    ResetItemKouraRKartItems(kouraR);
}

// Returns TRUE when the shell is already within hit range of the kart or has no collision slot; otherwise frees the
// slot, requests CloseIn and returns FALSE.
BOOL RequestItemKouraRCloseInIfFar(void *kouraParam, s32 kartIndex) {
    ItemKouraR *kouraR;
    Kart *kart;
    s32 deltaZ;
    s32 hitRadius;
    s32 deltaX;

    kouraR = kouraParam;
    kart = GetKart(kartIndex);
    hitRadius = kart->mRadius + ((kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mRadius * 3) >> 1);
    deltaZ = kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.z - kart->mPointAlongUp.z;
    deltaX = kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.x - kart->mPointAlongUp.x;
    if (SQUARE_SUM2(deltaX, deltaZ) < (s64) hitRadius * hitRadius) {
        return TRUE;
    }
    if (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCollisionSlotIndex == -1) {
        return TRUE;
    }
    FreeItemObjectCollisionSlot(&kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    kouraR->mStateMachine.mNextState = ITEM_KOURA_R_STATE_CLOSE_IN;
    kouraR->mStateMachine.mNextStateRequested = 1;
    SetItemKouraRKartItems(kouraR, kartIndex);
    return FALSE;
}
