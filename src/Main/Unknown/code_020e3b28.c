#include "Main/Unknown/code_020e3b28.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ea000.h"

#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020e3618.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020f9c6c.h"

#pragma thumb off

void rotcyl_state3Update(Unk020e3ef4 *object) {
    if (object->field0.mStateMachine.mStateFrames > object->field148) {
        object->field0.mStateMachine.mNextState = 0;
        object->field0.mStateMachine.mNextStateRequested = 1;
    }
}

void rotcyl_renderAll(void *viewMatrix) {
    dcol_render(rotobj_sRenderPart, viewMatrix, dcol_commonRender);
}

BOOL rotcyl_isRotatingCylinder(s32 kind) {
    switch (kind) {
        case 0xcb:
        case 0xce:
        case 0xd0:
        case 0xd1:
            return TRUE;
        default:
            return FALSE;
    }
}

#pragma thumb on

void rotcyl_loadModels(Unk020e1dc0 *list) {
    Unk020e3ef4 *object;
    s32 objectIndex;
    s32 modelIndex;
    s32 objectCount;
    s32 j;
    s32 l;
    u32 *loadedFlagSlot;
    u32 modelLoaded[5];

    for (modelIndex = 0; modelIndex < 5; modelIndex++) {
        modelLoaded[modelIndex] = 0;
    }
    objectCount = list->field4;
    for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
        object = list->field0[objectIndex];
        loadedFlagSlot = &modelLoaded[object->field158];
        if (modelLoaded[object->field158] == 0) {
            switch (object->field158) {
                case 0:
                    model2_createFromNsbmd(&gTestCylinder, mobj_getMapObjFile(aTest_cylinder_), NULL);
                    model_setPolyIdLightFlagsEmi(gTestCylinder, 0x3f, 2, 0x294a);
                    break;
                case 1:
                    model2_createFromNsbmd(&gGearBlack, mobj_getMapObjFile(aGear_black_nsb), NULL);
                    model_setPolyIdLightFlagsEmi(gGearBlack, 0x3f, 2, 0x294a);
                    break;
                case 2:
                    model2_createFromNsbmd(&gGearWhite, mobj_getMapObjFile(aGear_white_nsb), NULL);
                    model_setPolyIdLightFlagsEmi(gGearWhite, 0x3f, 2, 0x294a);
                    break;
                case 3:
                    model2_createFromNsbmd(&gRotaryRoom, mobj_getMapObjFile(aRotary_room_ns), NULL);
                    model_setPolyIdLightFlagsEmi(gRotaryRoom, 0x3f, 2, 0x294a);
                    break;
                case 4:
                    model2_createFromNsbmd(&gRotaryBridge, mobj_getMapObjFile(aRotary_bridge_), NULL);
                    model_setPolyIdLightFlagsEmi(gRotaryBridge, 0x3f, 2, 0x294a);
                    break;
            }
            *loadedFlagSlot = 1;
        }
    }
    l = list->field4;
    for (j = 0; j < l; j++) {
        object = list->field0[j];
        switch (object->field158) {
            case 0:
                object->mModel = gTestCylinder;
                break;
            case 1:
                object->mModel = gGearBlack;
                break;
            case 2:
                object->mModel = gGearWhite;
                break;
            case 3:
                object->mModel = gRotaryRoom;
                break;
            case 4:
                object->mModel = gRotaryBridge;
                break;
        }
    }
}

void rotcyl_globalLogicInit(Unk020e1dc0 *list) {
    Unk020e3ef4 *object;
    s32 index;
    s32 previousIndex;
    s32 count;
    u32 z;
    u32 z2;
    Vec3 offset;
    Unk020e3ef4 **objects;

    objects = list->field0;
    previousIndex = -1;
    z = 0;
    z2 = 0;
    count = list->field4;
    for (index = 0; index < count; index++) {
        object = objects[index];
        if (object->field0.mKind == 0xcb) {
            if (previousIndex < 0) {
                object->field138 = z;
            } else {
                VEC_Subtract(&objects[previousIndex]->field0.mPos, &object->field0.mPos, &offset);
                offset.y = z2;
                object->field154 = VEC_Mag(&offset);
                object->field154 -= objects[previousIndex]->field0.mExtent.x;
            }
            previousIndex = index;
        }
    }
}

void rotcyl_init(Unk020e3ef4 *object, struct CourseMapRow *courseRow, Unk020e1e98_154 *kindInfo) {
    sm_init(&object->field0.mStateMachine, (UnkFunc *const *) rotobj_sStates, 4, object);
    object->fieldE8 = object->field0.mPos;
    object->fieldA0 = *(Unk020e38a0_28 *) &object->field0.mMatrix;
    object->fieldC4 = *(Unk020e38a0_28 *) &object->field0.mMatrix;
    object->field124.x = 0;
    object->field124.y = 0;
    object->field124.z = 0;
    object->field130 = kindInfo->field0 != 0 ? 0 : 1;
    object->field144 = courseRow->field2C;
    object->field146 = courseRow->field2A;
    object->field148 = courseRow->field2E;
    object->field14A = courseRow->field28 * 0x80 / 100;
    if (courseRow->field30 != 0) {
        object->field14A = -object->field14A;
    }
    object->field0.mAngle = 0;
    if (object->field144 != 0) {
        object->field150 = 0x1000 / object->field144;
    } else {
        object->field150 = 0;
    }
    object->field14C = 0;
    object->field100 = ((s64) kindInfo->field4 * object->field0.mScale.x) >> 12;
    object->field104 = (s32) (((s64) kindInfo->field8 * object->field0.mScale.y) >> 12) >> 1;
    if (kindInfo->field0 != 0) {
        object->field110 = FALSE;
        object->field114.x = 1;
    } else {
        object->field110 = TRUE;
        object->field114.x = 0;
    }
    object->field114.z = 0;
    object->field120 = kindInfo->field10;
    object->field134 = 1;
    object->field138 = kindInfo->field14;
    object->field0.mFlags |= data_02158d58;
    object->field0.mStateMachine.mNextState = 0;
    object->field0.mStateMachine.mNextStateRequested = 1;
    object->field158 = kindInfo->fieldC;
    if (object->field158 == 1 && courseRow->field32 == 0) {
        object->field158 = 2;
    }
    object->field0.mFlags &= ~2;
    object->field0.mFlags &= ~8;
    object->field0.mAlpha = 0x1f;
    if (kindInfo->fieldC == 0) {
        object->field15C = courseRow->fieldC.x > 0 ? 0x175 : 0x176;
    } else {
        object->field15C = kindInfo->field18;
    }
    if (object->field15C != -1) {
        mobj_initSoundEmitterForObjectSfxParam3(&object->field0);
    }
}

