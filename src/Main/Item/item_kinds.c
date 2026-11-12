#include "Main/Item/item_kinds.h"
#include "Main/System/heap.h"

#include "Main/System/heap_call.h"
#include "Main/Item/item_kind_copy_size.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Item/pooled_item_box.h"
#include "Main/Item/code_020f4dfc.h"
#include "Main/Item/code_020f50b4.h"
#include "Main/Item/code_020f5324.h"
#include "Main/Item/code_020f5ffc.h"
#include "Main/Item/code_020f6264.h"
#include "Main/Item/code_020f62b0.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/item_kinoko_p_boost.h"
#include "Main/Item/item_koura_w_kart_items.h"
#include "Main/Item/item_teresa_offset.h"
#include "Main/Item/item_gesso.h"
#include "Main/Item/item_f_box.h"

#pragma thumb on

void CreateItemKinds(void) {
    ItemKind *kinds;
    enum { K0 } kindIndex;
    enum { K1 } limitKindIndex;
    s32 mode;
    u32 value;
    u32 (*getFar)(void);

    kinds = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x930);
    gItemKinds = kinds;
    kinds[0] = gItemKindKouraG;
    kinds[1] = gItemKindKouraR;
    kinds[2] = gItemKindBanana;
    kinds[3] = gItemKindKinoko;
    kinds[4] = gItemKindStar;
    kinds[5] = gItemKindKouraW;
    kinds[6] = gItemKindThunder;
    kinds[7] = gItemKindFBox;
    kinds[8] = data_0215a4dc;
    kinds[9] = gItemKindBomb;
    kinds[10] = gItemKindGesso;
    kinds[11] = gItemKindTeresa;
    kinds[12] = gItemKindKinokoP;
    kinds[13] = gItemKindKiller;
    for (kindIndex = 0; kindIndex < 0xe; kindIndex++) {
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
            gItemKinds[8].mLimit = 8;
            break;
        case MODE_MISSION_RUN:
            for (limitKindIndex = 0; limitKindIndex < 0xe; limitKindIndex++) {
                gItemKinds[limitKindIndex].mLimit = gItemKinds[limitKindIndex].mMissionRunLimit;
            }
            break;
        case 5:
            gItemKinds[3].mLimit = 0x20;
            break;
    }
}

void ComputeItemKindObjectCounts(void) {
    s32 maxObjectCounts[14];
    enum { K0 } kindIndex;
    enum { K1 } itemInfoIndex;
    s32 objectCount;

    for (kindIndex = 0; kindIndex < 0xe; kindIndex++) {
        gItemKinds[kindIndex].mObjectBudget = gItemKinds[kindIndex].mLimit - 1;
        maxObjectCounts[kindIndex] = 1;
    }
    for (itemInfoIndex = 0; itemInfoIndex < 0x12; itemInfoIndex++) {
        if (gItemInfos[itemInfoIndex].mEnabled != FALSE) {
            kindIndex = gItemInfos[itemInfoIndex].mObjectKind;
            objectCount = gItemInfos[itemInfoIndex].mObjectCount;
            if (maxObjectCounts[kindIndex] < objectCount) {
                maxObjectCounts[kindIndex] = objectCount;
            }
        }
    }
    for (kindIndex = 0; kindIndex < 0xe; kindIndex++) {
        gItemKinds[kindIndex].mObjectBudget = gItemKinds[kindIndex].mObjectBudget + maxObjectCounts[kindIndex];
        gItemKinds[kindIndex].mObjectCount = gItemKinds[kindIndex].mObjectBudget;
    }
    if (gRaceSetup->mMode == MODE_WIFI) {
        for (kindIndex = 0; kindIndex < 0xe; kindIndex++) {
            gItemKinds[kindIndex].mObjectCount = gItemKinds[kindIndex].mObjectCount + 3;
        }
    } else {
        gItemKinds[2].mObjectCount = gItemKinds[2].mObjectCount + 0x10;
    }
}

#pragma thumb off
