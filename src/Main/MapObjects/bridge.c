#include "Main/MapObjects/bridge.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/nsbmd_model_draw_variants.h"
#include "Main/MapObjects/jg.h"
#include "Main/MapObjects/map_object_draw_list_flags.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/nsbmd_model_draw.h"

#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/System/heap_call.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/choropu_state.h"
#include "Main/MapObjects/bridge_kind_descriptor.h"

#pragma thumb off

const Vec3 gChoropuZeroVector = {0, 0, 0};
struct MapObjectList *gChoropuUpdateList;
struct MapObjectDrawList *gChoropuDrawList;
struct NsbmdModel *gChoropu;
struct ModelAnimation *gBridgeNsbca;
struct MapObjectDrawList *gChoropuShadowDrawList;
struct BridgeDrawList *gBridgeDrawList;
struct MapObjectList *gBridgeUpdateList;
struct Nsbmd *gRotaryRoom;
struct Nsbmd *gBridge;
struct Nsbmd *gGearWhite;
struct Nsbmd *gGearBlack;
struct MapObjectList *gRotaryUpdateList;
struct Nsbmd *gRotaryBridge;
void *gRotaryDrawList;
struct Nsbmd *gTestCylinder;

MapObjectKindData *CreateChoropuKindData(void) {
    MapObjectKindData *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectKindData));
    *kindData = gChoropuKindData;
    return kindData;
}

MapObjectList *CreateChoropuDrawList(void) {
    MapObjectDrawList *drawList;

    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*drawList));
    gChoropuDrawList = drawList;
    *drawList = gChoropuDrawListData;
    SetDrawListSlot(&gChoropuDrawList);
    return &gChoropuDrawList->mList;
}

MapObjectList *CreateChoropuShadowDrawList(void) {
    MapObjectDrawList *drawList;

    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*drawList));
    gChoropuShadowDrawList = drawList;
    *drawList = gChoropuShadowDrawListData;
    SetDrawListSlot(&gChoropuShadowDrawList);
    return &gChoropuShadowDrawList->mList;
}

MapObjectList *CreateChoropuUpdateList(void) {
    MapObjectList *updateList;

    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectList));
    gChoropuUpdateList = updateList;
    *updateList = gChoropuUpdateListData;
    SetUpdateListSlot(&gChoropuUpdateList);
    return gChoropuUpdateList;
}

void SetupDrawChoropu(void) {
    QueueNsbmdModelMaterial(gChoropu);
}

void DrawChoropu(s32 unused, Choropu *choropu, s32 unusedArg, u16 alpha) {
    MtxFx43 *matrix;

    switch (choropu->mMapObject.mStateMachine.mState) {
        case CHOROPU_STATE_LEAP:
            gChoropu->mFrameIndex = 1;
            matrix = SetViewTransposeMatrixPos(&choropu->mMapObject.mPos);
            DrawNsbmdModelWithMatrixAndMaxAlpha(gChoropu, matrix, &choropu->mMapObject.mScale, 0, alpha);
            break;
        case CHOROPU_STATE_WAIT_REPEAT:
            break;
        case CHOROPU_STATE_LAUNCHED_SPIN:
        case CHOROPU_STATE_FALL_SPIN:
            gChoropu->mFrameIndex = 1;
            matrix = SetViewTransposeMatrixPos(&choropu->mMapObject.mPos);
            DrawNsbmdModelWithMatrixAndAngle(gChoropu, matrix, choropu->mSpinAngle, &choropu->mMapObject.mScale, 0,
                                             alpha);
            break;
        default:
            gChoropu->mFrameIndex = 0;
            matrix = SetViewTransposeMatrixPos(&choropu->mMapObject.mPos);
            DrawNsbmdModelWithMatrixAndMaxAlpha(gChoropu, matrix, &choropu->mMapObject.mScale, 0, alpha);
    }
}
