#include "Main/MapObjects/rock_kind_data.h"
#include "Main/MapObjects/rock.h"
#include "Main/MapObjects/group_follower.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Menu/choises_s.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "01/Race/mission_run_state.h"
#include "matrix_3x3_basic.h"
#include "fixed_vector_math.h"
#include "Main/MapObjects/quaternion_math.h"
#include "Main/MapObjects/group_paths.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "fixed_arctangent.h"
#include "registers.h"
#include "particle_instance.h"

const MapObjectKindData gRockKindData = {(s32 (*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithRock,
                                         (s32 (*)(MapObject *, void *, void *, void *)) CollideItemObjectWithRock,
                                         1,
                                         0x1b000,
                                         0,
                                         0,
                                         NULL,
                                         1,
                                         1,
                                         0x17a,
                                         0,
                                         0,
                                         0,
                                         0,
                                         0,
                                         0};

MapObjectKindData *CreateRockKindData(void) {
    MapObjectKindData *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectKindData));
    *kindData = gRockKindData;
    kindData->mHeightRangeMax = ROCK_HEIGHT_RANGE_MAX;
    kindData->mHeightRangeMin = -0x3e8000;
    return kindData;
}
