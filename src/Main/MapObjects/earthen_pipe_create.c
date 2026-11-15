#include "Main/MapObjects/earthen_pipe_create.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Course/course_triangle_flag.h"
#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/MapObjects/nsbmd_model_draw_variants.h"
#include "Main/MapObjects/view_matrix_queue.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "vector_math.h"
#include "Main/MapObjects/earthen_pipe.h"
#include "Main/MapObjects/group_item_box_kind_descriptor.h"
#include "Main/MapObjects/item_box_kind_descriptor.h"

const MapObjectList gEarthenPipeUpdateListData = {NULL, 0, {0, 0}, NULL, NULL, UpdateEarthenPipe,
                                                  NULL, 0, NULL,   0,    NULL};
const MapObjectDrawList gEarthenPipeDrawListData = {{NULL,
                                                     0,
                                                     {0, 0},
                                                     (void (*)(MapObjectList *)) CreateEarthenPipe1AndEarthenPipe2,
                                                     (void (*)(MapObjectList *)) SetupDrawEarthenPipe,
                                                     (MapObjectForEachCallback) DrawEarthenPipe,
                                                     NULL,
                                                     2,
                                                     NULL,
                                                     0,
                                                     NULL},
                                                    0};
const MapObjectKindData gEarthenPipeKindData = {
    (s32(*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithEarthenPipe,
    (s32(*)(MapObject *, void *, void *, void *)) CollideItemObjectWithEarthenPipe,
    2,
    0xb000,
    0xc000,
    0,
    NULL,
    1,
    0,
    0x127,
    0,
    0,
    0,
    0,
    0,
    0};

#pragma thumb off

MapObjectKindData *CreateEarthenPipeKindData(void) {
    MapObjectKindData *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectKindData));
    *kindData = gEarthenPipeKindData;
    return kindData;
}

MapObjectList *CreateEarthenPipeDrawList(void) {
    gEarthenPipeDrawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gEarthenPipeDrawList));
    *gEarthenPipeDrawList = gEarthenPipeDrawListData;
    SetDrawListSlot(&gEarthenPipeDrawList);
    return &gEarthenPipeDrawList->mList;
}

MapObjectList *CreateEarthenPipeUpdateList(void) {
    gEarthenPipeUpdateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gEarthenPipeUpdateList));
    *gEarthenPipeUpdateList = gEarthenPipeUpdateListData;
    SetUpdateListSlot(&gEarthenPipeUpdateList);
    return gEarthenPipeUpdateList;
}

void SetupDrawEarthenPipe(void) {
    QueueNsbmdModelMaterial(gEarthenPipe1);
}
