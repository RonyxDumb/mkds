#include "Main/MapObjects/earthen_pipe_create.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
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
#include "Main/MapObjects/code_020e66e4.h"
#include "Main/MapObjects/code_020e6a74.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/data_0217b000.h"
#include "code_02147cd8.h"
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
    gEarthenPipeDrawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    *gEarthenPipeDrawList = gEarthenPipeDrawListData;
    SetDrawListSlot(&gEarthenPipeDrawList);
    return &gEarthenPipeDrawList->mList;
}

MapObjectList *CreateEarthenPipeUpdateList(void) {
    gEarthenPipeUpdateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    *gEarthenPipeUpdateList = gEarthenPipeUpdateListData;
    SetUpdateListSlot(&gEarthenPipeUpdateList);
    return gEarthenPipeUpdateList;
}

void SetupDrawEarthenPipe(void) {
    QueueNsbmdModelMaterial(gEarthenPipe1);
}
