#include "Main/Unknown/code_020df48c.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020debec.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087cfc.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d8c74.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e5668.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ea514.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
void efbub_loadModel(void) {
    void *nsbmd;

    nsbmd = mobj_getMapObjFile("mkd_ef_bubble.nsbmd");
    model2_createFromNsbmd(&gMkdEfBubble, nsbmd, NULL);
    model_setPolyIdLightFlagsEmi(gMkdEfBubble, 0x3f, 2, 0x294a);
    gMkdEfBubbleNsbta = heap_alloc(proc_getHeap(proc_getCurrent()), 0x38);
    anim_20EA514(1, gMkdEfBubble, gMkdEfBubbleNsbta, nsbmd,
                                  mobj_getMapObjFile("mkd_ef_bubble.nsbta"));
    anim_setLoop(gMkdEfBubbleNsbta, 0, 1);
}

void efbub_init(MkdEfBubbleObject *bubble, CourseMapRow *row) {
    sm_init(&bubble->field0.mStateMachine, efbub_sStates, 2, bubble);
    bubble->fieldA0 = row->field28;
    bubble->fieldAC = bubble->field0.mPos.y;
    bubble->fieldA4 = bubble->field0.mPos.y - 0x10000;
    bubble->field0.field10.x = 0;
    bubble->field0.field10.y = 0;
    bubble->field0.field10.z = 0;
    bubble->fieldA8 = 0;
    bubble->field0.mStateMachine.mNextState = 0;
    bubble->field0.mStateMachine.mNextStateRequested = 1;
    oshd_setParams(&bubble->fieldB0, &bubble->field0.mPos, ((s64) bubble->field0.mScale.x * 0x18000) >> 12, 0xd);
    bubble->field0.mFlags |= data_02158740;
}
#pragma thumb off

MapObjectKindData *mibox_setupCollision(void) {
    MapObjectKindData *kindData;

    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = data_02158700;
    return kindData;
}

MapObjectList *mibox_setupLogicPart(void) {
    mibox_sLogicPart = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    *mibox_sLogicPart = data_021586d8;
    mobj_logicPartSetThisPointer(&mibox_sLogicPart);
    return mibox_sLogicPart;
}

void mibox_globalPreUpdate(void) {
    s32 sine;

    sine = FX_SinCosTable_[(data_0217b750 >> 4) * 2];
    data_0217b754 = ((s64) sine * 0x4000) >> 12;
    data_0217b750 += 0x2d8;
    data_0217b75c = 0xf00 - (sine >> 4);
    data_0217b760.x = 0x1666;
    data_0217b760.y = 0x1666;
    data_0217b760.z = 0x1666;
}

void mibox_update(void *unused, ItemBox *itemBox) {
    if (itemBox->mFollower.field0.mGroupIndex != 0xffff) {
        if (pwex_update(&itemBox->mFollower) != 0) {
            if (itemBox->mFollower.field0.mFromEntry->field10 != 0) {
                pwex_init(&itemBox->mFollower, 0, 1);
            }
        }
        pw_calcCurrentPointXYZ(&itemBox->mFollower.field0, &itemBox->field0.mPos);
        if (itemBox->mFollower.field0.mFromEntry->fieldD != 0 && itemBox->mFollower.field0.mToEntry->fieldD != 0) {
            itemBox->field0.mFlags |= data_021586d4;
        } else {
            itemBox->field0.mFlags &= ~0x20;
        }
        itemBox->field0.mPos.y += data_0217b754;
        itemBox->field0.mPos.y += 0x10000;
    }
    if (itemBox->fieldB0 == 0) {
        oshd_setPositionXZ(&itemBox->fieldB4, &itemBox->field0.mPos);
    }
    ibox_update(unused, itemBox);
}
