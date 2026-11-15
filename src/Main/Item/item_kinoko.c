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
#include "vector_math.h"
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
#include "sound_archive_load.h"
#include "Main/MapObjects/koopa_block_hit_link.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "player.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_type.h"
#include "stream.h"
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

const ItemInfo gItemInfoBananaThree = {1, 0, 2, 3, 0, 3, NULL};
const ItemInfo gItemInfoKinokoThree = {1, 1, 3, 3, 0, 0, StartItemKinokoBoost};

#pragma thumb on

// Fills a table of eighteen 0x1c-byte objects allocated here.
void CreateItemInfos(void) {
    ItemInfo *infos;
    s32 infoIndex;

    infos = HeapAlloc(GetHeap(GetCurrentHeapCall()), ITEM_INFO_COUNT * sizeof(*infos));
    gItemInfos = infos;
    infos[0] = gItemInfoKouraG;
    infos[1] = gItemInfoKouraR;
    infos[2] = gItemInfoBanana;
    infos[3] = gItemInfoFBox;
    infos[4] = gItemInfoKinoko;
    infos[5] = gItemInfoKinokoThree;
    infos[6] = gItemInfoBomb;
    infos[7] = gItemInfoKouraW;
    infos[8] = gItemInfoThunder;
    infos[9] = gItemInfoKouraGThree;
    infos[10] = gItemInfoBananaThree;
    infos[11] = gItemInfoKouraRThree;
    infos[12] = gItemInfoStar;
    infos[13] = gItemInfoKinokoP;
    infos[14] = gItemInfoKiller;
    infos[15] = gItemInfoGesso;
    infos[16] = gItemInfoTeresa;
    infos[17] = gItemInfoBouncingItemBox;
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            infos[17].mEnabled = TRUE;
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
