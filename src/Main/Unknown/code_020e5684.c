#include "Main/Unknown/code_020e5684.h"

#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020e57f4.h"
#include "Main/Unknown/code_020e57fc.h"
#include "Main/Unknown/code_020e5850.h"
#include "Main/Unknown/code_020e5854.h"
#include "Main/Unknown/code_020e58b8.h"
#include "Main/Unknown/code_020e58c4.h"
#include "Main/Unknown/code_020e58fc.h"
#include "Main/Unknown/code_020e5900.h"
#include "Main/Unknown/code_020e5950.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/code_020ec000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ec884.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e5b88.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020ec1fc.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020e337c.h"
#include "Main/Unknown/code_020e5c6c.h"

void obpak_render(u32 a, Unk020e43a8 *obPakkunSf, u32 c, u16 alpha) {
    MtxFx43 *matrix;
    obpak_sModel->mFrameIndex = ((*(u16 *) &obPakkunSf->fieldA0.field18.x & 0x10) >> 4);
    if (obPakkunSf->field0.mStateMachine.mState == 0) {
        matrix = bbm_getYBillboardAtPos(&obPakkunSf->field0.mPos);
        bbm_renderTransformedScaled(obpak_sModel, matrix, &obPakkunSf->field0.mScale, 0, alpha);
        return;
    }
    matrix = bbm_getYBillboardAtPos(&obPakkunSf->field0.mPos);
    bbm_renderTransformedRotatedScaled(obpak_sModel, matrix, *(u16 *) &obPakkunSf->fieldA0.fieldC.x, &obPakkunSf->field0.mScale, 0, alpha);
}

void obpak_update(u32 a, Unk020e43a8 *obPakkunSf) {
    Unk0210b7a8 soundRequest;
    s32 falloffIndex;

    *(u16 *) &obPakkunSf->fieldA0.field18 = *(u16 *) &obPakkunSf->fieldA0.field18 + 1;
    if ((*(u16 *) &obPakkunSf->fieldA0.field18 & 0x1f) == 0 &&
        (obPakkunSf->field0.mDistanceSquaredAndFlags & 4) == 0) {
        if (obPakkunSf->field0.mFarDistanceSquared == gSfxParams[2].field20) {
            falloffIndex = 2;
        } else if (obPakkunSf->field0.mFarDistanceSquared == gSfxParams[3].field20) {
            falloffIndex = 3;
        } else {
            falloffIndex = 4;
        }
        soundRequest.mSoundId = 0x163;
        soundRequest.mPositionSource = &obPakkunSf->field0.mPos;
        soundRequest.field8 = falloffIndex;
        soundRequest.mDistanceSquared = mobj_calcXZCamDist(&obPakkunSf->field0.mPos);
        sub_210B7A8(&soundRequest);
    }
    sm_execute(&obPakkunSf->field0.mStateMachine);
}

u8 obpak_onDriverCollide(Unk020e43a8 *obPakkunSf, void *kart, u8 *b, u8 *c) {
    if (rdmo_onDriverCollide(obPakkunSf, kart, b) != FALSE) {
        mobj_tryDestroyByDriver(&obPakkunSf->field0, kart);
    }
    return *c;
}

u8 obpak_onItemCollide(Unk020e43a8 *obPakkunSf, void *itemObject, u8 *b, u8 *c) {
    rdmo_onItemCollide(obPakkunSf, itemObject, b);
    return *c;
}

#pragma thumb on

void obpak_loadModel(void) {
    void *nsbmdFile;
    void *nsbtpFile;
    nsbmdFile = mobj_getMapObjFile(aOb_pakkun_sf_n);
    nsbtpFile = mobj_getMapObjFile(aOb_pakkun_sf_0);
    bbm_createFromNsbmd((NsbmdModel **) (((u32 *) &obpak_sModel)), nsbmdFile, nsbtpFile, 0);
    bbm_setDefaultMatParams(obpak_sModel);
}

