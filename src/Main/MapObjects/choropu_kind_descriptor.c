#include "Main/MapObjects/choropu_kind_descriptor.h"
#include "Main/MapObjects/bridge.h"
#include "Main/MapObjects/choropu.h"
#include "Main/System/heap.h"
#include "Main/Course/course_color_blend.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/jg.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Race/data_020f36d8.h" // ItemObject
#include "Main/Sound/kart_surface_sound.h"
#include "Main/MapObjects/data_02158000.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/data_0217b000.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/kart_motion.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Item/item_pool.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/Sound/data_0210b000.h"
#include "code_02012b30.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/System/state_machine_init.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/Kart/kart_drift.h"
#include "Main/MapObjects/code_020e6a74.h"
#include "Main/Item/held_item.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Item/data_027e0000.h"
#include "Main/Race/entry_race_ended.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Graphics/light_color.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/map_object_sound.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Course/code_02042044.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "01/code_02187eb0.h"
#include "Main/MapObjects/shadow_model_create.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/Sound/sound_distance_change_reset.h"
#include "fx_mtx43.h"
#include "Main/MapObjects/choropu_state.h"
#include "Main/MapObjects/collision_hit_link_create.h"
#include "Main/System/init_after_startup.h"

const u16 gChoropuInitFlag = 0x200;
const MapObjectKindDescriptor gChoropuKindDescriptor = {0,
                                                        {0, 0},
                                                        0xf0,
                                                        InitChoropu,
                                                        CreateChoropuKindData,
                                                        (MapObjectList *(*)(void)) CreateChoropuDrawList,
                                                        (MapObjectList *(*)(void)) CreateChoropuShadowDrawList,
                                                        NULL,
                                                        CreateChoropuUpdateList,
                                                        NULL,
                                                        {NULL, NULL, NULL, NULL}};

#pragma thumb on

void InitChoropu(Choropu *choropu, struct CourseMapRow *courseRow) {
    InitStateMachine(&choropu->mMapObject.mStateMachine, gChoropuStateTable, 8, choropu);
    choropu->mInitialY = choropu->mMapObject.mPos.y;
    choropu->mBottomY = choropu->mMapObject.mPos.y - 0x12000;
    choropu->mLowestY = choropu->mMapObject.mPos.y - 0x18000;
    choropu->mRepeatDelayFrameCount = courseRow->mSettings[0];
    choropu->mStartDelayFrameCount = courseRow->mSettings[1];
    choropu->mMapObject.mStateMachine.mNextState = 0;
    choropu->mMapObject.mStateMachine.mNextStateRequested = 1;
    RefreshShadowMatrix(&choropu->mShadowMatrix, &choropu->mMapObject.mPos,
                        MUL_FIXED12_NO_ROUND(choropu->mMapObject.mScale.x, 0x1b000), 0x1e);
    choropu->mMapObject.mFlags |= gChoropuInitFlag;
}

#pragma thumb off
