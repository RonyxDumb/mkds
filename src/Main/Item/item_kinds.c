#include "Main/Item/item_kinds.h"
#include "Main/System/heap.h"

#include "Main/System/heap_call.h"
#include "Main/Item/item_kind_copy_size.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Item/pooled_item_box.h"
#include "Main/Item/item_kinoko_kind.h"
#include "Main/Item/item_banana.h"
#include "Main/Item/item_koura_r.h"
#include "Main/Item/item_koura_g.h"
#include "Main/Item/item_star.h"
#include "Main/Item/item_thunder.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/item_kinoko_p_boost.h"
#include "Main/Item/item_koura_w_kart_items.h"
#include "Main/Item/item_teresa_offset.h"
#include "Main/Item/item_gesso.h"
#include "Main/Item/item_f_box.h"
#include "Main/Item/bouncing_item_box_kind.h"

#pragma thumb on

void CreateItemKinds(void) {
    ItemKind *kinds;
    enum { KIND_INDEX_FIRST } kindIndex;
    enum { LIMIT_KIND_INDEX_FIRST } limitKindIndex;
    s32 mode;
    u32 value;
    u32 (*getFar)(void);

    kinds = HeapAlloc(GetHeap(GetCurrentHeapCall()), ITEM_OBJECT_KIND_COUNT * sizeof(*kinds));
    gItemKinds = kinds;
    kinds[ITEM_OBJECT_KIND_KOURA_G] = gItemKindKouraG;
    kinds[ITEM_OBJECT_KIND_KOURA_R] = gItemKindKouraR;
    kinds[ITEM_OBJECT_KIND_BANANA] = gItemKindBanana;
    kinds[ITEM_OBJECT_KIND_KINOKO] = gItemKindKinoko;
    kinds[ITEM_OBJECT_KIND_STAR] = gItemKindStar;
    kinds[ITEM_OBJECT_KIND_KOURA_W] = gItemKindKouraW;
    kinds[ITEM_OBJECT_KIND_THUNDER] = gItemKindThunder;
    kinds[ITEM_OBJECT_KIND_F_BOX] = gItemKindFBox;
    kinds[ITEM_OBJECT_KIND_BOUNCING_ITEM_BOX] = gItemKindBouncingItemBox;
    kinds[ITEM_OBJECT_KIND_BOMB] = gItemKindBomb;
    kinds[ITEM_OBJECT_KIND_GESSO] = gItemKindGesso;
    kinds[ITEM_OBJECT_KIND_TERESA] = gItemKindTeresa;
    kinds[ITEM_OBJECT_KIND_KINOKO_P] = gItemKindKinokoP;
    kinds[ITEM_OBJECT_KIND_KILLER] = gItemKindKiller;
    for (kindIndex = 0; kindIndex < ITEM_OBJECT_KIND_COUNT; kindIndex++) {
        gItemKinds[kindIndex].mDataSize = GetItemKindCopyDataSize(kindIndex);
        getFar = gItemKinds[kindIndex].mGetFarDistanceSquared;
        if (getFar != NULL) {
            value = getFar();
        } else {
            value = gSoundFalloffs[1].mFarDistanceSquared;
        }
        gItemKinds[kindIndex].mFarDistanceSquared = value;
    }
    mode = gRaceSetup->mMode;
    switch (mode) {
        case MODE_BATTLE:
            gItemKinds[ITEM_OBJECT_KIND_BOUNCING_ITEM_BOX].mLimit = ITEM_BATTLE_BOUNCING_ITEM_BOX_LIMIT;
            break;
        case MODE_MISSION_RUN:
            for (limitKindIndex = 0; limitKindIndex < ITEM_OBJECT_KIND_COUNT; limitKindIndex++) {
                gItemKinds[limitKindIndex].mLimit = gItemKinds[limitKindIndex].mMissionRunLimit;
            }
            break;
        case MODE_WIFI:
            gItemKinds[ITEM_OBJECT_KIND_KINOKO].mLimit = ITEM_WIFI_KINOKO_LIMIT;
            break;
    }
}

void ComputeItemKindObjectCounts(void) {
    s32 maxObjectCounts[ITEM_OBJECT_KIND_COUNT];
    enum { KIND_INDEX_FIRST } kindIndex;
    enum { ITEM_INFO_INDEX_FIRST } itemInfoIndex;
    s32 objectCount;

    for (kindIndex = 0; kindIndex < ITEM_OBJECT_KIND_COUNT; kindIndex++) {
        gItemKinds[kindIndex].mObjectBudget = gItemKinds[kindIndex].mLimit - 1;
        maxObjectCounts[kindIndex] = 1;
    }
    for (itemInfoIndex = 0; itemInfoIndex < ITEM_INFO_COUNT; itemInfoIndex++) {
        if (gItemInfos[itemInfoIndex].mEnabled != FALSE) {
            kindIndex = gItemInfos[itemInfoIndex].mObjectKind;
            objectCount = gItemInfos[itemInfoIndex].mObjectCount;
            if (maxObjectCounts[kindIndex] < objectCount) {
                maxObjectCounts[kindIndex] = objectCount;
            }
        }
    }
    for (kindIndex = 0; kindIndex < ITEM_OBJECT_KIND_COUNT; kindIndex++) {
        gItemKinds[kindIndex].mObjectBudget = gItemKinds[kindIndex].mObjectBudget + maxObjectCounts[kindIndex];
        gItemKinds[kindIndex].mObjectCount = gItemKinds[kindIndex].mObjectBudget;
    }
    if (gRaceSetup->mMode == MODE_WIFI) {
        for (kindIndex = 0; kindIndex < ITEM_OBJECT_KIND_COUNT; kindIndex++) {
            gItemKinds[kindIndex].mObjectCount = gItemKinds[kindIndex].mObjectCount + 3;
        }
    } else {
        gItemKinds[ITEM_OBJECT_KIND_BANANA].mObjectCount = gItemKinds[ITEM_OBJECT_KIND_BANANA].mObjectCount + 0x10;
    }
}

#pragma thumb off
