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
#include "Main/Item/item_kinoko_kind.h"
#include "Main/Item/item_banana.h"
#include "Main/Item/item_koura_r.h"
#include "Main/Item/item_koura_g.h"
#include "Main/Item/item_star.h"
#include "Main/Item/item_thunder.h"
#include "Main/Item/item_kinoko_p_boost.h"
#include "Main/Item/item_koura_w_kart_items.h"
#include "Main/Item/item_gesso.h"
#include "Main/Item/bouncing_item_box_kind.h"

ItemInfo *gItemInfos;
Vec3 *gItemPushVector;

const ItemInfo gItemInfoBananaThree = {1, 0, ITEM_OBJECT_KIND_BANANA, 3, 0, ITEM_USE_KIND_TRAIL, NULL};
const ItemInfo gItemInfoKinokoThree = {
    1, 1, ITEM_OBJECT_KIND_KINOKO, 3, 0, ITEM_USE_KIND_HOOK_ONLY, StartItemKinokoBoost};

#pragma thumb on

// Allocates gItemInfos, copies the eighteen gItemInfo records into it and sets mEnabled for the battle, Wi-Fi and
// demo-race cases.
void CreateItemInfos(void) {
    ItemInfo *infos;
    s32 infoIndex;

    infos = HeapAlloc(GetHeap(GetCurrentHeapCall()), ITEM_INFO_COUNT * sizeof(*infos));
    gItemInfos = infos;
    infos[ITEM_INFO_KOURA_G] = gItemInfoKouraG;
    infos[ITEM_INFO_KOURA_R] = gItemInfoKouraR;
    infos[ITEM_INFO_BANANA] = gItemInfoBanana;
    infos[ITEM_INFO_F_BOX] = gItemInfoFBox;
    infos[ITEM_INFO_KINOKO] = gItemInfoKinoko;
    infos[ITEM_INFO_KINOKO_THREE] = gItemInfoKinokoThree;
    infos[ITEM_INFO_BOMB] = gItemInfoBomb;
    infos[ITEM_INFO_KOURA_W] = gItemInfoKouraW;
    infos[ITEM_INFO_THUNDER] = gItemInfoThunder;
    infos[ITEM_INFO_KOURA_G_THREE] = gItemInfoKouraGThree;
    infos[ITEM_INFO_BANANA_THREE] = gItemInfoBananaThree;
    infos[ITEM_INFO_KOURA_R_THREE] = gItemInfoKouraRThree;
    infos[ITEM_INFO_STAR] = gItemInfoStar;
    infos[ITEM_INFO_KINOKO_P] = gItemInfoKinokoP;
    infos[ITEM_INFO_KILLER] = gItemInfoKiller;
    infos[ITEM_INFO_GESSO] = gItemInfoGesso;
    infos[ITEM_INFO_TERESA] = gItemInfoTeresa;
    infos[ITEM_INFO_BOUNCING_ITEM_BOX] = gItemInfoBouncingItemBox;
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            infos[ITEM_INFO_BOUNCING_ITEM_BOX].mEnabled = TRUE;
            break;
        case MODE_WIFI:
            for (infoIndex = 0; infoIndex < ITEM_INFO_COUNT; infoIndex++) {
                if (GetItemInfo(infoIndex)->mEnabled != FALSE && GetItemInfo(infoIndex)->mEnabledInWiFi == 0) {
                    gItemInfos[infoIndex].mEnabled = FALSE;
                }
            }
            break;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        gItemInfos[ITEM_INFO_GESSO].mEnabled = FALSE;
    }
}

#pragma thumb off

void InitHeldItem(HeldItem *heldItem, KartItems *kartItems) {
    s32 slotIndex;

    heldItem->mKartItems = kartItems;
    heldItem->mItemInfoIndex = ITEM_INFO_NONE;
    heldItem->mObjectCount = 0;
    heldItem->mObjectStartFramesLeft = 0;
    heldItem->mUsesTimer = 0;
    heldItem->mTimer = 0;
    heldItem->mUseTimerLimit = 0;
    for (slotIndex = 0; slotIndex < 3; slotIndex++) {
        heldItem->mObjects[slotIndex] = NULL;
    }
    heldItem->mIsPeerEntry = gRaceSetup->mCurrentEntries[kartItems->mKartIndex].mPlayer.mKind == PLAYER_KIND_PEER;
}

// Starts one held object at counts 7, 5 and 3 of the countdown that StartHeldItemObjects sets.
void StartNextHeldItemObject(HeldItem *heldItem) {
    ItemObject *item;
    Kart *kart;
    Vec3 *kartDrawPos;
    Vec3 *kartVelocity;
    void (*kindCallback)(void *);
    s32 slotIndex;
    enum { KIND_FIRST } kind;

    if (heldItem->mObjectStartFramesLeft <= 0) {
        return;
    }
    heldItem->mObjectStartFramesLeft--;
    if (heldItem->mObjectStartFramesLeft != HELD_ITEM_FIRST_LAUNCH_FRAME &&
        heldItem->mObjectStartFramesLeft != HELD_ITEM_SECOND_LAUNCH_FRAME &&
        heldItem->mObjectStartFramesLeft != HELD_ITEM_THIRD_LAUNCH_FRAME) {
        return;
    }
    kart = heldItem->mKartItems->mKart;
    heldItem->mObjectCount--;
    item = heldItem->mObjects[heldItem->mObjectCount];
    kartDrawPos = &kart->mDrawMatrixPos;
    kartVelocity = &kart->mVelocity;
    StartItemObject(gItemPools + item->mKind, item);
    CopyKartPlacementToItemObject(heldItem->mKartItems, item);
    VEC_MultAdd(0xb33, kartVelocity, &item->mVelocity, &item->mVelocity);
    item->mPos = *kartDrawPos;
    LaunchItemObjectFromPos(item, 0, kartDrawPos, kartVelocity, &kart->mGroundNormal);
    kind = item->mKind;
    kindCallback = gItemKinds[kind].mAfterLaunchCallback;
    if (kindCallback != NULL) {
        kindCallback(item);
    }
    if (heldItem->mObjectCount != 0) {
        return;
    }
    heldItem->mItemInfoIndex = ITEM_INFO_NONE;
    heldItem->mObjectCount = 0;
    heldItem->mObjectStartFramesLeft = 0;
    heldItem->mUsesTimer = 0;
    heldItem->mTimer = 0;
    heldItem->mUseTimerLimit = 0;
    for (slotIndex = 0; slotIndex < 3; slotIndex++) {
        heldItem->mObjects[slotIndex] = NULL;
    }
}
