#include "Main/MapObjects/cow.h"
#include "ITCM/g3d_draw_and_irq_handler.h"
#include "Main/MapObjects/basabasa.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_drift.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Graphics/model_effect_kinds.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "vector_math.h"
#include "fixed_arctangent.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Kart/karts.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/bound.h"

MapObjectModel *gCow;

MapObjectKindDescriptor gCowKindDescriptor = {0, {0, 0}, 0xa0, 0, CreateEmptyMapObjectKindData, CreateCowDrawList};

void CreateCow(void *mapObjectList) {
    gCow = CreateMapObjectModelNsbmdNsbtp(mapObjectList, "cow.nsbmd", "cow.nsbtp");
    SetMapObjectModelPolygonId(gCow, 0x3f);
}

void SetupDrawCow(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gCow);
}

void DrawCow(void *mapObjectList, MapObject *mapObject) {
    s32 commandArg;

    commandArg = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandArg, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&mapObject->mPos), 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &mapObject->mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gCow, mapObject->mCourseMapRow->mSettings[0]);
    DrawMapObjectModel(mapObjectList, gCow, mapObject);
}

MapObjectList *CreateCowDrawList(void) {
    return CreateMapObjectDrawList2(CreateCow, DrawCow, SetupDrawCow);
}
