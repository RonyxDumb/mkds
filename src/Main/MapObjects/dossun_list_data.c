#include "Main/MapObjects/dossun_list_data.h"
#include "Main/MapObjects/dossun.h"
#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/map_object_create.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/rock.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "fx_mtx33.h"
#include "code_02148538.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/MapObjects/shadow_model_create.h"
#include "Main/System/state_machine_init.h"
#include "Main/MapObjects/data_02158000.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/wanwan_chain_object.h"
#include "ITCM/kart_motion.h"
#include "ITCM/code_01ffc000.h"
#include "code_02147cd8.h"
#include "tp.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/camera.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/code_020d6dc0.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/code_020e66e4.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/MapObjects/group_follower.h"
#include "Main/MapObjects/kuribo.h"
#include "Main/System/init_after_startup.h"

const MapObjectList gDossunUpdateListData = {NULL, 0, {0, 0}, NULL, NULL, UpdateDossun,
                                             NULL, 0, NULL,   0,    NULL};
const struct DossunDrawList gDossunDrawListData = {{NULL,
                                                    0,
                                                    {0, 0},
                                                    (void (*)(MapObjectList *)) CreateDossunAndDossunShadow,
                                                    NULL,
                                                    DrawDossun,
                                                    NULL,
                                                    1,
                                                    NULL,
                                                    0,
                                                    NULL},
                                                   0};
const MapObjectKindData gDossunKindData = {(s32(*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithDossun,
                                           NULL,
                                           2,
                                           0x24000,
                                           0x2d000,
                                           0,
                                           NULL,
                                           1,
                                           2,
                                           0x18a,
                                           0,
                                           0,
                                           0,
                                           0,
                                           0,
                                           0};

#pragma thumb off

MapObjectKindData *CreateDossunKindData(void) {
    MapObjectKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = gDossunKindData;
    return kindData;
}

MapObjectList *CreateDossunDrawList(void) {
    DossunDrawList *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gDossunDrawList = drawList;
    *drawList = gDossunDrawListData;
    SetDrawListSlot(&gDossunDrawList);
    return &gDossunDrawList->mList;
}

MapObjectList *CreateDossunUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gDossunUpdateList = updateList;
    *updateList = gDossunUpdateListData;
    SetUpdateListSlot(&gDossunUpdateList);
    return gDossunUpdateList;
}
