#include "Main/MapObjects/wanwan_chain.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/wanwan_chain_object.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/MapObjects/code_020ec1fc.h"
#include "Main/MapObjects/pushed_motion.h"
#include "Main/MapObjects/pushed_object_states_init.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/data_0217b000.h"

const MapObjectList gWanwanChainUpdateListData = {NULL, 0, {0, 0}, NULL, NULL, UpdateWanwanChain,
                                                  NULL, 0, NULL,   0,    NULL};
const MapObjectDrawList gWanwanChainDrawListData = {{NULL,
                                                     0,
                                                     {0, 0},
                                                     (void (*)(MapObjectList *)) CreateWanwanChainAndWanwanKui,
                                                     NULL,
                                                     (UnkFunc *) DrawWanwanChain,
                                                     NULL,
                                                     2,
                                                     NULL,
                                                     0,
                                                     NULL},
                                                    0};
const MapObjectKindData gWanwanChainKindData = {
    (s32(*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithWanwanChain,
    (s32(*)(MapObject *, void *, void *, void *)) CollideItemObjectWithWanwanChain,
    2,
    0x5000,
    0xa000,
    0,
    NULL,
    1,
    0,
    0x12f,
    0,
    0,
    0,
    0,
    0,
    0};
MapObjectDrawList *gWanwanChainDrawList;
NsbmdModel *gWanwanChain;
MapObjectList *gWanwanChainUpdateList;
NsbmdModel *gWanwanKui;

#pragma thumb on
void InitEarthenPipe(PushedObject *pipe) {
    pipe->mMapObject.mPos.y += MUL_FIXED12_NO_ROUND(pipe->mMapObject.mScale.y, 0xd000);
    InitPushedMotion(pipe, pipe->mMapObject.mPos.y - 0xc0000, 0x400, 0x400, 0x5000, 0x2000);
    InitPushedObjectStates(pipe);
}
#pragma thumb off

MapObjectKindData *CreateWanwanChainKindData(void) {
    MapObjectKindData *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectKindData));
    *kindData = gWanwanChainKindData;
    return kindData;
}

MapObjectDrawList *CreateWanwanChainDrawList(void) {
    gWanwanChainDrawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectDrawList));
    *gWanwanChainDrawList = gWanwanChainDrawListData;
    SetDrawListSlot(&gWanwanChainDrawList);
    return gWanwanChainDrawList;
}

MapObjectList *CreateWanwanChainUpdateList(void) {
    gWanwanChainUpdateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectList));
    *gWanwanChainUpdateList = gWanwanChainUpdateListData;
    SetUpdateListSlot(&gWanwanChainUpdateList);
    return gWanwanChainUpdateList;
}

void DrawWanwanChain(void *unused, WanwanChainObject *chainObject, s32 unusedValue, u16 maxAlpha) {
    DrawWanwanChainLinks(&chainObject->mChain, gWanwanChain, unusedValue, maxAlpha);
    if (chainObject->mHasKui == FALSE) {
        return;
    }
    DrawWanwanChainKui(&chainObject->mChain, gWanwanKui, &chainObject->mPos, unusedValue, maxAlpha);
}

void UpdateWanwanChain(void *unused, WanwanChainObject *chainObject) {
    Vec3 endPoint;
    Wanwan *wanwan;

    wanwan = chainObject->mWanwan;
    if (chainObject->mHasKui == FALSE) {
        chainObject->mPos = wanwan->mMapObject.mPos;
    }
    VEC_MultAdd(-wanwan->mScaledLength, &wanwan->mMapObject.mMatrix.mRows[2], &wanwan->mMapObject.mPos, &endPoint);
    UpdateWanwanChainPoints(&chainObject->mChain, &endPoint, &wanwan->mMapObject.mPosStep);
}
