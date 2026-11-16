#include "Main/Unknown/code_020e44e4.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020467d0.h"

#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020ec000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"

#pragma thumb on

void puku_init(Unk020e43a8 *pukupuku, Vec3 *position) {
    sm_init(&pukupuku->field0.mStateMachine, (UnkFunc *const *) puku_sStates, 4, pukupuku);
    pukupuku->field0.mPos.y = pukupuku->field0.mPos.y + (s32) (((s64) pukupuku->field0.mScale.y * 0xa000) >> 12);
    pukupuku->fieldA0.field18 = pukupuku->field0.mPos;
    pukupuku->fieldC4 = 4;
    pukupuku->field0.field10.x = 0;
    pukupuku->field0.field10.y = 0;
    pukupuku->field0.field10.z = 0;
    rdmo_initParams(pukupuku, pukupuku->field0.mPos.y - 0x1e000, 0x400, 0x400, 0x4000, 0x1800);
    pukupuku->field0.mStateMachine.mNextState = 0;
    pukupuku->field0.mStateMachine.mNextStateRequested = 1;
    oshd_setParams((ShadowMatrix *) &pukupuku->fieldC8, position,
                        ((s64) pukupuku->field0.mScale.x * 0x12000) >> 12, 0xd);
    pukupuku->fieldF4.z = position->y;
    {
        s32 *secondRow = &pukupuku->fieldD4;
        pukupuku->field104 = -FX_Div(secondRow[0], secondRow[1]);
        pukupuku->field108 = -FX_Div(secondRow[2], secondRow[1]);
    }
}

#pragma thumb off

Unk020e46c8 *rotcyl_setupGearConfig(void) {
    Unk020e46c8 *kindData;
    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = *(Unk020e46c8 *) data_02158f70;
    kindData->field38 = 0x2bc000;
    return kindData;
}

Unk020e46c8 *rotcyl_setupRotRoomConfig(void) {
    Unk020e46c8 *kindData;
    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = *(Unk020e46c8 *) data_02158f30;
    return kindData;
}

Unk020e46c8 *rotcyl_setupRotBridgeConfig(void) {
    Unk020e46c8 *kindData;
    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = *(Unk020e46c8 *) data_02158ef0;
    return kindData;
}

Unk020e466c *rotcyl_setupRenderPart(void) {
    Unk020e466c *drawList;
    drawList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    rotobj_sRenderPart = drawList;
    *drawList = *(Unk020e466c *) data_02158ec4;
    mobj_renderPartSetThisPointer(&rotobj_sRenderPart);
    return rotobj_sRenderPart;
}

Unk020e4610 *rotcyl_setupLogicPart(void) {
    Unk020e4610 *updateList;
    updateList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    rotobj_sLogicPart = updateList;
    *updateList = *(Unk020e4610 *) data_02158e9c;
    mobj_logicPartSetThisPointer(&rotobj_sLogicPart);
    return rotobj_sLogicPart;
}

void rotcyl_update(u32 unused, Unk020e43a8 *object) {
    s32 previousAngle;
    s32 angleChange;
    previousAngle = object->field0.mAngle;
    sm_execute(&object->field0.mStateMachine);
    angleChange = object->field0.mAngle - previousAngle;
    if (angleChange > 0x8000) {
        angleChange -= 0x10000;
    }
    if (angleChange < -0x8000) {
        angleChange += 0x10000;
    }
    object->field124 = ((s64) object->field0.mMatrix.field0[1].x * angleChange) >> 12;
    object->field128 = ((s64) object->field0.mMatrix.field0[1].y * angleChange) >> 12;
    object->field12C = ((s64) object->field0.mMatrix.field0[1].z * angleChange) >> 12;
    object->fieldA0 = *(Unk020e43a8_28 *) &object->field0.mMatrix;
    MTX_RotY33_((s32 *) &object->field0.mMatrix, FX_SinCosTable_[(object->field0.mAngle >> 4) * 2],
                FX_SinCosTable_[(object->field0.mAngle >> 4) * 2 + 1]);
    MTX_Concat33((const s32 *) &object->field0.mMatrix, (const s32 *) &object->fieldC4,
                 (s32 *) &object->field0.mMatrix);
    VEC_MultAdd(-object->field104, &object->field0.mMatrix.field0[1], &object->field0.mPos, &object->fieldF4);
    if (object->field0.mStateMachine.mState == 3) {
        return;
    }
    if (object->field15C == -1) {
        return;
    }
    mobj_emitSfxFromEmitter(&object->field0, object->field15C);
}
