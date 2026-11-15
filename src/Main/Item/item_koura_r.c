#include "Main/Item/item_kinoko.h"
#include "Main/Sound/sound_start.h"
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
#include "code_02147cd8.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/MapObjects/view_matrix_queue.h"
#include "Main/Course/course_color_blend.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/item_object_reset_collide.h"
#include "Main/Item/held_item.h"
#include "Main/Item/pooled_item_box.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Sound/kart_sound_callbacks.h"
#include "Main/Sound/kart_surface_sound.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Item/item_object_throw.h"
#include "Main/Item/item_koura_r_kart_items.h"
#include "Main/Item/item_object_bouncing.h"
#include "Main/Sound/sound_distance_change_reset.h"
#include "Main/System/state_machine_init.h"
#include "Main/Item/item_link_following.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/rock.h"
#include "Main/Race/race.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "code_0212d214.h"
#include "Main/MapObjects/koopa_block_hit_link.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "player.h"
#include "code_021479b4.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/menu_screens_work.h"
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
#include "ITCM/collision_slots.h"
#include "Main/Item/item_koura_r.h"
#include "Main/System/init_after_startup.h"

const u16 gItemBananaUntilCourseHitBit = ITEM_OWNER_EXCLUDED_UNTIL_COURSE_HIT;

StateCallbacks gItemKouraRStateTable[7] = {{NULL, UpdateItemKouraRStraight},
                                           {NULL, UpdateItemKouraRStraight},
                                           {NULL, UpdateItemKouraRSeekAfterThrow},
                                           {EnterItemKouraRFollowLink, UpdateItemKouraRFollowLink},
                                           {EnterItemKouraRHoming, UpdateItemKouraRHoming},
                                           {NULL, UpdateItemKouraRCloseIn},
                                           {NULL, UpdateItemKouraRGlideToKartVelocity}};

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
    StartSoundWhileRequested(&kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource, 0xd8, 0x7f,
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
                targetKartIndex = GetKartAtRank(rankAhead);
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
        kouraR->mStateMachine.mNextState = ITEM_KOURA_R_STATE_STRAIGHT_FLAGGED;
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

void RequestItemKouraRHomingForKart(ItemKouraR *kouraR, u32 kartIndex) {
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
    u16 rankAhead;

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
        targetKartIndex = GetKartAtRank(rankAhead);
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

void EnterItemKouraRHoming(void *stateObject) {
    ItemKouraR *kouraR = stateObject;
    kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mBounce =
        (void (*)(ItemObject *, Vec3 *, Vec3 *)) DeflectItemKouraROnHit;
}

// Runs the two 0x7c/0x4c checks of the object in the 0x1fc word of the 0x1c pointer, then
// one of the four SteerItemKouraRToKart calls, and stores the 0x24c/0x24e halfwords it picks.
void UpdateItemKouraRHoming(void *stateObject) {
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

// Checks IsKartNotNormal of the Kart, then the 0x240 counter and the sum of the two
// squares of the 0x50/0x54/0x58 differences against the 0x1d0/0x1d4/0x1e0 square.
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

// Runs AdvanceItemObjectMotion and hands StartItemKouraRSound to AddSoundRequest when the 0x74 bit 0 is clear.
void UpdateItemKouraRGlideToKartVelocity(void *stateObject) {
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

// Runs StartKartSeqArcSoundOffset8 with the 0x3bc word of the 0x1fc object when the 0x78 high bits of the
// third parameter match that object's 0x74 halfword and the 0x74/0x78/0xdc tests pass.
void StartTargetKartSoundOnOwnItemHit(void *kouraParam, s32 hitType, ItemObject *otherParam) {
    ItemKouraR *kouraR;
    ItemObject *other;
    KartItems *kartItems;
    Kart *kart;
    u16 otherOwnerIndex;
    u32 otherFlags;

    kouraR = kouraParam;
    other = otherParam;
    if ((u32) (hitType - 1) > 1) {
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
        if ((other->mOwnerKartIndexAndFlags & ITEM_OWNER_KOURA_R_TARGETED) == 0) {
            return;
        }
        if (other->mAgeFrames >= ITEM_KOURA_R_TARGET_SOUND_AGE_FRAMES) {
            return;
        }
    }
    StartKartSeqArcSoundOffset8(kart, kart->mSoundIndex);
}

// Hands the 0x44 word and the 0x5c/0x130/0x250/0x254/0x60/0x54 addresses of b to
// CopyItemObjectData, CopyItemPointLinkIndex, StoreItemDataFlagBit, LoadItemDataFlagBit and AddItemDataSizedByKind.
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

// Stores SetItemKouraSoundTrackParams in the 0x30 word, moves the seven words of gItemKouraRStateTable to 0x23c,
// then picks one of three calls from the 0x254/0x21c words.
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

// Returns 1 while GetKart(b) is within the 0x1d0/0x1d4 radius of the 0x50/0x54/0x58
// words, or when the 0xda halfword is -1; otherwise sets the 0x24c/0x24e halfwords, returns 0.
// Returns FALSE when it requested CloseIn because the shell is not yet at the kart.
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
