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
#include "Main/Item/item_koura_g.h"

const ItemInfo gItemInfoKouraG = {1, 1, 0, 1, 0, 1, NULL};
const ItemInfo gItemInfoKouraRThree = {1, 0, 1, 3, 0, 4, NULL};

const ItemKind gItemKindKouraG = {0x188,
                                  8,
                                  0x20,
                                  -1,
                                  -1,
                                  {0},
                                  NULL,
                                  NULL,
                                  NULL,
                                  (s32(*)(void *, void *)) InitItemKouraG,
                                  (void (*)(ItemObject *)) AdvanceItemKouraG,
                                  NULL,
                                  ComputeViewTest,
                                  NULL,
                                  NULL,
                                  NULL,
                                  0,
                                  0,
                                  (void *(*) (void *, void *, s32)) CopyItemKouraGData,
                                  0,
                                  (void (*)(void *)) InitItemKouraGFromData,
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

void StartItemKouraGSound(void *kouraParam, s32 unused) {
    ItemKouraG *koura;

    koura = kouraParam;
    if (!(koura->mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_HAS_SOUND_SOURCE)) {
        return;
    }
    AdvanceSoundDistanceSquaredChange(&koura->mSoundDistanceSquaredChange,
                                      koura->mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f);
    StartSoundWhileRequested(&koura->mDirectedItemObject.mItemObject.mSoundSource, 0xd7, 0x7f, 0);
}

BOOL InitItemKouraG(ItemInUse *itemInUse, ItemKouraG *koura) {
    BOOL isBattle;

    isBattle = gRaceSetup->mMode == MODE_BATTLE;
    StartItemObjectSoundSource(&koura->mDirectedItemObject.mItemObject);
    ResetSoundDistanceSquaredChange(&koura->mSoundDistanceSquaredChange);
    koura->mDirectedItemObject.mItemObject.mSoundSource.mTrackParamsFunction =
        (void (*)(void *, void *, void *)) SetItemKouraSoundTrackParams;
    if (itemInUse->mKartItems->mFlags & KART_ITEMS_DOWN) {
        InitItemObjectThrow(koura, itemInUse, isBattle != FALSE ? 2 : 4, 0, 0, 0x5000);
        return FALSE;
    }
    InitItemObjectThrow(koura, itemInUse, isBattle != FALSE ? 5 : 9, 1, 0, 0x5000);
    return TRUE;
}

void AdvanceItemKouraG(ItemKouraG *koura) {
    if (koura->mDirectedItemObject.mItemObject.mAgeFrames > ITEM_KOURA_G_LIFETIME_FRAMES) {
        koura->mDirectedItemObject.mHitsRemaining = 0;
    }
    AdvanceItemObjectMotion(&koura->mDirectedItemObject, 0x84cd);
    if (koura->mDirectedItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FADE_OUT_STARTED) {
        return;
    }
    AddSoundRequest(&gSoundRequestQueues[5],
                    (koura->mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f) + 0x9c40,
                    StartItemKouraGSound, koura, 0);
}

void *CopyItemKouraGData(void *buffer, ItemKouraG *koura, void *toBuffer) {
    void *result;

    if (koura != NULL && toBuffer != NULL) {
        StoreItemDataFlagBit(Vec3DotUnrounded(&koura->mDirectedItemObject.mItemObject.mVelocity,
                                              &koura->mDirectedItemObject.mDirection) < 0,
                             &koura->mDirectedItemObject.mItemObject.mVelocity.y);
    }
    result = CopyItemObjectData(buffer, koura, toBuffer);
    if (koura != NULL && toBuffer == NULL) {
        LoadItemDataFlagBit(koura->mDirectedItemObject.mItemObject.mVelocity.y, &koura->mReverse);
    }
    if (koura != NULL && toBuffer != NULL) {
        return AddItemDataSizedByKind(koura->mDirectedItemObject.mItemObject.mKind);
    }
    return result;
}

void InitItemKouraGFromData(ItemKouraG *koura) {
    SetupItemObjectFromData(&koura->mDirectedItemObject.mItemObject);
    ResetSoundDistanceSquaredChange(&koura->mSoundDistanceSquaredChange);
    koura->mDirectedItemObject.mItemObject.mSoundSource.mTrackParamsFunction =
        (void (*)(void *, void *, void *)) SetItemKouraSoundTrackParams;
    InitItemObjectMotion(koura, 9, koura->mReverse, 0);
}