#pragma thumb off

#pragma thumb on

void obpak_init(Unk020e43a8 *obPakkunSf) {
    obPakkunSf->field0.mPos.y =
        obPakkunSf->field0.mPos.y + (s32) (((s64) obPakkunSf->field0.mScale.y * 0xa000) >> 12);
    *(u16 *) &obPakkunSf->fieldA0.field18.x = 0;
    rdmo_initParams(obPakkunSf, obPakkunSf->field0.mPos.y - 0x18000, 0x400, 0x800, 0x4000, 0x1800);
    rdmo_initStateMachine(obPakkunSf);
}

#pragma thumb off

Unk020e5a9c *shand_setupConfig(void) {
    Unk020e5a9c *kindData;
    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = *(Unk020e5a9c *) shand_colData;
    return kindData;
}

Unk020e5a40 *shand_setupRenderPart(void) {
    Unk020e5a40 *drawList;
    drawList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    shand_sRenderPart = drawList;
    *drawList = *(Unk020e5a40 *) shand_renderPartData;
    mobj_renderPartSetThisPointer(&shand_sRenderPart);
    return shand_sRenderPart;
}

Unk020e59e4 *shand_setupLogicPart(void) {
    Unk020e59e4 *updateList;
    updateList = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    shand_sLogicPart = updateList;
    *updateList = *(Unk020e59e4 *) shand_logicPartData;
    mobj_logicPartSetThisPointer(&shand_sLogicPart);
    return shand_sLogicPart;
}

void shand_render(u32 a, Unk020e43a8 *secondHand, u32 b, u32 alpha) {
    secondHand->field0.mMatrix.field0[3].x = secondHand->field0.mPos.x >> 4;
    secondHand->field0.mMatrix.field0[3].y = secondHand->field0.mPos.y >> 4;
    secondHand->field0.mMatrix.field0[3].z = secondHand->field0.mPos.z >> 4;
    model2_renderModel(shand_sModel, &secondHand->field0.mMatrix, &secondHand->field0.mScale, alpha);
}

void shand_update(u32 a, Unk020e43a8 *secondHand) {
    sm_execute(&secondHand->field0.mStateMachine);
    Quaternion_Rotate_20D77E0(&secondHand->fieldA0.fieldC.y, secondHand->field0.mAngle, &secondHand->fieldA0);
    qtrn_toMtx33(&secondHand->field0.mMatrix, &secondHand->fieldA0);
}

void shand_accelerateStateInit(Unk020e58b8 *secondHand) {
    secondHand->fieldC8 = 0x0u;
}

void shand_accelerateStateUpdate(Unk020e43a8 *secondHand) {
    secondHand->fieldC8 = secondHand->fieldC8 + secondHand->fieldCC;
    secondHand->field0.mAngle =
        secondHand->field0.mAngle + (s16) (((s64) secondHand->fieldC8 * secondHand->fieldC6) >> 12);
    if (secondHand->field0.mStateMachine.mStateFrames > *(u16 *) &secondHand->fieldA0.field18.z) {
        secondHand->field0.mStateMachine.mNextState = 1;
        secondHand->field0.mStateMachine.mNextStateRequested = 1;
    }
}

u32 shand_moveStateInit(u32 value) {
    return value;
}

void shand_moveStateUpdate(Unk020e43a8 *secondHand) {
    secondHand->field0.mAngle = secondHand->field0.mAngle + secondHand->fieldC6;
    if (*((u16 *) &secondHand->fieldA0.field18.z + 1) == 0) {
        return;
    }
    if (secondHand->field0.mStateMachine.mStateFrames > *((u16 *) &secondHand->fieldA0.field18.z + 1)) {
        secondHand->field0.mStateMachine.mNextState = 2;
        secondHand->field0.mStateMachine.mNextStateRequested = 1;
    }
}

void shand_decelerateStateInit(Unk020e58b8 *secondHand) {
    secondHand->fieldC8 = 0x4000u;
}

