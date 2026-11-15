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
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "01/Race/mission_run_state.h"
#include "fx_mtx33.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/code_020d6dc0.h"
#include "Main/MapObjects/group_paths.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "code_02148538.h"
#include "registers.h"
#include "code_0201c528.h"

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
