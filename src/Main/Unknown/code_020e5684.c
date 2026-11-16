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
    obpak_sModel->mFrameIndex = ((*(u16 *) &obPakkunSf->mUnk_a0.mUnk_18.x & 0x10) >> 4);
    if (obPakkunSf->mUnk_00.mStateMachine.mState == 0) {
        matrix = bbm_getYBillboardAtPos(&obPakkunSf->mUnk_00.mPos);
        bbm_renderTransformedScaled(obpak_sModel, matrix, &obPakkunSf->mUnk_00.mScale, 0, alpha);
        return;
    }
    matrix = bbm_getYBillboardAtPos(&obPakkunSf->mUnk_00.mPos);
    bbm_renderTransformedRotatedScaled(obpak_sModel, matrix, *(u16 *) &obPakkunSf->mUnk_a0.mUnk_0c.x, &obPakkunSf->mUnk_00.mScale, 0, alpha);
}

void obpak_update(u32 a, Unk020e43a8 *obPakkunSf) {
    Unk0210b7a8 soundRequest;
    s32 falloffIndex;

    *(u16 *) &obPakkunSf->mUnk_a0.mUnk_18 = *(u16 *) &obPakkunSf->mUnk_a0.mUnk_18 + 1;
    if ((*(u16 *) &obPakkunSf->mUnk_a0.mUnk_18 & 0x1f) == 0 &&
        (obPakkunSf->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
        if (obPakkunSf->mUnk_00.mFarDistanceSquared == gSfxParams[2].mUnk_20) {
            falloffIndex = 2;
        } else if (obPakkunSf->mUnk_00.mFarDistanceSquared == gSfxParams[3].mUnk_20) {
            falloffIndex = 3;
        } else {
            falloffIndex = 4;
        }
        soundRequest.mSoundId = 0x163;
        soundRequest.mPositionSource = &obPakkunSf->mUnk_00.mPos;
        soundRequest.mUnk_08 = falloffIndex;
        soundRequest.mDistanceSquared = mobj_calcXZCamDist(&obPakkunSf->mUnk_00.mPos);
        func_0210b7a8(&soundRequest);
    }
    sm_execute(&obPakkunSf->mUnk_00.mStateMachine);
}

u8 obpak_onDriverCollide(Unk020e43a8 *obPakkunSf, void *kart, u8 *b, u8 *c) {
    if (rdmo_onDriverCollide(obPakkunSf, kart, b) != FALSE) {
        mobj_tryDestroyByDriver(&obPakkunSf->mUnk_00, kart);
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
    obPakkunSf->mUnk_00.mPos.y =
        obPakkunSf->mUnk_00.mPos.y + (s32) (((s64) obPakkunSf->mUnk_00.mScale.y * 0xa000) >> 12);
    *(u16 *) &obPakkunSf->mUnk_a0.mUnk_18.x = 0;
    rdmo_initParams(obPakkunSf, obPakkunSf->mUnk_00.mPos.y - 0x18000, 0x400, 0x800, 0x4000, 0x1800);
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
    secondHand->mUnk_00.mMatrix.mUnk_00[3].x = secondHand->mUnk_00.mPos.x >> 4;
    secondHand->mUnk_00.mMatrix.mUnk_00[3].y = secondHand->mUnk_00.mPos.y >> 4;
    secondHand->mUnk_00.mMatrix.mUnk_00[3].z = secondHand->mUnk_00.mPos.z >> 4;
    model2_renderModel(shand_sModel, &secondHand->mUnk_00.mMatrix, &secondHand->mUnk_00.mScale, alpha);
}

void shand_update(u32 a, Unk020e43a8 *secondHand) {
    sm_execute(&secondHand->mUnk_00.mStateMachine);
    Quaternion_Rotate_20D77E0(&secondHand->mUnk_a0.mUnk_0c.y, secondHand->mUnk_00.mAngle, &secondHand->mUnk_a0);
    qtrn_toMtx33(&secondHand->mUnk_00.mMatrix, &secondHand->mUnk_a0);
}

void shand_accelerateStateInit(Unk020e58b8 *secondHand) {
    secondHand->mUnk_c8 = 0x0u;
}

void shand_accelerateStateUpdate(Unk020e43a8 *secondHand) {
    secondHand->mUnk_c8 = secondHand->mUnk_c8 + secondHand->mUnk_cc;
    secondHand->mUnk_00.mAngle =
        secondHand->mUnk_00.mAngle + (s16) (((s64) secondHand->mUnk_c8 * secondHand->mUnk_c6) >> 12);
    if (secondHand->mUnk_00.mStateMachine.mStateFrames > *(u16 *) &secondHand->mUnk_a0.mUnk_18.z) {
        secondHand->mUnk_00.mStateMachine.mNextState = 1;
        secondHand->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u32 shand_moveStateInit(u32 value) {
    return value;
}

void shand_moveStateUpdate(Unk020e43a8 *secondHand) {
    secondHand->mUnk_00.mAngle = secondHand->mUnk_00.mAngle + secondHand->mUnk_c6;
    if (*((u16 *) &secondHand->mUnk_a0.mUnk_18.z + 1) == 0) {
        return;
    }
    if (secondHand->mUnk_00.mStateMachine.mStateFrames > *((u16 *) &secondHand->mUnk_a0.mUnk_18.z + 1)) {
        secondHand->mUnk_00.mStateMachine.mNextState = 2;
        secondHand->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void shand_decelerateStateInit(Unk020e58b8 *secondHand) {
    secondHand->mUnk_c8 = 0x4000u;
}

void shand_decelerateStateUpdate(Unk020e43a8 *secondHand) {
    secondHand->mUnk_c8 = secondHand->mUnk_c8 - secondHand->mUnk_cc;
    secondHand->mUnk_00.mAngle =
        secondHand->mUnk_00.mAngle + (s16) (((s64) secondHand->mUnk_c8 * secondHand->mUnk_c6) >> 12);
    if (secondHand->mUnk_00.mStateMachine.mStateFrames > *(u16 *) &secondHand->mUnk_a0.mUnk_18.z) {
        secondHand->mUnk_c6 = -secondHand->mUnk_c6;
        secondHand->mUnk_00.mStateMachine.mNextState = 3;
        secondHand->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u32 shand_waitStateInit(u32 value) {
    return value;
}

void shand_waitStateUpdate(Unk020e43a8 *secondHand) {
    if (secondHand->mUnk_00.mStateMachine.mStateFrames > secondHand->mUnk_c4) {
        secondHand->mUnk_00.mStateMachine.mNextState = 0;
        secondHand->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

s32 shand_onDriverCollide(Unk020e43a8 *secondHand, KartItemEffectView *kart, s32 a, u8 *b) {
    u32 x;

    x = kart->mUnk_29c;
    if (x == 1 || x == 3) {
        secondHand->mUnk_00.mDistanceSquaredAndFlags |= data_021590e8;
    }
    return *b;
}

u32 shand_onItemCollide(u32 p0, u32 p1, u32 p2, u32 p3) {
    return (*OFFSET_PTR(const u8, p3, 0));
}

void shand_collide(Unk020e43a8 *secondHand, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset) {
    Vec3 s;
    s32 y;

    y = secondHand->mUnk_00.mExtent.y;
    s.x = secondHand->mUnk_00.mExtent.x;
    s.y = y;
    s.z = 0;
    col_collideSphereBox(sphereCenter, &secondHand->mUnk_00.mPos, &secondHand->mUnk_00.mMatrix.mUnk_00[0],
                                 &secondHand->mUnk_00.mExtent, &s, sphereRadius, overlapOffset);
}

#pragma thumb on

void shand_loadModel(void) {
    model2_createFromNsbmd(&shand_sModel, mobj_getMapObjFile(aSecond_hand_ns), NULL);
    model_setPolyIdLightFlagsEmi(shand_sModel, 0x3f, 2, 0x294a);
}

void shand_init(Unk020e43a8 *secondHand, Unk020e5684 *courseRow) {
    secondHand->mUnk_00.mExtent.y = ((s64) secondHand->mUnk_00.mScale.x * 0x4b000) >> 12;
    sm_init(&secondHand->mUnk_00.mStateMachine, (UnkFunc *const *) shand_sStates, 4, secondHand);
    qtrn_fromEulerAngles(&courseRow->mUnk_0c, (u32 *) &secondHand->mUnk_a0.mUnk_00);
    *(Quaternion *) &secondHand->mUnk_a0.mUnk_0c.y = *(Quaternion *) &secondHand->mUnk_a0.mUnk_00;
    *(s16 *) &secondHand->mUnk_a0.mUnk_18.z = courseRow->mUnk_2c;
    *((s16 *) &secondHand->mUnk_a0.mUnk_18.z + 1) = courseRow->mUnk_2a;
    secondHand->mUnk_c4 = courseRow->mUnk_2e;
    secondHand->mUnk_c6 = (courseRow->mUnk_28 << 7) / 0x64;
    if (courseRow->mUnk_30 != 0) {
        secondHand->mUnk_c6 = -secondHand->mUnk_c6;
    }
    secondHand->mUnk_00.mAngle = 0;
    if (*(u16 *) &secondHand->mUnk_a0.mUnk_18.z != 0) {
        secondHand->mUnk_cc = 0x1000 / *(u16 *) &secondHand->mUnk_a0.mUnk_18.z;
    } else {
        secondHand->mUnk_cc = 0;
    }
    secondHand->mUnk_c8 = 0;
    secondHand->mUnk_00.mStateMachine.mNextState = 0;
    secondHand->mUnk_00.mStateMachine.mNextStateRequested = 1;
    secondHand->mUnk_00.mFlags |= data_021590b0;
}

#pragma thumb off
