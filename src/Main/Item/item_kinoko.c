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
#include "Main/Item/code_020f4dfc.h"
#include "Main/Item/code_020f50b4.h"
#include "Main/Item/code_020f5324.h"
#include "Main/Item/code_020f5ffc.h"
#include "Main/Item/code_020f6264.h"
#include "Main/Item/code_020f62b0.h"
#include "Main/Item/item_kinoko_p_boost.h"

Vec3 *gItemPushVector;

const ItemInfo gItemInfoKinokoThree = {1, 1, 3, 3, 0, 0, StartItemKinokoBoost};
const ItemInfo gItemInfoBananaThree = {1, 0, 2, 3, 0, 3, NULL};

#pragma thumb on

// Fills a table of eighteen 0x1c-byte objects allocated here.
void CreateItemInfos(void) {
    ItemInfo *infos;
    s32 infoIndex;

    infos = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x1f8);
    gItemInfos = infos;
    infos[0] = gItemInfoKouraG;
    infos[1] = gItemInfoKouraR;
    infos[2] = gItemInfoBanana;
    infos[3] = data_02159f68;
    infos[4] = gItemInfoKinoko;
    infos[5] = gItemInfoKinokoThree;
    infos[6] = data_02159e54;
    infos[7] = data_02159cc0;
    infos[8] = gItemInfoThunder;
    infos[9] = data_02159f4c;
    infos[10] = gItemInfoBananaThree;
    infos[11] = gItemInfoKouraRThree;
    infos[12] = gItemInfoStar;
    infos[13] = data_02159d90;
    infos[14] = gItemInfoKiller;
    infos[15] = data_0215a2ec;
    infos[16] = gItemInfoTeresa;
    infos[17] = data_0215a4c0;
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            infos[17].mEnabled = TRUE;
            break;
        case MODE_WIFI:
            for (infoIndex = 0; infoIndex < 0x12; infoIndex++) {
                if (GetItemInfo(infoIndex)->mEnabled != FALSE && GetItemInfo(infoIndex)->mEnabledInWiFi == 0) {
                    gItemInfos[infoIndex].mEnabled = FALSE;
                }
            }
            break;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        gItemInfos[15].mEnabled = FALSE;
    }
}

#pragma thumb off

void InitHeldItem(HeldItem *heldItem, KartItems *kartItems) {
    s32 slotIndex;

    heldItem->mKartItems = kartItems;
    heldItem->mItemInfoIndex = 0x13;
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
    enum { K0 } kind;

    if (heldItem->mObjectStartFramesLeft <= 0) {
        return;
    }
    heldItem->mObjectStartFramesLeft--;
    if (heldItem->mObjectStartFramesLeft != 7 && heldItem->mObjectStartFramesLeft != 5 &&
        heldItem->mObjectStartFramesLeft != 3) {
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
    heldItem->mItemInfoIndex = 0x13;
    heldItem->mObjectCount = 0;
    heldItem->mObjectStartFramesLeft = 0;
    heldItem->mUsesTimer = 0;
    heldItem->mTimer = 0;
    heldItem->mUseTimerLimit = 0;
    for (slotIndex = 0; slotIndex < 3; slotIndex++) {
        heldItem->mObjects[slotIndex] = NULL;
    }
}
