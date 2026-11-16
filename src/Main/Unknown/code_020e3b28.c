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
    if (object->mUnk_000.mStateMachine.mStateFrames > object->mUnk_148) {
        object->mUnk_000.mStateMachine.mNextState = 0;
        object->mUnk_000.mStateMachine.mNextStateRequested = 1;
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
    objectCount = list->mUnk_04;
    for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
        object = list->mUnk_00[objectIndex];
        loadedFlagSlot = &modelLoaded[object->mUnk_158];
        if (modelLoaded[object->mUnk_158] == 0) {
            switch (object->mUnk_158) {
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
    l = list->mUnk_04;
    for (j = 0; j < l; j++) {
        object = list->mUnk_00[j];
        switch (object->mUnk_158) {
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

    objects = list->mUnk_00;
    previousIndex = -1;
    z = 0;
    z2 = 0;
    count = list->mUnk_04;
    for (index = 0; index < count; index++) {
        object = objects[index];
        if (object->mUnk_000.mKind == 0xcb) {
            if (previousIndex < 0) {
                object->mUnk_138 = z;
            } else {
                VEC_Subtract(&objects[previousIndex]->mUnk_000.mPos, &object->mUnk_000.mPos, &offset);
                offset.y = z2;
                object->mUnk_154 = VEC_Mag(&offset);
                object->mUnk_154 -= objects[previousIndex]->mUnk_000.mExtent.x;
            }
            previousIndex = index;
        }
    }
}

void rotcyl_init(Unk020e3ef4 *object, struct CourseMapRow *courseRow, Unk020e1e98_154 *kindInfo) {
    sm_init(&object->mUnk_000.mStateMachine, (UnkFunc *const *) rotobj_sStates, 4, object);
    object->mUnk_0e8 = object->mUnk_000.mPos;
    object->mUnk_0a0 = *(Unk020e38a0_28 *) &object->mUnk_000.mMatrix;
    object->mUnk_0c4 = *(Unk020e38a0_28 *) &object->mUnk_000.mMatrix;
    object->mUnk_124.x = 0;
    object->mUnk_124.y = 0;
    object->mUnk_124.z = 0;
    object->mUnk_130 = kindInfo->mUnk_00 != 0 ? 0 : 1;
    object->mUnk_144 = courseRow->mUnk_2c;
    object->mUnk_146 = courseRow->mUnk_2a;
    object->mUnk_148 = courseRow->mUnk_2e;
    object->mUnk_14a = courseRow->mUnk_28 * 0x80 / 100;
    if (courseRow->mUnk_30 != 0) {
        object->mUnk_14a = -object->mUnk_14a;
    }
    object->mUnk_000.mAngle = 0;
    if (object->mUnk_144 != 0) {
        object->mUnk_150 = 0x1000 / object->mUnk_144;
    } else {
        object->mUnk_150 = 0;
    }
    object->mUnk_14c = 0;
    object->mUnk_100 = ((s64) kindInfo->mUnk_04 * object->mUnk_000.mScale.x) >> 12;
    object->mUnk_104 = (s32) (((s64) kindInfo->mUnk_08 * object->mUnk_000.mScale.y) >> 12) >> 1;
    if (kindInfo->mUnk_00 != 0) {
        object->mUnk_110 = FALSE;
        object->mUnk_114.x = 1;
    } else {
        object->mUnk_110 = TRUE;
        object->mUnk_114.x = 0;
    }
    object->mUnk_114.z = 0;
    object->mUnk_120 = kindInfo->mUnk_10;
    object->mUnk_134 = 1;
    object->mUnk_138 = kindInfo->mUnk_14;
    object->mUnk_000.mFlags |= data_02158d58;
    object->mUnk_000.mStateMachine.mNextState = 0;
    object->mUnk_000.mStateMachine.mNextStateRequested = 1;
    object->mUnk_158 = kindInfo->mUnk_0c;
    if (object->mUnk_158 == 1 && courseRow->mUnk_32 == 0) {
        object->mUnk_158 = 2;
    }
    object->mUnk_000.mFlags &= ~2;
    object->mUnk_000.mFlags &= ~8;
    object->mUnk_000.mAlpha = 0x1f;
    if (kindInfo->mUnk_0c == 0) {
        object->mUnk_15c = courseRow->mUnk_0c.x > 0 ? 0x175 : 0x176;
    } else {
        object->mUnk_15c = kindInfo->mUnk_18;
    }
    if (object->mUnk_15c != -1) {
        mobj_initSoundEmitterForObjectSfxParam3(&object->mUnk_000);
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

    sine = FX_SinCosTable_[(bridge->mUnk_148 >> 4) * 2];
    x = bridge->mUnk_144 + (s32) (((s64) sine * bridge->mUnk_144) >> 12);
    y = 0x10000 - x;
    angleDelta = y - bridge->mUnk_14a;
    if (angleDelta > 0x8000) {
        angleDelta -= 0x10000;
    }
    if (angleDelta < -0x8000) {
        angleDelta += 0x10000;
    }
    bridge->mUnk_124.x = ((s64) bridge->mUnk_000.mMatrix.mUnk_00[0].x * angleDelta) >> 12;
    bridge->mUnk_124.y = ((s64) bridge->mUnk_000.mMatrix.mUnk_00[0].y * angleDelta) >> 12;
    bridge->mUnk_124.z = ((s64) bridge->mUnk_000.mMatrix.mUnk_00[0].z * angleDelta) >> 12;
    bridge->mUnk_14a = y;
    bridge->mUnk_0a0 = *(Unk020e38a0_28 *) &bridge->mUnk_000.mMatrix;
    MTX_RotX33_((s32 *) &bridge->mUnk_000.mMatrix, FX_SinCosTable_[(y >> 4) * 2], FX_SinCosTable_[(y >> 4) * 2 + 1]);
    MTX_Concat33((const s32 *) &bridge->mUnk_000.mMatrix, (const s32 *) &bridge->mUnk_0c4,
                 (s32 *) &bridge->mUnk_000.mMatrix);
    VEC_MultAdd(-bridge->mUnk_104, &bridge->mUnk_000.mMatrix.mUnk_00[1], &bridge->mUnk_000.mPos, &bridge->mUnk_0f4);
    if (bridge->mUnk_150 != 0) {
        bridge->mUnk_150--;
        return;
    }
    if (bridge->mUnk_000.mSound != NULL) {
        mobj_emitSfxFromEmitter(&bridge->mUnk_000, 0x189);
    }
    bridge->mUnk_148 += bridge->mUnk_146;
    if (bridge->mUnk_148 >= 0x4000 && bridge->mUnk_148 < bridge->mUnk_146 + 0x4000) {
        bridge->mUnk_150 = bridge->mUnk_14c;
    } else if (bridge->mUnk_148 >= 0xc000 && bridge->mUnk_148 < bridge->mUnk_146 + 0xc000) {
        bridge->mUnk_150 = bridge->mUnk_14e;
    }
    y = 0x10000 - bridge->mUnk_14a;
    bridge->mUnk_154 = (s32) ((((s64) (s32) (u16) (0x10000 - bridge->mUnk_14a) * 0x1680000) + 0x80000) >> 20) << 1;
    if (bridge->mUnk_154 > ((Unk020e1dc0 *) *(void **) bridge_sRenderPart)->mUnk_2c) {
        bridge->mUnk_154 = ((Unk020e1dc0 *) *(void **) bridge_sRenderPart)->mUnk_2c;
    }
    if (bridge->mUnk_154 < 0) {
        bridge->mUnk_154 = 0;
    }
}

void bridge_render(Unk020e3ef4 *object, void *viewMatrix, u32 alpha) {
    Unk020e1e98_12c *animation;

    object->mUnk_000.mMatrix.mUnk_00[3].x = object->mUnk_000.mPos.x >> 4;
    object->mUnk_000.mMatrix.mUnk_00[3].y = object->mUnk_000.mPos.y >> 4;
    object->mUnk_000.mMatrix.mUnk_00[3].z = object->mUnk_000.mPos.z >> 4;
    animation = bridge_sNsbcaAnim;
    animation->mUnk_0c = object->mUnk_154;
    *animation->mUnk_1c[animation->mUnk_1a] = animation->mUnk_0c;
    model2_renderModel(object->mModel, &object->mUnk_000.mMatrix, &object->mUnk_000.mScale.x, alpha);
}

void bridge_renderAll(void *viewMatrix) {
    dcol_render(*(void **) bridge_sRenderPart, viewMatrix, bridge_render);
}
