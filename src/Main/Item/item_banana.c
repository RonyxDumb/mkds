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
#include "sound_archive_load.h"
#include "Main/MapObjects/koopa_block_hit_link.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "sound_archive_load_result.h"
#include "Main/Race/race_clock.h"
#include "Main/Kart/karts.h"
#include "Main/Item/item_teresa_offset.h"
#include "ITCM/collision_slots.h"
#include "Main/Item/item_banana.h"
#include "Main/Item/item_koura_r.h"

const Vec3 gItemKinokoVec3UnitY = {0, 0x1000, 0};

const ItemInfo gItemInfoBanana = {1, 1, 2, 1, 0, 1, NULL};

const ItemKind gItemKindBanana = {0x134,
                                  0xc,
                                  0x20,
                                  -1,
                                  -1,
                                  {0},
                                  NULL,
                                  NULL,
                                  NULL,
                                  (s32(*)(void *, void *)) InitItemBanana,
                                  (void (*)(ItemObject *)) AdvanceItemBanana,
                                  NULL,
                                  ComputeViewTest,
                                  NULL,
                                  NULL,
                                  NULL,
                                  0,
                                  0,
                                  (void *(*) (void *, void *, s32)) CopyItemBananaData,
                                  0,
                                  (void (*)(void *)) InitItemBananaFromData,
                                  0,
                                  0,
                                  0x4b0000,
                                  2,
                                  0x319a,
                                  0x5000,
                                  0x2e66,
                                  0x14cd,
                                  0x2000,
                                  0x19a,
                                  0x19a,
                                  1,
                                  1,
                                  1,
                                  {0},
                                  1,
                                  1,
                                  1,
                                  0xdb,
                                  1,
                                  0};

// Runs StartItemObjectSoundSource, ors gItemBananaUntilCourseHitBit into the 0x78 halfword, then makes one of two
// ThrowBouncingItem calls depending on the 0x1ec halfword of the 0x0c pointer, and returns the
// 0x130 word it stores.
s32 InitItemBanana(ItemInUse *itemInUse, ItemBanana *banana) {
    KartItems *kartItems;
    s32 unused;

    StartItemObjectSoundSource(&banana->mBouncingItemObject.mItemObject);
    banana->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags |= gItemBananaUntilCourseHitBit;
    kartItems = itemInUse->mKartItems;
    if (kartItems->mFlags & KART_ITEMS_THROW_FORWARD) {
        ThrowBouncingItem(&banana->mBouncingItemObject, itemInUse, 0, 1, 0x4000, 0x3000, 0x59a);
        StartSound(&banana->mBouncingItemObject.mItemObject.mSoundSource, 0xda, 0x7f, 0);
        banana->mThrowForward = 1;
        return banana->mThrowForward;
    }
    ThrowBouncingItem(&banana->mBouncingItemObject, itemInUse, 0, 0, 0x4000, 0x3000, 0x59a);
    banana->mThrowForward = 0;
    return banana->mThrowForward;
}

// Calls AdvanceBouncingItem with one of two pairs of numbers, and when the 0x74 bits allow it
// doubles the 0x60 word and runs StopSound and StartRestingItemObject.
void AdvanceItemBanana(ItemBanana *banana) {
    u32 collisionHitLink;
    u32 flags;

    if (banana->mThrowForward != 0) {
        AdvanceBouncingItem(&banana->mBouncingItemObject, 0x1ec, 0xfec, 0, &collisionHitLink);
    } else {
        AdvanceBouncingItem(&banana->mBouncingItemObject, 0x2e1, 0xf85, 0, &collisionHitLink);
    }
    flags = banana->mBouncingItemObject.mItemObject.mFlags;
    if ((flags & ITEM_OBJECT_FLAG_LANDED) == 0) {
        return;
    }
    if (flags & (ITEM_OBJECT_FLAG_FADE_OUT_STARTED | ITEM_OBJECT_FLAG_RELEASE_STARTED)) {
        return;
    }
    if (banana->mThrowForward != 0) {
        banana->mBouncingItemObject.mItemObject.mVelocity.y = banana->mBouncingItemObject.mItemObject.mVelocity.y * 2;
    }
    StopSound(&banana->mBouncingItemObject.mItemObject.mSoundSource, 0xda);
    StartRestingItemObject(&banana->mBouncingItemObject.mItemObject, &collisionHitLink);
}

// Hands the 0x130 word and the 0x60 word to StoreItemDataFlagBit/LoadItemDataFlagBit around the
// CopyItemObjectData call, and returns AddItemDataSizedByKind's value when b and c are both set.
void *CopyItemBananaData(void *buffer, ItemBanana *banana, void *toBuffer) {
    void *result;

    if (banana != NULL && toBuffer != NULL) {
        StoreItemDataFlagBit(banana->mThrowForward, &banana->mBouncingItemObject.mItemObject.mVelocity.y);
    }
    result = CopyItemObjectData(buffer, banana, toBuffer);
    if (banana != NULL && toBuffer == NULL) {
        LoadItemDataFlagBit(banana->mBouncingItemObject.mItemObject.mVelocity.y, &banana->mThrowForward);
    }
    if (banana != NULL && toBuffer != NULL) {
        return AddItemDataSizedByKind(banana->mBouncingItemObject.mItemObject.mKind);
    }
    return result;
}

// Runs SetupItemObjectFromData and StartItemObjectBouncing, then StartSound when the two 0x74/0x130 tests pass.
void InitItemBananaFromData(ItemBanana *banana) {
    SetupItemObjectFromData(&banana->mBouncingItemObject.mItemObject);
    StartItemObjectBouncing(&banana->mBouncingItemObject, 0);
    if ((banana->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FROM_DATA) == 0) {
        return;
    }
    if (banana->mThrowForward == 0) {
        return;
    }
    StartSound(&banana->mBouncingItemObject.mItemObject.mSoundSource, 0xda, 0x7f, 0);
}
