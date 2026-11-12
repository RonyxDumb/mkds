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

#pragma thumb on
void InitEarthenPipe(PushedObject *pipe) {
    pipe->mMapObject.mPos.y += MUL_FIXED12_NO_ROUND(pipe->mMapObject.mScale.y, 0xd000);
    InitPushedMotion(pipe, pipe->mMapObject.mPos.y - 0xc0000, 0x400, 0x400, 0x5000, 0x2000);
    InitPushedObjectStates(pipe);
}
#pragma thumb off

MapObjectKindData *CreateWanwanChainKindData(void) {
    MapObjectKindData *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02158460;
    return kindData;
}

MapObjectDrawList *CreateWanwanChainDrawList(void) {
    data_0217b6dc = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    *data_0217b6dc = data_02158434;
    SetDrawListSlot(&data_0217b6dc);
    return data_0217b6dc;
}

MapObjectList *CreateWanwanChainUpdateList(void) {
    data_0217b6e0 = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    *data_0217b6e0 = data_0215840c;
    SetUpdateListSlot(&data_0217b6e0);
    return data_0217b6e0;
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
    VEC_MultAdd(-wanwan->mUnk_f0, &wanwan->mMapObject.mMatrix.mRows[2], &wanwan->mMapObject.mPos, &endPoint);
    UpdateWanwanChainPoints(&chainObject->mChain, &endPoint, &wanwan->mMapObject.mPosStep);
}
