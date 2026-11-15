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
#include "fixed_arctangent.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/MapObjects/shadow_model_create.h"
#include "Main/System/state_machine_init.h"
#include "Main/MapObjects/map_object_draw_list_flags.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/MapObjects/wanwan_chain_object.h"
#include "ITCM/kart_motion.h"
#include "vector_math.h"
#include "tp.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
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
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "player.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/quaternion_math.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/nsbmd_model_draw_variants.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/MapObjects/view_matrix_setters.h"
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
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectKindData));
    *kindData = gDossunKindData;
    return kindData;
}

MapObjectList *CreateDossunDrawList(void) {
    DossunDrawList *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(DossunDrawList));
    gDossunDrawList = drawList;
    *drawList = gDossunDrawListData;
    SetDrawListSlot(&gDossunDrawList);
    return &gDossunDrawList->mList;
}

MapObjectList *CreateDossunUpdateList(void) {
    MapObjectList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectList));
    gDossunUpdateList = updateList;
    *updateList = gDossunUpdateListData;
    SetUpdateListSlot(&gDossunUpdateList);
    return gDossunUpdateList;
}
