#include "Main/Unknown/code_020de214.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020dda38.h"
#include "Main/Unknown/code_020e43a8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ec1fc.h"
#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/code_020ec884.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
void epipe_init(Unk020e43a8 *pipe) {
    pipe->mUnk_00.mPos.y += (s32) (((s64) pipe->mUnk_00.mScale.y * 0xd000) >> 12);
    rdmo_initParams(pipe, pipe->mUnk_00.mPos.y - 0xc0000, 0x400, 0x400, 0x5000, 0x2000);
    rdmo_initStateMachine(pipe);
}
#pragma thumb off

MapObjectKindData *wwchn_setupCollision(void) {
    MapObjectKindData *kindData;

    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = WanwanChain_CollisionInfo;
    return kindData;
}

MapObjectDrawList *wwchn_setupRenderPart(void) {
    wwchn_sRenderPart = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    *wwchn_sRenderPart = data_02158434;
    mobj_renderPartSetThisPointer(&wwchn_sRenderPart);
    return wwchn_sRenderPart;
}

MapObjectList *wwchn_setupLogicPart(void) {
    wwchn_sLogicPart = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    *wwchn_sLogicPart = data_0215840c;
    mobj_logicPartSetThisPointer(&wwchn_sLogicPart);
    return wwchn_sLogicPart;
}

void wwchn_render(void *unused, WanwanChainObject *chainObject, s32 c, u16 d) {
    DrawWanwanChainLinks(&chainObject->mChain, wwchn_sChainModel, c, d);
    if (chainObject->mHasKui == FALSE) {
        return;
    }
    DrawWanwanChainKui(&chainObject->mChain, wwchn_sKuiModel, &chainObject->mPos, c, d);
}

void wwchn_update(void *unused, WanwanChainObject *chainObject) {
    Vec3 endPoint;
    Wanwan *wanwan;

    wanwan = chainObject->mWanwan;
    if (chainObject->mHasKui == FALSE) {
        chainObject->mPos = wanwan->mUnk_00.mPos;
    }
    VEC_MultAdd(-wanwan->mUnk_f0, &wanwan->mUnk_00.mMatrix.mUnk_00[2], &wanwan->mUnk_00.mPos, &endPoint);
    UpdateWanwanChainPoints(&chainObject->mChain, &endPoint, &wanwan->mUnk_00.mUnk_10);
}