#pragma thumb off

void *bridge_setupConfig(void) {
    void *kindData;

    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *(Unk020e03f8 *) kindData = *(const Unk020e03f8 *) data_02158d18;
    return kindData;
}

void *bridge_setupRenderPart(void) {
    void *drawList;

    drawList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x30);
    *(void **) bridge_sRenderPart = drawList;
    *(Unk020e3e48 *) drawList = *(const Unk020e3e48 *) data_02158ce8;
    mobj_renderPartSetThisPointer(&bridge_sRenderPart);
    return *(void **) bridge_sRenderPart;
}

void *bridge_setupLogicPart(void) {
    void *updateList;

    updateList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    bridge_sLogicPart = updateList;
    *(Unk020e0340 *) updateList = *(const Unk020e0340 *) data_02158cc0;
    mobj_logicPartSetThisPointer(&bridge_sLogicPart);
    return bridge_sLogicPart;
}

void bridge_update(s32 a, Bridge *bridge) {
    s16 sine;
    s32 angleDelta;
    u16 x;
    u16 y;

    sine = FX_SinCosTable_[(bridge->field148 >> 4) * 2];
    x = bridge->field144 + (s32) (((s64) sine * bridge->field144) >> 12);
    y = 0x10000 - x;
    angleDelta = y - bridge->field14A;
    if (angleDelta > 0x8000) {
        angleDelta -= 0x10000;
    }
    if (angleDelta < -0x8000) {
        angleDelta += 0x10000;
    }
    bridge->field124.x = ((s64) bridge->field0.mMatrix.field0[0].x * angleDelta) >> 12;
    bridge->field124.y = ((s64) bridge->field0.mMatrix.field0[0].y * angleDelta) >> 12;
    bridge->field124.z = ((s64) bridge->field0.mMatrix.field0[0].z * angleDelta) >> 12;
    bridge->field14A = y;
    bridge->fieldA0 = *(Unk020e38a0_28 *) &bridge->field0.mMatrix;
    MTX_RotX33_((s32 *) &bridge->field0.mMatrix, FX_SinCosTable_[(y >> 4) * 2], FX_SinCosTable_[(y >> 4) * 2 + 1]);
    MTX_Concat33((const s32 *) &bridge->field0.mMatrix, (const s32 *) &bridge->fieldC4,
                 (s32 *) &bridge->field0.mMatrix);
    VEC_MultAdd(-bridge->field104, &bridge->field0.mMatrix.field0[1], &bridge->field0.mPos, &bridge->fieldF4);
    if (bridge->field150 != 0) {
        bridge->field150--;
        return;
    }
    if (bridge->field0.mSound != NULL) {
        mobj_emitSfxFromEmitter(&bridge->field0, 0x189);
    }
    bridge->field148 += bridge->field146;
    if (bridge->field148 >= 0x4000 && bridge->field148 < bridge->field146 + 0x4000) {
        bridge->field150 = bridge->field14C;
    } else if (bridge->field148 >= 0xc000 && bridge->field148 < bridge->field146 + 0xc000) {
        bridge->field150 = bridge->field14E;
    }
    y = 0x10000 - bridge->field14A;
    bridge->field154 = (s32) ((((s64) (s32) (u16) (0x10000 - bridge->field14A) * 0x1680000) + 0x80000) >> 20) << 1;
    if (bridge->field154 > ((Unk020e1dc0 *) *(void **) bridge_sRenderPart)->field2C) {
        bridge->field154 = ((Unk020e1dc0 *) *(void **) bridge_sRenderPart)->field2C;
    }
    if (bridge->field154 < 0) {
        bridge->field154 = 0;
    }
}

void bridge_render(Unk020e3ef4 *object, void *viewMatrix, u32 alpha) {
    Unk020e1e98_12c *animation;

    object->field0.mMatrix.field0[3].x = object->field0.mPos.x >> 4;
    object->field0.mMatrix.field0[3].y = object->field0.mPos.y >> 4;
    object->field0.mMatrix.field0[3].z = object->field0.mPos.z >> 4;
    animation = bridge_sNsbcaAnim;
    animation->fieldC = object->field154;
    *animation->field1C[animation->field1A] = animation->fieldC;
    model2_renderModel(object->mModel, &object->field0.mMatrix, &object->field0.mScale.x, alpha);
}

void bridge_renderAll(void *viewMatrix) {
    dcol_render(*(void **) bridge_sRenderPart, viewMatrix, bridge_render);
}