void shand_decelerateStateUpdate(Unk020e43a8 *secondHand) {
    secondHand->fieldC8 = secondHand->fieldC8 - secondHand->fieldCC;
    secondHand->field0.mAngle =
        secondHand->field0.mAngle + (s16) (((s64) secondHand->fieldC8 * secondHand->fieldC6) >> 12);
    if (secondHand->field0.mStateMachine.mStateFrames > *(u16 *) &secondHand->fieldA0.field18.z) {
        secondHand->fieldC6 = -secondHand->fieldC6;
        secondHand->field0.mStateMachine.mNextState = 3;
        secondHand->field0.mStateMachine.mNextStateRequested = 1;
    }
}

u32 shand_waitStateInit(u32 value) {
    return value;
}

void shand_waitStateUpdate(Unk020e43a8 *secondHand) {
    if (secondHand->field0.mStateMachine.mStateFrames > secondHand->fieldC4) {
        secondHand->field0.mStateMachine.mNextState = 0;
        secondHand->field0.mStateMachine.mNextStateRequested = 1;
    }
}

s32 shand_onDriverCollide(Unk020e43a8 *secondHand, KartItemEffectView *kart, s32 a, u8 *b) {
    u32 x;

    x = kart->field29C;
    if (x == 1 || x == 3) {
        secondHand->field0.mDistanceSquaredAndFlags |= data_021590e8;
    }
    return *b;
}

u32 shand_onItemCollide(u32 p0, u32 p1, u32 p2, u32 p3) {
    return (*OFFSET_PTR(const u8, p3, 0));
}

void shand_collide(Unk020e43a8 *secondHand, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset) {
    Vec3 s;
    s32 y;

    y = secondHand->field0.mExtent.y;
    s.x = secondHand->field0.mExtent.x;
    s.y = y;
    s.z = 0;
    col_collideSphereBox(sphereCenter, &secondHand->field0.mPos, &secondHand->field0.mMatrix.field0[0],
                                 &secondHand->field0.mExtent, &s, sphereRadius, overlapOffset);
}

#pragma thumb on

void shand_loadModel(void) {
    model2_createFromNsbmd(&shand_sModel, mobj_getMapObjFile(aSecond_hand_ns), NULL);
    model_setPolyIdLightFlagsEmi(shand_sModel, 0x3f, 2, 0x294a);
}

void shand_init(Unk020e43a8 *secondHand, Unk020e5684 *courseRow) {
    secondHand->field0.mExtent.y = ((s64) secondHand->field0.mScale.x * 0x4b000) >> 12;
    sm_init(&secondHand->field0.mStateMachine, (UnkFunc *const *) shand_sStates, 4, secondHand);
    qtrn_fromEulerAngles(&courseRow->fieldC, (u32 *) &secondHand->fieldA0.field0);
    *(Quaternion *) &secondHand->fieldA0.fieldC.y = *(Quaternion *) &secondHand->fieldA0.field0;
    *(s16 *) &secondHand->fieldA0.field18.z = courseRow->field2C;
    *((s16 *) &secondHand->fieldA0.field18.z + 1) = courseRow->field2A;
    secondHand->fieldC4 = courseRow->field2E;
    secondHand->fieldC6 = (courseRow->field28 << 7) / 0x64;
    if (courseRow->field30 != 0) {
        secondHand->fieldC6 = -secondHand->fieldC6;
    }
    secondHand->field0.mAngle = 0;
    if (*(u16 *) &secondHand->fieldA0.field18.z != 0) {
        secondHand->fieldCC = 0x1000 / *(u16 *) &secondHand->fieldA0.field18.z;
    } else {
        secondHand->fieldCC = 0;
    }
    secondHand->fieldC8 = 0;
    secondHand->field0.mStateMachine.mNextState = 0;
    secondHand->field0.mStateMachine.mNextStateRequested = 1;
    secondHand->field0.mFlags |= data_021590b0;
}

#pragma thumb off
