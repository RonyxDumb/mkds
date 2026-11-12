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
#include "ITCM/collision_slots.h"
#include "Main/Item/code_020f5ffc.h"

const ItemInfo gItemInfoKouraG = {1, 1, 0, 1, 0, 1, NULL};
const ItemInfo gItemInfoKouraRThree = {1, 0, 1, 3, 0, 4, NULL};

const ItemKind gItemKindKouraG = {
    0x188, 8, 0x20, -1, -1, {0}, NULL, NULL, NULL, (s32 (*)(void *, void *)) InitItemKouraG, (void (*)(ItemObject *)) AdvanceItemKouraG, NULL, ComputeViewTest, NULL, NULL, NULL,
    0, 0, (void *(*)(void *, void *, s32)) CopyItemKouraGData, 0, (void (*)(void *)) InitItemKouraGFromData, 0, 0, 0x4b0000, 2, 0x319a, 0x6000, 0x2e66, 0x1000, 0x1ccd, 0x29, 0xa4,
    1, 1, 1, {0}, 3, 0xd6, 0xd9, 1, 1, 0};

void StartItemKouraGSound(void *kouraParam, s32 unused) {
    ItemKouraG *koura;

    koura = kouraParam;
    if (!(koura->mDirectedItemObject.mItemObject.mFlags & 0x400000)) {
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
    if (koura->mDirectedItemObject.mItemObject.mAgeFrames > 0x258) {
        koura->mDirectedItemObject.mHitsRemaining = 0;
    }
    AdvanceItemObjectMotion(&koura->mDirectedItemObject, 0x84cd);
    if (koura->mDirectedItemObject.mItemObject.mFlags & 1) {
        return;
    }
    AddSoundRequest(&gKouraSoundRequestQueue,
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
