#include "Main/MapObjects/bridge.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/code_020e66e4.h"
#include "Main/MapObjects/jg.h"
#include "Main/MapObjects/data_02158000.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/nsbmd_model_draw.h"

#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
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
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/System/heap_call.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/data_0217b000.h"
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

    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gChoropuDrawList = drawList;
    *drawList = gChoropuDrawListData;
    SetDrawListSlot(&gChoropuDrawList);
    return &gChoropuDrawList->mList;
}

MapObjectList *CreateChoropuShadowDrawList(void) {
    MapObjectDrawList *drawList;

    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
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
